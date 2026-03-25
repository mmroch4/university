digits :: Int -> [Int]
digits 0 = [0]
digits n =  recursive n exponents
    where   exponents = reverse (takeWhile (\x -> x <= n) [10 ^ e | e <- [0..]])
            

recursive :: Int -> [Int] -> [Int] 
recursive n e
    | (length e) == 0 = []
    | otherwise = [n `div` head e] ++ recursive (rest n (head e)) (tail e) 
    
rest n p = n - (n `div` p) * p