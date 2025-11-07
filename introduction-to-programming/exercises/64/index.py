def duplicates(lst):
  lst.sort()
  
  s = set()
  
  dup = []
  
  dup_added = set()
  
  for n in lst:
    if n in s and n not in dup_added:
      dup.append(n)
      dup_added.add(n)
      continue

    s.add(n)
  
  return dup
