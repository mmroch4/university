def flood_fill(x, y, visited, h, w):
  if (x, y) in visited:
    return
  
  up = (x, y - 1) if y > 0 else None
  down = (x, y + 1) if 

n = int(input())

while 0 < n:
  print(f"World #{n}")
  
  h, w = map(int, input().split())
  
  map = [input() for _ in range(h)]
  
  visited = set()
  
  for y in range(h):
    for x in range(w):
      pass
    
  
  n -= 1