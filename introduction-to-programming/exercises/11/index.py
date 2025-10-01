price = float(input())
customer_type = input()

if customer_type == "P":
  price *= 1.06
else:
  if price < 50:
    price *= 0.98
  elif 50 <= price <= 200:
    price *= 0.95
  else: price *= 0.9


print(f"Customer: {customer_type} | Price: {round(price, 3)}")
