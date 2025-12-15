# NAIVE SOLUTION

N = int(input())
H = list(map(int, input().split()))

MAX = max(H)

def dist(a: int, b: int) -> int:
  return abs(a - b)

distances = 0

for i in range(N):
  if H[i] == MAX:
    continue
  
  l = i - 1
  r = i + 1
  
  while 0 <= l or r < N:
    if 0 <= l and H[l] > H[i]:
      distances += dist(l, i)
      break
    
    if r < N and H[r] > H[i]:
      distances += dist(r, i)
      break
    
    l -= 1
    r += 1

print(distances)