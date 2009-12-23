\name{deque<>-class}
\Rdversion{1.1}
\docType{class}
\alias{deque<>-class}
\alias{as.vector,deque<>-method}
\alias{as.list,deque<>-method}
\alias{[[,deque<>-method}
\alias{length,deque<>-method}

\title{Class "deque<>", virtual super class of all set wrapper R classes}
\description{Virtual super class of all R wrapper classes around \code{std::deque}}
\section{Objects from the Class}{A virtual Class: No objects may be created from it.}
\section{Slots}{
\describe{
	 \item{\code{pointer}:}{external pointer to the \code{std::deque} object }
}
}
\section{Extends}{
Class \code{"\linkS4class{C++Object}"}, directly.
}
\section{Methods}{
\describe{
    \item{as.vector}{\code{signature(x = "deque<>")}: returns the content of the set as an R vector }
    \item{as.list}{\code{signature(x = "set<>")}: same as \code{as.vector} }
    \item{[[}{\code{signature(x = "deque<>")}: extracts the element of the set in the given position }
    \item{length}{\code{signature(x = "deque<>")}: the number of elements in the set }
}
}
\references{ The \code{std::deque} C++ template from the standard template library.  }
\author{ Romain Francois <francoisromain@free.fr> }
\seealso{
	\linkS4class{deque<int>}, \linkS4class{deque<raw>}, \linkS4class{deque<double>}
}
\examples{
	x <- new( CPP( "deque<int>") )
	x$assign( 21:40 )
	x$push_back( 41:60 )
	x$push_front( 1:20 )
	x$size()
	\dontshow{	stopifnot( identical( as.vector( x ), 1:60 ) )}
	
	x <- new( CPP( "deque<double>") )
	x$assign( 21:40 )
	x$push_back( 41:60 )
	x$push_front( 1:20 )
	x$size()
	\dontshow{	stopifnot( identical( as.vector( x ), as.numeric(1:60) ) )}
	
	x <- new( CPP( "deque<raw>") )
	x$assign( 21:40 )
	x$push_back( 41:60 )
	x$push_front( 1:20 )
	x$size()
	\dontshow{	stopifnot( identical( as.vector( x ), as.raw(1:60) ) )}

}
\keyword{classes}
