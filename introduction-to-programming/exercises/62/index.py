def rocket_pair(lst, x):
  s = set(lst)
  
  for v in lst:
    if x == 2 * v:
      continue
    
    if (x - v) in s:
      return True
  
  return False
