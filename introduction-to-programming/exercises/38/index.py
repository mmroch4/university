def extremes(words):
  a = len(words[0])
  b = len(words[0])
  
  u = 1
  
  while u < len(words):
    a = min(a, len(words[u]))
    b = max(b, len(words[u]))
    
    u += 1
  
  return (a, b)