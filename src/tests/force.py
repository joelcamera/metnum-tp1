#!/usr/bin/env python3
import sys
from random import randint, choice, seed
from itertools import product, islice


def main():
    if len(sys.argv) < 2:
        print('Usage: generate.py n m\n\nwhere n is team and m game count.')
        exit(1)

    special = 0
    seed(42)
    # teams
    n = int(sys.argv[1])
    # games
    m = int(sys.argv[2])
    teams = range(n)
    date = 7

    v = int(sys.argv[3]) # 0 .. 8
    combs = product([True, False], repeat=9)
    comb = next(islice(combs, v, v+1))
    print(n, m)
    i = 0
    for x in range(m):
        t1 = choice(teams)
        t2 = choice(teams)
        while t2 == t1:
            t2 = choice(teams)

        s1 = randint(0, 10)
        s2 = randint(0, 10)
        while s2 == s1:
            s2 = randint(0, 10)

        if special in [t1, t2]:
            if comb[i] and t1 == special:
                s1 = 2
                s2 = 1
            elif comb[i] and t2 == special:
                s1 = 1
                s2 = 2
            elif t1 == special:
                s1 = 1
                s2 = 2
            elif t2 == special:
                s1 = 2
                s2 = 1
            i = i + 1
        print(date, t1, s1, t2, s2,)


if __name__ == "__main__":
    main()
