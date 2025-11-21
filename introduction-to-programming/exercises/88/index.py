MEMO = {}

SEQ = [0, 1, 2]

def get_l(x):
  if SEQ[-1] < x:
    while SEQ[-1] < x:
      SEQ.append(SEQ[-1] + SEQ[-2])
    
    return SEQ[-2]
  
  l = 0
  r = len(SEQ) - 1
  
  while l < r:
    m = (l + r) // 2
    
    if x == SEQ[m]:
      return SEQ[m - 1]
    elif SEQ[m - 1] < x <= SEQ[m]:
      return SEQ[m - 1]
    
    if x < SEQ[m]:
      r = m - 1
    elif SEQ[m] < x:
      l = m + 1
  
  return SEQ[l - 1]

def count_range(a: int, b: int):
  if a == 1 and b == 1:
    return 1
  elif a == 1 and b == 2:
    return 1
  elif a == 2 and b == 2:
    return 0
  
  if MEMO.get((a, b)) != None:
    return MEMO[(a, b)]
  
  l = get_l(b)
  
  if l < a:
    c = count_range(a - l, b - l)
    
    MEMO[(a, b)] = c
    
    return c
  elif b <= l:
    c = count_range(a, b)
    
    MEMO[(a, b)] = c
    
    return c  
  else:
    c = count_range(a, l) + count_range(l + 1, b)
    
    MEMO[(a, b)] = c
    
    return c
