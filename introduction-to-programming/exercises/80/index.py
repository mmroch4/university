def find_all(keyword, text):
  occurrences = []
  
  i = 0
  u = 0
  
  while i < len(text):
    if text[i] == keyword[u]:
      u += 1
      
      if u == len(keyword):
        occurrences.append(i - len(keyword) + 1)
        u = 1
    else:
      u = 0
    
    i += 1
  
  return occurrences
