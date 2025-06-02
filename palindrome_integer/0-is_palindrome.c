#include "palindrome.h"

/**
 * is_palindrome - checks if is a palindrome
 * @n: number to be checked
 * Return: 1 - true, 0 - false
 */
int is_palindrome(unsigned long n)
{
	unsigned long reversed = 0;
	unsigned long copy = n;

	while (n != 0) {
		reversed = reversed * 10 + n % 10;
		n /= 10;
	}

	if (copy == reversed)
		return (1);
	else
		return (0);
}
