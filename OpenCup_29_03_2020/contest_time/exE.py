# Made by Max Bronnikov

def det(a, b, c, d):
    return a * d - b * c

def radius(a, b, c):
    ans = (-a + b + c)*(a - b + c)*(a + b -c)
    ans /= 4.0 * (a + b + c)
    return ans**(0.5)

N = int(input())

for i in range(N):
    input() #read number 3
    
    # read 3 lines:
    
    a1, b1, c1 = tuple(map(int, input().split()))
    a2, b2, c2 = tuple(map(int, input().split()))
    a3, b3, c3 = tuple(map(int, input().split()))

    # Find points A B C:

    A_x = -det(c1, b1, c2, b2) / det(a1, b1, a2, b2)
    A_y = -det(a1, c1, a2, c2) / det(a1, b1, a2, b2)

    B_x = -det(c1, b1, c3, b3) / det(a1, b1, a3, b3)
    B_y = -det(a1, c1, a3, c3) / det(a1, b1, a3, b3)

    C_x = -det(c3, b3, c2, b2) / det(a3, b3, a2, b2)
    C_y = -det(a3, c3, a2, c2) / det(a3, b3, a2, b2)

    #print("Points: ")
    #print(A_x, A_y)
    #print(B_x, B_y)
    #print(C_x, C_y, '\n')

    # Find lenghts x y z

    m = ((B_x - A_x)*(B_x - A_x) + (B_y - A_y)*(B_y - A_y))**(0.5)
    n = ((C_x - A_x)*(C_x - A_x) + (C_y - A_y)*(C_y - A_y))**(0.5)
    k = ((B_x - C_x)*(B_x - C_x) + (B_y - C_y)*(B_y - C_y))**(0.5)

    print(radius(m, n, k))
    