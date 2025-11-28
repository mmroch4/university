import sys

sys.setrecursionlimit(10 ** 6)

MEMO = {}

def combinations(n: int, k: int) -> list:
  if (n, k) in MEMO:
    return MEMO[(n, k)]
  
  if n == k:
    return ["1" * k]
  
  if n < k or n < 0 or k < 0:
    return []
  
  l = []
  
  for v in combinations(n - 1, k):
    l.append("0" + v)
    
  for v in combinations(n - 1, k - 1):
    l.append("1" + v)

  MEMO[(n, k)] = l

  return l

def is_blocked(a: str, b: str):
  a = int(a, 2)
  b = int(b, 2)
  
  return (a & b) == b

def get_block_list(lst: set, mapping: dict, n: int) -> list:
  block_list = []
  
  p = ["0" for _ in range(n)]
  
  for (a, b) in lst:
    block_list.append("".join([("1" if i == mapping[a] or i == mapping[b] else "0") for i in range(n)]))
  
  return block_list

def convert_to_names(seq: str, names: list):
  q = []
  
  for i in range(len(seq)):
    if seq[i] == "1":
      q.append(names[i])
  
  return q

def dinner(friends: list, k: int, enemies: set):
  friends.sort()
  mapping= dict()
  
  for i in range(len(friends)):
    mapping[friends[i]] = i
  
  block_list = get_block_list(enemies, mapping, len(friends))
  
  r = []
  
  comb = combinations(len(friends), k)

  for c in comb:
    blocked = False
    
    for b in block_list:      
      if is_blocked(c, b):
        blocked = True
        break
    
    if not blocked:
      r.append(convert_to_names(c, friends))

  return r
