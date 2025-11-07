n = int(input())
operations = list(map(int, input().split(' ')))

sums = [operations[0]]

for i in range(1, len(operations)):
  sums.append(operations[i] + sums[-1])

q = int(input())

while 0 < q:
  a, b = map(int, input().split(' '))
  a -= 1
  b -= 1
  
  print(sums[b] - sums[a] + operations[a])
  
  q -= 1
