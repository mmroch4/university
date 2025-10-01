import math

PI = math.pi

m = input()

r = float(input())

match m:
  case "1":
    diameter = round(2 * r, 2)
    
    print(f"Diameter: {diameter}")
  case "2":
    perimeter = round(2 * PI * r, 2)
    
    print(f"Perimeter: {perimeter}")
  case "3":
    area = round(PI * (r ** 2), 2)
    
    print(f"Area: {area}")
  case _:
    print("Invalid Option.")
