maxOccurs :: Integer -> Integer -> (Integer, Integer)
maxOccurs a b = (m, o)
    where 
        m = max a b
        o = if a == b then 2 else 1

orderTriple :: (Integer , Integer , Integer ) -> (Integer , Integer , Integer)
orderTriple (a, b, c)
    | a <= b && b <= c = (a, b, c)
    | a <= c && c <= b = (a, c, b)
    | b <= a && a <= c = (b, a, c)
    | b <= c && c <= a = (b, c, a)
    | c <= a && a <= b = (c, a, b)
    | c <= b && b <= a = (c, b, a)
    