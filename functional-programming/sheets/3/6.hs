factorial :: Int -> Int
factorial 0 = 1
factorial n = n * factorial (n - 1)

binom :: Int -> Int -> Int
binom n k = (product [x | x <- [(n - k + 1)..n]]) `div` (factorial k)

pascal :: Int -> [[Int]]
pascal n = [[ binom r k | k <- [0..r]] | r <- [0..n]]
