zipWith2 :: (a -> b -> c) -> [a] -> [b] -> [c]
zipWith2 f [] _ = []
zipWith2 f _ [] = []
zipWith2 f (x:xs) (y:ys) = f x y : zipWith2 f xs ys
