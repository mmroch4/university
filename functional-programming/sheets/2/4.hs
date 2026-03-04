xor :: Bool -> Bool -> Bool
xor a b
    | a && not b = True
    | not a && b = True
    | otherwise = False