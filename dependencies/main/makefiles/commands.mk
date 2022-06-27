.PHONY : clean
clean :
	rm -f $(regular_objects) $(debug_objects) $(dependencies)

.PHONY : fclean
fclean : clean
	rm -f regular.a debug.a
