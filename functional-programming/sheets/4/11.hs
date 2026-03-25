intersperse :: a -> [a] -> [a]
intersperse d [] = []
intersperse d w
    | length (tail w) == 0 = [head w]
    | otherwise = [head w] ++ [d] ++ intersperse d (tail w)