charToString :: Char -> String
charToString a = [a]

get_unity_label :: String -> String
get_unity_label a
    | a == "0" = ""
    | a == "1" = "one"
    | a == "2" = "two"
    | a == "3" = "three"
    | a == "4" = "four"
    | a == "5" = "five"
    | a == "6" = "six"
    | a == "7" = "seven"
    | a == "8" = "eight"
    | a == "9" = "nine"
    | a == "10" = "ten"
    | a == "11" = "eleven"
    | a == "12" = "twelve"
    | a == "13" = "thirteen"
    | a == "14" = "fourteen"
    | a == "15" = "fifteen"
    | a == "16" = "sixteen"
    | a == "17" = "seventeen"
    | a == "18" = "eighteen"
    | a == "19" = "nineteen"
    | otherwise = ""

get_ten_label :: String -> String
get_ten_label a 
    | a == "0" = ""
    | a == "1" = "ten"
    | a == "2" = "twenty"
    | a == "3" = "thirty"
    | a == "4" = "forty"
    | a == "5" = "fifty"
    | a == "6" = "sixty"
    | a == "7" = "seventy"
    | a == "8" = "eighty"
    | a == "9" = "ninety"
    | otherwise = ""

get_hundred_label :: String -> String
get_hundred_label a
    | a == "0" = ""
    | a == "1" = "one hundred"
    | a == "2" = "two hundred"
    | a == "3" = "three hundred"
    | a == "4" = "four hundred"
    | a == "5" = "five hundred"
    | a == "6" = "six hundred"
    | a == "7" = "seven hundred"
    | a == "8" = "eight hundred"
    | a == "9" = "nine hundred"
    | otherwise = ""

get_blocks :: String -> [String]
get_blocks s
    | n > 0 && m == 0 = [first_block]
    | n > 0 && m > 0 = [second_block, first_block]
    | otherwise = []
    where
        first_block = reverse (take 3 (reverse s))
        second_block = reverse (drop 3 (reverse s))
        
        n = length first_block
        m = length second_block

format_block_one_field :: String -> String -> String
format_block_one_field block label = formatted
    where
        p1 = charToString (block !! 0)
        
        formatted
            | p1 == "0" = ""
            | otherwise = (get_unity_label p1) ++ label

format_block_two_field :: String -> String -> String
format_block_two_field block label = formatted
    where
        p2 = charToString (block !! 0)
        p1 = charToString (block !! 1)
        
        formatted 
            | p2 == "1" = (get_unity_label (p2 ++ p1)) ++ label
            | p2 == "0" && p1 == "0" = ""
            | p2 == "0" && p1 /= "0" = (get_unity_label p1) ++ label
            | p2 /= "0" && p1 == "0" = (get_ten_label p2) ++ label
            | otherwise = (get_ten_label p2) ++ " " ++ (get_unity_label p1) ++ label

format_block_three_field :: String -> String -> String
format_block_three_field block label = formatted
    where
        p3 = charToString (block !! 0)
        p2 = charToString (block !! 1)
        p1 = charToString (block !! 2)
        
        formatted 
            | p3 == "0" = (format_block_two_field (drop 1 block) label)
            | p3 /= "0" && (p2 /= "0" || p1 /= "0") = (get_hundred_label p3) ++ " and " ++ (format_block_two_field (drop 1 block) label)
            | p3 /= "0" && p2 == "0" && p1 == "0" = (get_hundred_label p3) ++ label
            | otherwise = "INCORRECT FALLBACK"
            
format_block :: String -> String -> String
format_block block label
        | l == 0 = ""
        | l == 1 = format_block_one_field block label 
        | l == 2 = format_block_two_field block label 
        | l == 3 = format_block_three_field block label 
        where            
            l = length block
                    
textual :: Int -> String
textual s
    | n == 1 = (format_block (blocks !! 0) "")
    | n == 2 = (format_block (blocks !! 0) " thousand") ++ " " ++ (format_block (blocks !! 1) "")
    | otherwise = "INCORRECT SIZE"
    where
        blocks = get_blocks (show s)
        
        n = length blocks
        