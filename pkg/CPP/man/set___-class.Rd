\name{set<>-class}
\Rdversion{1.1}
\docType{class}
\alias{set<>-class}
\alias{as.vector,set<>-method}
\alias{[[,set<>-method}
\alias{length,set<>-method}
\alias{as.list,set<>-method}

\title{Class "set<>", virtual super class of all set wrapper R classes}
\description{Virtual super class of all R wrapper classes around \code{std::set}}
\section{Objects from the Class}{A virtual Class: No objects may be created from it.}
\section{Slots}{
\describe{
	 \item{\code{pointer}:}{external pointer to the \code{std::set} object }
}
}
\section{Extends}{
Class \code{"\linkS4class{C++Object}"}, directly.
}
\section{Methods}{
  \describe{
    \item{as.vector}{\code{signature(x = "set<>")}: returns the content of the set as an R vector }
    \item{as.list}{\code{signature(x = "set<>")}: same as \code{as.vector} }
    \item{[[}{\code{signature(x = "set<>")}: extracts the element of the set in the given position }
    \item{length}{\code{signature(x = "set<>")}: the number of elements in the set }
	 }
}
\references{ The \code{std::set} C++ template from the standard template library.  }
\author{ Romain Francois <francoisromain@free.fr> }
\seealso{
	\linkS4class{set<int>}, \linkS4class{set<raw>}, \linkS4class{set<double>}
}
\examples{
	x <- new( CPP( "set<int>") )
	x$insert( c( sample( 1:20 ), sample(1:20) ) )
	x$size()
	\dontshow{	stopifnot( identical( as.vector( x ), 1:20 ) )}
	
	x <- new( CPP( "set<double>") )
	x$insert( c( sample( 1:20 ), sample(1:20) ) )
	x$size()
	\dontshow{	stopifnot( identical( as.vector( x ), as.numeric(1:20) ) )}
	
	x <- new( CPP( "set<raw>") )
	x$insert( c( sample( 1:20 ), sample(1:20) ) )
	x$size()
	\dontshow{	stopifnot( identical( as.vector( x ), as.raw(1:20) ) )}
		
}
\keyword{classes}
