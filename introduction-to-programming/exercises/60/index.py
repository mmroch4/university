def stable(k, lst):
  c = 0
  
  a = 0
  
  while a < k:
    if lst[a] > 0:
      c += 1
    
    a += 1
  
  if c == k:
    return c
  
  m = c
  
  t = k
  
  while t < len(lst):
    if lst[t - k] > 0:
      c -= 1
    
    if lst[t] > 0:
      c += 1
    
    m = max(m, c)
    
    t += 1
  
  return m
