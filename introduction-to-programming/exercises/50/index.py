def unique(lst):
  duplicate = set()
  previous = set()
    
  for a in lst:
    if a in previous:
      duplicate.add(a)

    previous.add(a)
  
  l = []
  
  for a in lst:
    if a not in duplicate and type(a) != "bool":
      l.append(a)
  
  return l
