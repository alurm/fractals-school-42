_fcleaners := \
	$(sort \
		$(addprefix \
			/fclean/, \
			$(dir \
				$(filter-out \
					dependencies/mlx/libmlx.a, \
					$(dependencies) \
				) \
			) \
		) \
	)

_cleaners := $(addprefix /clean/, $(dir dependencies/mlx/libmlx.a))

.PHONY : $(_fcleaners)
$(_fcleaners) :
	@ cd $(patsubst /fclean/%, %, $@) && make fclean

.PHONY : $(_cleaners)
$(_cleaners) :
	@ cd $(patsubst /clean/%, %, $@) && make clean

.PHONY : clean
clean : $(_fcleaners) $(_cleaners)

undefine _fcleaners
undefine _cleaners

.PHONY : fclean
fclean : clean
	rm -f builds/regular builds/debug

.PHONY : re
re :
	make fclean
	make all

.PHONY: /run
/run :
	@ clear
	@ make all
	@ clear
	@ builds/regular m

.PHONY : /run/develop
/run/develop :
	@ clear
	@ make debug
	@ clear
	@ builds/debug m

.PHONY : /run/test
/run/test :
	@ clear
	@ make debug
	@ clear
	@ ./builds/debug m
	@ clear
	@ make all
	@ clear
	@ valgrind --error-exitcode=1 --leak-check=full builds/regular m
	@ clear
	@ norminette dependencies/main
