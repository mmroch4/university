import sys

sys.setrecursionlimit(10 ** 6)

INF = float("inf")

def recursive(coins, k, memo):
  if k == 0:
    return 0
  elif k < 0:
    return -1

  if memo.get(k) != None:
    return memo[k]
  
  counter = INF
  not_possible = 0
  
  for c in coins:
    s = recursive(coins, k - c, memo)
    
    if s == -1:
      not_possible += 1
      continue
    
    counter = min(counter, 1 + s)
  
  if not_possible == len(coins):
    counter = -1
  
  memo[k] = counter
  
  return counter

def minimum_coins(coins: set, k: int):
  memo = dict()
  
  return recursive(coins, k, memo)
