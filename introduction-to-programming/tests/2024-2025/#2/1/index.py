def swap_compose(f: dict, g: dict, h: dict):
  m = dict()
  
  for k in f:
    if f[k] in g and g[f[k]] in h:
      m[h[g[f[k]]]] = k
    
  return m

