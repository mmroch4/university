import math

def digits_average(n):
  seq = str(n)
  n = len(seq)
  
  r = int((n * (n + 1)) / 2)
    
  digits = [False for _ in range(r)]
  
  u = r - n
  
  for d in seq:
    d = int(d)
    
    digits[u] = d
    
    u += 1
  
  
  k = r - n - 1
  a = n - 1
  
  while a >= 0:
    p = a
    
    while p > 0:
      digits[k] = math.ceil((digits[k + a] + digits[k + a + 1]) / 2 )
      
      p -= 1
      k -= 1
    
    a -= 1  
  
  return digits[0] 

print(digits_average(158))
print(digits_average(9534))
print(digits_average(9062))