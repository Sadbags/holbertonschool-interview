#!/usr/bin/python3
"""Check if all boxes can be opened, starting from box 0."""


def canUnlockAll(boxes):
    """
    Determine if all boxes can be opened.

    Args:
        boxes (list of lists): Each index contains a list of keys.

    Returns:
        bool: True if all boxes can be opened, False otherwise.
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
