replicate2 :: Int -> a -> [a]
replicate2 n a = [a | i <- [1..n]]

(!!!) :: [a] -> Int -> a
(!!!) l i = head [ v | (v, u) <- (zip l [0..i]), u == i]
