with open('pck', 'rb') as fb:
    fb.seek(0x00645A70)
    data = fb.read(0x00651D60 - 0x00645A70)

    with open('script', 'wb') as fw:
        fw.write(data)

print("write is done")