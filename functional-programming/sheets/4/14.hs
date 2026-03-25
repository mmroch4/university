sumFun :: (Integer -> Integer) -> Integer -> Integer
sumFun f n
    | n == 0 = f n
    | otherwise = f n + sumFun f (n - 1)
