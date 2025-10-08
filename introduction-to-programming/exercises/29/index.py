def collatz(n):
  sequence = [n]
  
  a = n
  
  while a != 1:
    if a % 2 == 0:
      a = int(a / 2)
    else:
      a = 3 * a + 1
    
    sequence.append(a)
  
  return ", ".join(map(str, sequence))
