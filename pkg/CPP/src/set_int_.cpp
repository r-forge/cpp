#include "set_int_.h"

namespace CPP{
	
	void set_int____finalizer(SEXP p){
		if( TYPEOF(p) == EXTPTRSXP ){
			std::set<int>* ptr = (std::set<int>*) EXTPTR_PTR(p) ;
			delete ptr ;
		}
	}
	
	SEXP set_int____new(){
		std::set<int>* p = new std::set<int> ;
		SEXP ptr = PROTECT(R_MakeExternalPtr( (void*)p , R_NilValue, R_NilValue));
		R_RegisterCFinalizerEx( ptr, set_int____finalizer , FALSE ) ;
		UNPROTECT(1) ; /* ptr */
		return ptr ;
	}
	
	SEXP set_int____size(SEXP x){
		x_ptr< std::set<int> > p(x) ;
		return Rf_ScalarInteger( p->size() ) ;
	}
	
	SEXP set_int____max_size(SEXP x){
		x_ptr< std::set<int> > p(x) ;
		return Rf_ScalarInteger( p->max_size() ) ;
	}
	
	SEXP set_int____empty(SEXP x){
		x_ptr< std::set<int> > p(x) ;
		return( Rf_ScalarLogical( p->empty() ) ) ;
	}
	
	SEXP set_int____clear(SEXP x){
		x_ptr< std::set<int> > p(x) ;
		p->clear() ;
		return R_NilValue ;
	}
	
	SEXP set_int____insert___integer(SEXP x, SEXP p1){
		x_ptr< std::set<int> > p(x) ;
		int n = LENGTH(p1); 
		int*start = INTEGER(p1) ;
		p->insert( start, start+n ) ;
		return R_NilValue ;
	}
	
	SEXP set_int____get___integer(SEXP x, SEXP p1){
		x_ptr< std::set<int> > p(x) ;
		int index = INTEGER(p1)[0] ;
		if( index > p->size() ){
			Rf_error( "out of bounds" ) ; 
		}
		
		std::set<int>::iterator it ;
		int i=0; 
		for( it=p->begin(); i<index; i++, it++) ;
		return( Rf_ScalarInteger( *it ) );
	}
	
	SEXP set_int____as_dot_vector(SEXP x){
		x_ptr< std::set<int> > p(x) ;
		SEXP res = PROTECT(Rf_allocVector( INTSXP, p->size() ));
		copy( p->begin(), p->end(), INTEGER(res) ) ;
		UNPROTECT( 1 ) ; /* res */
		return res ;
	}
	
}
