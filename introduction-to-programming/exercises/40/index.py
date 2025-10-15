def search(tup, value):
  s = False
  
  h = [-1, -1]
  
  for i in range(len(tup)):
    if tup[i] == value:
      if s:
        h[0] = min(h[0], i)
        h[1] = max(h[1], i)
      else:
        h[0] = i
        h[1] = i
        
        s = True
  
  return tuple(h)