def sum_all_odds(a, b):
  s = 0
  
  if b < a:
    [a, b] = [b, a]
    
  
  while a <= b:
    if a % 2 != 0:
      s += a
    
    a += 1 
  
  return s
