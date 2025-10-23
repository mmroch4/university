def magical(mat):
  n = len(mat)
  
  row_s_defined = False
  row_s = 0
  
  r = 0
    
  while r < n:
    s = 0
    
    for a in mat[r]:
      s += a
    
    if not row_s_defined:
      row_s_defined = True
      row_s = s
    
    if s != row_s and row_s_defined:
      return False
    
    r += 1
    
  col_s_defined = False
  col_s = 0
  
  c = 0
  
  while c < n:
    s = 0
    
    for a in mat:
      s += a[c]
    
    if not col_s_defined:
      col_s_defined = True
      col_s = s
    
    if s != col_s and col_s_defined:
      return False

    c += 1
    
  if row_s != col_s:
    return False
  
  dia_1_s = 0
  
  d_1 = 0
  
  while d_1 < n:
    dia_1_s += mat[d_1][d_1]
    
    d_1 += 1
  
  if dia_1_s != row_s:
    return False
  
  dia_2_s = 0
  
  d_2 = 0
  
  while d_2 < n:
    dia_2_s += mat[d_2][n - d_2 - 1]
    
    d_2 += 1
  
  if dia_2_s != row_s:
    return False
  
  return True
