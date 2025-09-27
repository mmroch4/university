def whichone(n):
  r = [1, 2]

  p = 2

  while r[-1] < n:
    r.append(r[p - 1] + r[p - 2])
    
    p += 1

  k = n
  t = p - 1

  while t > 1:
    left = k <= r[t - 1]
    right = k >= r[t - 1] + 1
    
    if right:
      k -= r[t - 1]
      t -= 2
    else:
      t -= 1

  ans = ["A", "AB"]

  return ans[t][k - 1]
