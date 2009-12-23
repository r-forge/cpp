\name{vector<>-class}
\Rdversion{1.1}
\docType{class}
\alias{vector<>-class}
\alias{as.vector,vector<>-method}
\alias{[[,vector<>-method}
\alias{length,vector<>-method}
\alias{as.list,vector<>-method}

\title{Class "vector<>" - virtual class, super class of std vector objects}
\description{Super class of all \code{std::vector} objects}
\section{Objects from the Class}{A virtual Class: No objects may be created from it.}
\section{Slots}{
  \describe{
    \item{\code{pointer}:}{Object of class \code{"externalptr"} ~~ }
  }
}
\section{Extends}{
Class \code{"\linkS4class{C++Object}"}, directly.
}
\section{Methods}{
\describe{
	\item{as.vector}{\code{signature(x = "vector<>")}: returns the \code{std::vector} as an R vector of the appropriate type }
	\item{as.list}{\code{signature(x = "vector<>")}: same as \code{as.vector} }
	\item{length}{\code{signature(x = "vector<>")}: the number of elements in the \code{std::vector} }
	\item{[[}{\code{signature(x = "vector<>")}: extracts one element from the \code{std::vector} as an R vector of length 1 }
}
}
\author{ Romain Francois <francoisromain@free.fr> }
\seealso{
	Implementations classes: \linkS4class{vector<int>}, 
	\linkS4class{vector<double>}, \linkS4class{vector<raw>}
}
\examples{
	x <- new( CPP( "vector<int>") )
	x$assign( 1:20 )
	x$size()
	x$push_back( 21:40 )
	\dontshow{	stopifnot( identical( as.vector( x ), 1:40 ) )}
	
	x <- new( CPP( "vector<double>") )
	x$assign( 1:20 )
	x$size() 
	x$push_back( 21:40 )
	\dontshow{	stopifnot( identical( as.vector( x ), as.numeric(1:40) ) )}
	
	x <- new( CPP( "vector<raw>") )
	x$assign( 1:20 )
	x$size() 
	x$push_back( 21:40 )
	\dontshow{	stopifnot( identical( as.vector( x ), as.raw(1:40) ) )}
	
}
\keyword{classes}
