setClass( "deque<>", contains = c( "C++Object", "VIRTUAL" ) )

setClass( "deque<int>", contains = "deque<>" )
# setClass( "deque<double>", contains = "deque<>" )
# setClass( "deque<raw>", contains = "deque<>" )

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

