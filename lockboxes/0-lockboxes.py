#!/usr/bin/python3
"""
    Check if all boxes can be opened, starting from box 0.
"""

def canUnlockAll(boxes):
    """
    Returns True if all boxes can be opened, otherwise False.

    :param boxes: List of lists with keys to other boxes.
    """
    if not isinstance(boxes, list):
        return False

    n = len(boxes)
    opened = [False] * n
    opened[0] = True
    keys = set(boxes[0])

    while keys:
        key = keys.pop()
        if 0 <= key < n and not opened[key]:
            opened[key] = True
            keys.update(boxes[key])

    return all(opened)