GAP = ord("a") - ord("A")
MOD = 26

def convert(letter: str) -> str:  
  if ord("A") <= ord(letter) <= ord("Z"):
    n = (ord(letter) - ord("A") - 1) % MOD + ord("a")
    
    return chr(n)
  else:
    n = (ord(letter) - ord("a") + 1) % MOD + ord("A")

    return chr(n)

def sopranos_code(s: str) -> str:
  r = []
  
  for c in s:
    if ord("a") <= ord(c) <= ord("z") or ord("A") <= ord(c) <= ord("Z"):
      r.append(convert(c))
    else:
      r.append(c)
      
  return "".join(r)
