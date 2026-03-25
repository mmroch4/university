twoPower :: Int -> Int
twoPower 0 = 1
twoPower n = 2 * twoPower (n - 1)