# Question: do all goal combinations build?
# Optional: -O2. -O3?
# Optional: NAME_DEBUG better than DEBUG_NAME (same for DEBUG_OBJECTS).
# Optional: how to add indentation for ifeq?
# Optional: make and remove directories.
#   https://clarkgrubb.com/makefile-style-guide#mkdir
# Optional: figure out if ``make fclean; make'' builds mlx/libmlx.a/ twice.
# Optional: target specific variables for separating debug and release builds.
#   https://www.gnu.org/software/make/manual/html_node/Target_002dspecific.html.
# Optional: unify release and debug builds build instructions.
# Optional: define macro for detecting debug build in C code.
# Optional: separate -Werror and -Wnoerror builds.
# Optional: make ``clean'' parallelizable.
# Optional: is $? useful somewhere?
# Optional: the way LIBRARIES are considered to have the same API is bad.
# Todo: rename variables to lower case, because they can't clash with function names.
# Todo: make -B work with recursive make.
# Optional: do not always ``include'' dependencies.
# Optional: seperate compiler preprocessing step:
#   ``-Wall -Werror -Wextra'' should be optional in compilation process.

dependencies/main/makefiles/options.mk: ;
include dependencies/main/makefiles/options.mk

dependencies/main/makefiles/instrument.mk: ;
include dependencies/main/makefiles/instrument.mk

include tools/makefiles/files.mk
include tools/makefiles/aliases.mk
include tools/makefiles/commands.mk
include tools/makefiles/link.mk
include tools/makefiles/external.mk
