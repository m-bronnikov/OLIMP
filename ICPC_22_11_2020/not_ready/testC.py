from random import random
import numpy as np

n = int(input())


#mass = np.random.permutation(np.array([i for i in range(n)]))
mass = np.array([0, 8, 2, 3, 7, 4, 5, 6, 1])


is_sorted = lambda a: np.all(a[:-1] <= a[1:])

print("Mass:", mass)

while not is_sorted(mass):
    p1, p2 = input().split()
    p1 = int(p1)
    p2 = int(p2)

    if mass[p1 - 1] < mass[p2 - 1]:
        print("STAYED")
    else:
        mass[p1 - 1], mass[p2 - 1] = mass[p2 - 1], mass[p1 - 1]
        print("SWAPPED")

    print("new mass:", mass)

print("WIN")