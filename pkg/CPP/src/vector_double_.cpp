#include "vector_double_.h"

namespace CPP{
	
	void vector_double____finalizer(SEXP p){
		if( TYPEOF(p) == EXTPTRSXP ){
			std::vector<double>* ptr = (std::vector<double>*) EXTPTR_PTR(p) ;
			delete ptr ;
		}
	}
	
	SEXP vector_double____new(){
		std::vector<double>* p = new std::vector<double> ;
		SEXP ptr = PROTECT(R_MakeExternalPtr( (void*)p , R_NilValue, R_NilValue));
		R_RegisterCFinalizerEx( ptr, vector_double____finalizer , FALSE ) ;
		UNPROTECT(1) ; /* ptr */
		return ptr ;
	}
	
	SEXP vector_double____push_back___double(SEXP x, SEXP p1){
		x_ptr< std::vector<double> > p(x) ;
		for( int i=0; i<LENGTH(p1); i++){
			p->push_back( REAL(p1)[i] ) ;
		}
		return(R_NilValue) ;
	}
	
	SEXP vector_double____size(SEXP x){
		x_ptr< std::vector<double> > p(x) ;
		return Rf_ScalarInteger( p->size() ) ;
	}
	
	SEXP vector_double____capacity(SEXP x){
		x_ptr< std::vector<double> > p(x) ;
		return Rf_ScalarInteger( p->capacity() ) ;
	}
	
	SEXP vector_double____max_size(SEXP x){
		x_ptr< std::vector<double> > p(x) ;
		return Rf_ScalarInteger( p->max_size() ) ;
	}
	
	SEXP vector_double____resize___integer__integer(SEXP x, SEXP p1, SEXP p2){
		x_ptr< std::vector<double> > p(x) ;
		p->resize( INTEGER(p1)[0], INTEGER(p2)[0] ) ;
		return R_NilValue ;
	}
	
	SEXP vector_double____resize___integer(SEXP x, SEXP p1){
		x_ptr< std::vector<double> > p(x) ;
		p->resize( INTEGER(p1)[0], 0 ) ;
		return R_NilValue ;
	}
	
	SEXP vector_double____empty(SEXP x){
		x_ptr< std::vector<double> > p(x) ;
		return( Rf_ScalarLogical( p->empty() ) ) ;
	}
	
	SEXP vector_double____clear(SEXP x){
		x_ptr< std::vector<double> > p(x) ;
		p->clear() ;
		return R_NilValue ;
	}
	
	SEXP vector_double____reserve___integer(SEXP x, SEXP p1){
		x_ptr< std::vector<double> > p(x) ;
		p->reserve( INTEGER(p1)[0] ) ;
		return R_NilValue ;
	}
	
	SEXP vector_double____assign___integer( SEXP x, SEXP p1){
		x_ptr< std::vector<double> > p(x) ;
		p->assign( REAL(p1), REAL(p1)+LENGTH(p1) ) ;
		return R_NilValue ;
	}
	
	SEXP vector_double____get___integer(SEXP x, SEXP p1){
		x_ptr< std::vector<double> > p(x) ;
		std::vector<double>& vec = *p ;
		return( Rf_ScalarReal( vec[ INTEGER(p1)[0] ] ) ) ;
	}
	
	SEXP vector_double____as_dot_vector(SEXP x){
		x_ptr< std::vector<double> > p(x) ;
		SEXP res = PROTECT(Rf_allocVector( REALSXP, p->size() ));
		copy( p->begin(), p->end(), REAL(res) ) ;
		UNPROTECT( 1 ) ; /* res */
		return res ;
	}
	
}
