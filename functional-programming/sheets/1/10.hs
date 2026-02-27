second :: [a] -> a
second xs = head (tail xs)

swap :: (a, b) -> (b, a)
swap (x, y) = (y, x)

pair :: a -> b -> (a, b)
pair x y = (x, y)

double :: Num a => a -> a
double x = 2 * x

half :: Fractional a => a -> a
half x = x / 2

lowercase :: Char -> Bool
lowercase x = 'a' <= x && x <= 'z'

range :: Ord a => a -> a -> a -> Bool
range x a b = a <= x && x <= b

palindrome :: Eq a => [a] -> Bool
palindrome xs = reverse xs == xs

twice :: (b -> b) -> b -> b
twice f x = f (f x)