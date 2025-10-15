def count(word, letters):
  l = [a for a in letters]
  
  counter = 0
  
  for k in l:
    for c in word:
      if c == k:
        counter += 1
  
  return counter