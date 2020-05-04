num = input()

while num[0].isspace():
    num = num[1:]

if num.isdigit():
    print(int(num))
else:
    print("invalid input")