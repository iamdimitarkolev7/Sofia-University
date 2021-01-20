main :: IO()
main = do
    print (isBinarySearchTree t1)
    print (isBinarySearchTree t2)
    print (isBinarySearchTree t3)

data BTree = Empty | Node Int BTree BTree deriving (Show, Eq)

t1 :: BTree
t1 = Node 8 (Node 3 (Node 1 Empty Empty)
 (Node 4 Empty Empty))
 (Node 10 (Node 9 Empty Empty)
 (Node 14 Empty Empty))

t2 :: BTree
t2 = Node 8 (Node 3 (Node 1 Empty Empty) 
 (Node 4 Empty Empty)) 
 (Node 10 (Node 5 Empty Empty) 
 (Node 14 Empty Empty))

t3 :: BTree
t3 = Node 8 (Node 3 (Node 5 Empty Empty)
 (Node 6 Empty Empty))
 (Node 10 (Node 9 Empty Empty)
 (Node 14 Empty Empty))

isBinarySearchTree :: BTree -> Bool
isBinarySearchTree Empty = True 
isBinarySearchTree node@(Node x _ _) = helper node x x
    where 
        helper :: BTree -> Int -> Int -> Bool
        helper Empty _ _              = True 
        helper (Node a lt rt) min max = 
            not (a < min && a > max) &&
            helper lt min (a - 1) && 
            helper rt (a + 1) max 