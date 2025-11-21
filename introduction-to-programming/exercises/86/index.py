import math


def show_table(k: int, lst: list):
  n = math.ceil(len(lst) / k)
  
  grid = []
  
  u = 0
  
  while u < n:
    grid.append(lst[u * k: u * k + k])
    
    u += 1
  
  if len(grid[-1]) < k:
    p = k - len(grid[-1])
    
    while 0 < p:
      grid[-1].append('')
      
      p -= 1
  

  
  width = 0

  t = 0
  
  while t < len(lst):
    width = max(width, len(lst[t]))
    
    t += 1
  
  print(("+" + width * "-") * k + "+")
  
  for row in grid:
    d = ""
    
    for c in row:
      d += "|" + (" ") * (width - len(c)) + c
    
    d += "|"
    
    print(d)
    print(("+" + width * "-") * k + "+")
    

  
show_table(4, ["Robb", "Sansa", "Arya", "Bran", "Rickon", "Jon"])
show_table(2, ["Braavos","Dothraki","Lys","Pentos","Lhazar","Qarth","KingsLanding", "Dragonstone"])
show_table(3, ["Tyrion","Cersei","Jaime","Tiwin"])