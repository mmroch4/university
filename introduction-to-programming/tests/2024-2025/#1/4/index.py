vowels = {"a", "e", "i", "o", "u"}

def transform(word):
  v = ""
  r = ""
  
  for c in word:
    if c in vowels:
      v += c
    else:
      r += c
  
  return (v, r)