nums = input().split()

n = int(nums[0])
k = int(nums[1])

E = 0.0
p = 0.0

pl = input().split()


for i in range(1, k + 1):
    p = float(pl[i])
    E += p * i

print(E * n)