#ifndef CPP_VECTOR_<%= casefold( ctype_r , upper = TRUE ) %>_H
#define CPP_VECTOR_<%= casefold( ctype_r , upper = TRUE ) %>_H

#include "CPP.h"

namespace CPP{
	
	// finalizer
	RcppExport void vector_<%= ctype_r %>____finalizer(SEXP); 
	
	// constructors
	RcppExport SEXP vector_<%= ctype_r %>____new() ;
	
	// methods
	RcppExport SEXP vector_<%= ctype_r %>____push_back___integer(SEXP, SEXP) ;
	RcppExport SEXP vector_<%= ctype_r %>____push_back___double(SEXP, SEXP) ;
	RcppExport SEXP vector_<%= ctype_r %>____push_back___raw(SEXP, SEXP) ;
	RcppExport SEXP vector_<%= ctype_r %>____size(SEXP);
	RcppExport SEXP vector_<%= ctype_r %>____capacity(SEXP);
	RcppExport SEXP vector_<%= ctype_r %>____max_size(SEXP);
	RcppExport SEXP vector_<%= ctype_r %>____resize___integer(SEXP, SEXP);
	RcppExport SEXP vector_<%= ctype_r %>____resize___integer__integer(SEXP, SEXP, SEXP);
	RcppExport SEXP vector_<%= ctype_r %>____empty(SEXP);
	RcppExport SEXP vector_<%= ctype_r %>____clear(SEXP);
	RcppExport SEXP vector_<%= ctype_r %>____reserve___integer(SEXP, SEXP);
	RcppExport SEXP vector_<%= ctype_r %>____get___integer(SEXP, SEXP);
	RcppExport SEXP vector_<%= ctype_r %>____as_dot_vector(SEXP) ;
	RcppExport SEXP vector_<%= ctype_r %>____assign___integer(SEXP, SEXP);
	RcppExport SEXP vector_<%= ctype_r %>____assign___double(SEXP, SEXP);
	RcppExport SEXP vector_<%= ctype_r %>____assign___raw(SEXP, SEXP);
	
}

#endif
