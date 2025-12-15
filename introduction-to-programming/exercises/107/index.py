def nested_exceptions(tree):
  results = []
  
  for leaf in tree:
    if isinstance(leaf, tuple):
      results.append(nested_exceptions(leaf))
    else:
      try:
        leaf()
      except:
        results.append(True)
      else:
        results.append(False)

  return tuple(results)

print(nested_exceptions((lambda: 1/0, lambda: 0)))
print(nested_exceptions((lambda: 1/0, (lambda: 0, lambda: 1/0))))