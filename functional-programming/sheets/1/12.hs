first :: Int -> (Int -> Int) -> Int
first a f = f a

second :: Char -> Bool -> Bool
second a b = (a == 'a') || b

third :: (Char -> Char -> Int) -> Char -> Int
third f a = f a a

fourth :: Eq a => a -> [a] -> Bool
fourth a b = a == (head b)

fifth :: Eq a => a -> [a] -> [a]
fifth a b = [a] ++ b

sixth :: Ord a => a -> a -> a
sixth a b = if a <= b then a else b