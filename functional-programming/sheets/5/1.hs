-- [f x | x ← xs, p x]
 
alternative f p xs = map f (filter p xs)