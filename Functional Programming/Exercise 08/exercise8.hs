main :: IO()
main = do 
    print (countDivisors 10)

myMin :: Float -> Float -> Float 
myMin a b = if a < b then a else b

isInside :: Double -> Double -> Double -> Bool
isInside x a b = x >= a && x <= b 

myFunc :: Double -> Double -> Double 
myFunc x y = (x * x + y * y) / 2

myFib :: Int -> Int 
myFib x 
    | x == 0 = 1
    | x == 1 = 1
    | otherwise = myFib (x - 1) + myFib (x - 2)

myGcd :: Int -> Int -> Int 
myGcd a b 
    | a < b = myGcd a (b - a)
    | a > b = myGcd (a - b) b
    | a == b = a

sumOdd :: Int -> Int -> Int 
sumOdd a b 
    | a > b          = 0
    | a `mod` 2 == 1 = a + sumOdd (a + 1) b 
    | otherwise      = sumOdd (a + 1) b

isPrime :: Int -> Bool
isPrime 1 = False  
isPrime n = helper 2
    where
        helper d  
            | d == n         = True 
            | n `mod` d == 0 = False
            | otherwise      = helper (d + 1)

countPalindromes :: Int -> Int -> Int 
countPalindromes a b 
    | a > b          = 0
    | isPalindrome a = 1 + countPalindromes (a + 1) b
    | otherwise      = countPalindromes (a + 1) b
    where
        reverseHelper k res =
            if k < 10
            then res * 10 + k
            else reverseHelper (k `div` 10) (res * 10 + k `mod` 10)
        isPalindrome elem = reverseHelper elem 0 == a
        
countDivisors :: Int -> Int 
countDivisors n = helper 1 n 
    where
        helper crr n
            | crr == n         = 1
            | n `mod` crr == 0 = 1 + helper (crr + 1) n
            | otherwise        = helper (crr + 1) n