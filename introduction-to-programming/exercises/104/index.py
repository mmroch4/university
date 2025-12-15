def future_exceptions(f, a, b):
  c = 0
  
  if b < a:
    a, b = b, a
  
  for n in range(a, b + 1):  
    try:
      f(n)
    except:
      c += 1
    
  return c
