def whichone(n):
  f = [1, 2]
  
  while f[-1] < n:
    f.append(f[-1] + f[-2])
  
  l = len(f) - 1
  p = n
  
  while 1 < l:
    if f[l - 1] < p:
      p -= f[l - 1]

      l -= 2
    else:
      l -= 1
      
  return "AB"[p - 1]
