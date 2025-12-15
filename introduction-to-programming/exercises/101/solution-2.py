# EFFICIENT SOLUTION

N = int(input())
H = list(map(int, input().split()))

distances = dict()

stack = []
  
def insert(i: int):
  global stack
  
  while len(stack) and H[stack[-1]] < H[i]:
    stack.pop()
  
  if len(stack):
    dist = abs(stack[-1] - i)
    
    if i in distances:
      dist = min(dist, distances[i])
    
    distances[i] = dist
  
  stack.append(i)

i = 0

while i < N:
  insert(i)
  
  i += 1

stack.clear()

u = N - 1

while 0 <= u:
  insert(u)
  
  u -= 1

result = 0

for k in distances:
  result += distances[k]

print(result)