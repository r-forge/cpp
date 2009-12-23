setClass( "deque<>", contains = c( "C++Object", "VIRTUAL" ) )

setClass( "deque<int>", contains = "deque<>" )
setClass( "deque<double>", contains = "deque<>" )
setClass( "deque<raw>", contains = "deque<>" )

setMethod( "as.vector", "deque<>", function(x, mode = "any") {
	x$as.vector()
} )

setMethod( "as.list", "deque<>", function(x, mode = "any") {
	x$as.vector()
} )

setMethod( "length", "deque<>", function(x){
	x$size()
} )

setMethod( "[[", "deque<>", function(x, i, j, ..., exact = TRUE){
	x$get( i )
} )

# converters
setAs( "deque<int>", "integer", function(from) from$as.vector() )
setAs( "deque<int>", "numeric", function(from) as.numeric( from$as.vector() ) )
setAs( "deque<int>", "raw", function(from) as.raw( from$as.vector() ) )
setAs( "deque<double>", "integer", function(from) as.integer( from$as.vector() ) )
setAs( "deque<double>", "numeric", function(from) from$as.vector() )
setAs( "deque<double>", "raw", function(from) as.raw( from$as.vector() ) )
setAs( "deque<raw>", "integer", function(from) as.integer( from$as.vector() ) )
setAs( "deque<raw>", "numeric", function(from) as.numeric( from$as.vector() ) )
setAs( "deque<raw>", "raw", function(from) from$as.vector() )

._as_deque_builder <- function(dest = "double"){
	cppclass <- CPP( sprintf( "deque<%s>", dest ) )
	function(from){
		x <- new( cppclass )
		x$push_back( from )
		x
	}
}
._as_deque_raw <- ._as_deque_builder( "raw")
._as_deque_double <- ._as_deque_builder( "double")
._as_deque_int <- ._as_deque_builder( "int")

setAs( "integer", "deque<raw>"   , ._as_deque_raw )
setAs( "numeric", "deque<raw>"   , ._as_deque_raw )
setAs( "raw"    , "deque<raw>"   , ._as_deque_raw )
setAs( "integer", "deque<double>", ._as_deque_double )
setAs( "numeric", "deque<double>", ._as_deque_double )
setAs( "raw"    , "deque<double>", ._as_deque_double )
setAs( "integer", "deque<int>"   , ._as_deque_int )
setAs( "numeric", "deque<int>"   , ._as_deque_int )
setAs( "raw"    , "deque<int>"   , ._as_deque_int )

