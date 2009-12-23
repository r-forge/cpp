#include "vector_<%= ctype_r %>_.h"
<%#
ctype_r : the c type as seen by R : int, double, raw
ctype_c : the c type as seen by C : int, double, Rbyte
scalar_builder : the name of the c function (from the R api) that is used to wrap one 
	value of the std::vector. Rf_ScalarInteger, Rf_ScalarReal, Rf_ScalarRaw
SXP     : kind of SXP that is made INTSXP, RAWSXP, REALSXP
MACRO   : the R macro used to get the pointer: INTEGER, RAW, REAL
#%>
namespace CPP{
	
	void vector_<%= ctype_r %>____finalizer(SEXP p){
		if( TYPEOF(p) == EXTPTRSXP ){
			std::vector<<%= ctype_c %>>* ptr = (std::vector<<%= ctype_c %>>*) EXTPTR_PTR(p) ;
			delete ptr ;
		}
	}
	
	SEXP vector_<%= ctype_r %>____new(){
		std::vector<<%= ctype_c %>>* p = new std::vector<<%= ctype_c %>> ;
		SEXP ptr = PROTECT(R_MakeExternalPtr( (void*)p , R_NilValue, R_NilValue));
		R_RegisterCFinalizerEx( ptr, vector_<%= ctype_r %>____finalizer , FALSE ) ;
		UNPROTECT(1) ; /* ptr */
		return ptr ;
	}
	
	SEXP vector_<%= ctype_r %>____push_back___integer(SEXP x, SEXP p1){
		x_ptr< std::vector<<%= ctype_c %>> > p(x) ;
		int n = LENGTH(p1) ;
		int* start = INTEGER(p1);
		if( p->size() + n < p->capacity() ){
			p->insert( p->end(), start, start + n) ;
		}
		return(R_NilValue) ;
	}
	
	SEXP vector_<%= ctype_r %>____push_back___double(SEXP x, SEXP p1){
		x_ptr< std::vector<<%= ctype_c %>> > p(x) ;
		int n = LENGTH(p1) ;
		double* start = REAL(p1);
		if( p->size() + n < p->capacity() ){
			p->insert( p->end(), start, start + n) ;
		}
		return(R_NilValue) ;
	}
	
	SEXP vector_<%= ctype_r %>____push_back___raw(SEXP x, SEXP p1){
		x_ptr< std::vector<<%= ctype_c %>> > p(x) ;
		int n = LENGTH(p1) ;
		Rbyte* start = RAW(p1);
		if( p->size() + n < p->capacity() ){
			p->insert( p->end(), start, start + n) ;
		}
		return(R_NilValue) ;
	}
	
	SEXP vector_<%= ctype_r %>____size(SEXP x){
		x_ptr< std::vector<<%= ctype_c %>> > p(x) ;
		return Rf_ScalarInteger( p->size() ) ;
	}
	
	SEXP vector_<%= ctype_r %>____capacity(SEXP x){
		x_ptr< std::vector<<%= ctype_c %>> > p(x) ;
		return Rf_ScalarInteger( p->capacity() ) ;
	}
	
	SEXP vector_<%= ctype_r %>____max_size(SEXP x){
		x_ptr< std::vector<<%= ctype_c %>> > p(x) ;
		return Rf_ScalarInteger( p->max_size() ) ;
	}
	
	SEXP vector_<%= ctype_r %>____resize___integer__integer(SEXP x, SEXP p1, SEXP p2){
		x_ptr< std::vector<<%= ctype_c %>> > p(x) ;
		p->resize( INTEGER(p1)[0], INTEGER(p2)[0] ) ;
		return R_NilValue ;
	}
	
	SEXP vector_<%= ctype_r %>____resize___integer(SEXP x, SEXP p1){
		x_ptr< std::vector<<%= ctype_c %>> > p(x) ;
		p->resize( INTEGER(p1)[0], 0 ) ;
		return R_NilValue ;
	}
	
	SEXP vector_<%= ctype_r %>____empty(SEXP x){
		x_ptr< std::vector<<%= ctype_c %>> > p(x) ;
		return( Rf_ScalarLogical( p->empty() ) ) ;
	}
	
	SEXP vector_<%= ctype_r %>____clear(SEXP x){
		x_ptr< std::vector<<%= ctype_c %>> > p(x) ;
		p->clear() ;
		return R_NilValue ;
	}
	
	SEXP vector_<%= ctype_r %>____reserve___integer(SEXP x, SEXP p1){
		x_ptr< std::vector<<%= ctype_c %>> > p(x) ;
		p->reserve( INTEGER(p1)[0] ) ;
		return R_NilValue ;
	}
	
	SEXP vector_<%= ctype_r %>____get___integer(SEXP x, SEXP p1){
		x_ptr< std::vector<<%= ctype_c %>> > p(x) ;
		std::vector<<%= ctype_c %>>& vec = *p ;
		return( <%= scalar_builder %>( vec[ INTEGER(p1)[0] ] ) ) ;
	}
	
	SEXP vector_<%= ctype_r %>____as_dot_vector(SEXP x){
		x_ptr< std::vector<<%= ctype_c %>> > p(x) ;
		SEXP res = PROTECT(Rf_allocVector( <%= SXP %>, p->size() ));
		copy( p->begin(), p->end(), <%= MACRO %>(res) ) ;
		UNPROTECT( 1 ) ; /* res */
		return res ;
	}
	
	SEXP vector_<%= ctype_r %>____assign___integer( SEXP x, SEXP p1){
		x_ptr< std::vector<<%= ctype_c %>> > p(x) ;
		p->assign( INTEGER(p1), INTEGER(p1)+LENGTH(p1) ) ;
		return R_NilValue ;
	}
	
	SEXP vector_<%= ctype_r %>____assign___double( SEXP x, SEXP p1){
		x_ptr< std::vector<<%= ctype_c %>> > p(x) ;
		p->assign( REAL(p1), REAL(p1)+LENGTH(p1) ) ;
		return R_NilValue ;
	}
	
	SEXP vector_<%= ctype_r %>____assign___raw( SEXP x, SEXP p1){
		x_ptr< std::vector<<%= ctype_c %>> > p(x) ;
		p->assign( RAW(p1), RAW(p1)+LENGTH(p1) ) ;
		return R_NilValue ;
	}
	
}
