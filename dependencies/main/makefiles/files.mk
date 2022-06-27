origins := 0 1 2 3 4 5 6

sources := $(addsuffix /source.c, $(origins))

regular_objects := $(addsuffix /objects/regular.o, $(origins))
debug_objects := $(addsuffix /objects/debug.o, $(origins))

.SECONDARY : $(dependencies)
dependencies := $(addsuffix /dependencies.d, $(origins))
