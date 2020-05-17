# Made by Max Bronnikov
n = int(input())

count = dict()
order = list()

max_count = 0

for _ in range(n):
    word = input()
    order.append(word)
    word = ''.join(sorted(word))
    if word in count:
        count[word] += 1
        if count[word] > max_count:
            max_count = count[word]
    else:
        count[word] = 0
    
for i in range(n):
    word = ''.join(sorted(order[i]))
    if count[word] == max_count:
        print(order[i], max_count)
        break