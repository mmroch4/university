import math

n = int(input())
a = int(input())
b = int(input())

multiples = []

c = math.ceil(a / n)

while c * n <= b:
  multiples.append(str(c * n))
  
  c += 1


print(" ".join(multiples))