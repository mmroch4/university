merge2 :: Ord a => [a] -> [a] -> [a]
merge2 [] [] = []
merge2 a [] = a
merge2 [] b = b
merge2 a b
    | head a <= head b = [head a] ++ merge2 (tail a) b
    | otherwise = [head b] ++ merge2 a (tail b)

half2 :: [a] -> ([a], [a])
half2 l = (take (length l `div` 2) l, drop (length l `div` 2) l)

msort :: Ord a => [a] -> [a]
msort [] = []
msort w
    | length w == 1 = w
    | otherwise = merge2 (msort l) (msort r)
        where   (l, r) = half2 w