import Data.Char ( toUpper )
main :: IO()
main = do
    print $ inverseFun (\x -> x+1) (\x -> x-1) 5 10
    print $ inverseFun (\x -> x*x) (\x -> x^3) 0 1 
    print $ inverseFun (\x -> x+1) (\x -> x+2) 0 1 
    print $ fn 3

reduceStr :: String -> String
reduceStr []  = ""

inverseFun :: (Int -> Int) -> (Int -> Int) -> Int -> Int -> Bool
inverseFun f g a b 
    | a > b                            = True
    | (f . g) a == a && (g . f) a == a = inverseFun f g (a + 1) b
    | otherwise                        = False

-- Задача 6. Да се дефинира функция maximize :: (Ord a, Num a) => [(a -> a)] -> (a -> a), за която 
-- оценката на обръщението maximize l, където l е непразен списък от едноместни числови функции, да 
-- е едноместна числова функция на аргумент x, която дава стойността f(x) на тази фунция f от списъка l, 
-- за която числото f(x) е най-голямо по абсолютна стойност

maximize :: (Ord a, Num a) => [(a -> a)] -> (a -> a)
maximize fs x = snd (maximum [(abs (f x), f x) | f <- fs])

fn = maximize [\ x -> x * x * x, (+ 1)]