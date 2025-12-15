r, k = map(int, input().split())
g = input()

def get_rule(r: int) -> dict:
  transition = dict()
  
  r = format(r, "b")
  
  i = 0
  u = len(r) - 1
  
  while i <= 7:
    if u < 0:
      transition[i] = 0
      
      i += 1
      
      continue
    
    transition[i] = int(r[u])
    
    i += 1
    u -= 1
  
  return transition

def next_generation(current: str, rule: dict):
  generation = []
  
  current = "." + current + "."
  
  for i in range(1, len(current) - 1):
    n = 0
    
    if current[i + 1] == "#":
      n += 1
      
    if current[i] == "#": 
      n += 2
      
    if current[i - 1] == "#":
      n += 4
    
    char = [".", "#"]
    generation.append(char[rule[n]])  
  
  return "".join(generation)

while k:
  rule = get_rule(r)
  
  g = next_generation(g, rule)
  
  print(g)
  
  k -= 1