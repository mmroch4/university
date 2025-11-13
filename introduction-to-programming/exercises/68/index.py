def rename(menu, old_name, new_name):
  if menu.get(old_name) != None:
    menu[new_name] = menu[old_name]
    del menu[old_name]
