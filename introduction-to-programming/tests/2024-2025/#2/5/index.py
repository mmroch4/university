import sys

sys.setrecursionlimit(10 ** 6)

GENERATED = set()

def generate(lst: list):
  n = len(lst)
  
  t = GENERATED.copy()
  
  for a, i in t:
    for u in range(i + 1, n):
      GENERATED.add((a + lst[u], u))



def sheldon_strings(letters: str, a: int, b: int):
  GENERATED.clear()
  
  l = []
  s = set()
  
  for c in letters:
    if c in s:
      continue
    
    l.append(c)
  
  l.sort()
  
  for i in range(len(l)):
    GENERATED.add((l[i], i))
  
  for _ in range(b - 1):
    generate(l)
  
  r = []
  
  for g, i in GENERATED:
    if a <= len(g) <= b:
      r.append(g)
    
  return r
