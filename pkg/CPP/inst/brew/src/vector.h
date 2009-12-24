#ifndef CPP_VECTOR_<%= casefold( ctype_r , upper = TRUE ) %>_H
#define CPP_VECTOR_<%= casefold( ctype_r , upper = TRUE ) %>_H

#include "CPP.h"

namespace CPP{
	
	// finalizer
	RcppExport void vector_<%= ctype_r %>____finalizer(SEXP); 
	
	// constructors
	RcppExport SEXP vector_<%= ctype_r %>____new() ;
	
	// methods
<%#===== common methods ===== #%>	
	
	RcppExport SEXP vector_<%= ctype_r %>____size(SEXP);
	RcppExport SEXP vector_<%= ctype_r %>____capacity(SEXP);
	RcppExport SEXP vector_<%= ctype_r %>____max_size(SEXP);
	RcppExport SEXP vector_<%= ctype_r %>____resize___integer(SEXP, SEXP);
	RcppExport SEXP vector_<%= ctype_r %>____resize___double(SEXP, SEXP);
	RcppExport SEXP vector_<%= ctype_r %>____empty(SEXP);
	RcppExport SEXP vector_<%= ctype_r %>____clear(SEXP);
	RcppExport SEXP vector_<%= ctype_r %>____reserve___integer(SEXP, SEXP);
	RcppExport SEXP vector_<%= ctype_r %>____reserve___double(SEXP, SEXP);
	RcppExport SEXP vector_<%= ctype_r %>____get___integer(SEXP, SEXP);
	RcppExport SEXP vector_<%= ctype_r %>____front(SEXP);
	RcppExport SEXP vector_<%= ctype_r %>____back(SEXP);
	RcppExport SEXP vector_<%= ctype_r %>____pop_back(SEXP);
	RcppExport SEXP vector_<%= ctype_r %>____as_dot_vector(SEXP) ; 
	
<%#===== methods that need some specific treatment given 
         the type of data they handle %>
<% if( ctype_r %in% c("int","double","raw") ) { %>
	RcppExport SEXP vector_<%= ctype_r %>____push_back___integer(SEXP, SEXP) ;
	RcppExport SEXP vector_<%= ctype_r %>____push_back___double(SEXP, SEXP) ;
	RcppExport SEXP vector_<%= ctype_r %>____push_back___raw(SEXP, SEXP) ;
	RcppExport SEXP vector_<%= ctype_r %>____assign___integer(SEXP, SEXP);
	RcppExport SEXP vector_<%= ctype_r %>____assign___double(SEXP, SEXP);
	RcppExport SEXP vector_<%= ctype_r %>____assign___raw(SEXP, SEXP);

<% } else if( ctype_r == "string" ) { %>
	
	RcppExport SEXP vector_string____push_back___character(SEXP, SEXP) ;
	RcppExport SEXP vector_string____assign___character(SEXP, SEXP);
	
<% } %>

}

#endif
