setClass( "vector<>", contains = c( "C++Object", "VIRTUAL" ) )

setClass( "vector<int>", contains = "vector<>" )
setClass( "vector<double>", contains = "vector<>" )
setClass( "vector<raw>", contains = "vector<>" )

setMethod( "as.vector", "vector<>", function(x, mode = "any") {
	x$as.vector()
} )

setMethod( "as.list", "vector<>", function(x, mode = "any") {
	x$as.vector()
} )

setMethod( "length", "vector<>", function(x){
	x$size()
} )

setMethod( "[[", "vector<>", function(x, i, j, ..., exact = TRUE){
	x$get( i )
} )

# converters
setAs( "vector<int>", "integer", function(from) from$as.vector() )
setAs( "vector<int>", "numeric", function(from) as.numeric( from$as.vector() ) )
setAs( "vector<int>", "raw", function(from) as.raw( from$as.vector() ) )
setAs( "vector<double>", "integer", function(from) as.integer( from$as.vector() ) )
setAs( "vector<double>", "numeric", function(from) from$as.vector() )
setAs( "vector<double>", "raw", function(from) as.raw( from$as.vector() ) )
setAs( "vector<raw>", "integer", function(from) as.integer( from$as.vector() ) )
setAs( "vector<raw>", "numeric", function(from) as.numeric( from$as.vector() ) )
setAs( "vector<raw>", "raw", function(from) from$as.vector() )

._as_vector_raw <- ._as_std_builder( "vector", "raw")
._as_vector_double <- ._as_std_builder( "vector", "double")
._as_vector_int <- ._as_std_builder( "vector", "int")

setAs( "integer", "vector<raw>"   , ._as_stdvector_raw )
setAs( "numeric", "vector<raw>"   , ._as_stdvector_raw )
setAs( "raw"    , "vector<raw>"   , ._as_stdvector_raw )
setAs( "integer", "vector<double>", ._as_stdvector_double )
setAs( "numeric", "vector<double>", ._as_stdvector_double )
setAs( "raw"    , "vector<double>", ._as_stdvector_double )
setAs( "integer", "vector<int>"   , ._as_stdvector_int )
setAs( "numeric", "vector<int>"   , ._as_stdvector_int )
setAs( "raw"    , "vector<int>"   , ._as_stdvector_int )


