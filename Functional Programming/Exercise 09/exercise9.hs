main :: IO()
main = do
    print (isAscending 123)

incrementAllBy :: [Int] -> Int -> [Int]
incrementAllBy xs a = [x + a | x <- xs]

incrementAllBy' :: [Int] -> Int -> [Int]
incrementAllBy' []     _ = []
incrementAllBy' (x:xs) a = (x + a) : incrementAllBy' xs a

incrementAllBy'' :: [Int] -> Int -> [Int]
incrementAllBy'' xs a = 
    if null xs
    then []
    else head xs + a : incrementAllBy'' (tail xs) a

multiplyAllBy :: [Int] -> Int -> [Int]
multiplyAllBy xs a = [x * a | x <- xs]

multiplyAllBy' ::  [Int] -> Int -> [Int]
multiplyAllBy' [] _ = []
multiplyAllBy' (x:xs) a = (x * a) : multiplyAllBy' xs a

filterSmallerThan :: [Int] -> Int -> [Int]
filterSmallerThan xs a 
    | null xs = []
    | head xs >= a = head xs : filterSmallerThan (tail xs) a
    | otherwise    = filterSmallerThan (tail xs) a

numToList :: Int -> [Int]
numToList n =
    if n < 10
    then [n]
    else (n `mod` 10) : numToList (n `div` 10)

helper :: [Int] -> Bool 
helper xs 
    | null xs || null (tail xs) = True
    | head xs >= head (tail xs) = False
    | otherwise                 = helper (tail xs) 

isAscending :: Int -> Bool 
isAscending n = helper (reverse (numToList n))
