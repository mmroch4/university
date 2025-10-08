def leap(y):
  return y % 4 == 0 and not (y % 100 == 0 and y % 400 != 0)


print(leap(2000))
print(leap(1900))
print(leap(2019))