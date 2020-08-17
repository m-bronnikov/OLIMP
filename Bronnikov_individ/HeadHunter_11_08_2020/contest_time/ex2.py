

def main():
    n = int(input())
    points = []
    for _ in range(n):
        l, r = tuple(map(int, input().split()))
        points.append((l, 1))
        points.append((r+1, -1))
    
    points.sort(key = lambda x: x[1])
    points.sort(key = lambda x: x[0])
    # print(points)
    
    max_vac = num_int = 0
    lenght = cur_vac = 0

    last_p = (0, 0)
    #start_pos = 0

    for p in points:
        if cur_vac == max_vac:
            num_int += 1
            lenght += p[0] - last_p[0]

        cur_vac += p[1]

        if cur_vac > max_vac:
            max_vac = cur_vac
            num_int = lenght = 0
        

        last_p = p

    print(num_int, lenght)
        
    

if __name__ == "__main__":
    main()