main :: IO()
main = do
    print (splitPoints (1,1) 5 [(1,2),(2,3),(10,15),(-1,1),(12,14)])

type Point = (Double, Double)

isInside :: Point -> Double -> Point -> Bool 
isInside (x_center, y_center) r (x, y) = (x - x_center)^2 + (y - y_center) ^ 2 < r^2 

splitPoints :: Point -> Double -> [Point] -> ([Point], [Point])
splitPoints p r ps = helper p r ps ([], [])
    where 
        helper :: Point -> Double -> [Point] -> ([Point], [Point]) -> ([Point], [Point])
        helper center radius pts res@(inside, out) 
            | null pts = res
            | isInside center radius (head pts) = helper center radius (tail pts) ((head pts):inside, out)
            | otherwise                         = helper center radius (tail pts) (inside, (head pts):out)