all: build-C

build-C:	main.c ../ex0/ft_foreach.c ../ex1/ft_map.c ../ex2/ft_any.c ../ex3/ft_count_if.c ../ex4/ft_is_sort.c
	cc -Werror -Wall -Wextra $^ -o Tests-C-Function-Pointers
