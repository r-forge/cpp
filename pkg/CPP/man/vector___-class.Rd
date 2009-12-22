\name{vector<>-class}
\Rdversion{1.1}
\docType{class}
\alias{vector<>-class}
\alias{as.vector,vector<>-method}
\alias{[[,vector<>-method}
\alias{length,vector<>-method}

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
	\item{length}{\code{signature(x = "vector<>")}: the number of elements in the \code{std::vector} }
	\item{[[}{\code{signature(x = "vector<>")}: extracts one element from the \code{std::vector} as an R vector of length 1 }
}
}
\author{ Romain Francois <francoisromain@free.fr> }
\seealso{
	Implementations classes: \linkS4class{vector<int>}, 
	\linkS4class{vector<double>}, \linkS4class{vector<raw>}
}
\keyword{classes}