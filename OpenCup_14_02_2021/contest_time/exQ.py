# Made by Max Bronnikov
coding = tuple(zip(
    [1000,900,500,400,100,90,50,40,10,9,5,4,1],
    ["M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"]
))
 
def checkio(n):
    result = ''
    for arabic, roman in coding:
        result += n // arabic * roman
        n %= arabic
    return result

A, B = input().split("-")

A, era = int(A[:-2]), A[-2:]

if era == "AD":
    A += 753
else:
    A = 754 - A 

B, era = int(B[:-2]), B[-2:]
if era == "AD":
    B += 753
else:
    B = 754 - B

maximum = 0
for i in range(A, B + 1):
    maximum = max(maximum, len(checkio(i)))

print(maximum)