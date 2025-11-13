def price_diversity(menu: dict):
  s = set()
  
  for k in menu:
    s.add(menu[k])
  
  return s