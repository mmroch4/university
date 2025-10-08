def largest_sequence(num):
  s = str(num)
  
  m = 1
  current = 1
  
  for i in range(1, len(s)):
    if int(s[i - 1]) < int(s[i]):
      current += 1
    else:
      current = 1
    
    m = max(current, m)
  
  return m
  
print(largest_sequence(129643457))
print(largest_sequence(1213478911))
print(largest_sequence(123123412345))