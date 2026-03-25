fromBits :: [Int] -> Int
fromBits [] = 0
fromBits bits = (head bits) *  (2 ^ ((length bits) - 1)) + fromBits (tail bits)