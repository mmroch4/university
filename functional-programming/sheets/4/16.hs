minimum2 :: Ord a => [a] -> a
minimum2 l 
    | length l == 1 = head l
    | otherwise = min (head l) (minimum2 (tail l))

delete2 :: Eq a => a -> [a] -> [a]
delete2 n [] = []
delete2 n l
    | head l == n = tail l
    | otherwise = [head l] ++ delete2 n (tail l)

ssort :: Ord a => [a] -> [a]
ssort [] = []
ssort l = [minimum2 l] ++ ssort (delete2 (minimum2 l) l)