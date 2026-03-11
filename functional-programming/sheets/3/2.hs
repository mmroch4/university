aprox :: Int -> Double
aprox n = 4 * sum [ fromIntegral((-1) ^ i) / fromIntegral(2 * i + 1) | i <- [0..n] ]


aprox' :: Int -> Double
aprox' n = 12 * sum [ fromIntegral((-1) ^ i) / fromIntegral((i + 1) ^ 2) | i <- [0..n]]
