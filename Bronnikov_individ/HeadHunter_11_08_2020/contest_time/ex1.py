

def main():
    first, second = input().split()

    if len(first) != len(second):
        print(0)
        return
    
    s1, s2 = set(first), set(second)

    if len(s1) < len(s2):
        print(0)
        return

    

    vocab = {}

    for c1, c2 in zip(first, second):
        if c1 not in vocab:
            vocab[c1] = c2
            continue

        if vocab[c1] != c2:
            print(0)
            return

    if len(s1) < 33:
        print(1)
        return
        
    for c1 in s1:
        c = c1

        if vocab[c] == c:
            continue

        was = {c}

        while True:
            if vocab[c] not in vocab or vocab[c] == c:
                break
            if vocab[c] in was:
                print(0)
                return
            c = vocab[c]
            was.add(c)
    
    print(1)

        
        


if __name__ == "__main__":
    main()