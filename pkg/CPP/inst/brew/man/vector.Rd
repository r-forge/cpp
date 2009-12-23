\name{vector<<%= ctype_r %>>-class}
\Rdversion{1.1}
\docType{class}
\alias{vector<<%= ctype_r %>>-class}
\alias{as.vector-vector<<%= ctype_r %>>-method}

\title{Class "vector<<%= ctype_r %>>"}
\description{R wrapper around the C++ class \code{std::vector<<%= ctype_r %>>}}
\section{Objects from the Class}{
Objects can be created by calls of the form
\code{new( CPP("vector<<%= ctype_r %>>") )}.
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
		\item{as.vector}{\code{signature(x = "vector<<%= ctype_r %>>")}: converts this to an R vector}
	}
}
\author{ Romain Francois <francoisromain@free.fr> }
\seealso{\linkS4class{vector<>} for examples}
\keyword{classes}
