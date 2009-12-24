#ifndef CPP_SET_<%= casefold( ctype_r, upper = TRUE) %>_H
#define CPP_SET_<%= casefold( ctype_r, upper = TRUE) %>_H

#include "CPP.h"

namespace CPP{
	
	// finalizer
	RcppExport void set_<%= ctype_r %>____finalizer(SEXP); 
	
	// constructors
	RcppExport SEXP set_<%= ctype_r %>____new() ;
	
	// methods
<%#===== common methods ===== #%>	
	RcppExport SEXP set_<%= ctype_r %>____size(SEXP);
	RcppExport SEXP set_<%= ctype_r %>____max_size(SEXP);
	RcppExport SEXP set_<%= ctype_r %>____empty(SEXP);
	RcppExport SEXP set_<%= ctype_r %>____clear(SEXP);
	RcppExport SEXP set_<%= ctype_r %>____get___integer(SEXP, SEXP);
	RcppExport SEXP set_<%= ctype_r %>____as_dot_vector(SEXP) ;
	
<%#===== methods that need some specific treatment given 
         the type of data they handle %>
<% if( ctype_r %in% c("int","double","raw") ) { %>

	RcppExport SEXP set_<%= ctype_r %>____insert___integer(SEXP, SEXP);
	RcppExport SEXP set_<%= ctype_r %>____insert___double(SEXP, SEXP);
	RcppExport SEXP set_<%= ctype_r %>____insert___raw(SEXP, SEXP);

<% } else if( ctype_r == "string" ) { %>

	RcppExport SEXP set_string____insert___character(SEXP, SEXP);

<% } %>

}

#endif
