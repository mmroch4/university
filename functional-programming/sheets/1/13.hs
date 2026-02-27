f :: (a, [a]) -> Bool
f (a, b) = True

a = f (2, [3])
b = f (2, [])
c = f (2, [True]) -- INCORRECT