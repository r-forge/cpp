setClass( "vector<>", contains = c( "C++Object", "VIRTUAL" ) )

setClass( "vector<int>", contains = "vector<>" )
setClass( "vector<double>", contains = "vector<>" )
setClass( "vector<raw>", contains = "vector<>" )

setMethod( "as.vector", "vector<>", function(x, mode = "any") {
	x$as.vector()
} )

setMethod( "length", "vector<>", function(x){
	x$size()
} )

setMethod( "[[", "vector<>", function(x, i, j, ..., exact = TRUE){
	x$get( i )
} )

