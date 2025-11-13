INF = float("inf")

def highest_items(menu):
  m = -INF
  k = []
  
  for c in menu:
    if menu[c] > m:
      m = menu[c]
      k = [c]
    elif menu[c] == m:
      k.append(c)
  
  return k

menu = {"donut":100, "burger":400, "water":50, "pizza":400, "juice":150}
print(sorted(highest_items(menu)))