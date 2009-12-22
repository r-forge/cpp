#ifndef CPP_CPP_H
#define CPP_CPP_H

#include "Rcpp.h"
#include <set>
#include <algorithm>

namespace CPP{

template <typename T>
class x_ptr {
	public:
  		explicit x_ptr(SEXP xp) ;
  		
  		T& operator*() const ;
  		T* operator->() const ;
  		
  	private:
  		x_ptr() ;
  		T* pointer ;
};

template<typename T>
x_ptr<T>::x_ptr(SEXP xp){
	pointer = (T*)EXTPTR_PTR(xp) ;
}

template<typename T>
T& x_ptr<T>::operator*() const {
	return *pointer ;
}

template<typename T>
T* x_ptr<T>::operator->() const {
	return pointer ;
}

RcppExport SEXP bar(SEXP) ;

// does not work
// RcppExport SEXP foo(x_ptr< std::vector<int> > ) ;

} // namespace CPP

#endif
