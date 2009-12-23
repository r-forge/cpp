#include "set_<%= ctype_r %>_.h"

<%#
ctype_r : the c type as seen by R : int, double, raw
ctype_c : the c type as seen by C : int, double, Rbyte
scalar_builder : the name of the c function (from the R api) that is used to wrap one 
	value of the std::vector. Rf_ScalarInteger, Rf_ScalarReal, Rf_ScalarRaw
SXP     : kind of SXP that is made INTSXP, RAWSXP, REALSXP
MACRO   : the R macro used to get the pointer: INTEGER, RAW, REAL
#%>

namespace CPP{
	
	void set_<%= ctype_r %>____finalizer(SEXP p){
		if( TYPEOF(p) == EXTPTRSXP ){
			std::set<<%= ctype_c %>>* ptr = (std::set<<%= ctype_c %>>*) EXTPTR_PTR(p) ;
			delete ptr ;
		}
	}
	
	SEXP set_<%= ctype_r %>____new(){
		std::set<<%= ctype_c %>>* p = new std::set<<%= ctype_c %>> ;
		SEXP ptr = PROTECT(R_MakeExternalPtr( (void*)p , R_NilValue, R_NilValue));
		R_RegisterCFinalizerEx( ptr, set_<%= ctype_r %>____finalizer , FALSE ) ;
		UNPROTECT(1) ; /* ptr */
		return ptr ;
	}
	
	SEXP set_<%= ctype_r %>____size(SEXP x){
		x_ptr< std::set<<%= ctype_c %>> > p(x) ;
		return Rf_ScalarInteger( p->size() ) ;
	}
	
	SEXP set_<%= ctype_r %>____max_size(SEXP x){
		x_ptr< std::set<<%= ctype_c %>> > p(x) ;
		return Rf_ScalarInteger( p->max_size() ) ;
	}
	
	SEXP set_<%= ctype_r %>____empty(SEXP x){
		x_ptr< std::set<<%= ctype_c %>> > p(x) ;
		return( Rf_ScalarLogical( p->empty() ) ) ;
	}
	
	SEXP set_<%= ctype_r %>____clear(SEXP x){
		x_ptr< std::set<<%= ctype_c %>> > p(x) ;
		p->clear() ;
		return R_NilValue ;
	}
	
	SEXP set_<%= ctype_r %>____get___integer(SEXP x, SEXP p1){
		x_ptr< std::set<<%= ctype_c %>> > p(x) ;
		int index = INTEGER(p1)[0] ;
		if( index > p->size() ){
			Rf_error( "out of bounds" ) ; 
		}
		
		std::set<<%= ctype_c %>>::iterator it ;
		int i=0; 
		for( it=p->begin(); i<index; i++, it++) ;
		return( <%= scalar_builder %>( *it ) );
	}
	
	SEXP set_<%= ctype_r %>____as_dot_vector(SEXP x){
		x_ptr< std::set<<%= ctype_c %>> > p(x) ;
		SEXP res = PROTECT(Rf_allocVector( <%= SXP %>, p->size() ));
		copy( p->begin(), p->end(), <%= MACRO %>(res) ) ;
		UNPROTECT( 1 ) ; /* res */
		return res ;
	}
	
	SEXP set_<%= ctype_r %>____insert___integer(SEXP x, SEXP p1){
		x_ptr< std::set<<%= ctype_c %>> > p(x) ;
		int n = LENGTH(p1); 
		int *start = INTEGER(p1) ;
		p->insert( start, start+n ) ;
		return R_NilValue ;
	}
	
	SEXP set_<%= ctype_r %>____insert___double(SEXP x, SEXP p1){
		x_ptr< std::set<<%= ctype_c %>> > p(x) ;
		int n = LENGTH(p1); 
		double *start = REAL(p1) ;
		p->insert( start, start+n ) ;
		return R_NilValue ;
	}
	
	SEXP set_<%= ctype_r %>____insert___raw(SEXP x, SEXP p1){
		x_ptr< std::set<<%= ctype_c %>> > p(x) ;
		int n = LENGTH(p1); 
		Rbyte *start = RAW(p1) ;
		p->insert( start, start+n ) ;
		return R_NilValue ;
	}
	
}
