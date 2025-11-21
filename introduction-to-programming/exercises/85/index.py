def sort_initials(text: str):
  words = text.lower().split()
  
  f = []
  
  for i in range(0, 26):
    f.append([0, chr(ord("a") + i)])
  
  for w in words:
    f[(ord(w[0]) - ord("a"))][0] += 1
  
  f.sort(key=lambda x: -x[0])
  
  c = []
  
  i = 1

  t = [f[0][1]]
  
  while i < len(f):
    if f[i][0] == 0:
      break
    
    if f[i][0] == f[i - 1][0]:
      t.append(f[i][1])
      t.sort()
    else:
      c += t
      t = [f[i][1]]
    
    i += 1
    
  c += t
  
  return "".join(c)
