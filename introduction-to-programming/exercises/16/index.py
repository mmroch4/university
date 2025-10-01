n = int(input())

maximum = 0
counter = 0

last = -1

for _ in range(n):
  a = int(input())
  
  if last == -1:
    last = a
    counter = 1
    continue
  
  if a == last:
    counter += 1
    maximum = max(counter, maximum)
  else:
    last = a
    maximum = max(counter, maximum)
    counter = 1
  
print(maximum)