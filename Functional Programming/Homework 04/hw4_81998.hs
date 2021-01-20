main :: IO()
main = do
    print $ getAverageBalance (accounts1, people1) (\ (_,_,city) -> city == "Burgas")
    print $ countInteresting t1
    print $ countInteresting t2


-- Task 1
people1 :: [Person]
people1 = [(1,"Ivan","Sofia"),(2,"Georgi","Burgas"),(3,"Petar","Plovdiv"),(4,"Petya","Burgas")]

accounts1 :: [Account]
accounts1 = [(1,1,12.5),(2,1,123.2),(3,2,13.0),(4,2,50.2),(5,2,17.2), (6,3,18.3)]


type Account = (Int, Int, Double)
type Person = (Int, String, String)

getAverageBalance :: ([Account], [Person]) -> (Person -> Bool) -> Double
getAverageBalance (acc, people) p = helper acc (filter p people) 0 0
    where 
        helper :: [Account] -> [Person] -> Int -> Double -> Double
        helper ((_, id, balance):accs) (x@(pid, _, _):peop) counter result
            | null peop && check accs x /= 0 = (result + check accs x) / fromIntegral (counter + 1)
            | null peop && check accs x == 0 = result / fromIntegral counter
            | null accs = helper acc peop counter result
            | id == pid = helper accs (x:peop) (counter + 1) (result + balance)
            | otherwise = helper accs (x:peop) counter result
                where 
                    -- this helper function is checking whether the last person of people list has a balance in accounts list 
                    check :: [Account] -> Person -> Double 
                    check [] _ = 0
                    check ((_, identification, b):a) var@(personId, _, _) =
                        if identification == personId
                        then b + check a var
                        else 0 + check a var


-- Task 2
data BTree = Empty | Node Int BTree BTree deriving (Eq, Show)

t1 :: BTree
t1 = Node 16 (Node 0 Empty Empty)
            (Node 4 (Node 1 Empty Empty)
                    (Node 0 Empty Empty))

t2 :: BTree
t2 = Node 4 (Node 0 Empty Empty)
            (Node 2 (Node 1 Empty Empty)
                    Empty)


countInteresting :: BTree -> Int
countInteresting Empty = 0
countInteresting (Node x lt rt) 
    | lt /= Empty && rt /= Empty && x == 4 = 1 + countInteresting rt + countInteresting lt
    | lt /= Empty && rt == Empty && x == 2 = 1 + countInteresting rt + countInteresting lt
    | lt == Empty && rt /= Empty && x == 2 = 1 + countInteresting rt + countInteresting lt
    | lt == Empty && rt == Empty && x == 1 = 1 + countInteresting rt + countInteresting lt
    | otherwise                            = 0 + countInteresting rt + countInteresting lt