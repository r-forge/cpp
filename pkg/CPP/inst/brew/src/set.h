#ifndef CPP_SET_<%= casefold( ctype_r, upper = TRUE) %>_H
#define CPP_SET_<%= casefold( ctype_r, upper = TRUE) %>_H

#include "CPP.h"

namespace CPP{
	
	// finalizer
	RcppExport void set_<%= ctype_r %>____finalizer(SEXP); 
	
	// constructors
	RcppExport SEXP set_<%= ctype_r %>____new() ;
	
	// methods
	RcppExport SEXP set_<%= ctype_r %>____size(SEXP);
	RcppExport SEXP set_<%= ctype_r %>____max_size(SEXP);
	RcppExport SEXP set_<%= ctype_r %>____empty(SEXP);
	RcppExport SEXP set_<%= ctype_r %>____clear(SEXP);
	RcppExport SEXP set_<%= ctype_r %>____get___integer(SEXP, SEXP);
	RcppExport SEXP set_<%= ctype_r %>____as_dot_vector(SEXP) ;
	RcppExport SEXP set_<%= ctype_r %>____insert___integer(SEXP, SEXP);
	RcppExport SEXP set_<%= ctype_r %>____insert___double(SEXP, SEXP);
	RcppExport SEXP set_<%= ctype_r %>____insert___raw(SEXP, SEXP);
	
}

#endif
