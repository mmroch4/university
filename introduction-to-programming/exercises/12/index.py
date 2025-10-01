n = int(input())

for i in range(n):
  u = i + 1
  
  if u % 3 == 0 and u % 5 == 0:
    print("FizzBuzz")
  elif u % 3 == 0:
    print("Fizz")
  elif u % 5 == 0:
    print("Buzz")
  else:
    print(u)