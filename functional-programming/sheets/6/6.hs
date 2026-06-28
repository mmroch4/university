stringsN :: Int -> [String]

stringsN 0 = [""]
stringsN n = [ s ++ [c] | s <- stringsN(n - 1), c <- ['a'..'z']]