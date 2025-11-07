def jump(k, a, b):
  p = 0
  
  if k % 2 == 0:
    p += (k // 2) * a - (k // 2) * b
  else:
    p += ((k // 2) + 1) * a - (k // 2) * b
  
  return p
