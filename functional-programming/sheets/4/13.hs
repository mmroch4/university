anyZero :: (Integer -> Integer) -> Integer -> Bool
anyZero f n
    | n == 0 = (f n) == 0
    | otherwise = (f n) == 0 || anyZero f (n - 1)

