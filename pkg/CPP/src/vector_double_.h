#ifndef CPP_VECTOR_DOUBLE_H
#define CPP_VECTOR_DOUBLE_H

#include "CPP.h"

namespace CPP{
	
	// finalizer
	RcppExport void vector_double____finalizer(SEXP); 
	
	// constructors
	RcppExport SEXP vector_double____new() ;
	
	// methods
	RcppExport SEXP vector_double____push_back___double(SEXP, SEXP) ;
	RcppExport SEXP vector_double____size(SEXP);
	RcppExport SEXP vector_double____capacity(SEXP);
	RcppExport SEXP vector_double____max_size(SEXP);
	RcppExport SEXP vector_double____resize___integer(SEXP, SEXP);
	RcppExport SEXP vector_double____resize___integer__integer(SEXP, SEXP, SEXP);
	RcppExport SEXP vector_double____empty(SEXP);
	RcppExport SEXP vector_double____clear(SEXP);
	RcppExport SEXP vector_double____reserve___integer(SEXP, SEXP);
	RcppExport SEXP vector_double____assign___integer(SEXP, SEXP);
	RcppExport SEXP vector_double____get___integer(SEXP, SEXP);
	RcppExport SEXP vector_double____as_dot_vector(SEXP) ;
	
}

#endif
