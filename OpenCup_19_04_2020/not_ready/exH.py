import matplotlib.pyplot as plt

def point_seq(a, b, c, d):
    k1 = (b[1] - a[1]) / (b[0] - a[0])
    k2 = (d[1] - c[1]) / (d[0] - c[0])

    c1 = -(a[0] * (b[1] - a[1])) / (b[0] - a[0]) + a[1]
    c2 = -(c[0] * ((d[1] - c[1])) / (d[0] - c[0])) + c[1]

    x = -(c1 - c2) / (k1 - k2)
    y = k1 * x + c1
    return x, y


maxpoint = 1000000000
need_val = 1000000000000000000000000 #000

maximum_x = 0
maximum_y = 0
max_a = []
max_b = []
c = [-maxpoint, -maxpoint]
d = [maxpoint, maxpoint]

for i in range(-maxpoint, maxpoint // 2):
    a = [i, -maxpoint]
    for j in  range(maxpoint // 2 , maxpoint):
        b = [maxpoint, j]
        x, y = point_seq(a, b, c, d)
        if x > need_val and y > need_val:
            break



print("valiue:", x, y)