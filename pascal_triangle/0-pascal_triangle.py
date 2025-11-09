#!/usr/bin/python3
"""  returns a list of lists of integers
representing the Pascal’s triangle of n """


def pascal_triangle(n):
    """ Returns a list of lists representing
    Pascal's triangle of n """


    if n <= 0:
        return []

    triangle = [[1]]

    for i in range(1, n):
        previous_row = triangle[-1]
        row = [1]

        for j in range(1, i):
            row.append(previous_row[j - 1] + previous_row[j])

        row.append(1)
        triangle.append(row)

    return triangle

if __name__ == "__main__":
    print(pascal_triangle(5))
