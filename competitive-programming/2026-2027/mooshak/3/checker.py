import sys
from math import factorial, floor

sys.set_int_max_str_digits(1000000)


def getTraillingZerosCount(n):
    s = str(n)
    i = -1
    count = 0

    while s[i] == "0":
        count += 1
        i -= 1

    return count
    
def getLastDigit(n):
    s = str(n)
    i = -1

    while s[i] == "0":
        i -= 1

    return int(s[i])
    


def solve(N):
    e = 1

    count = 0
    
    while 5 ** e <= N:
        count += floor(N / (5 ** e))
    
        e += 1

    return count

for i in range(1, 1000000):
    ans = factorial(i)

    zero_count = 0

    x = str(ans)

    u = -1

    while x[u] == "0":
        zero_count += 1
        u -= 1

    lll = solve(i)

    print(f"{i}: {zero_count} | solve: {lll}")

    if (zero_count != lll):
        print(f"FALSE: {i} | {zero_count=} | {lll=}")
        break
