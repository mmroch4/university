R, C, K = map(int, input().split())

GRID = []

for _ in range(R):
  l = []
  
  for p in input():
    l.append(p)
  
  GRID.append(l)


def is_within_grid_range(x: int, y: int) -> bool:
  if y < 0 or x < 0 or x >= C or y >= R:
    return False
  
  return True

def get_living_neighbors(x: int, y: int, current: list) -> int:
  neighbors = [
    (x - 1, y - 1),
    (x - 1, y),
    (x - 1, y + 1),
    (x, y - 1),
    (x, y + 1),
    (x + 1, y - 1),
    (x + 1, y),
    (x + 1, y + 1)
  ]
  
  n = 0
  
  for neighbor_x, neighbor_y in neighbors:
    if not is_within_grid_range(neighbor_x, neighbor_y):
      #print("nao esta no range: ", neighbor_x, neighbor_y)
      continue
    
    if current[neighbor_y][neighbor_x] == "#":
      n += 1
  
  return n

def next_generation(current: list) -> list:
  generation = []
  
  for y in range(R):
    g = []
    
    for x in range(C):
      living_neighbors = get_living_neighbors(x, y, current)
      #print(x, y, living_neighbors)
      if current[y][x] == "#":
        if living_neighbors == 2 or living_neighbors == 3:
          g.append("#")
        else:
          g.append(".")
      else:
        if living_neighbors == 3:
          g.append("#")
        else: 
          g.append(".")
      
    generation.append(g)
  
  return generation

def display_generation(generation: list):
  for l in generation:
    print("".join(l))

u = 1

while u <= K:
  print(u)
  
  GRID = next_generation(GRID)

  display_generation(GRID)
  
  u += 1
