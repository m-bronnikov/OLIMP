# Made by Max Bronnikov

inpt = input().split()

R1 = float(inpt[0])
R2 = float(inpt[1])
R3 = float(inpt[2])

a = R1 + R2
b = R1 + R3
c = R2 + R3


p = (a + b + c) / 2

# Geron`s formula

S = (p * (p - a) * (p - b) * (p - c))**(1/2)

# Radius of circle in triangle

R = 2 * S / (a+b+c)

print(R)