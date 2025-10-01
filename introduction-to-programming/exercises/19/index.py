import math


a = float(input())
b = float(input())
c = float(input())

delta = (b ** 2) - 4 * a * c

if delta == 0:
  root = (-1 * b) / (2 * a)
  
  root = round(root, 2)
  
  print(f"R = {root}")
elif delta > 0:
  root_1 = (-1 * b + math.sqrt(delta)) / (2 * a)
  
  root_1 = round(root_1, 2)
  
  root_2 = (-1 * b - math.sqrt(delta)) / (2 * a)
  
  root_2 = round(root_2, 2)
  
  print(f"R1 = {root_1}")
  print(f"R2 = {root_2}")
else:
  root_real = (-1 * b) / (2 * a)
  root_imaginary = math.sqrt(-1 * delta) / (2 * a)
  
  root_real = round(root_real, 2)
  root_imaginary = round(root_imaginary, 2)
    
  print(f"R1 = {root_real} + {root_imaginary}i")
  print(f"R2 = {root_real} - {root_imaginary}i")
