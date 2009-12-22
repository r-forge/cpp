#!/bin/env Rscript

headers <- list.files( "src", pattern = "[.]h$", full.names = TRUE )
invisible( file.copy( headers, "inst/include", overwrite = TRUE ) )

lines <- unlist( lapply( headers, function( file ){
	gsub( "^.*RcppExport\\s+SEXP\\s+", "", grep( "RcppExport.*?SEXP.*___", readLines( file ), value = TRUE, perl = TRUE ), perl = TRUE )
} ) )

rx <- "^(.*?)___(?!_)(.*)$"
classes <- sub( rx, "\\1", lines, perl = TRUE )
classes <- sub( "vector_(.*)_", "vector<\\1>", classes )
classes <- sub( "set_(.*)_", "set<\\1>", classes )

right <- sub( rx, "\\2", lines, perl = TRUE )
nargs <- sapply( strsplit( sub( "^.*[(](.*)[)].*", "\\1", right ), "," ), length )

left <- sub( "^(.*?)[(].*$", "\\1", right, perl = TRUE )
parts <- strsplit( left, "___")
method <- sapply( parts, "[", 1L )
method <- sub( "_dot_", ".", method )

args <- sapply( parts, function(x){
	if( identical( length(x), 1L) ) character(0) else strsplit( x[-1L], "__" )[[1]]
})

reflection <- data.frame( 
	declaration = lines, 
	classes = classes, 
	nargs = nargs, 
	method = method, 
	args = structure(args, dim = length(lines) ), 
	stringsAsFactors = FALSE
)

save( reflection, file="data/reflection.rda" )

