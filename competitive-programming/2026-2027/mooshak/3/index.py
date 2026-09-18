from math import floor

N = int(input())

e = 1

count = 0

while 5**e <= N:
    count += floor(N / (5**e))

    e += 1

print(count)
