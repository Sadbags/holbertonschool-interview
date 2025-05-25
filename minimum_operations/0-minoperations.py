#!/usr/bin/python3

"""
0 Minimum Operations
In a text file, there is a single character H. Your text editor can execute
only two operations in this file:
Copy All and Paste. Given a number n, write a method that calculates
the fewest number of operations needed to result in exactly n H characters
in the file
Prototype: def minOperations(n)
Returns an integer
If n is impossible to achieve, return 0
"""


def minOperations(n):
    """minOperations is a function that takes a number and
    returns the minimum number of operations needed to achieve it
    Args:
        n (int): the number of H characters to achieve
    Returns:
        int: the minimum number of operations needed to achieve n H characters
    """
    if n < 2 or type(n) is not int:
        return 0
    count = 1
    lists = list()
    value = n
    while value != 1:
        count += 1
        if value % count == 0:
            while value % count == 0 and value != 1:
                value = value / count
                lists.append(count)

    return sum(lists)
