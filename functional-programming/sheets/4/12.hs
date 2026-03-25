maxFun :: (Integer -> Integer) -> Integer -> Integer
maxFun f n
    | n == 0 = f n
    | otherwise = max (f n) (maxFun f (n - 1))