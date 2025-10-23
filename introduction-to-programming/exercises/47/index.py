def fibonacci(a, b, n):
  l = [a, b]
  
  while len(l) < n:
    l.append(l[len(l) - 1] + l[len(l) - 2])
  
  return l