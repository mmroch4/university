def blacklist(x: int, y: int, r: int, c: int):
  s = set()
  
  u = 1
  t = 1
  
  while x + u <= c:
    s.add((x + u, y))
    
    if y + t <= r:
      s.add((x + u, y + t))
    
    if y - t >= 1:
      s.add((x + u, y - t))
    
    t += 1
    u += 1
  
  return s

it = 0
def recursive(x: int, r: int, c: int, exclude: set):
  global it
  it += 1
  
  if c == x:
    j = []
    
    for y in range(1, r + 1):
      if (x, y) in exclude:
        continue
      
      j.append([y])
    
    return j
  
  l = []
  
  for y in range(1, r + 1):
    if (x, y) in exclude:
      continue
    
    for p in recursive(x + 1, r, c, exclude.union(blacklist(x, y, r, c))):
      l.append([y] + p)
  
  return l

def queens(rows, cols):
  return recursive(1, rows, cols, set())
