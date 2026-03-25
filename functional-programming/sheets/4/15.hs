insert2 :: Ord a => a -> [a] -> [a]
-- insert2 a l = sorted
--     where   b = takeWhile (\(x, i) -> x <= a) (zip l [1..])
--             i = length b
--             sorted = (take i l) ++ [a] ++ (drop i l)

insert2 a [] = [a]
insert2 a l
    | head l > a = [a] ++ l
    | otherwise = [head l] ++ insert2 a (tail l) 

isort :: Ord a => [a] -> [a]
isort [] = []
isort l = insert2 (head l) (isort (tail l))