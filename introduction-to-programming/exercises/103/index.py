def transform(lst) :
  l = []
  
  for j in lst:
    t = []
    
    for n in j:
      try:
        n = int(n)
        
        t.append(1/n)
      except Exception as error:        
        print(f'Error: {type(error).__name__} for value "{n}": {error}.')

    if t:
      l.append(t)  
  
  return l
