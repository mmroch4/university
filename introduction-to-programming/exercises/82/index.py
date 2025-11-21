ORD_a = ord("a")
ORD_z = ord("z")

def caesar_cipher(text, k):
  text = text.lower()
  
  cypher = []
  
  for c in text:
    if ord(c) < ORD_a or ORD_z < ord(c):
      cypher.append(c)
      continue
    
    n = (ord(c) - ORD_a + k) % 26
    
    cypher.append(chr(n + ORD_a))
  
  return "".join(cypher)
