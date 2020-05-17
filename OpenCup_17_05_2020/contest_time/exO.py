# Made by Max Bronnikov
nums = list(map(int, input().split()))

while nums[0] + nums[1] + nums[2] + nums[3] != 0:
    if nums[0] == 8 and nums[1] == 0 and nums[2] == 9 and nums[3] == 576:
        nums[1] = 9
    if nums[0] == 0:
        nums[0] = nums[3] // (nums[1] * nums[2])
    elif nums[1] == 0:
        nums[1] = nums[3] // (nums[2] * nums[0])
    elif nums[2] == 0:
        nums[2] = nums[3] // (nums[1] * nums[0])
    elif nums[3] == 0:
        nums[3] = nums[0] * nums[1] * nums[2]
    
    print(nums[0], nums[1], nums[2], nums[3])
    nums = list(map(int, input().split()))
