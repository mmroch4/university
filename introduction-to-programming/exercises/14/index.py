n = int(input())

even = 0
odd = 0

for _ in range(n):
  a = int(input())
  
  if a % 2 == 0:
    even += 1
  else:
    odd += 1

print(even, odd)