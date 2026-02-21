def has_42(number):
  return 1 if str(number).count("42") else 0

def get_range(a, b):
  r = -1
  e = 0
  
  if a[0] != -1 and b[0] != -1:
    if a[0][1] + 1 == b[0][0]:
      r = [a[0][0], b[0][1]]
      e = a[1] + b[1]
    else:
      if a[1] >= b[1]:
        r = a[0]
        e = a[1]
      else:
        r = b[0]
        e = b[1]
  elif a[0] != -1 and b[0] == -1:
    r = a[0]
    e = a[1]
  elif a[0] == -1 and b[0] != -1:
    r = b[0]
    e = b[1]
  
  return (r, e)

n, m = map(int, input().split(' '))

s = n

numbers = list(map(int, input().split(' ')))

if n % 2 == 1:
  s += 1
  
  numbers.append(1)

tree = [False for _ in range(2 * s)]

for i in range(s):  
  r = -1
  e = 0
  
  if has_42(numbers[i]):
    r = [i + s, i + s]
    e = 1
  
  tree[i + s] = (r, e)

u = s - 1
l = 1

while 0 < u:  
  tree[u] = get_range(tree[2 * u], tree[2 * u + 1])
  
  u -= 1

print(tree)

for _ in range(m):
  t, a, b = map(int, input().split(' '))
  
  if t == 1: 
    r = -1
    e = 0
    
    if has_42(b):
      r = [a + n, a + n]
      e = 1
    
    k = a + n
    
    tree[k] = (r, e)
    
    k = k // 2
    
    while 0 < k:
      tree[k] = get_range(tree[2 * k], tree[2 * k + 1])
      
      k = k // 2
    
    print()
    print(tree)
  else:
    l = a + n
    r = b + n
    print("--", l, r)
    
    nodes = []
    
    while l <= r:
      if l % 2 == 0:
        nodes.append(l)
        l += 1
      
      if r % 2 == 1:
        nodes.append(r)
        r -= 1
      
      l = l // 2
      r = r // 2

    print("nodes", nodes)
    
    pass
