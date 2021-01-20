main :: IO()
main = do
    print (get [[1, 2, 3, 2], [-4, -4], [5]])

get :: [[Int]] -> Int
get (x:xs) = head x

reverseOrdSuff :: Int -> Int
reverseOrdSuff n = helper n 0
    where
        helper num result
            | num >= 0 && num <= 9                       = result * 10 + num 
            | (num `mod` 10) < ((num `div` 10) `mod` 10) = helper (num `div` 10) (result * 10 + (num `mod` 10))
            | otherwise                                  = result * 10 + (num `mod` 10)

sumUnique :: [[Int]] -> Int
sumUnique xss = sum (concat [uniques xs [] | xs <- xss])
    where
        uniques [] checked     = []
        uniques (x:xs) checked = 
            if notElem x xs && notElem x checked 
            then x : uniques xs (x:checked) 
            else uniques xs (x:checked)

quicksort :: Ord a => [a] -> [a]
quicksort []     = []
quicksort (p:xs) = quicksort lesser ++ [p] ++ quicksort greater
    where
        lesser  = filter (< p) xs
        greater = filter (>= p) xs

