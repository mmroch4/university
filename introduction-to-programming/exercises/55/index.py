def sort_strings(lst):
  n = len(lst)
  
  indexes = set()
  l = []
  
  for _ in range(n):
    u = 0
    while u in indexes:
      u += 1
    
    m = len(lst[u])
    
    for i in range(n):
      if i in indexes: continue
      
      if len(lst[i]) > m:
        m = len(lst[i])
        u = i
      elif len(lst[i]) == m and lst[i] < lst[u]:
        u = i
    
    l.append(lst[u])
    indexes.add(u)
  
  for k in range(n):
    lst[k] = l[k]
