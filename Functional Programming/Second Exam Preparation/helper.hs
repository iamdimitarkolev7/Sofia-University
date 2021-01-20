{- Списъци в Haskell - работят по подобен начин като тези в Racket, но синтаксиса е малко по-различен, и благодарение на 
    pattern matching-а на практика ще работим с тях по малко по-различен начин
    []   - празен списък
    x:xs - операторът ':' конструира списък с глава x и опашка xs, като (cons x xs) в Racket
    head (x:xs) - връща главата x, подобно на car/first в Racket
    tail (x:xs) - връща опашката xs, подобно на cdr/rest в Racket

    [1,2,3] - списък с елементи 1, 2 и 3, еквивалентно на 1:(2:(3:[]))

В Haskell обаче списъците са хомогенни, за разлика от тези в Racket (които поради динамичното типизиране на езика можеха да съдържат различни типове)
    [а]     - списък от елементи от типа а
    [[a]]   - списък от списъци с елементи от типа а
    [[[a]]] - списък от списъци от списъци с елементи от типа а
    [[[[a]]]] и т.н. 
-}



{- List Comprehension - конструиране на списък чрез определяне на неговия обхват, подобно на range в Racket, но не е отделна функция
   [a..b]    - конструира списък [a, a+1, a+2,  ..., b]
   [a,h,..b] - конструира списък [a, a+h, a+2h, ..., b]

   [x | x <- xs, predicate] - конструира списък от тези елементи на xs, за които predicate e верен, подобно на filter
   [x | x <- xs, predicate1, predicate2, ..., predicateN] - конструира списък от тези елементи на xs, за които са верни всичките предикати. Доста по-удобно от N вложени filter-а.

   [f x | x <- xs] - ако f е функция на един аргумент ще получим списък, в който към всеки елемент е приложена f (подобно на map)

   може да комбинираме двете горни функционалности:
   [f x | x <- xs, predicate x] - като map върху filter-нат списък

   [(x,y) | x <- xs, y <- ys] - ще конструира списък от двойки с първи елемент от xs и втори от ys
                              - взимаме 1ви елемент от xs -> изчерпваме ys -> взимаме 2ри от xs -> изчерпваме ys -> ...
                              - всъщност ще се получи нещо като декартово произведение, ако мислим за списъците като множества 
-}

