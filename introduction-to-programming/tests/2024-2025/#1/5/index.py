def invert(lst, a, b):
  if a > b:
    return
  
  if a < 0 or b >= len(lst):
    return
  
  u = a
  i = b
  
  d = (b - a + 1) // 2
  
  while d > 0:
    lst[i], lst[u] = lst[u], lst[i]
    
    i -= 1
    u += 1
    d -= 1


lst = [0,1,2,3,4,5,6]
invert(lst,1,5)
print(lst)

lst = [10, 20, 30, 40, 50]
invert(lst,1,2)
print(lst)

lst = ['a','b','c','d','e']
invert(lst,0,4)
print(lst)

lst = ['a','b','c','d','e']
invert(lst,4,0)
print(lst)

lst = [True, True, False]
invert(lst,-1,4)
print(lst)