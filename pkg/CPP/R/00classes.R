# base class of all C++ objects that are wrapped up as external
# pointers
setClass( "C++Object", representation(pointer = "externalptr"), 
	contains = "VIRTUAL", 
	prototype = list( pointer = NULL)
	)
	
setClass( "C++Class", representation(cppclass="character"), 
	prototype= list( cppclass = character(0) ) )

# indicates if cppclass is a class known to extend "C++Object"
isCppClass <- function(cppclass){
	subclasses <- getClass("C++Object")@subclasses
	for( cl in subclasses ){
		if( identical( cppclass, cl@subClass ) ) return(TRUE)
	}
	FALSE
}

CPP <- function( cppclass ){
	
	if( isCppClass(cppclass) ){
		new( "C++Class", cppclass=cppclass )
	} else{
		stop( sprintf("`%s` is not known as a C++ class", cppclass) )
	}
}

METHODS <- new.env()

# creates a routine signature
getRoutineSignature <- function( cppclass, routine, ...){
	                             
	# so that vector<int> gets a valid name
	# clname <- gsub( "<", "_lt_", cppclass , fixed = TRUE )
	# clname <- gsub( ">", "_gt_", clname   , fixed = TRUE )
	clname <- gsub( "[<>]", "_", cppclass )
	
	# we replace "." with "_dot_" so that "as.vector" can be a valid 
	# C symbol
	routine <- gsub( "[.]", "_dot_", routine )
	
	dots <- list(...)
	if( !length(dots) ){
		sprintf( "%s___%s", clname, routine )
	} else{
		types <- sapply( dots, function(x){
			type <- typeof(x)
			if( identical(type, "S4" ) ){
				type <- sprintf( "S4_%s", class(x) )
			}
			type
		} )
		sprintf( "%s___%s___%s", clname, routine, 
			paste( types, collapse = "__" ) )
	}
}

setGeneric( "new" )
setMethod( "new", "C++Class", function(Class, ...){ 
	# we need to find a constructor that is suitable 
	# for the ... parameters
	# this is achieved by a convention of symbol name in the 
	# dll where the class is defined
	cppclass <- Class@cppclass
	clazz <- getClass( cppclass )
	pkg <- clazz@package
	
	routine <- getRoutineSignature( cppclass, "new", ... )
	xp <- .Call( routine, ..., PACKAGE = pkg )
	new( cppclass, pointer = xp )
} )

setMethod( "$", "C++Object", function(x, name ){
	# TODO: deal with fields
	# we need some sort of reflection mechanism 
	# to query/set the fields of a class
	# but for now, let's just do methods
	
	# methods :
	function(...) {
		clazz <- class(x)
		
		# we cook the signature name based on the class
		# and the types of the parameters
		routine <- getRoutineSignature( clazz, name, ... )
		
		# we assume that the routine is in the package where the 
		# S4 class is defined, it seems silly otherwise
		pkg <- getClass(clazz)@package
		
		# call this routine
		res <- .Call( routine , x@pointer, ..., PACKAGE = pkg )
		if( is.null(res) ) invisible(NULL) else res
	}
	
} )

setGeneric( "as.vector" )
setGeneric( "length" )

