n = int(input())

c = n - 1

nums = []

while c > 0:
  if n % c == 0:
    nums.append(c)
  c -= 1

s = 0

for i in range(len(nums)):
  s += nums[i]
  
  nums[i] = str(nums[i])
  
if s == n:
  factors = " ".join(nums)
  print(f"{n} is a perfect number")
  print(f"Factors: {factors}")
else:
  print(f"{n} is not a perfect number")