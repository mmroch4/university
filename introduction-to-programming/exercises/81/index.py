def count_words(text):
  words = map(lambda w: w.lower(), text.split())  
  
  s = set(words)
  
  return len(s)

print(count_words("what  What  wHaT is love baby dont hurt me"))
print(count_words("  "))
print(count_words(" abc abC aBc aBC Abc AbC ABc ABC "))
print(count_words("Fuzzy Wuzzy was a bear Fuzzy Wuzzy had no hair Fuzzy Wuzzy wasnt fuzzy was he"))
print(count_words("You know New York you need New York you know you need unique New York"))
print(count_words("Which witch is which"))
print(count_words(" all    your    base    belong   to   us  "))