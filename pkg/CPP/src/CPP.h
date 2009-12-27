#ifndef CPP_CPP_H
#define CPP_CPP_H

#include "Rcpp.h"
#include <set>
#include <algorithm>

namespace CPP{

template <typename T>
class x_ptr {
	public:
  		x_ptr(SEXP xp, bool ownsPointer) ;
  		x_ptr(T* p, bool ownsPointer) ;
  		~x_ptr() ;
  		
  		T& operator*() const ;
  		T* operator->() const ;
  		SEXP getProtected() ;
  		SEXP getTag() ;
  		SEXP getExternalPointer() ;
  		void setOwnsPointer( bool ownership );
  		void protect() ;
  		
  	private:
  		SEXP xp;
  		bool ownsPointer;
  		bool isProtected;
};

// template<typename T>
// x_ptr<T> x_ptr<T>::operator=(SEXP xp){
// 	Rprintf( "operator=( SEXP )\n" ) ;
// 	this.xp = xp ;
// 	return *this ;
// }

template<typename T>
x_ptr<T>::x_ptr(SEXP xp, bool ownsPointer=false) : xp(xp), ownsPointer(ownsPointer), isProtected(false) {
	Rprintf( "x_ptr( SEXP, bool )\n", xp, ownsPointer ) ;
	Rprintf( "   pointer = <%p>\n", EXTPTR_PTR(xp) ) ;
}

template<typename T>
x_ptr<T>::x_ptr(T* p, bool ownsPointer=false) : ownsPointer(ownsPointer), isProtected(false) {
	Rprintf( "x_ptr( T* <%p>, %d)\n", p, ownsPointer ) ;
	xp = R_MakeExternalPtr( (void*)p , R_NilValue, R_NilValue) ;
	protect() ;
}

// template<typename T>
// x_ptr<T>::x_ptr(){
// 	Rprintf( "default ctor\n" ) ; 
// }


template<typename T>
void x_ptr<T>::protect(){
	R_PreserveObject( xp ) ;
	isProtected = true ;
}

template<typename T>
x_ptr<T>::~x_ptr(){
	T* pointer ;
	if( ownsPointer ){
		pointer = (T*)EXTPTR_PTR( xp) ; 
	}
	if( isProtected ){
		R_ReleaseObject( xp ) ;
	}
	if( ownsPointer ){
		delete pointer ;
	}
}

template<typename T>
T& x_ptr<T>::operator*() const {
	Rprintf( "*  : <%p>\n", (T*)EXTPTR_PTR( xp) ) ;
	return *((T*)EXTPTR_PTR( xp)) ;
}

template<typename T>
T* x_ptr<T>::operator->() const {
	Rprintf( "-> : <%p>\n", (T*)EXTPTR_PTR( xp) ) ;
	return (T*)(EXTPTR_PTR( xp));
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

template<typename T>
void x_ptr<T>::setOwnsPointer( bool ownership ){
	ownsPointer = ownership ;
}

RcppExport SEXP foo( x_ptr< std::vector<int> > ) ;


} // namespace CPP

#endif
