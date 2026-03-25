toBits :: Int -> [Int]
toBits 0 = [0]
toBits n = recursive n exponents
    where exponents = reverse (takeWhile (\x -> x <= n) [2 ^ e | e <- [0..]])

recursive n e
    | length e == 0 = []
    | otherwise = [m] ++ recursive r (tail e)
    where   p = head e
            m = n `div` p
            r = n - m * p