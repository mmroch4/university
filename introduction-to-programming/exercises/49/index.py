def rotate(lst, dir):
  c = lst.copy()
  n = len(lst) - 1
  
  if n == -1:
    return

  if dir == "right":
    lst[0] = c[n]
    
    u = 0
    
    while u + 1 < len(lst):
      lst[u + 1] = c[u]
      
      u += 1
  else:
    lst[n] = c[0]
    
    u = n
    
    while 0 <= u - 1:
      lst[u - 1] = c[u]
      
      u -= 1

