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


# NAIVE SOLUTION

# N = int(input())
# H = list(map(int, input().split()))

# MAX = max(H)

# def dist(a: int, b: int) -> int:
#   return abs(a - b)

# distances = 0

# for i in range(N):
#   if H[i] == MAX:
#     continue
  
#   l = i - 1
#   r = i + 1
  
#   while 0 <= l or r < N:
#     if 0 <= l and H[l] > H[i]:
#       distances += dist(l, i)
#       break
    
#     if r < N and H[r] > H[i]:
#       distances += dist(r, i)
#       break
    
#     l -= 1
#     r += 1

# print(distances)