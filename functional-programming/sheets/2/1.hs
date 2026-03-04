min3_1 a b c 
    | a <= b && a <= c = a
    | b <= a && b <= c = b
    | otherwise = c

max3_1 a b c 
    | a >= b && a >= c = a
    | b >= a && b >= c = b
    | otherwise = c

max3_2 a b c = max (max a b) c
min3_2 a b c = min (min a b) c
