leastSquare :: Int -> Int
leastSquare n = recursive n n

recursive n 1 = 1
recursive n k
    | k * k <= n = k
    | otherwise = recursive n (k - 1)


isqrt :: Int -> Int
isqrt 0 = 0
isqrt n = head (reverse (takeWhile (\k -> k * k <= n) [1..n]))
