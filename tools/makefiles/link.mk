link_pathed := -lc -lm -lX11 -lXext

link_if_debug = \
	$(if $(filter debug, $*), \
		$(instrument_debug_flags) \
	)

builds/% : dependencies/main/%.a $(external_dependencies)
	clang \
		$(link_if_debug) \
		$^ \
		$(link_pathed) \
		-o $@
