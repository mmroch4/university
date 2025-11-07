def brain_streaks(k, lst):
  if k == 1:
    return len(lst)
  
  c = 0
  
  t = 1
  
  for i in range(1, k):
    if lst[i - 1] < lst[i]:
      t += 1
    else:
      t = 1
  
  if t == k:
    c += 1
  
  for u in range(k, len(lst)):
    if lst[u - 1] < lst[u]:
      t += 1
      
      if t >= k:
        c += 1
    else:
      t = 1
  
  return c
