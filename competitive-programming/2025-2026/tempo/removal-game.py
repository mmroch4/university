# https://cses.fi/alon/submit/1097/

n = int(input())
integers = list(map(int, input().split()))

NOT_CALCULATED = -1e18 - 5
INF = 1e20

dp = [[NOT_CALCULATED for z in range(n)] for _ in range(n)]

def solve(a, b):
  p = a + (n - b - 1)
  
  if a > b:
    return 0
  
  if dp[a][b] != NOT_CALCULATED:
    return dp[a][b]
  
  if p % 2 == 0:
    best = -INF
    best = max(best, integers[a] + solve(a + 1, b), integers[b] + solve(a, b - 1))
  else:
    best = INF
    best = min(best, solve(a + 1, b), solve(a, b - 1))
  
  dp[a][b] = best
  return best

print(solve(0, n - 1))