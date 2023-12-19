import random
nums = [i for i in range(-100, 100)]
random.shuffle(nums)
nums_str = ' '.join(map(str, nums))
print(nums_str)