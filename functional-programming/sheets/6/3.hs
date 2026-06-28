sums :: [Int] -> [Int]
sums xs = 0 : [f i | i <- [0..]]
    where   f 0 = xs !! 0
            f x = xs !! x + f (x - 1)