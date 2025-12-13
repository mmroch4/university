def error_processor(lst, idx, divisor):
  try:
    return lst[idx] / divisor
  except IndexError:
    return "Error: Index out of range."
  except ZeroDivisionError:
    return "Error: Division by zero."
  except:
    return "Error: Incorrect type for division."
