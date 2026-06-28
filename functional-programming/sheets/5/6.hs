{-

Consider the function rotate, which produces all possible rotations of a list. That is rotate [1, 2,
3] = [[1, 2, 3],[2, 3, 1],[3, 1, 2]].
(a) Denes the shift function, which places the rst item of a list at the end. For example, shift
[1,2, 3] = [2, 3, 1] and shift "eat" = "ate".
(b) Using foldr and shift dene the rotate function.

-}

shift :: [a] -> [a]
shift [] = []
shift (x:xs) = xs ++ [x]

--rotate :: [a] -> [[a]]
--rotate [] = []
-- rotate xs = take (length xs) (xs : rotate (shift xs))
rotate xs = 