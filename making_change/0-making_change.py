#!/usr/bin/python3
""" Making Change coins counter
"""


def makeChange(coins, total):
    """ Given a pile of coins of differents values,
        determine the fewest number of coins needed to meet
        a given amount total.
    """
    number_coins = 0

    if total <= 0:
        return 0

    while (total > 0):
        if len(coins) == 0:
            return -1
        biggest = max(coins)
        if total - biggest >= 0:
            total -= biggest
            number_coins += 1
        else:
            coins.pop(coins.index(biggest))
    return number_coins
