#ifndef CPP_DEQUE_<%= casefold( ctype_r, upper = TRUE) %>_H
#define CPP_DEQUE_<%= casefold( ctype_r, upper = TRUE) %>_H

#include "CPP.h"

namespace CPP{
	
	// finalizer
	RcppExport void deque_<%= ctype_r %>____finalizer(SEXP); 
	
	// constructors
	RcppExport SEXP deque_<%= ctype_r %>____new() ;
	
	// methods
	RcppExport SEXP deque_<%= ctype_r %>____size(SEXP);
	RcppExport SEXP deque_<%= ctype_r %>____max_size(SEXP);
	RcppExport SEXP deque_<%= ctype_r %>____empty(SEXP);
	RcppExport SEXP deque_<%= ctype_r %>____clear(SEXP);
	RcppExport SEXP deque_<%= ctype_r %>____resize__integer(SEXP, SEXP);
	RcppExport SEXP deque_<%= ctype_r %>____resize__double(SEXP, SEXP);
	RcppExport SEXP deque_<%= ctype_r %>____get___integer(SEXP, SEXP);
	RcppExport SEXP deque_<%= ctype_r %>____assign___integer(SEXP, SEXP);
	RcppExport SEXP deque_<%= ctype_r %>____assign___double(SEXP, SEXP);
	RcppExport SEXP deque_<%= ctype_r %>____assign___raw(SEXP, SEXP);
	RcppExport SEXP deque_<%= ctype_r %>____push_back___integer(SEXP, SEXP);
	RcppExport SEXP deque_<%= ctype_r %>____push_back___double(SEXP, SEXP);
	RcppExport SEXP deque_<%= ctype_r %>____push_back___raw(SEXP, SEXP);
	RcppExport SEXP deque_<%= ctype_r %>____push_front___integer(SEXP, SEXP);
	RcppExport SEXP deque_<%= ctype_r %>____push_front___double(SEXP, SEXP);
	RcppExport SEXP deque_<%= ctype_r %>____push_front___raw(SEXP, SEXP);
	RcppExport SEXP deque_<%= ctype_r %>____pop_back(SEXP);
	RcppExport SEXP deque_<%= ctype_r %>____pop_front(SEXP);
	RcppExport SEXP deque_<%= ctype_r %>____back(SEXP);
	RcppExport SEXP deque_<%= ctype_r %>____front(SEXP);
	RcppExport SEXP deque_<%= ctype_r %>____as_dot_vector(SEXP) ;
	
}

#endif
