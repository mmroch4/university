factorial = [f x | x <- [0..10]]
    where   f 0 = 1
            f x = x * f (x - 1)

fibonacci = [0, 1] ++ [ fibonacci !! (x - 1) + fibonacci !! (x - 2) | x <- [2..]]