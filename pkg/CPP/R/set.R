setClass( "set<>", contains = c( "C++Object", "VIRTUAL" ) )

setClass( "set<int>", contains = "set<>" )
# setClass( "set<double>", contains = "set<>" )
# setClass( "set<raw>", contains = "set<>" )

setMethod( "as.vector", "set<>", function(x, mode = "any") {
	x$as.vector()
} )

setMethod( "length", "set<>", function(x) {
	x$size()
} )

setMethod( "[[", "set<>", function(x, i, j, ..., exact = TRUE){
	x$get( i )
} )

