\name{reflection}
\alias{reflection}
\docType{data}
\title{
Reflection information generated from the headers
}
\description{
This dataset contains pseudo reflection information that is extracted 
from the header files of this package
}
\usage{data(reflection)}
\format{
  A data frame with the following 5 variables.
  \describe{
    \item{\code{declaration}}{the full line of the C routine declaration}
    \item{\code{classes}}{The C++ class}
    \item{\code{nargs}}{the number of arguments of the routine, including the object}
    \item{\code{method}}{The name of the method}
    \item{\code{args}}{Each element is a character vector giving the type of argument the routine is expecting. }
  }
}
\details{
	The \code{configure.R} script generates this information when the 
	package is configured, typically at \code{R CMD INSTALL} time
}
\seealso{
	The header files from which the data set is generated are 
	stored in the \code{include} directory of the installed package
}
\examples{
	# no need to call data since we use lazy loading
	head( reflection )
	
	
	
}
\keyword{datasets}
