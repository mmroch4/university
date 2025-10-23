def swap_list(lst):
  u = 1
  
  while u < len(lst):
    lst[u], lst[u - 1] = lst[u - 1], lst[u]
    
    u += 2
