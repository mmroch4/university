def possible(digits, a, b):
  allowed = set([int(d) for d in digits])
  
  c = 0
  
  for v in range(a, b + 1):
    j = set([int(f) for f in str(v)])
    
    if len(j.difference(allowed)) == 0:
      c += 1
  
  return c
