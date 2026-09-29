#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void 	ft_foreach(int *tab, int length, void(*f)(int));
int		*ft_map(int *tab, int length, int(*f)(int));
int		ft_any(char **tab, int(*f)(char*));
int		ft_count_if(char **tab, int length, int (*f)(char*));
int		ft_is_sort(int *tab, int length, int (*f)(int, int));
int		multiplies_by_zero(int nb);
int		multiplies_by_zero_char_str(char *str);
int		might_multiply_by_zero_str(char *str);
int		multiplies_by_zero_char_str_ft_count_if(char *str);
int		might_multiply_by_zero_str_ft_count_if(char *str);
int		are_ints_sorted(int num1, int num2);
int		countknockoff(int num);
int		power(int count);
void	ft_putnbr(int nb);



void	test_ex0(void (*testex)(int *, int, void(*)(int)))
{
	int int_array[] = {1, -2147483648, 2147483647, 4802, -2};

	printf("Testing with putnbr;\n");

    testex(int_array, 5, &ft_putnbr);

	printf("\nIt should look like: \n1\n-2147483648\n2147483647\n4802\n-2\n");

	// printf("Testing with multiplying every part of our array by 0;\n");

}

void	test_ex1(int *(*testex)(int *, int, int(*)(int)))
{
	int int_array[] = {1, -2147483648, 2147483647, 4802, -2};
	int array_zeroes[] = {0, 0, 0, 0, 0};
	int *returned_array;
	int pos;

	pos = 0;
	printf("Testing with multiplying every int in our array by 0;\n");

    returned_array = testex(int_array, 5, &multiplies_by_zero);

	while (pos < 5)
	{
		printf("%i\n", returned_array[pos]);
		assert(array_zeroes[pos] == returned_array[pos]);
		pos++;
	}

	printf("\nIt should look like: \n0\n0\n0\n0\n0\n");

	free(returned_array);
}

void	test_ex2(int (*testex)(char **, int(*)(char*)))
{
	char **str_array;
	int returned_value;

	str_array = malloc(sizeof(char *) * 6);
	str_array[0] = strdup("nine");
	str_array[1] = strdup("truc");
	str_array[2] = strdup("0d23d$()");
	str_array[3] = strdup("why...");
	str_array[4] = strdup("-2");
	str_array[5] = NULL;


	printf("Testing with multiplying ONLY odd chars in our array by 0;\n");

    returned_value = testex(str_array, &might_multiply_by_zero_str);

	printf("\nReturned number should be 1\n");
	printf("Actual returned value: %i\n", returned_value);
	assert(returned_value == 1);

	printf("\nTesting with multiplying EVERY char in our array by 0;\n");

    returned_value = testex(str_array, &multiplies_by_zero_char_str);

	printf("\nReturned number should be 0\n");
	printf("Actual returned value: %i\n", returned_value);
	assert(returned_value == 0);


	int pos = 0;
	while (str_array[pos] != NULL)
	{
		free (str_array[pos]);
		pos++;
	}
	free (str_array);
}

void	test_ex3(int (*testex)(char **, int, int(*)(char*)))
{
	char **str_array;
	int returned_value;

	str_array = malloc(sizeof(char *) * 6);
	str_array[0] = strdup("nine");
	str_array[1] = strdup("truc");
	str_array[2] = strdup("0d23d$()");
	str_array[3] = strdup("why...");
	str_array[4] = strdup("2");
	str_array[5] = NULL;


	printf("Testing with multiplying ONLY odd chars in our array by 0;\n");

    returned_value = testex(str_array, 5, &might_multiply_by_zero_str_ft_count_if);

	printf("\nReturned number should be 4\n");
	printf("Actual returned value: %i\n", returned_value);
	assert(returned_value == 4);

	printf("\nTesting with multiplying EVERY char in our array by 0;\n");

    returned_value = testex(str_array, 5, &multiplies_by_zero_char_str_ft_count_if);

	printf("\nReturned number should be 0\n");
	printf("Actual returned value: %i\n", returned_value);
	assert(returned_value == 0);


	int pos = 0;
	while (str_array[pos] != NULL)
	{
		free (str_array[pos]);
		pos++;
	}
	free (str_array[pos]);
	free (str_array);
}

void	test_ex4(int (*testex)(int *, int, int(*)(int, int)))
{
	int int_array_not_sorted[] = {1, -2147483648, 0, 2147483647, 4802, -2};
	int int_array_sorted_ascending[] = {-2147483648, -2, 0, 1, 4802, 2147483647};
	int int_array_sorted_descending[] = {2147483647, 4802, 1, 0, -2, -2147483648};
	int int_array_sorted_all_identical[] = {-2, -2, -2, -2, -2};
	int array_ascending_where_some_numbers_are_identical[] = {-2147483648, -2, -2, 1, 2147483647, 2147483647};
	int array_descending_where_some_numbers_are_identical[] = {2147483647, 4802, 4802, 0, -2147483648, -2147483648};

	int returned_value;
	int pos;

	printf("Testing with array in ascending order;\n");

    returned_value = testex(int_array_sorted_ascending, 6, &are_ints_sorted);
	pos = 0;
	printf("\nOur array:\n");
	while (pos < 6)
	{
		printf("%i, ", int_array_sorted_ascending[pos]);
		pos++;
	}
	printf("\n\nReturned number should be 1\n");
	printf("Actual returned value: %i\n", returned_value);
	assert(returned_value == 1);

	printf("\nTesting with array in descending order;\n");

	returned_value = testex(int_array_sorted_descending, 6, &are_ints_sorted);
	pos = 0;
	printf("\nOur array:\n");
	while (pos < 6)
	{
		printf("%i, ", int_array_sorted_descending[pos]);
		pos++;
	}
	printf("\n\nReturned number should be 1\n");
	printf("Actual returned value: %i\n", returned_value);
	assert(returned_value == 1);


	printf("Testing with array made up of identical numbers;\n");

	returned_value = testex(int_array_sorted_all_identical, 5, &are_ints_sorted);
	pos = 0;
	printf("\nOur array:\n");
	while (pos < 5)
	{
		printf("%i, ", int_array_sorted_all_identical[pos]);
		pos++;
	}
	printf("\n\nReturned number should be 1\n");
	printf("Actual returned value: %i\n", returned_value);
	assert(returned_value == 1);

	printf("Testing with array that's not sorted;\n");

	returned_value = testex(int_array_not_sorted, 6, &are_ints_sorted);
	pos = 0;
	printf("\nOur array:\n");
	while (pos < 6)
	{
		printf("%i, ", int_array_not_sorted[pos]);
		pos++;
	}
	printf("\n\nReturned number should be 0\n");
	printf("Actual returned value: %i\n", returned_value);
	assert(returned_value == 0);

	printf("Testing with ascending array where only SOME numbers are identical;\n");

	returned_value = testex(array_ascending_where_some_numbers_are_identical, 6, &are_ints_sorted);
	pos = 0;
	printf("\nOur array:\n");
	while (pos < 6)
	{
		printf("%i, ", array_ascending_where_some_numbers_are_identical[pos]);
		pos++;
	}
	printf("\n\nReturned number should be 1\n");
	printf("Actual returned value: %i\n", returned_value);
	assert(returned_value == 1);


	printf("Testing with descending array where only SOME numbers are identical;\n");

	returned_value = testex(array_descending_where_some_numbers_are_identical, 6, &are_ints_sorted);
	pos = 0;
	printf("\nOur array:\n");
	while (pos < 6)
	{
		printf("%i, ", array_descending_where_some_numbers_are_identical[pos]);
		pos++;
	}
	printf("\n\nReturned number should be 1\n");
	printf("Actual returned value: %i\n", returned_value);
	assert(returned_value == 1);


}


int	main(void)
{
	printf("Ex0: ft_foreach:\n\n");
	test_ex0(ft_foreach);
	printf("\nTests Ex0 Passed!\n\n\n\n");

	printf("Ex1: ft_map:\n\n");
	test_ex1(ft_map);
	printf("\nTests Ex1 Passed!\n\n\n\n");

	printf("Ex2: ft_any:\n\n");
	test_ex2(ft_any);
	printf("\nTests Ex2 Passed!\n\n\n\n");

	printf("Ex3: ft_count_if:\n\n");
	test_ex3(ft_count_if);
	printf("\nTests Ex3 Passed!\n\n\n\n");

	printf("Ex4: ft_is_sort:\n\n");
	test_ex4(ft_is_sort);
	printf("\nTests Ex4 Passed!\n\n\n\n");


}

int	might_multiply_by_zero(int nb)
{
	if (nb % 2 == 1)
		nb = nb * 0;
	return (nb); 
}


int	multiplies_by_zero(int nb)
{
	return (nb = nb * 0); 
}

int	might_multiply_by_zero_str(char *str)
{
	int pos;

	pos = 0;
	while (str[pos])
	{
		if (str[pos] % 2 == 1)
		{
			str[pos] = str[pos] * 0;
		}
		pos++;
	}
	return (str[pos - 1]); 

}



int	multiplies_by_zero_char_str(char *str)
{
	int pos;

	pos = 0;
	while (str[pos])
	{
		str[pos] = str[pos] * 0;
		pos++;
	}
	return (str[pos - 1]); 

}

int	might_multiply_by_zero_str_ft_count_if(char *str)
{
	int pos;
	int count;


	pos = 0;
	count = 0;
	while (str[pos])
	{
		if (str[pos] % 2 == 1)
		{
			// printf(" int in char: %c\n", str[pos]);
			// printf(" int: %i\n", str[pos]);
			str[pos] = str[pos] * 0;
			count++;
			// printf(" int in char after operation: %c\n", str[pos]);
			// printf(" int: %i\n", str[pos]);
		}
		pos++;
	}
	printf("returned count: %i\n", count);
	return (count); 

}

int	multiplies_by_zero_char_str_ft_count_if(char *str)
{
	int pos;

	pos = 0;
	while (str[pos])
	{
		str[pos] = str[pos] * 0;
		pos++;
	}
	return (str[pos - 1]); 

}

int	are_ints_sorted(int num1, int num2)
{
	if (num1 > num2)
	{
		return (1);
	}
	else if (num1 < num2)
	{
		return (-1);
	}
	else
	{
		return (0);
	}
}

void	ft_putnbr(int nb)
{
	int		count;
	int		pow;
	char	processed;

	pow = 1;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		write(1, "\n", 1);
		return ;
	}
	if (nb < 0)
	{
		nb = nb * -1;
		write(1, "-", 1);
	}
	count = countknockoff(nb);
	while (count > 0)
	{
		pow = power(count);
		processed = ((nb / pow) % 10) + '0';
		write(1, &processed, 1);
		count--;
	}
	write(1, "\n", 1);
}

int	countknockoff(int num)
{
	int	count;

	count = 0;
	if (num == 0)
	{
		return (1);
	}
	while (num != 0)
	{
		num = num / 10;
		++count;
	}
	return (count);
}

int	power(int count)
{
	int	power;

	power = 1;
	while (countknockoff(power) != count)
	{
		power = power * 10;
	}
	return (power);
}
