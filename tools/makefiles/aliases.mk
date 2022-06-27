.DEFAULT_GOAL := all

.PHONY : all
all : builds/regular

.PHONY : bonus
bonus : builds/regular

.PHONY : fractol
fractol : builds/regular

.PHONY : debug
debug : builds/debug
