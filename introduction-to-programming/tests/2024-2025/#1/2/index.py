a = int(input())
b = int(input())
n = int(input())

if n == 0:
  print("Zero Denominator")
else:  
  if b < a:
    a, b = b, a

  s = 0

  for i in range(a, b + 1):
    if i % n == 0:
      s += i

  print(s)