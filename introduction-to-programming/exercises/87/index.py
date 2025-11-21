ORD_a = ord("a")
ORD_z = ord("z")
ORD_A = ord("A")
ORD_Z = ord("Z")

def shift(a: str, b: str):
  n = (ord(b) - ORD_a)
  
  base = ORD_a if ORD_a <= ord(a) <= ORD_z else ORD_A
  
  return chr((ord(a) - base + n) % 26 + base)

def unshift(a: str, b: str):
  n = (ord(b) - ORD_a)
  base = ORD_a if ORD_a <= ord(a) <= ORD_z else ORD_A
  
  return chr((ord(a) - base - n) % 26 + base)


def vigenere_encrypt(text, keyword):
  i = 0
  u = 0
  
  encrypted = []
  
  while i < len(text):
    if ORD_a <= ord(text[i]) <= ORD_z or ORD_A <= ord(text[i]) <= ORD_Z:
      encrypted.append(shift(text[i], keyword[u]))
      
    else:
      encrypted.append(text[i])
      
    u = (u + 1) % len(keyword)
    i += 1
  
  return "".join(encrypted)

def vigenere_decrypt(text, keyword):
  i = 0
  u = 0
  
  decrypted = []
  
  while i < len(text):
    if ORD_a <= ord(text[i]) <= ORD_z or ORD_A <= ord(text[i]) <= ORD_Z:
      decrypted.append(unshift(text[i], keyword[u]))
      
    else:
      decrypted.append(text[i])
      
    u = (u + 1) % len(keyword)
    i += 1
  
  return "".join(decrypted)
