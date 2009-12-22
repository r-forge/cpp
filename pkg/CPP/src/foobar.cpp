#include "CPP.h"

namespace CPP{

SEXP bar( SEXP xp ){
	x_ptr< std::vector<int> > p(xp) ; 
	// trying the -> operator
	Rprintf( "size() = %d\n", p->size()  ) ;
	
	// trying the * operator
	std::vector<int>& v = *p ;
	Rprintf( "size() = %d\n", v.size()  ) ;
	
	return R_NilValue ;
}

// does not work 
//SEXP foo( x_ptr< std::vector<int> > p){
// 	Rprintf( ">> foo\n" ) ;
// 	Rprintf( "size() = %d\n", p->size()  ) ;
// 	return R_NilValue ;
// }

} // namespace CPP
