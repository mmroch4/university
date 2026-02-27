a :: [Char] = ['a', 'b', 'c']
b :: (Char, Char, Char) = ('a', 'b', 'c')
c :: [(Bool, Char)] = [(False, '0'), (True, '1')]
d :: ([Bool], [Char]) = ([False, True], ['0', '1'])
e :: [[a] -> [a]] = [tail, init, reverse]
f :: [a -> a] = [id, not]
