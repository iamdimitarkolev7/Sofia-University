main :: IO()
main = do
    print (dominates (+4) (*2) [1..4])
    print (dominates (+4) (*2) [1..5])

dominates :: (Int -> Int) -> (Int -> Int) ->[Int] -> Bool
dominates f g xs 
    | null xs                                = True 
    | abs (f (head xs)) >= abs (g (head xs)) = dominates f g (tail xs)
    | otherwise                              = False  