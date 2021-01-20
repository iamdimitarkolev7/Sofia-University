main :: IO()
main = do
    print (containsWord charTree1 "acd")

data BTree = Empty | Node Int BTree BTree deriving (Show, Eq)

t1 :: BTree                                                
t1 = Node 5 (Node 2 Empty                              
                    (Node 3 Empty Empty))  
            (Node 6 Empty Empty)                
                                          
t2 :: BTree                                         
t2 = Node 5 (Node 3 Empty Empty)                      
            (Node 4 
                (Node 5 Empty Empty)     
                (Node 7 
                    (Node 4 Empty Empty) 
                Empty))

size :: BTree -> Int 
size Empty = 0
size (Node _ left right) = 1 + size left + size right 

height :: BTree -> Int 
height Empty = 0
height (Node _ left right) = max (1 + height left) (1 + height right) 

sumTree :: BTree -> Int 
sumTree Empty = 0
sumTree (Node x lt rt) = x + sumTree lt + sumTree rt

sumLeaves :: BTree -> Int 
sumLeaves Empty = 0
sumLeaves (Node x lt rt) = if lt == Empty && rt == Empty then x else sumLeaves lt + sumLeaves rt

inorder :: BTree -> [Int]
inorder Empty = []
inorder (Node x lt rt) = inorder lt ++ [x] ++ inorder rt

getLevel :: Int -> BTree -> [Int]
getLevel k (Node x lt rt) = if k == 0 then [x] else getLevel (k - 1) lt ++ getLevel (k - 1) rt

average :: BTree -> Double 
average Empty = error "Empty"
average bt = fromIntegral (sumTree bt) / fromIntegral (size bt)

symetric :: BTree -> Bool 
symetric Empty = True 
symetric (Node _ lt rt) 
    | lt /= Empty && rt /= Empty = symetric lt && symetric rt
    | lt /= Empty || rt /= Empty = False

mirrorTree :: BTree -> BTree
mirrorTree Empty = Empty
mirrorTree (Node x lt rt) = Node x (mirrorTree rt) (mirrorTree lt)

data BTreeChar = E | N Char BTreeChar BTreeChar deriving (Show, Eq)

charTree1 :: BTreeChar
charTree1 = N 'a' (N 'c' (N 'f' E E)
                         (N 'd' E E))
                  (N 'b' E 
                         (N 'e' E E))

containsWord :: BTreeChar -> String -> Bool
containsWord E _ = False 
containsWord t [] = False
containsWord (N x lt rt) word 
    | lt == E && rt == E && length word == 1 = x == head word 
    | x /= head word                         = False 
    | otherwise                              = containsWord lt (tail word) || containsWord rt (tail word)