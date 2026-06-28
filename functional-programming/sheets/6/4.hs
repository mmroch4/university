factorial :: Int -> Int
factorial 0 = 1
factorial n = n * factorial (n - 1)

binom :: Int -> Int -> Int
binom n k = (factorial n) `div` (factorial (k) * factorial(n - k))

pascal :: [[Int]]
pascal = [[binom n k | k <- [0..n]] | n <- [0..]]

pascal2 :: [[Int]]
pascal2 = [[1]] ++ [[ f n k | k <- [0..n]] | n <- [1..]]
    where   f n 0 = 1
            f n k
                | n == k = 1
                | otherwise = f (n - 1) (k - 1) + f (n - 1) k

