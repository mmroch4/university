short :: [a] -> Bool

short a = length a <= 2

short a
    | size <= 2 = True
    | otherwise = False
    where        
        zipped = zip a [1..]
        size = foldl max 0 [ i | (x, i) <- zipped]
        