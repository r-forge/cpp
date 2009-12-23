#include "deque_<%= ctype_r %>_.h"

#include <deque>

<%#
ctype_r : the c type as seen by R : int, double, raw
ctype_c : the c type as seen by C : int, double, Rbyte
scalar_builder : the name of the c function (from the R api) that is used to wrap one 
	value of the std::vector. Rf_ScalarInteger, Rf_ScalarReal, Rf_ScalarRaw
SXP     : kind of SXP that is made INTSXP, RAWSXP, REALSXP
MACRO   : the R macro used to get the pointer: INTEGER, RAW, REAL
#%>

namespace CPP{
	
	void deque_<%= ctype_r %>____finalizer(SEXP p){
		if( TYPEOF(p) == EXTPTRSXP ){
			std::deque<<%= ctype_c %>>* ptr = (std::deque<<%= ctype_c %>>*) EXTPTR_PTR(p) ;
			delete ptr ;
		}
	}
	
	SEXP deque_<%= ctype_r %>____new(){
		std::deque<<%= ctype_c %>>* p = new std::deque<<%= ctype_c %>> ;
		SEXP ptr = PROTECT(R_MakeExternalPtr( (void*)p , R_NilValue, R_NilValue));
		R_RegisterCFinalizerEx( ptr, deque_<%= ctype_r %>____finalizer , FALSE ) ;
		UNPROTECT(1) ; /* ptr */
		return ptr ;
	}
	
	SEXP deque_<%= ctype_r %>____size(SEXP x){
		x_ptr< std::deque<<%= ctype_c %>> > p(x) ;
		return Rf_ScalarInteger( p->size() ) ;
	}
	
	SEXP deque_<%= ctype_r %>____max_size(SEXP x){
		x_ptr< std::deque<<%= ctype_c %>> > p(x) ;
		return Rf_ScalarInteger( p->max_size() ) ;
	}
	
	SEXP deque_<%= ctype_r %>____empty(SEXP x){
		x_ptr< std::deque<<%= ctype_c %>> > p(x) ;
		return( Rf_ScalarLogical( p->empty() ) ) ;
	}
	
	SEXP deque_<%= ctype_r %>____clear(SEXP x){
		x_ptr< std::deque<<%= ctype_c %>> > p(x) ;
		p->clear() ;
		return R_NilValue ;
	}
	
	SEXP deque_<%= ctype_r %>____resize___integer(SEXP x, SEXP p1){
		x_ptr< std::deque<<%= ctype_c %>> > p(x) ;
		p->resize( INTEGER(p1)[0], 0 ) ;
		return R_NilValue ;
	}
	
	SEXP deque_<%= ctype_r %>____resize___numeric(SEXP x, SEXP p1){
		x_ptr< std::deque<<%= ctype_c %>> > p(x) ;
		p->resize( (int)REAL(p1)[0], 0 ) ;
		return R_NilValue ;
	}
	
	SEXP deque_<%= ctype_r %>____get___integer(SEXP x, SEXP p1){
		x_ptr< std::deque<<%= ctype_c %>> > p(x) ;
		std::deque<<%= ctype_c %>>& vec = *p ;
		return( <%= scalar_builder %>( p->at( INTEGER(p1)[0] ) ) ) ;
	}
	
	SEXP deque_<%= ctype_r %>____assign___integer( SEXP x, SEXP p1){
		x_ptr< std::deque<<%= ctype_c %>> > p(x) ;
		p->assign( INTEGER(p1), INTEGER(p1)+LENGTH(p1) ) ;
		return R_NilValue ;
	}
	
	SEXP deque_<%= ctype_r %>____assign___double( SEXP x, SEXP p1){
		x_ptr< std::deque<<%= ctype_c %>> > p(x) ;
		p->assign( REAL(p1), REAL(p1)+LENGTH(p1) ) ;
		return R_NilValue ;
	}
	
	SEXP deque_<%= ctype_r %>____assign___raw( SEXP x, SEXP p1){
		x_ptr< std::deque<<%= ctype_c %>> > p(x) ;
		p->assign( RAW(p1), RAW(p1)+LENGTH(p1) ) ;
		return R_NilValue ;
	}
	
	SEXP deque_<%= ctype_r %>____push_back___integer(SEXP x, SEXP p1){
		x_ptr< std::deque<<%= ctype_c %>> > p(x) ;
		int n = LENGTH(p1) ;
		int* start = INTEGER(p1);
		p->insert( p->end(), start, start + n) ;
		return(R_NilValue) ;
	}
	
	SEXP deque_<%= ctype_r %>____push_back___double(SEXP x, SEXP p1){
		x_ptr< std::deque<<%= ctype_c %>> > p(x) ;
		int n = LENGTH(p1) ;
		double* start = REAL(p1);
		p->insert( p->end(), start, start + n) ;
		return(R_NilValue) ;
	}
	
	SEXP deque_<%= ctype_r %>____push_back___raw(SEXP x, SEXP p1){
		x_ptr< std::deque<<%= ctype_c %>> > p(x) ;
		int n = LENGTH(p1) ;
		Rbyte* start = RAW(p1);
		p->insert( p->end(), start, start + n) ;
		return(R_NilValue) ;
	}
	
	
	SEXP deque_<%= ctype_r %>____push_front___integer(SEXP x, SEXP p1){
		x_ptr< std::deque<<%= ctype_c %>> > p(x) ;
		int n = LENGTH(p1) ;
		int* start = INTEGER(p1);
		p->insert( p->begin(), start, start + n) ;
		return(R_NilValue) ;
	}
	
	SEXP deque_<%= ctype_r %>____push_front___double(SEXP x, SEXP p1){
		x_ptr< std::deque<<%= ctype_c %>> > p(x) ;
		int n = LENGTH(p1) ;
		double* start = REAL(p1);
		p->insert( p->begin(), start, start + n) ;
		return(R_NilValue) ;
	}
	
	SEXP deque_<%= ctype_r %>____push_front___raw(SEXP x, SEXP p1){
		x_ptr< std::deque<<%= ctype_c %>> > p(x) ;
		int n = LENGTH(p1) ;
		Rbyte* start = RAW(p1);
		p->insert( p->begin(), start, start + n) ;
		return(R_NilValue) ;
	}
	
	SEXP deque_<%= ctype_r %>____pop_back(SEXP x){
		x_ptr< std::deque<<%= ctype_c %>> > p(x) ;
		p->pop_back() ;
		return(R_NilValue) ;
	}
	
	SEXP deque_<%= ctype_r %>____pop_front(SEXP x){
		x_ptr< std::deque<<%= ctype_c %>> > p(x) ;
		p->pop_front() ;
		return(R_NilValue) ;
	}
	
	SEXP deque_<%= ctype_r %>____back(SEXP x){
		x_ptr< std::deque<<%= ctype_c %>> > p(x) ;
		return( Rf_ScalarInteger( p->back() ) ) ;
	}
	
	SEXP deque_<%= ctype_r %>____front(SEXP x){
		x_ptr< std::deque<<%= ctype_c %>> > p(x) ;
		return( Rf_ScalarInteger( p->front() ) ) ;
	}
	
	SEXP deque_<%= ctype_r %>____as_dot_vector(SEXP x){
		x_ptr< std::deque<<%= ctype_c %>> > p(x) ;
		SEXP res = PROTECT(Rf_allocVector( <%= SXP %>, p->size() ));
		copy( p->begin(), p->end(), <%= MACRO %>(res) ) ;
		UNPROTECT( 1 ) ; /* res */
		return res ;
	}
	
	
}
