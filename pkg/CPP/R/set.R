setClass( "set<>", contains = c( "C++Object", "VIRTUAL" ) )

setClass( "set<int>", contains = "set<>" )
setClass( "set<double>", contains = "set<>" )
setClass( "set<raw>", contains = "set<>" )

setMethod( "as.vector", "set<>", function(x, mode = "any") {
	x$as.vector()
} )

setMethod( "as.list", "set<>", function(x, mode = "any") {
	x$as.vector()
} )

setMethod( "length", "set<>", function(x){
	x$size()
} )

setMethod( "[[", "set<>", function(x, i, j, ..., exact = TRUE){
	x$get( i )
} )

# converters
setAs( "set<int>", "integer", function(from) from$as.vector() )
setAs( "set<int>", "numeric", function(from) as.numeric( from$as.vector() ) )
setAs( "set<int>", "raw", function(from) as.raw( from$as.vector() ) )
setAs( "set<double>", "integer", function(from) as.integer( from$as.vector() ) )
setAs( "set<double>", "numeric", function(from) from$as.vector() )
setAs( "set<double>", "raw", function(from) as.raw( from$as.vector() ) )
setAs( "set<raw>", "integer", function(from) as.integer( from$as.vector() ) )
setAs( "set<raw>", "numeric", function(from) as.numeric( from$as.vector() ) )
setAs( "set<raw>", "raw", function(from) from$as.vector() )

._as_stdvector_builder <- function(dest = "double"){
	cppclass <- CPP( sprintf( "set<%s>", dest ) )
	function(from){
		x <- new( cppclass )
		x$push_back( from )
		x
	}
}
._as_stdvector_raw <- ._as_stdvector_builder( "raw")
._as_stdvector_double <- ._as_stdvector_builder( "double")
._as_stdvector_int <- ._as_stdvector_builder( "int")

setAs( "integer", "set<raw>"   , ._as_stdvector_raw )
setAs( "numeric", "set<raw>"   , ._as_stdvector_raw )
setAs( "raw"    , "set<raw>"   , ._as_stdvector_raw )
setAs( "integer", "set<double>", ._as_stdvector_double )
setAs( "numeric", "set<double>", ._as_stdvector_double )
setAs( "raw"    , "set<double>", ._as_stdvector_double )
setAs( "integer", "set<int>"   , ._as_stdvector_int )
setAs( "numeric", "set<int>"   , ._as_stdvector_int )
setAs( "raw"    , "set<int>"   , ._as_stdvector_int )


