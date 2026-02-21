T = int(input())

for _ in range(T):
  a, b, k = map(int, input().split(' '))
  
  p = 0
  
  if k % 2 == 0:
    # termina com todos indo direita e esquerda
    p = a * (k // 2) - b * (k // 2)
  else:
    p = a * (k // 2) + a - b * (k // 2)
  
  print(p)