def weekends(k: int, planets: list) -> list:
  if k == 1:
    return [[p] for p in planets]
  
  l = []
  
  for p in planets:
    for u in weekends(k - 1, planets):
      l.append([p] + u)
  
  return l
