divprop :: Int -> [Int]
divprop n = [ x | x <- [1..limit], n `mod` x == 0]
    where limit = n `div` 2