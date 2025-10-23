def eeny_meeny(lst, k):
  n = len(lst)
  
  l = lst.copy()
  
  c = []
  
  next = 0
  
  while 0 < n:
    i = 0
    
    if k <= len(l):
      i = k - 1 + next
    else:
      i = (k % len(l)) - 1 + next
    
    i %= len(l)
    
    next = 0 if i == len(l) - 1 else i
    
    c.append(l[i])
    l.pop(i)
    n -= 1
  
  return c
