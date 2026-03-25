replicate2 :: Int -> a -> [a]
replicate2 0 a = []
replicate2 1 a = [a]
replicate2 n a = [a] ++ replicate2 (n - 1) a

(!!!) :: [a] -> Int -> a
(!!!) l 0 = head l
(!!!) l i = (!!!) (tail l) (i - 1)

elem2 :: Eq a => a -> [a] -> Bool
elem2 e [] = False
elem2 e l 
    | (head l) == e = True
    | otherwise = elem2 e (tail l)