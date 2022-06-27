preprocess_flags := -I ..

_objects := %/objects/regular.o %/objects/debug.o

$(_objects) : override private mode = $(notdir $(basename $@))
$(_objects) : %/source.c
	cc \
		$(preprocess_flags) \
		-std=c99 -Wall -Wextra -Werror -pedantic \
		$(if $(filter regular, $(mode)), \
			-O3) \
		$(if $(filter debug, $(mode)), \
		  $(instrument_debug_flags) \
			-g -fno-builtin -fno-omit-frame-pointer -O0) \
		-c -o $@ $<

undefine _objects

%/dependencies.d : %/source.c
	clang \
		$(preprocess_flags) \
			-M \
			-MP \
			-MT $*/objects/regular.o \
			-MT $*/objects/debug.o \
			-MF $@ \
		$<

include $(dependencies)
