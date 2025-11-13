def remove(x: str, menu: set):
  s = set()
  
  for k in menu:
    if k[0] == x:
      s.add(k)
  
  menu.difference_update(s)