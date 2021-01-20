main :: IO()
main = do 
    print (orderedTree t1)

data BTree = NullT | Node (Float,Float) BTree BTree

t1 :: BTree
t1 = Node (3.0,10.0) (Node (5.0,8.0) 
                        (Node (6.0,7.0) NullT NullT)
                        (Node (4.0,9.0) NullT NullT))
                     (Node (2.0,12.0) NullT
                        (Node (1.0,15.0) NullT NullT))

subInterval :: (Float, Float) -> (Float, Float) -> Bool 
subInterval (x1, y1) (x2, y2) = x1 >= x2 && y1 <= y2

orderedTree :: BTree -> Bool 
orderedTree NullT                                                                       = True
orderedTree (Node _ NullT NullT)                                                        = True
orderedTree (Node interval left@(Node leftInterval _ _) NullT)                          = 
    subInterval leftInterval interval && orderedTree left
orderedTree (Node interval NullT right@(Node rightInterval _ _))                        = 
    subInterval interval rightInterval && orderedTree right
orderedTree (Node interval left@(Node leftInterval _ _) right@(Node rightInterval _ _)) = 
    subInterval leftInterval interval && subInterval interval rightInterval && orderedTree left && orderedTree right