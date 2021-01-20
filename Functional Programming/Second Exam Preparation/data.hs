main :: IO()
main = do
    print (closestToAverage store1)
    print (cheaperAlternative store2)

type Product = (String, Double)
type StoreAvailability = [Product]

store1 :: StoreAvailability
store1 = [ ("bread", 1), ("milk", 2.5), ("lamb", 10), ("cheese", 5), ("butter", 2.3)]

store2 :: StoreAvailability
store2 = [("bread", 1), ("cheese", 2.5), ("bread", 1), ("cheese", 5), ("butter", 2.3)]

getAveragePrice :: StoreAvailability -> Double
getAveragePrice [] = 0
getAveragePrice products = helper products 0 1
    where 
        helper :: [Product] -> Double -> Double -> Double
        helper (product:prod) crrSum count = 
            if null prod 
            then realToFrac (crrSum + snd product) / count
            else helper prod (crrSum + snd product) (count + 1) 

closestToAverage :: StoreAvailability -> String
closestToAverage []    = error "Error"
closestToAverage store = helper store (getAveragePrice store) (head store) (getAveragePrice store - snd (head store))
    where 
        helper :: StoreAvailability -> Double -> Product -> Double -> String
        helper s avg result crrMin 
            | null s                                   = fst result
            | abs (avg - snd (head s)) < abs crrMin = helper (tail s) avg (head s) (avg - snd (head s))
            | otherwise                                = helper (tail s) avg result crrMin

cheaperAlternative :: StoreAvailability -> Int 
cheaperAlternative []    = error "None"
cheaperAlternative store = helper store store 0
    where 
        helper :: StoreAvailability -> StoreAvailability -> Int -> Int
        helper s is counter 
            | null s                                                        = counter
            | null is                                                       = helper (tail s) store counter
            | snd (head s) < snd (head is) && fst (head s) == fst (head is) = helper s (tail is) (counter + 1)
            | otherwise                                                     = helper s (tail is) counter