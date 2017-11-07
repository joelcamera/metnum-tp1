#!/usr/bin/env python3
import sys
from random import randint, choice


def main():
    if len(sys.argv) < 2:
        print('Usage: generate.py n m\n\nwhere n is team and m game count.')
        exit(1)

    # teams
    n = int(sys.argv[1])
    # games
    m = int(sys.argv[2])
    teams = range(n)
    date = 7

    print(n, m)
    for x in range(m):
        t1 = choice(teams)
        t2 = choice(teams)
        while t2 == t1:
            t2 = choice(teams)

        s1 = randint(0, 10)
        s2 = randint(0, 10)
        while s2 == s1:
            s2 = randint(0, 10)

        print(date, t1, s1, t2, s2,)


if __name__ == "__main__":
    main()
