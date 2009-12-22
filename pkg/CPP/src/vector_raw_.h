#ifndef CPP_VECTOR_RAW_H
#define CPP_VECTOR_RAW_H

#include "CPP.h"

namespace CPP{
	
	// finalizer
	RcppExport void vector_raw____finalizer(SEXP); 
	
	// constructors
	RcppExport SEXP vector_raw____new() ;
	
	// methods
	RcppExport SEXP vector_raw____push_back___raw(SEXP, SEXP) ;
	RcppExport SEXP vector_raw____size(SEXP);
	RcppExport SEXP vector_raw____capacity(SEXP);
	RcppExport SEXP vector_raw____max_size(SEXP);
	RcppExport SEXP vector_raw____resize___integer(SEXP, SEXP);
	RcppExport SEXP vector_raw____resize___integer__integer(SEXP, SEXP, SEXP);
	RcppExport SEXP vector_raw____empty(SEXP);
	RcppExport SEXP vector_raw____clear(SEXP);
	RcppExport SEXP vector_raw____reserve___integer(SEXP, SEXP);
	RcppExport SEXP vector_raw____assign___integer(SEXP, SEXP);
	RcppExport SEXP vector_raw____get___integer(SEXP, SEXP);
	RcppExport SEXP vector_raw____as_dot_vector(SEXP) ;
	
}

#endif
