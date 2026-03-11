power :: Int -> Int -> Int
power x n = product [x | i <- [1..n]]
-- power _ 0 = 1
-- power x n = x * power x (n - 1)