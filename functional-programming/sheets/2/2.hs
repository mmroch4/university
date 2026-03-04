classifyBMI :: Float -> Float -> String
classifyBMI weight height
    | bmi < 18.5 = "underweight"
    | 18.5 <= bmi && bmi < 25 = "normal weight"
    | 25 <= bmi && bmi < 30 = "overweight"
    | otherwise = "obesity"
    where 
        bmi = weight / (height * height)
