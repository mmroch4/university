def swap(word):
  a = 1
  
  s = ""
  
  while a < len(word):
    s += word[a] + word[a - 1]
    
    a += 2

  if len(word) % 2 == 1:
    s += word[-1]

  return s
