def substring(needle, haystack):
  a = 0
  b = 0
  
  
  while b < len(haystack):
    if haystack[b] == needle[a]:
      a += 1
      
      if a == len(needle):
        return True
    
    b += 1
  
  return False
