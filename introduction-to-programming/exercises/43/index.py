def evolve(initial, n):
  print(initial)
  
  a = 1
  
  k = initial
  
  while a <= n:
    x = ""
    
    l = [m for m in k]
    
    for y in l:
      if y == "A":
        x += "AB"
      else:
        x += "A"
    
    k = x
    
    print(k)
    
    a += 1
