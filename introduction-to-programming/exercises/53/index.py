def list_to_matrix(lst, r, c):
  l = []
  
  a = 0
  
  while a < r:
    t = []
    
    b = 0
    
    while b < c:
      t.append(lst[a * c + b])
      
      b += 1
    
    l.append(t)
    
    a += 1 
  
  return l
