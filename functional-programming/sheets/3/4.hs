perfect :: Int -> [Int]
perfect n = [ x | x <- [1..n], x == sum [y | y <- [1..(x `div` 2)], x `mod` y == 0]]