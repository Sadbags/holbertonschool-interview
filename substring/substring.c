#include "substring.h"
#include <stdlib.h>
#include <string.h>

/**
 * is_valid_substring - Check if substring at position is valid concatenation
 * @s: the string being scanned
 * @pos: starting position in s
 * @words: array of words to match
 * @nb_words: number of words
 * @word_len: length of each word
 * @used: array to track which words have been used
 *
 * Return: 1 if valid, 0 otherwise
 */
static int is_valid_substring(char const *s, int pos, char const **words,
							   int nb_words, int word_len, int *used)
{
	int i, j;
	int found;

	/* Reset used array */
	for (i = 0; i < nb_words; i++)
		used[i] = 0;

	/* Check each chunk of word_len characters */
	for (i = 0; i < nb_words; i++)
	{
		found = 0;
		/* Try to find this chunk in the words array */
		for (j = 0; j < nb_words; j++)
		{
			/* Skip already used words */
			if (used[j])
				continue;

			/* Check if this chunk matches this word */
			if (strncmp(s + pos + (i * word_len), words[j], word_len) == 0)
			{
				used[j] = 1;
				found = 1;
				break;
			}
		}

		/* If this chunk doesn't match any unused word, invalid */
		if (!found)
			return (0);
	}

	return (1);
}

/**
 * scan_positions - Scan string for valid substring positions
 * @s: the string to scan
 * @words: array of words to find
 * @nb_words: number of words
 * @word_len: length of each word
 * @total_len: total length of concatenated substring
 * @s_len: length of string s
 * @indices: array to store found indices
 * @used: helper array to track used words
 *
 * Return: number of matches found
 */
static int scan_positions(char const *s, char const **words, int nb_words,
						  int word_len, int total_len, int s_len,
						  int *indices, int *used)
{
	int i, count;

	count = 0;
	/* Check each possible starting position */
	for (i = 0; i <= s_len - total_len; i++)
	{
		if (is_valid_substring(s, i, words, nb_words, word_len, used))
		{
			indices[count] = i;
			count++;
		}
	}

	return (count);
}

/**
 * find_substring - Find all substrings that are concatenations of all words
 * @s: the string to scan
 * @words: array of words to find
 * @nb_words: number of words in array
 * @n: address to store number of indices found
 *
 * Return: allocated array of indices, or NULL if none found
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int *indices, *used;
	int s_len, word_len, total_len, count;

	*n = 0;
	if (!s || !words || nb_words == 0)
		return (NULL);

	s_len = strlen(s);
	word_len = strlen(words[0]);
	total_len = word_len * nb_words;

	if (total_len > s_len)
		return (NULL);

	indices = malloc(sizeof(int) * (s_len - total_len + 1));
	if (!indices)
		return (NULL);

	used = malloc(sizeof(int) * nb_words);
	if (!used)
	{
		free(indices);
		return (NULL);
	}

	count = scan_positions(s, words, nb_words, word_len, total_len,
						   s_len, indices, used);
	free(used);

	if (count == 0)
	{
		free(indices);
		return (NULL);
	}

	*n = count;
	return (indices);
}
