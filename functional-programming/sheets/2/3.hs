median :: Int -> Int -> Int -> Int
median a b c 
    | a <= b && b <= c = b
    | a <= c && c <= b = c
    | b <= a && a <= c = a
    | b <= c && c <= a = c
    | c <= a && a <= b = a
    | c <= b && b <= a = b
    | otherwise = a
    