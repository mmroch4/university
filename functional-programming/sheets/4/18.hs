bools :: Int -> [[Bool]]
bools 0 = []
bools 1 = [[True], [False]]
bools n = [[True] ++ v | v <- bools (n - 1)] ++ [[False] ++ v | v <- bools (n - 1)]