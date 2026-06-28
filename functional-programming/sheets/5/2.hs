-- (a) (++) :: [a] → [a] → [a], using foldr
fn1 :: [a] -> [a] -> [a]
fn1 xs ys = foldr (:) ys xs

-- (b) concat :: [[a]] → [a], using foldr ;
fn2 :: [[a]] -> [a]
fn2 xs = foldr (++) [] xs

-- (c) reverse :: [a] → [a], using foldr ;
fn3 :: [a] -> [a]
fn3 xs = foldr (\x -> f x) [] xs
    where f x y = y ++ [x]

-- (d) reverse :: [a] → [a], using foldl;
fn4 :: [a] -> [a]
fn4 xs = foldl (\x -> f x) [] xs
    where f x y = [y] ++ x
    
-- (e) elem :: Eq a ⇒ a → [a] → Bool, using any.
fn5 :: Eq a => a -> [a] -> Bool
fn5 x xs = any (==x) xs