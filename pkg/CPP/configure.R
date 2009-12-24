#!/bin/env Rscript

if( !require( "brew" ) ){
	stop( "The brew package is required to build this package" )
}

# generate the Makevars
brew( 
	file.path( "inst", "brew", "src", "Makevars" ), 
	file.path( "src", "Makevars" )
)

# generate header filers and cpp files for vector<{int,double,raw}>
vector_header <- file.path( "inst", "brew", "src", "vector.h" )
vector_cpp    <- file.path( "inst", "brew", "src", "vector.cpp" )
vector_man    <- file.path( "inst", "brew", "man", "vector.Rd" )

set_header    <- file.path( "inst", "brew", "src", "set.h" )
set_cpp       <- file.path( "inst", "brew", "src", "set.cpp" )
set_man       <- file.path( "inst", "brew", "man", "set.Rd" )

deque_header    <- file.path( "inst", "brew", "src", "deque.h" )
deque_cpp       <- file.path( "inst", "brew", "src", "deque.cpp" )
deque_man       <- file.path( "inst", "brew", "man", "deque.Rd" )

variables <- list( 
	ctype_r        = c( "int", "double", "raw" ),
	ctype_c        = c( "int", "double", "Rbyte" ),
	scalar_builder = c( "Rf_ScalarInteger", "Rf_ScalarReal", "Rf_ScalarRaw"), 
	SXP            = c( "INTSXP", "REALSXP", "RAWSXP"),
	MACRO          = c( "INTEGER", "REAL", "RAW" )
)
for( i in 1:3L){
	for( v in names(variables) ){
		assign( v, variables[[v]][i], globalenv() )
	}
	brew( vector_header, output = file.path( "src", sprintf( "vector_%s_.h"   , ctype_r ) ) )
	brew( vector_cpp   , output = file.path( "src", sprintf( "vector_%s_.cpp" , ctype_r ) ) )
	brew( vector_man   , output = file.path( "man", sprintf( "vector_%s_.Rd"  , ctype_r ) ) )
	
	brew( set_header, output = file.path( "src", sprintf( "set_%s_.h"   , ctype_r ) ) )
	brew( set_cpp   , output = file.path( "src", sprintf( "set_%s_.cpp" , ctype_r ) ) )
	brew( set_man   , output = file.path( "man", sprintf( "set_%s_.Rd" , ctype_r ) ) )
	
	brew( deque_header, output = file.path( "src", sprintf( "deque_%s_.h"   , ctype_r ) ) )
	brew( deque_cpp   , output = file.path( "src", sprintf( "deque_%s_.cpp" , ctype_r ) ) )
	brew( deque_man   , output = file.path( "man", sprintf( "deque_%s_.Rd" , ctype_r ) ) )
}


# now parse the headers to make the reflection data

headers <- list.files( "src", pattern = "[.]h$", full.names = TRUE )
invisible( file.copy( headers, "inst/include", overwrite = TRUE ) )
impl    <- list.files( "src", pattern = "[.]cpp$", full.names = TRUE )
invisible( file.copy( impl, "inst/include", overwrite = TRUE ) )

declarations <- unlist( lapply( headers, function( file ){
	grep( "RcppExport.*?SEXP.*___", readLines( file ), value = TRUE, perl = TRUE )
} ) )

lines <- gsub( "^.*RcppExport\\s+SEXP\\s+", "", declarations, perl = TRUE )

rx <- "^(.*?)___(?!_)(.*)$"
classes <- sub( rx, "\\1", lines, perl = TRUE )
classes <- sub( "vector_(.*)_", "vector<\\1>", classes )
classes <- sub( "set_(.*)_", "set<\\1>", classes )
classes <- sub( "deque_(.*)_", "deque<\\1>", classes )

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
	declaration = declarations, 
	class = classes, 
	nargs = nargs, 
	method = method, 
	args = structure(args, dim = length(lines) ), 
	stringsAsFactors = FALSE
)

save( reflection, file="data/reflection.rda" )

