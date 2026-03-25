gcd2 :: Int -> Int -> Int
gcd2 a b
    | b == 0 = a
    | otherwise = gcd2 b (a `mod` b)