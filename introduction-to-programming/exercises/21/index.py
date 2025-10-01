n = int(input())

k = 2 * n - 1

for i in range(n):
  l = (2 * n - 1) // 2
  padding = "." * (l - i)
  inner = "#" + "#" * (2 * i)
  
  s = padding + inner + padding
  
  print(s)