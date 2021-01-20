main :: IO()
main = do
    print (minDistance points)

type Point3D = (Double, Double, Double) 

points :: [Point3D]
points = [(0, 0, 0), (3, 3, 3), (8, 8, 8)]

distance :: Point3D -> Point3D -> Double
distance (x1, y1, z1) (x2, y2, z2) = 
    (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2)

minDistance :: [Point3D] -> Double 
minDistance [] = error "Empty list"
minDistance [_] = error "The minimum values should be 2"
minDistance points = helper points points (distance (head points) (head (tail points)))
    where 
        helper :: [Point3D] -> [Point3D] -> Double -> Double
        helper p ip res
            | null p                                             = res
            | null ip || null (tail ip)                          = helper (tail p) points res
            | distance (head p) (head (tail ip)) < res && 
                distance (head p) (head (tail ip)) /= 0          = helper p (tail ip) (distance (head p) (head (tail ip)))
            | otherwise                                          = helper p (tail ip) res