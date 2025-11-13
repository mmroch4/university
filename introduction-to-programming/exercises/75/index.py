def frequency(ingredients: list):
  inventory = dict()
  
  for i in ingredients:
    if inventory.get(i) != None:
      inventory[i] += 1
    else:
      inventory[i] = 1
  
  return inventory