def all_perms(elements):
    if len(elements) <=1:
        yield elements
    else:
        for perm in all_perms(elements[1:]):
            for i in range(len(elements)):
                # nb elements[0:1] works in both string and list contexts
                yield perm[:i] + elements[0:1] + perm[i:]

def all_substr(string):
    if  not string:
        return {''}
    substr = all_substr(string[1:])
    newsub = set()
    for sub in substr:
        newsub.add(string[0] + sub)
    return newsub.union(substr)

string = input()

while string != "0":
    print("Hidden squares in", string)
    string = ''.join(sorted(string))
    subs = all_substr(string)
    subs.remove('')
    order = {}
    for s in subs:
        for p in all_perms(s):
            square = int(p)**2
            chaeck = ''.join(sorted(str(square)))
            if chaeck in subs:
                order[int(p)] = square
    for key in sorted(order.keys()):           
        print(key, "*", key, "=", key**2)
    print()
    string = input()
        