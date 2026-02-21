import math

def get_q(n):
  return (-1 + math.sqrt(1 + 4 * 2 * n)) / 2

def get_sum(i, n):
  return (i + n) * n // 2

def coords2num(x, y):
  if x == 1 and y == 1:
    return 1
  
  is_x_even = x % 2 == 0
  is_y_even = y % 2 == 0
  
  if x == 1 and y != 1:
    if is_y_even:
      return get_sum(1, y - 1) + 1
    else:
      return get_sum(1, y)
  elif x != 1 and y == 1:
    if is_x_even:
      return get_sum(1, x)
    else:
      return get_sum(1, x - 1) + 1
  elif x != 1 and y != 1:
    if (is_x_even and is_y_even) or (not is_x_even and not is_y_even):
      return coords2num(1, y + x - 1) - x + 1
    elif (is_x_even and not is_y_even) or (not is_x_even and is_y_even):
      return coords2num(x + y - 1, 1) - y + 1

def num2coords(n):
  if n == 1:
    return (1, 1)
  
  q = get_q(n)
  
  if q == math.floor(q):
    q = math.floor(q)
    
    if q % 2 == 0:
      return (q, 1)
    else:
      return(1, q)

  q = math.floor(q)

  if q % 2 == 0:
    d = n - coords2num(q, 1)
    
    return (q - d + 2, d)
  
  d = n - coords2num(1, q)

  return (d, q - d + 2)
