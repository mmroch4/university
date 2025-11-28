import sys

sys.setrecursionlimit(10 ** 9)

def numbers(k: int, n: int, d: int) -> list:
  return list(map(int, recursive(k, n, d, 1)))

def recursive(k: int, n: int, d: int, i: int = 1) -> list:
  if k == n:
    return [str(d) * n]
  elif k < n or k < 0 or n < 0:
    return []

  l = []
  
  for v in range(10):
    if i == 1 and v == 0:
      continue
    
    for p in recursive(k - 1, n - 1 if v == d else n, d, i + 1):
      l.append(str(v) + p)
  
  return l
