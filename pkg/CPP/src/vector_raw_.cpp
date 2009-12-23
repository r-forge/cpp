#include "vector_raw_.h"

namespace CPP{
	
	void vector_raw____finalizer(SEXP p){
		if( TYPEOF(p) == EXTPTRSXP ){
			std::vector<Rbyte>* ptr = (std::vector<Rbyte>*) EXTPTR_PTR(p) ;
			delete ptr ;
		}
	}
	
	SEXP vector_raw____new(){
		std::vector<Rbyte>* p = new std::vector<Rbyte> ;
		SEXP ptr = PROTECT(R_MakeExternalPtr( (void*)p , R_NilValue, R_NilValue));
		R_RegisterCFinalizerEx( ptr, vector_raw____finalizer , FALSE ) ;
		UNPROTECT(1) ; /* ptr */
		return ptr ;
	}
	
	SEXP vector_raw____push_back___integer(SEXP x, SEXP p1){
		x_ptr< std::vector<Rbyte> > p(x) ;
		int n = LENGTH(p1) ;
		int* start = INTEGER(p1);
		if( p->size() + n < p->capacity() ){
			p->insert( p->end(), start, start + n) ;
		}
		return(R_NilValue) ;
	}
	
	SEXP vector_raw____push_back___double(SEXP x, SEXP p1){
		x_ptr< std::vector<Rbyte> > p(x) ;
		int n = LENGTH(p1) ;
		double* start = REAL(p1);
		if( p->size() + n < p->capacity() ){
			p->insert( p->end(), start, start + n) ;
		}
		return(R_NilValue) ;
	}
	
	SEXP vector_raw____push_back___raw(SEXP x, SEXP p1){
		x_ptr< std::vector<Rbyte> > p(x) ;
		int n = LENGTH(p1) ;
		Rbyte* start = RAW(p1);
		if( p->size() + n < p->capacity() ){
			p->insert( p->end(), start, start + n) ;
		}
		return(R_NilValue) ;
	}
	
	SEXP vector_raw____size(SEXP x){
		x_ptr< std::vector<Rbyte> > p(x) ;
		return Rf_ScalarInteger( p->size() ) ;
	}
	
	SEXP vector_raw____capacity(SEXP x){
		x_ptr< std::vector<Rbyte> > p(x) ;
		return Rf_ScalarInteger( p->capacity() ) ;
	}
	
	SEXP vector_raw____max_size(SEXP x){
		x_ptr< std::vector<Rbyte> > p(x) ;
		return Rf_ScalarInteger( p->max_size() ) ;
	}
	
	SEXP vector_raw____resize___integer__integer(SEXP x, SEXP p1, SEXP p2){
		x_ptr< std::vector<Rbyte> > p(x) ;
		p->resize( INTEGER(p1)[0], INTEGER(p2)[0] ) ;
		return R_NilValue ;
	}
	
	SEXP vector_raw____resize___integer(SEXP x, SEXP p1){
		x_ptr< std::vector<Rbyte> > p(x) ;
		p->resize( INTEGER(p1)[0], 0 ) ;
		return R_NilValue ;
	}
	
	SEXP vector_raw____empty(SEXP x){
		x_ptr< std::vector<Rbyte> > p(x) ;
		return( Rf_ScalarLogical( p->empty() ) ) ;
	}
	
	SEXP vector_raw____clear(SEXP x){
		x_ptr< std::vector<Rbyte> > p(x) ;
		p->clear() ;
		return R_NilValue ;
	}
	
	SEXP vector_raw____reserve___integer(SEXP x, SEXP p1){
		x_ptr< std::vector<Rbyte> > p(x) ;
		p->reserve( INTEGER(p1)[0] ) ;
		return R_NilValue ;
	}
	
	SEXP vector_raw____assign___integer( SEXP x, SEXP p1){
		x_ptr< std::vector<Rbyte> > p(x) ;
		p->assign( INTEGER(p1), INTEGER(p1)+LENGTH(p1) ) ;
		return R_NilValue ;
	}
	
	SEXP vector_raw____get___integer(SEXP x, SEXP p1){
		x_ptr< std::vector<Rbyte> > p(x) ;
		std::vector<Rbyte>& vec = *p ;
		return( Rf_ScalarRaw( vec[ INTEGER(p1)[0] ] ) ) ;
	}
	
	SEXP vector_raw____as_dot_vector(SEXP x){
		x_ptr< std::vector<Rbyte> > p(x) ;
		SEXP payload = PROTECT( Rf_allocVector(RAWSXP, p->size() ) ); 
		copy( p->begin(), p->end(), RAW(payload) ) ;
		UNPROTECT(1); /* payload */
		return(payload) ;
	}
	
}
