import math

PRIMES = [2, 3]

PRIMES_SET = set(PRIMES)

FACTOR_DB = {}

def generate_primes(l):
  i = PRIMES[-1] + 2
  
  while l >= i:
    is_prime = True
    
    u = 0
    
    while u < len(PRIMES) and PRIMES[u] <= math.sqrt(i):      
      if i % PRIMES[u] == 0:
        is_prime = False
        break
      
      u += 1
    
    if is_prime:
      PRIMES.append(i)
      PRIMES_SET.add(i) 

    i += 2

def factorize(n):
  generate_primes(math.sqrt(n))
  
  if n in PRIMES_SET:
    return f"{n}={n}"
  
  if n in FACTOR_DB:
    f = "*".join(FACTOR_DB.get(n))
    
    return f"{n}={f}"
  
  factors = []

  i = 0
  k = n
  
  while k > 1:
    if k in FACTOR_DB:
      factors += FACTOR_DB.get(k)
      
      break
    
    if k in PRIMES_SET:
      factors.append(str(k))
      
      break
    
    if i == len(PRIMES):
      factors.append(str(k))
      
      PRIMES_SET.add(k)
      
      break
    
    if PRIMES[i] > math.sqrt(k):
      factors.append(str(k))
      
      PRIMES_SET.add(k)
      
      break
    
    if k % PRIMES[i] == 0:
      factors.append(str(PRIMES[i]))
      
      k /= PRIMES[i]
      k = int(k)
    else:
      i += 1
  
  FACTOR_DB[n] = factors
  
  f = "*".join(factors)
    
  return f"{n}={f}"


print(factorize(84))
print(factorize(29))
print(factorize(6))
print(factorize(630))
print(factorize(100))
print(factorize(13))
print(factorize(75600))
print(factorize(360360))
print(factorize(18974736))
print(factorize(1000000000))
print(factorize(536870912))
print(factorize(300191))
print(factorize(10729))
print(factorize(999995713))
print(factorize(977))
print(factorize(1217))
print(factorize(330870))
print(factorize(562073))
print(factorize(704344))
print(factorize(801465))
print(factorize(706626))
print(factorize(208072))
print(factorize(328016))
print(factorize(237086))
print(factorize(718384))
print(factorize(561551))
