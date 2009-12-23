\name{vector<int>-class}
\Rdversion{1.1}
\docType{class}
\alias{vector<int>-class}
\alias{as.vector-vector<int>-method}

\title{Class "vector<int>"}
\description{R wrapper around the C++ class \code{std::vector<int>}}
\section{Objects from the Class}{
Objects can be created by calls of the form
\code{new( CPP("vector<int>") )}.
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
		\item{as.vector}{\code{signature(x = "vector<int>")}: converts this to an R vector}
	}
}
\author{ Romain Francois <francoisromain@free.fr> }
\seealso{\linkS4class{vector<>} for examples}
\keyword{classes}
