inc :: Num a => a -> a
inc x = x + 1

double :: Num a => a -> a
double x = x + x

square :: Num a => a -> a
square x = x * x

media :: Fractional a => a -> a -> a
media x y = (x + y) / 2

checkTriangle :: (Ord a, Num a) => a -> a -> a -> Bool
checkTriangle a b c = a < b + c && b < a + c && c < a + b