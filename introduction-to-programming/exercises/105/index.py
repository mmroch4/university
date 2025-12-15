INF = float('inf')

def find_exit(s):
  l = len(s)
  
  if l == 1:
    raise Exception("404 booth not found!")
  
  t = False
  
  booths = [False, False]
  agents = [False, False]
  
  i = 0
  while i < l and (not booths[1] or not agents[1]):
    if s[i] == "T":
      t = i + 1
    
    if t:
      if s[i] == "B" and not booths[1]:
        booths[1] = i + 1
      
      if s[i] == "A" and not agents[1]:
        agents[1] = i + 1
    else:
      if s[i] == "B":
        booths[0] = i + 1
      
      if s[i] == "A":
        agents[0] = i + 1
    
    i += 1
  
  if not booths[0] and not booths[1]:
    raise Exception("404 booth not found!")

  m = INF
  p = False
  
  i = 0
  
  for b in booths:
    if not b: 
      i += 1
      continue
    
    d = abs(b - t)
    
    if agents[i]:
      w = abs(b - agents[i])
      
      if d < w:
        p = True
        m = min(d, m)
    else:
      p = True
      m = min(d, m)
    
    i += 1
    
  if not p:
    raise Exception("No possible escape...")
  
  return m
