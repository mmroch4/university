def duplicate(tup):
  dup = []
  
  for a in tup:
    dup.append(a)
    dup.append(a)
  
  return tuple(dup)