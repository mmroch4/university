n = int(input())

views = list(map(int, input().split(' ')))

views.sort()

i = n - 1

c = 1
l = views[i]

i -= 1

p = 1

while 0 <= i:
  p += 1  
  
  if l <= p:
    c = views[i]
    break
  
  if views[i] < l:
    if p >= views[i - 1]:
      c = p
      break
    
    l = views[i]
  
  i -= 1

print(c)