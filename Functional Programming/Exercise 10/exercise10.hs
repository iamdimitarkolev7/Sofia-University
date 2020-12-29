main :: IO()
main = do
    print (chunksOf 4 [1..16])

isImage :: [Int] -> [Int] -> Bool 
isImage [_]        [_]        = True 
isImage (a1:a2:as) (b1:b2:bs) = a1 - b1 == a2 - b2 && isImage (a2:as) (b2:bs)

chunksOf :: Int -> [t] -> [[t]]
chunksOf _ [] = []
chunksOf k xs = take k xs : chunksOf k (drop k xs)