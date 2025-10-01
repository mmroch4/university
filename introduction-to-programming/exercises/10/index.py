grade = float(input())

if 90 <= grade:
  print(5)
elif 70 <= grade and grade < 90:
  print(4) 
elif 50 <= grade and grade < 70:
  print(3) 
elif 20 <= grade and grade < 50:
  print(2) 
elif 0 <= grade and grade < 20:
  print(1) 
else:
  print("NA")
