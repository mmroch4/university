def quantities(coins: list) -> set:
  if len(coins) == 1:
    return set([0, coins[0]])
  
  r = quantities(coins[1:])
  
  s = set(r)
    
  for c in r:
    s.add(coins[0] + c)
  
  return s
