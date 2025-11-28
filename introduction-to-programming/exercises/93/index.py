def recursive(planets: list) -> list:
  if len(planets) == 1:
    return [[planets[0]]]
  
  l = []
  
  for i in range(len(planets)):
    a = set(planets)
    a.remove(planets[i])    
    
    for r in recursive(list(a)):
      l.append([planets[i]] + r)
    
  return l

def visit(planets: list) -> list:
  return list(map(lambda x: x + [x[0]], recursive(planets)))
