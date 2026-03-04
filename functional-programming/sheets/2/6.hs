safetail :: [a] -> [a]

safetail a = if (length a) >= 1 then tail a else []

safetail a
    | length a >= 1 = tail a
    | otherwise = []

safetail [] = []
safetail a = tail a
