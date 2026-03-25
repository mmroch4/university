nub2 :: Eq a => [a] -> [a] -> [a]
nub2 left [] = left
nub2 left right = nub2 l r
    where   
        el = head right
        l
            | exists el left = left
            | otherwise = left ++ [el]
        r = tail right

exists _ [] = False
exists x l = if x == (head l) then True else exists x (tail l)



