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
		Rcpp::XPtr< std::set<<%= ctype_c %>> > p(x) ;
		return Rf_ScalarInteger( p->size() ) ;
	}
	
	SEXP set_<%= ctype_r %>____max_size(SEXP x){
		Rcpp::XPtr< std::set<<%= ctype_c %>> > p(x) ;
		return Rf_ScalarInteger( p->max_size() ) ;
	}
	
	SEXP set_<%= ctype_r %>____empty(SEXP x){
		Rcpp::XPtr< std::set<<%= ctype_c %>> > p(x) ;
		return( Rf_ScalarLogical( p->empty() ) ) ;
	}
	
	SEXP set_<%= ctype_r %>____clear(SEXP x){
		Rcpp::XPtr< std::set<<%= ctype_c %>> > p(x) ;
		p->clear() ;
		return R_NilValue ;
	}
	
<%# =========== numbers ============%>	
<% if( ctype_r %in% c("int","double","raw") ) { %>
	
	SEXP set_<%= ctype_r %>____insert___integer(SEXP x, SEXP p1){
		Rcpp::XPtr< std::set<<%= ctype_c %>> > p(x) ;
		int n = LENGTH(p1); 
		int *start = INTEGER(p1) ;
		p->insert( start, start+n ) ;
		return R_NilValue ;
	}
	
	SEXP set_<%= ctype_r %>____insert___double(SEXP x, SEXP p1){
		Rcpp::XPtr< std::set<<%= ctype_c %>> > p(x) ;
		int n = LENGTH(p1); 
		double *start = REAL(p1) ;
		p->insert( start, start+n ) ;
		return R_NilValue ;
	}
	
	SEXP set_<%= ctype_r %>____insert___raw(SEXP x, SEXP p1){
		Rcpp::XPtr< std::set<<%= ctype_c %>> > p(x) ;
		int n = LENGTH(p1); 
		Rbyte *start = RAW(p1) ;
		p->insert( start, start+n ) ;
		return R_NilValue ;
	}
	
	SEXP set_<%= ctype_r %>____get___integer(SEXP x, SEXP p1){
		Rcpp::XPtr< std::set<<%= ctype_c %>> > p(x) ;
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
		Rcpp::XPtr< std::set<<%= ctype_c %>> > p(x) ;
		SEXP res = PROTECT(Rf_allocVector( <%= SXP %>, p->size() ));
		copy( p->begin(), p->end(), <%= MACRO %>(res) ) ;
		UNPROTECT( 1 ) ; /* res */
		return res ;
	}
	
	
	
<% } else if( ctype_r == "string" ) { %>

<%# ============== strings ===============%>

	SEXP set_string____insert___character(SEXP x, SEXP p1){
		Rcpp::XPtr< std::set<std::string> > p(x) ;
		int n = LENGTH(p1); 
		for( int i=0; i<n; i++){
			p->insert( std::string( CHAR(STRING_ELT(p1,i) ) ) ) ;
		}
		return R_NilValue ;
	}
		
	SEXP set_string____get___integer(SEXP x, SEXP p1){
		Rcpp::XPtr< std::set<std::string> > p(x) ;
		int index = INTEGER(p1)[0] ;
		if( index > p->size() ){
			Rf_error( "out of bounds" ) ; 
		}
		
		std::set<std::string>::iterator it ;
		int i=0; 
		for( it=p->begin(); i<index; i++, it++) ;
		return( Rf_mkString( it->c_str() ) );
	}
	
	SEXP set_string____as_dot_vector(SEXP x){
		Rcpp::XPtr< std::set<std::string> > p(x) ;
		int n = p->size() ;
		SEXP res = PROTECT(Rf_allocVector( STRSXP, n ));
		std::set<std::string>::iterator it = p->begin() ;
		int i=0; 
		while( it!=p->end() ){
			SET_STRING_ELT( res, i, Rf_mkChar(it->c_str()) ) ;
			++it;
			++i ;
		}
		UNPROTECT( 1 ) ; /* res */
		return res ;
	}
	
	
<% } %>
	
}
