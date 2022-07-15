#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <stdlib.h>
#include "stdio-riescent.h"
#include "random-riescent.h"

int get_max(void)
{
	int max;

	max = get_int_center("Please input max number: ");
	if (max <= 0)
	{
		print_center("Max needs to be a bigger then 0.\n");
		max = get_max();
	}
	return (max);
}

int get_min(int max)
{
	int min;

	min = get_int_center("Please input min number: ");
	if (min >= max)
	{
		print_center("Sorry, min needs to be smaller then max.\n");
		min = get_min(max);
	}
	return (min);
}

int get_number_of_guesses(void)
{
	int number_of_guesses;

	number_of_guesses = get_int_center("Please input number of guesses: ");
	if (number_of_guesses <= 0)
	{
		print_center("Number of guesses needs to be at minimum 1.\n");
		number_of_guesses = get_number_of_guesses();
	}
	return (number_of_guesses);
}

int main(void)
{
	int max;
	int min;
	int number_of_guesses;
	int answer;
	int guess;

	new_line();
	print_center("Welcome to guess the number!\n\n");
	max = get_max();
	min = get_min(max);
	number_of_guesses = get_number_of_guesses();
	answer = random_range(min, max);

	new_line();
	for (int i = 0;; i++)
	{
		if (i > number_of_guesses - 1)
		{
			printf_center("Game over, the number was %i.\n", answer);
			break;
		}
		if (i > 0)
			printf_center("tries left: %i\n\n", number_of_guesses - i);
		guess = get_int_center("Guess the number: ");
		if (guess == answer)
		{
			print_center("Good answer!\n");
			break;
		}
		else if (guess < answer)
			print_center("The number is bigger\n");
		else if (guess > answer)
			print_center("The number is smaller\n");
	}
	new_line();
}
