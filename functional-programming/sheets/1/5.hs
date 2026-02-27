lastOne list = list !! i
    where   i = (length list) - 1
    
lastTwo list = (take 1 (reverse list)) !! 0

initOne list = take (l - 1) list
    where   l = length list

initTwo list = reverse (drop 1 (reverse list))