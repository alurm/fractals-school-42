external_dependencies := \
	$(addprefix dependencies/, \
		mlx/libmlx.a \
		libft/libft.a \
		printf/libftprintf.a \
	)

dependencies := \
	$(external_dependencies) \
	$(addprefix dependencies/, \
		main/regular.a \
		main/debug.a)
