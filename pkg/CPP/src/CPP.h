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
  		SEXP getProtected() ;
  		SEXP getTag() ;
  		SEXP getExternalPointer() ;
  		
  	private:
  		x_ptr() ;
  		SEXP xp;
  		T* pointer;
};

template<typename T>
x_ptr<T>::x_ptr(SEXP xp) : xp(xp) {
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

template<typename T>
SEXP x_ptr<T>::getProtected(){
	return EXTPTR_PROT(xp) ;
}

template<typename T>
SEXP x_ptr<T>::getTag(){
	return EXTPTR_TAG(xp) ;
}

template<typename T>
SEXP x_ptr<T>::getExternalPointer(){
	return xp ;
}


} // namespace CPP

#endif
