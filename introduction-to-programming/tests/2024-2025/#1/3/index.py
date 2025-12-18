def generate_card(n):
  if n < 0:
    return "Invalid Card Number"
  
  s = 0
  
  x = str(n)
  
  for a in x:
    s += int(a)
    
  if s % 2 == 0:
    return x + "0"

  return x + "1"