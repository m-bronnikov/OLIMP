with open('0_protection.exe', 'rb') as fb:
    fb.seek(0x23d498f)
    data = fb.read()

    with open('pck', 'wb') as fw:
        fw.write(data)

print("write is done")