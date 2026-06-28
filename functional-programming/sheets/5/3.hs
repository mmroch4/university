dec2int xs = foldl f 0 (zip xs [length xs - x | x <- [1..]])
    where f acc (x, y) = acc + x * 10 ^ y       

dec2int2 xs = foldr (\(x, y) -> (+)(x * 10 ^ y)) 0 (zip xs [length xs - x | x <- [1..]])