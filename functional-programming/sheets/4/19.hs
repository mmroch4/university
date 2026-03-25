import Data.List (delete)
permutations :: Eq a => [a] -> [[a]]
permutations [] = []
permutations l 
    | length l == 1 = [l]
    | otherwise = [[v] ++ p  | v <- l, p <- permutations (delete v l)]
