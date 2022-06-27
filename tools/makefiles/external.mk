$(dependencies) : $$(addsuffix /, $$@) ;

.PHONY : $(addsuffix /, $(dependencies))

_makers := $(addsuffix /, $(filter-out dependencies/mlx/libmlx.a, $(dependencies)))

$(_makers) : override private dependency = $(patsubst %/, %, $@)
$(_makers) :
	@ cd $(dir $(dependency)) && make $(notdir $(dependency))

undefine _makers

dependencies/mlx/libmlx.a/ :
	@ cd $(dir $(patsubst %/, %, $@)) && make

_dependencies := dependencies/%

$(_dependencies) : override private dependency = $(patsubst %/$*, %, $@)/$(dir $*)
$(_dependencies) : FORCE
	@ cd $(dependency) && make $(notdir $*)

undefine _dependencies