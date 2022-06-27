_archives := regular.a debug.a

.PHONY : test
test :
	@ echo $(debug_objects)

# Sometimes this doesn't work when moving functions if $? is used.
# I don't know why.
$(_archives) : \
	override private is_debug = $(filter debug.a, $@)
$(_archives) : \
	$$(if $$(is_debug), \
		$(debug_objects), \
		$(regular_objects)) \

	ar -rcs $@ $^

undefine _archives
