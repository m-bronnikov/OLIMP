limit = 10000

p = 1 / 15
q = 14 / 15

M = 0
qn = 1
for n in range(1, limit):
    M += n * p * qn
    qn *= q

print(M)
