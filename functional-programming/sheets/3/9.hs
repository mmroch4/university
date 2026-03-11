strong :: String -> Bool
strong password = isBigEnough && hasLowercase && hasUppercase && hasNumber
    where   isBigEnough = length password >= 8
            hasLowercase = length [c | c <- password, 'a' <= c && c <= 'z'] >= 1
            hasUppercase = length [c | c <- password, 'A' <= c && c <= 'Z'] >= 1
            hasNumber = length [c | c <- password, '0' <= c && c <= '9'] >= 1