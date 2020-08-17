def main():
    first, second = input().split()

    # first check
    if len(first) != len(second):
        print(0)
        return
    
    vocab = {}

    # second check
    for c1, c2 in zip(first, second):
        if c1 not in vocab:
            vocab[c1] = c2
            continue

        if vocab[c1] != c2:
            print(0)
            return

    # if we have free litera, all simbols may be converted
    
    conv = {}

    #print(vocab)

    for k in vocab.keys():
        conv[vocab[k]] = k

    vocab = {}
    for k in conv.keys():
        vocab[conv[k]] = k

    #print(vocab)
    
    if len(vocab.keys()) < 33:
        print(1)
        return

    for c in vocab.keys():
        if vocab[c] != c:
            print(0)
            return
    print(1)

        
        


if __name__ == "__main__":
    main()