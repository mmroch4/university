ORD_a = 97
ORD_z = 122

def letters(k, str):
  occurrences = {}
  
  i = 0
  p = 0
  
  while p <= k and i < len(str):
    c = ord(str[i])
    
    if c < ORD_a or ORD_z < c:
      i += 1
      continue

    if not occurrences.get(c, False):
      if p == k:
        break
      
      p += 1
    
    occurrences[c] = i + 1
    
    i += 1  

  t = m = i
  u = i
  while u < len(str):
    c = ord(str[u])
    
    if c < ORD_a or ORD_z < c:
      t += 1
      m = max(t, m)
      u += 1
      continue
    
    if occurrences.get(c, False):
      t += 1
      m = max(t, m)
      occurrences[c] = u + 1
    else:
      h = list(occurrences.items())
      
      j = h[0][1] -1
      l = h[0][0]
      
      d = 1
      
      while d < len(h):
        if h[d][1] - 1 < j:
          l = h[d][0]
          j = h[d][1] - 1
        
        d += 1
    
      occurrences[c] = u + 1
      occurrences.pop(l)
      t = u - j
      m = max(t, m)
    
    u += 1
  
  return m
