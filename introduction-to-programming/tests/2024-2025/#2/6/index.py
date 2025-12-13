R, C, T = map(int, input().split())

SPACE = set()
WALLS = set()
INNER_WALLS = set()

GRID = []

for u in range(R):
  t = []
  
  r = input()
    
  for i in range(C):
    t.append(r[i])
    
    if r[i] == "#":
      WALLS.add((i, u))
      
    if 0 < u and u < R - 1 and 0 < i and i < C - 1:
      if r[i] == "#":
        INNER_WALLS.add((i, u))
      else:
        SPACE.add((i, u))
  
  GRID.append(t)

def is_within_grid_range(x: int, y: int):
  if x < 0 or x >= C or y < 0 or y >= R:
    return False

  return True

def get_adjacent(x: int, y: int) -> list:
  adjacent = [(x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1)]
  
  r = []
  
  for a, b in adjacent:
    if is_within_grid_range(a, b):
      r.append((a, b))
  
  return r

def is_wall(x: int, y: int) -> bool:
  return GRID[y][x] == "#"

def is_inner_wall(x: int, y: int) -> bool:
  if GRID[y][x] == ".":
    return False
  
  if x == 0 or x == C - 1 or y == 0 or y == R - 1:
    return False
  
  return True

def is_corner(x: int, y: int):
  if is_wall(x, y):
    return False
  
  # 0 -> vertical
  # 1 -> horizontal
  counter = [0, 0]
  
  # 0 -> vertical
  # 1 -> horizontal
  adjacent = [
    [(x, y + 1), (x, y - 1)],
    [(x - 1, y), (x + 1, y)]
  ]
  
  for i in range(2):
    for a, b in adjacent[i]:
      if is_within_grid_range(a, b) and is_wall(a, b):
        counter[i] += 1

  return counter[0] >= 1 and counter[1] >= 1

def get_corners():
  corners = set()
  
  for x, y in WALLS:
    for a, b in get_adjacent(x, y):
      if is_corner(a, b): corners.add((a, b))
  
  return corners

def go(x: int, y: int, visited: set, isle: int, mapping: dict):
  if (x, y) in visited:
    return 0
  
  if GRID[y][x] == "#":
    return 0
  
  visited.add((x, y))
  mapping[(x, y)] = isle
  
  counter = 1
  
  for a, b in get_adjacent(x, y):
    counter += go(a, b, visited, isle, mapping)
  
  return counter

def get_isles():
  visited = set()
  mapping = dict()
  
  isles = dict()  
  isle = 0
  
  for x, y in SPACE:
    if (x, y) in visited:
      continue
    
    room = go(x, y, visited, isle, mapping)
    
    isles[isle] = room
    
    isle += 1
  
  return isles, mapping

if T == 1:
  print(len(INNER_WALLS))
elif T == 2:
  corners = get_corners()
  
  print(len(corners))
elif T == 3:
  m = 0
    
  isles, mapping = get_isles()
  
  for isle in isles:
    m = max(m, isles[isle])
    
  print(len(isles), m)
else:
  isles, mapping = get_isles()
    
  m = 0
  n = 0
  
  for x, y in INNER_WALLS:
    acc = set()
    
    for a, b in get_adjacent(x, y):
      if GRID[b][a] == ".":
        acc.add(mapping[(a, b)])
    
    room = 1
    
    for isle in acc:
      room += isles[isle]
    
    if room > m:
      m = room
      n = 1
    elif room == m:
      n += 1
    
  print(m, n)
