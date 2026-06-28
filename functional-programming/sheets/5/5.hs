import Data.List (insert)
isort2 :: Ord a => [a] -> [a]
isort2 xs = foldr insert [] xs
