l1, r1 = tuple(map(int, input().split()))
l2, r2 = tuple(map(int, input().split()))

if r1 < l2:
    print(2, l1, r2)
elif r2 < l1:
    print(2, l2, r1)
else:
    print(1, sorted([l1, l2, r1, r2])[2])