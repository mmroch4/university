f :: (a, [a]) -> a
f (a, b) = a

a = f (2, [3])
b = f (2, [])
c = f (2, [True]) --INCORRECT 