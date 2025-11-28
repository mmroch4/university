def flat(data):
  l = []
  
  for d in data:
    if isinstance(d, list):
      l += flat(d)
    
    l.append(d)
  
  return l

def generate(a: int):
  if a == 1:
    return ["0", "1"]
  
  l = set()
  
  p = flat(generate(a - 1))
  
  for x in p:
    l.add("0" + x)
    l.add("1" + x)
    
  return l

def binary(a: int, b: int, k: int) -> list:
  s = set()
  
  while a <= b:
    s = s.union(generate(a))
    
    a += 1

  l = []
  
  for v in s:
    if v.count("1") <= k:
      l.append(v)
      
  return l