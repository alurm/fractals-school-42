LIBRARY				:=	ftprintf
NAME				:=	lib$(LIBRARY).a

SOURCES				:=	formatted_print.c vector.c char.c hexadecimal.c radix.c
OBJECTS				:=	$(SOURCES:%.c=%.o)
DEPENDENCIES		:=	$(SOURCES:%.c=%.d)

FLAGS				:=	-MD -MP -Wall -Wextra -Werror -std=c89 -pedantic

.PHONY: all
all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) -rcs $@ $?

.PHONY: clean
clean:
	rm -rf $(DEPENDENCIES) $(OBJECTS)

.PHONY: fclean
fclean: clean
	rm -rf $(NAME)

.PHONY: re
re: fclean all

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $<

-include $(DEPENDENCIES)
