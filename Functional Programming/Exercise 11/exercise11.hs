import Data.List ( sort ) 
main :: IO()
main = do
    print (getClosestPoint [Point2D 1 2, Point2D 6 7, Point2D 7 6, Point2D 4 5] (Point2D 7 8))

data Shape = Circle Double |
            Rectangle Double Double | 
            Triangle Double Double Double 
            deriving Show

area :: Shape -> Double
area (Circle r)               = pi * r * r
area (Rectangle width height) = width * height
area (Triangle a b c)         = sqrt (p * (p - a) * (p - b) * (p - c))
    where 
        p = (a + b + c) / 2

isRound :: Shape -> Bool 
isRound (Circle _) = True
isRound _      = False 
 
sumArea :: [Shape] -> Double
sumArea shapes = sum (map area shapes)

biggestShape :: [Shape] -> Shape
biggestShape []     = error "Empty list"
biggestShape shapes = foldl1 (\ u v -> if area u < area v then u else v) shapes

data Point = Point2D Double Double |
            Point3D Double Double Double 
            deriving (Show)
            
instance Eq Point where
    (==) (Point2D x1 y1) (Point2D x2 y2) = x1 == x2 && y1 == y2
    (==) (Point3D x1 y1 z1) (Point3D x2 y2 z2) = x1 == x2 && y1 == y2 && z1 == z2

point1 :: Point
point1 = Point2D 2 3

point2 :: Point
point2 = Point2D 2 4

distance :: Point -> Point -> Double
distance (Point2D x1 y1) (Point2D x2 y2) = sqrt ((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1))
distance (Point3D x1 y1 z1) (Point3D x2 y2 z2) = sqrt ((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) + (z2 - z1) * (z2 - z1))

getClosestPoint :: [Point] -> Point -> Point
getClosestPoint points point = foldl1 (\ p1 p2 -> if distance p1 point < distance p2 point then p1 else p2) points