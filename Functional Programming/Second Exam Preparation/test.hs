main :: IO()
main = do
    print ([foldr (\ a b -> a + b) 0 xs | xs <- xss])

xss :: [[Int]]
xss = [[1, 2, 3], [3, 4, 8]]