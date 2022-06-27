MAKEFLAGS += \
	--warn-undefined-variables \
	--no-builtin-rules \
	--no-builtin-variables

unexport MAKEFLAGS

.DELETE_ON_ERROR :
.SUFFIXES :
.SECONDEXPANSION :

.PHONY : FORCE
FORCE :
