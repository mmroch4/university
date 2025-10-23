def spiral_number(y, x):
  if x == y: # Diagonal
    return (x - 1) * (y - 1) + x
  elif x > y: # Diagonal Superior
    if x % 2 == 0:
      return (x - 1) * (x - 1) + y
    
    return (x - 1) * (x - 1) + 2 * x - y
  elif x < y: # Diagonal Inferior:
    if y % 2 == 0:
      return (y - 1) * (y - 1) + 2 * y - x
    
    return (y - 1) * (y - 1) + x
