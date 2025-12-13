def cool_numbers(n: set, d: set) -> set:
  r = set()
  
  for w in n:
    for c in w:
      if c not in d:
        break
    else:
      r.add(w)
  
  return r
