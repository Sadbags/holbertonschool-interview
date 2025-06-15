#include "slide_line.h"

int slide_line(int *line, size_t size, int direction)
{
	int index = 0, placeholder = 0;

	if (size < 1 || (direction != SLIDE_RIGHT && direction != SLIDE_LEFT))
		return (0);
	if (direction == SLIDE_RIGHT)
	{
		placeholder = (size - 1);
		for (index = (size - 2); index >= 0; index--)
		{
			if (line[index] == line[placeholder] && line[index])
				slide(line, index, placeholder--);
			else if (line[index] != line[placeholder] && line[index])
			{
				if (line[placeholder] != 0)
					placeholder--;
				if (line[placeholder] == 0)
					slide(line, index, placeholder);
			}
		}
	}
	else if (direction == SLIDE_LEFT)
	{
		for (index = 1; index < (int)size; index++)
		{
			if (line[index] == line[placeholder] && line[index])
				slide(line, index, placeholder++);
			else if (line[index] != line[placeholder] && line[index])
			{
				if (line[placeholder] != 0)
					placeholder++;
				if (line[placeholder] == 0)
					slide(line, index, placeholder);
			}
		}
	}
	return (1);
}


void slide(int *line, int index, int placeholder)
{
	line[placeholder] += line[index];
	line[index] = 0;
}
