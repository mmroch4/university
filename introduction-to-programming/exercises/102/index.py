def division(a,b):
  try:
    if not isinstance(a, (int, float)) or not isinstance(b, (int, float)):
      raise TypeError

    d = a / b
    
    return f"{a}/{b} = {d}"
  except ZeroDivisionError:
    return "Error: Division by 0!"
  except:
    return "Error: Unsupported type(s) for division!"