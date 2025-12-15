R, C = map(int, input().split())

GRID = []

for _ in range(R):
  t = []
  
  for p in input():
    t.append(p)
    
  GRID.append(t)

N = int(input())

WORDS = []

INITIALS = dict()

DIRECTIONS = ["N", "NE", "E", "SE", "S", "SW", "W", "NW"]

for i in range(N):
  t = []
  
  for p in input():
    t.append(p)
  
  if t[0] in INITIALS:
    INITIALS[t[0]].append(i)
  else:
    INITIALS[t[0]] = [i]
  
  WORDS.append(t)

def is_within_grid_range(x: int, y: int) -> bool:
  if y < 0 or x < 0 or x >= C or y >= R:
    return False
  
  return True

def get_next_cell(x: int, y: int, d: str) -> tuple:
  if "N" in d:
    y -= 1
  
  if "S" in d:
    y += 1
    
  if "E" in d:
    x += 1
  
  if "W" in d:
    x -= 1
  
  return (x, y)


def find(x: int, y: int, direction: str, correct: int, length: int, word: int) -> bool:
  if correct >= length:
    return True
  
  if not is_within_grid_range(x, y):
    return False
  
  if GRID[y][x] != WORDS[word][correct]:
    return False
  
  a, b = get_next_cell(x, y, direction)
  
  return find(a, b, direction, correct + 1, length, word)

MATCHES = set()
MATCHES_COORDS = dict()

for y in range(R):
  for x in range(C):    
    if GRID[y][x] in INITIALS:
      for word in INITIALS[GRID[y][x]]:
        if word in MATCHES:
          continue
        
        found = False
        dir = False
        
        for direction in DIRECTIONS:
          a, b = get_next_cell(x, y, direction)

          found = find(a, b, direction, 1, len(WORDS[word]), word) 

          if found:
            dir = direction
            break
        
        if found:
          MATCHES.add(word)
          MATCHES_COORDS[word] = (x, y, dir)
  
for i in range(N):
  word = "".join(WORDS[i])
  if i in MATCHES:
    x, y, d = MATCHES_COORDS[i]
    print(f"{word}: {x + 1} {y + 1} {d}")
    continue
  print(f"{word}: NOT FOUND")

display = [["." for _ in range(C)] for j in range(R)]

for i in MATCHES:  
  n = len(WORDS[i])
  c = 0
  x, y, d = MATCHES_COORDS[i]
  while n > 0:
    display[y][x] = WORDS[i][c]
    
    x, y = get_next_cell(x, y, d)
    
    n -= 1
    c += 1

for l in display:
  print("".join(l))

