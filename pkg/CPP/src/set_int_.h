#ifndef CPP_SET_INT_H
#define CPP_SET_INT_H

#include "CPP.h"

namespace CPP{
	
	// finalizer
	RcppExport void set_int____finalizer(SEXP); 
	
	// constructors
	RcppExport SEXP set_int____new() ;
	
	// methods
	RcppExport SEXP set_int____size(SEXP);
	RcppExport SEXP set_int____max_size(SEXP);
	RcppExport SEXP set_int____empty(SEXP);
	RcppExport SEXP set_int____clear(SEXP);
	RcppExport SEXP set_int____insert___integer(SEXP, SEXP);
	RcppExport SEXP set_int____get___integer(SEXP, SEXP);
	RcppExport SEXP set_int____as_dot_vector(SEXP) ;
	
}

#endif
