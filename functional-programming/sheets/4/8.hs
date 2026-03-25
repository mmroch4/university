factorial :: Int -> Int
factorial 0 = 1
factorial n = n * factorial (n - 1)

rangeProduct :: Int -> Int -> Int
rangeProduct a b
    | a == b = a
    | otherwise = a * rangeProduct (a + 1) b
   
factorial' :: Int -> Int 
factorial' 0 = 1
factorial' n = rangeProduct 1 n