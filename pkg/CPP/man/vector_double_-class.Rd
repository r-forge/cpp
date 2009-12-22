\name{vector<double>-class}
\Rdversion{1.1}
\docType{class}
\alias{vector<double>-class}
\alias{as.vector-vector<double>-method}

\title{Class "vector<double>"}
\description{R wrapper around the C++ class \code{std::vector<double>}}
\section{Objects from the Class}{
Objects can be created by calls of the form
\code{new( CPP("vector<double>") )}.
}
\section{Slots}{
  \describe{
    \item{\code{pointer}:}{external pointer to the C++ vector}
  }
}
\section{Extends}{
Class \code{"\linkS4class{vector<>}"}, directly.
Class \code{"\linkS4class{C++Object}"}, by class "vector<>", distance 2.
}
\section{Methods}{
	\describe{
		\item{as.vector}{\code{signature(x = "vector<double>")}: converts this to an R integer vector}
	}
}
\author{ Romain Francois <francoisromain@free.fr> }
\examples{

x <- new( CPP("vector<double>") )
x$push_back( rnorm(10) )
x$size()
x$capacity()
x$reserve( 50L )
x$capacity()
x$max_size()
x$as.vector()
as.vector(x)

# this uses 0-based indexing
x[[0L]]

}
\keyword{classes}
