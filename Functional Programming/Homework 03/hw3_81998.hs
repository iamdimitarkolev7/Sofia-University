import Data.Char (isAlpha, isDigit)
main :: IO()
main = do
    print (encode "HHaaasKKell")
    print (encode "aaabccdefff")
    print (encode "aaaaaaaaaaaabbb")
    print (encode "aabbb")

    print (decode "3h2askell6 haha")
    print (decode "12a3b")
    print (decode "a3b")
    print (decode "aa3b")

{- TASK 1 -}
encodeHelper :: String -> String -> Int -> String
encodeHelper text result occ 
    | length text == 1 && occ <= 2              = result ++ replicate occ (head text)
    | length text == 1                          = result ++ show occ ++ text  
    | head (tail text) == head text             = encodeHelper (tail text) result (occ + 1)
    | head (tail text) /= head text && occ > 2  = encodeHelper (tail text) (result ++ show occ ++ [head text]) 1
    | otherwise                                 = encodeHelper (tail text) (result ++ replicate occ (head text)) 1

encode :: String -> String
encode text = encodeHelper text "" 1

{- TASK 2 -}
-- when crrNum equals 0 it indicates that a letter is parsed only once 
decodeHelper :: String -> String -> Int -> Int -> String 
decodeHelper text result crrNum power 
    | null text                          = result
    | isDigit (head text)                = decodeHelper (tail text) result ((read [head text] :: Int) + crrNum * 10 ^ power) (power + 1)
    | isAlpha (head text) && crrNum == 0 = decodeHelper (tail text) (result ++ [head text]) 0 0 
    | otherwise                          = decodeHelper (tail text) (result ++ replicate crrNum (head text)) 0 0

decode :: String -> String 
decode text = decodeHelper text "" 0 0 