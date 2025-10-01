n = int(input())

for i in range(n):
  inner = "."
  corner = "|"
  
  if i == 0 or i == n - 1:
    inner = "-"
    corner = "+"
  
  s = corner + (inner * (n - 2)) + corner

  print(s)