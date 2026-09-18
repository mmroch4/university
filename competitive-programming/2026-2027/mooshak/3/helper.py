from math import log


def getFactors(n, factor):
    count = 0

    while n % factor == 0:
        n /= factor
        count += 1

    return count

endings = set()

for i in range(0, 100000, 5):
    if i == 0:
        continue
    
    f = getFactors(i, 5)

    if f != 0:
        ll = log(i, 5)
        
        if i == (5 ** int(ll)):
            print(f"--- {i}: {f} -> 5 ^ {int(ll)}")            
        else:
            print(f"{i}: {f if f == 1 else f'{f} ---'}")

print(endings)