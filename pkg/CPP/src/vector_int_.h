#ifndef CPP_VECTOR_INT_H
#define CPP_VECTOR_INT_H

#include "CPP.h"

namespace CPP{
	
	// finalizer
	RcppExport void vector_int____finalizer(SEXP); 
	
	// constructors
	RcppExport SEXP vector_int____new() ;
	
	// methods
	RcppExport SEXP vector_int____push_back___integer(SEXP, SEXP) ;
	RcppExport SEXP vector_int____push_back___double(SEXP, SEXP) ;
	RcppExport SEXP vector_int____push_back___raw(SEXP, SEXP) ;
	RcppExport SEXP vector_int____size(SEXP);
	RcppExport SEXP vector_int____capacity(SEXP);
	RcppExport SEXP vector_int____max_size(SEXP);
	RcppExport SEXP vector_int____resize___integer(SEXP, SEXP);
	RcppExport SEXP vector_int____resize___integer__integer(SEXP, SEXP, SEXP);
	RcppExport SEXP vector_int____empty(SEXP);
	RcppExport SEXP vector_int____clear(SEXP);
	RcppExport SEXP vector_int____reserve___integer(SEXP, SEXP);
	RcppExport SEXP vector_int____assign___integer(SEXP, SEXP);
	RcppExport SEXP vector_int____get___integer(SEXP, SEXP);
	RcppExport SEXP vector_int____as_dot_vector(SEXP) ;
	
}

#endif
