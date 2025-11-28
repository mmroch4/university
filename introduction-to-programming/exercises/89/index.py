def sum_integers(data):
  s = 0
  
  for d in data:
    if isinstance(d, (tuple, list)):
      s += sum_integers(d)
    elif isinstance(d, int):
      s += d
  
  return s
