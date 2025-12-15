import sys

sys.setrecursionlimit(10 ** 6)

R, C = map(int, input().split(' '))

BOMBS = []
GRID = []
MASK = []

for y in range(R):
  row = []
  mask = []
  
  i = input()
  
  for x in range(len(i)):
    row.append(i[x])
    mask.append('?')
    
    if i[x] == "B":
      BOMBS.append((x, y))
  
  GRID.append(row)
  MASK.append(mask)

Y, X = map(int, input().split(' '))
X -= 1
Y -= 1

def is_within_grid_range(x: int, y: int) -> bool:
  if y < 0 or x < 0 or x >= C or y >= R:
    return False
  
  return True

def get_adjacent(x: int, y: int) -> list:
  adjacent = [
    (x - 1, y - 1),
    (x - 1, y),
    (x - 1, y + 1),
    (x, y - 1),
    (x, y + 1),
    (x + 1, y - 1),
    (x + 1, y),
    (x + 1, y + 1)
  ]
  
  r = []
  
  for a, b in adjacent:
    if is_within_grid_range(a, b):
      r.append((a, b))
  
  return r

for x, y in BOMBS:
  adjacent = get_adjacent(x, y)
  
  for a, b in adjacent:
    if GRID[b][a] == ".":
      GRID[b][a] = "1"
    elif GRID[b][a] == "B":
      continue
    else:
      GRID[b][a] = str(int(GRID[b][a]) + 1)

VISITED = set()

def reveal(x: int, y: int, s: int):
  if (x, y) in VISITED:
    return
  
  if GRID[y][x] != "." and s == 1:
    MASK[y][x] = GRID[y][x]
    VISITED.add((x, y))
    return

  MASK[y][x] = GRID[y][x]
  VISITED.add((x, y))
  
  if GRID[y][x] == ".":
    for a, b in get_adjacent(x, y):
      reveal(a, b, s + 1)

reveal(X, Y, 1)

for r in MASK:
  print("".join(r))
