ORD_A = ord("A")
ORD_Z = ord("Z")
ORD_a = ord("a")
ORD_z = ord("z")

def word_types(lst):
  t = [0, 0, 0]
  
  for w in lst:
    mode = -1
    
    for c in w:
      if ORD_A <= ord(c) <= ORD_Z:
        if mode != -1 and mode != 1:
          mode = 2
          break
      
        mode = 1
      else:
        if mode != -1 and mode != 0:
          mode = 2
          break
        
        mode = 0
    
    t[mode] += 1
  
  return tuple(t)
