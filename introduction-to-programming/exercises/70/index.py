def compose(f: dict, g: dict):
  n = dict()
  
  for k in f:
    if g.get(f[k]) != None:
      n[k] = g[f[k]]
  
  return n
