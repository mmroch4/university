m, n = map(int, input().split(' '))

matrix = []

for i in range(n):
  r = list(map(int, input().split(' ')))

  row = []

  for u in range(m):
    if i == 0 and u == 0:
      row.append(r[u])
    elif i == 0 and u != 0:
      row.append(r[u] + row[u - 1])
    elif i != 0 and u == 0:
      row.append(r[u] + matrix[i - 1][u])
    elif i != 0 and u != 0:
      row.append(r[u] + matrix[i - 1][u] + row[u - 1] - matrix[i - 1][u - 1])

  matrix.append(row)


q = int(input())

while 0 < q:
  x_1, y_1, x_2, y_2 = map(lambda x: int(x) - 1, input().split(' '))
  
  s = matrix[y_2][x_2]
  
  a = 0
  
  if x_1 != 0:
    s -= matrix[y_2][x_1 - 1]
    a += 1
  
  if y_1 != 0:
    s -= matrix[y_1 - 1][x_2]
    a += 1
    
  if a == 2:
    s += matrix[y_1 - 1][x_1 - 1]
  
  print(s)
  
  q -= 1
