main :: IO()
main = do
    print (findNb 1071225) -- > 45
    print (findNb 40539911473216) -- > 3568
    print (findNb 135440716410000) -- > 4824
    print (findNb 4183059834009) -- > 2022
    print (findNb 91716553919377) -- > -1
    print (findNb 24723578342962) -- > -1

findNb :: Integer -> Integer
findNb num = helper num 1 0 0 
    where 
        helper :: Integer -> Integer -> Integer -> Integer -> Integer 
        helper n crr res counter
            | res + crr^3 == n = counter + 1
            | res + crr^3 > n  = -1
            | otherwise = helper n (crr + 1) (res + crr^3) (counter + 1)