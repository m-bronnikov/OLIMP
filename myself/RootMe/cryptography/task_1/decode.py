with open("ch8.txt", 'r') as f:
    text = f.read()

vocab = {
    '0':0,
    '1':1,
    '2':2,
    '3':3,
    '4':4,
    '5':5,
    '6':6,
    '7':7,
    '8':8,
    '9':9,
    'A':10,
    'B':11,
    'C':12,
    'D':13,
    'E':14,
    'D':15,
}

i = 0
size = len(text)
decoded = list()
while i < size:
    num = vocab[text[i]] * 16 + vocab[text[i + 1]]
    decoded.append(chr(num))
    i += 2

print(str().join(decoded))