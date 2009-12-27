#include "CPP.h"

namespace CPP{
	SEXP foo( x_ptr< std::vector<int> > v){
		Rprintf( "hello <%p>\n", &v ) ;
		
		Rprintf( "size = %d\n", v->size() );
		return R_NilValue ;
	}
}

