def possible_sums(coins: set):
  s = set()
  
  for c1 in coins:
    s.add(c1)
  
  for c1 in coins:
    for c2 in coins:
      s.add(c1 + c2)
  
  for c1 in coins:
    for c2 in coins:
      for c3 in coins:
        s.add(c1 + c2 + c3)
  
  return s
