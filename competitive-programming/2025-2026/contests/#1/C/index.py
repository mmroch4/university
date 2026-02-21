n = int(input())

chat = []

for _ in range(n):
  m = input()
  
  chat.append(m)

printed = set()

i = n - 1

while 0 <= i:
  if chat[i] not in printed:
    print(chat[i])
    printed.add(chat[i])
  
  i -= 1
