N = int(input())

errors = dict()

for _ in range(N):
  expression = input()
  
  try:
    eval(expression)
  except Exception as error:
    name = type(error).__name__
    
    if name in errors:
      errors[name] += 1
    else:
      errors[name] = 1

l = dict()

for e in errors:
  if errors[e] in l:
    l[errors[e]].append(e)
  else:
    l[errors[e]] = [e]

o = []

for u in l:
  o.append((u, sorted(l[u])))

o.sort(key=lambda x: -x[0])

for v in o:
  for w in v[1]:
    print(v[0], w)