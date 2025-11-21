def csv_change(text: str, a: int, b: int):
  cols = text.split(',')
  
  cols[a - 1], cols[b - 1] = cols[b - 1], cols[a - 1]
  
  return ",".join(cols)
