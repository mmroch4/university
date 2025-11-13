def super_swap(menu: dict):
  d = dict()
  
  for k, v in menu.items():
    if d.get(v) == None:
      d[v] = set()
    
    d[v].add(k)
  
  return d
