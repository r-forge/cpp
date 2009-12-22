#include "vector_int_.h"

namespace CPP{
	
	void vector_int____finalizer(SEXP p){
		if( TYPEOF(p) == EXTPTRSXP ){
			std::vector<int>* ptr = (std::vector<int>*) EXTPTR_PTR(p) ;
			delete ptr ;
		}
	}
	
	SEXP vector_int____new(){
		std::vector<int>* p = new std::vector<int> ;
		SEXP ptr = PROTECT(R_MakeExternalPtr( (void*)p , R_NilValue, R_NilValue));
		R_RegisterCFinalizerEx( ptr, vector_int____finalizer , FALSE ) ;
		UNPROTECT(1) ; /* ptr */
		return ptr ;
	}
	
	SEXP vector_int____push_back___integer(SEXP x, SEXP p1){
		x_ptr< std::vector<int> > p(x) ;
		for( int i=0; i<LENGTH(p1); i++){
			p->push_back( INTEGER(p1)[i] ) ;
		}
		return(R_NilValue) ;
	}
	
	SEXP vector_int____size(SEXP x){
		x_ptr< std::vector<int> > p(x) ;
		return Rf_ScalarInteger( p->size() ) ;
	}
	
	SEXP vector_int____capacity(SEXP x){
		x_ptr< std::vector<int> > p(x) ;
		return Rf_ScalarInteger( p->capacity() ) ;
	}
	
	SEXP vector_int____max_size(SEXP x){
		x_ptr< std::vector<int> > p(x) ;
		return Rf_ScalarInteger( p->max_size() ) ;
	}
	
	SEXP vector_int____resize___integer__integer(SEXP x, SEXP p1, SEXP p2){
		x_ptr< std::vector<int> > p(x) ;
		p->resize( INTEGER(p1)[0], INTEGER(p2)[0] ) ;
		return R_NilValue ;
	}
	
	SEXP vector_int____resize___integer(SEXP x, SEXP p1){
		x_ptr< std::vector<int> > p(x) ;
		p->resize( INTEGER(p1)[0], 0 ) ;
		return R_NilValue ;
	}
	
	SEXP vector_int____empty(SEXP x){
		x_ptr< std::vector<int> > p(x) ;
		return( Rf_ScalarLogical( p->empty() ) ) ;
	}
	
	SEXP vector_int____clear(SEXP x){
		x_ptr< std::vector<int> > p(x) ;
		p->clear() ;
		return R_NilValue ;
	}
	
	SEXP vector_int____reserve___integer(SEXP x, SEXP p1){
		x_ptr< std::vector<int> > p(x) ;
		p->reserve( INTEGER(p1)[0] ) ;
		return R_NilValue ;
	}
	
	SEXP vector_int____assign___integer( SEXP x, SEXP p1){
		x_ptr< std::vector<int> > p(x) ;
		p->assign( INTEGER(p1), INTEGER(p1)+LENGTH(p1) ) ;
		return R_NilValue ;
	}
	
	SEXP vector_int____get___integer(SEXP x, SEXP p1){
		x_ptr< std::vector<int> > p(x) ;
		std::vector<int>& vec = *p ;
		return( Rf_ScalarInteger( vec[ INTEGER(p1)[0] ] ) ) ;
	}
	
	SEXP vector_int____as_dot_vector(SEXP x){
		x_ptr< std::vector<int> > p(x) ;
		SEXP res = PROTECT(Rf_allocVector( INTSXP, p->size() ));
		copy( p->begin(), p->end(), INTEGER(res) ) ;
		UNPROTECT( 1 ) ; /* res */
		return res ;
	}
	
}
