factorial n = product [1..n]

binomOne n k = numerator `div` denominator
    where   numerator = factorial n
            denominator = (factorial k) * (factorial (n - k))

binomTwo n k = numerator `div` denominator
    where   numerator = product [(n - k + 1)..n]
            denominator = product [1..k]