def occurrences(lst, x):
  indexes = []
  
  for i in range(len(lst)):
    if lst[i] == x:
      indexes.append(i)
  
  return indexes