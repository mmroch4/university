n = input()

i = 1

mode = -1
trend = -1

while i < len(n):
  current = int(n[i])
  previous = int(n[i - 1])
  
  if previous == current:
    mode = "chaotic"
    break
  elif previous < current:
    if trend == "decreasing" or trend == "mountain":
      mode = "chaotic"
      break
    
    trend = "increasing"
  elif previous > current:
    if trend == "increasing":
      trend = "mountain"
    elif trend == -1:
      trend = "decreasing"  
  
  i += 1

if mode == -1 and trend != -1:
  mode = trend

print(mode)