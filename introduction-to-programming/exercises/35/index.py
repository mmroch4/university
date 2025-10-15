def odd_even(tup):
  odd = []
  even = []
  
  for i in range(len(tup)):
    if (i + 1) % 2 == 0:
      even.append(tup[i])
    else:
      odd.append(tup[i])
  
  return tuple(odd + even)
