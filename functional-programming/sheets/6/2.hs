# TODO : INCOMPLETE

merge :: Ord a => [a] -> [a] -> [a]
merge [] [] = []
merge [] (y:ys)
    | ys == [] = y : []
    | y == head ys = merge [] ys
    | otherwise = y : merge [] ys
merge (x:xs) []
    | xs == [] = x : []
    | x == head xs = merge [] xs
    | otherwise = x : merge [] xs
merge (x:xs) (y:ys)
    | x == y = x : merge xs ys
    | x < y = x : merge xs (y:ys)
    | y < x = y : merge (x:xs) (ys)
    | otherwise = []

hamming = [x * y | x <- merged, y <- merged]
    where   powersOfTwo = [2 ^ x | x <- [0..]]
            powersOfThree = [3 ^ x | x <- [0..]]
            powersOfFive = [5 ^ x | x <- [0..]]
            
            merged = merge (merge powersOfTwo powersOfThree) powersOfFive
            
hamming2 = [ 2^x | x <- [0..]]