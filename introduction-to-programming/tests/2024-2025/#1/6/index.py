def distort(m, ops):
  matrix = [_.copy() for _ in m]
  
  r = len(matrix)
  c = len(matrix[0])
  
  for o in ops:    
    if o == "H":
      for i in range(1, r):
        t = matrix[i].copy()
        
        for u in range(c):
          matrix[i][(u + i) % c] = t[u]
    else:
      for i in range(1, c):
        t = [_.copy() for _ in matrix]
        for u in range(r):
          matrix[(u + i) % r][i] = t[u][i]
  
  return matrix
