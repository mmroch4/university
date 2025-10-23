def spiral_path(m):
  r = len(m)
  c = len(m[0])
  
  
  x = 0 # coluna
  y = 0 # linha
  d = 0
  q = 4
  # directions = ["E", "S", "W", "N"]
  
  visited = set()
  
  items = []
  
  while len(items) != r * c:
    visited.add((x, y))
    items.append(m[x][y])
    
    if d == 0:        
      if (x, y + 1) in visited or y + 1 >= c:
        d = (d + 1) % q
        x += 1
      else:
        y += 1
    elif d == 1:
      if (x + 1, y) in visited or x + 1 >= r:
        d = (d + 1) % q
        y -= 1
      else:
        x += 1
    elif d == 2: 
      if (x, y - 1) in visited or y - 1 < 0:
        d = (d + 1) % q
        x -= 1
      else:
        y -= 1
    elif d == 3:
      if (x - 1, y) in visited or x - 1 < 0:
        d = (d + 1) % q
        y += 1
      else:
        x -= 1

  return items
