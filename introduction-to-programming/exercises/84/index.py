ORD_0 = ord("0")
ORD_9 = ord("9")

def extract_numbers(text):
  numbers = []
  
  i = 0
  
  s = []
  
  while i < len(text):
    if ORD_0 <= ord(text[i]) <= ORD_9:
      s.append(text[i])
    elif 0 < len(s):
      numbers.append(int("".join(s)))
      s.clear()

    i += 1
  
  if 0 < len(s):
    numbers.append(int("".join(s)))

  return numbers


print(extract_numbers("104 soldiers, 50 horses and 3 catapults!"))
print(extract_numbers("the 7 kingdoms and the 5 stark brothers"))
print(extract_numbers("zz23yy42tt678pp81"))