prime :: Int -> Bool
prime n = length [x | x <-[1..n], n `mod` x == 0] == 2