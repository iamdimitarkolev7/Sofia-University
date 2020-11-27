#lang racket

; Task 1: Find the sum of the numbers in the interval [a,b] which digits are descending
(define (sum-numbers a b)
  (define (ascendingDigits? num)
    (cond [(and (>= num 0) (<= num 9)) #t]
          [(<= (remainder num 10) (remainder (quotient num 10) 10)) (ascendingDigits? (quotient num 10))]
          [else #f]))

  (define (sum-iter current result)
    (cond [(> current b) result]
          [(ascendingDigits? current) (sum-iter (+ current 1) (+ result current))]
          [else (sum-iter (+ 1 current) result)]))
  (sum-iter a 0))

; Task 2:
(define (num-bigger-elements lst) 
  (define (helper cs hs rs counter)
    (cond [(null? cs)            rs]
          [(null? hs)            (helper (cdr cs) lst (append rs (list counter)) 0)]
          [(< (car cs) (car hs)) (helper cs (cdr hs) rs (+ counter 1))]
          [else                  (helper cs (cdr hs) rs counter)]))
  (define (appender ls1 ls2 rs)
    (if (null? ls1)
        rs
        (appender (cdr ls1) (cdr ls2) (cons (cons (car ls1) (car ls2)) rs))))
  (reverse (appender lst (helper lst lst '() 0) '())))

; Task 3:
(define (switchsum f g n)
  (λ (x)
    (cond [(= n 1) (f x)]
          [(= (remainder n 2) 0) (+ (g x) ((switchsum f g (- n 1)) (g x)))]
          [else                  (+ (f x) ((switchsum f g (- n 1)) (f x)))])))

; Task 4:
(define (repeater str)
  (λ (count glue) (cond [(= count 1) str]
                        [else (string-append str glue ((repeater str) (- count 1)  glue))])))

; Task 5:
(define (sum-digit a b k)
  (define (sum-digit-iter current result)
    (cond [(> current b) result]
          [(= (remainder current k) 0) (sum-digit-iter (+ 1 current) (+ result current))]
          [else                        (sum-digit-iter (+ 1 current) result)]))
  (sum-digit-iter a 0))

; Task 6:
(define (max-ordered-sublist lst)
  (define (helper rs cs li)
    (cond [(null? (cdr li))                                          (if (> (length cs) (length rs)) cs rs)]
          [(and (>= (car li) (cadr li)) (> (length cs) (length rs))) (helper cs (list (cadr li)) (cdr li))]
          [(>= (car li) (cadr li))                                   (helper rs (list (cadr li)) (cdr li))]
          [else                                                      (helper rs (append cs (list (cadr li))) (cdr li))]))
  (helper '() (list (car lst)) lst))

; Task 7:
(define (where list-elements list-predicates)
  (if (null? list-predicates)
      list-elements
      (where (filter (car list-predicates) list-elements) (cdr list-predicates))))

; Task 8:
(define (set-union xs ys)
  (define (helper xs ys rs)
    (cond [(null? xs)            (append rs ys)]
          [(null? ys)            (append rs xs)]
          [(< (car xs) (car ys)) (helper (cdr xs) ys (append rs (list (car xs))))]
          [(> (car xs) (car ys)) (helper xs (cdr ys) (append rs (list (car ys))))]
          [else                  (helper (cdr xs) (cdr ys) (append rs (list (car xs))))]))
  (helper xs ys '()))

; Task 9:
(define (flatten xs)
  (define (helper rs ls)
    (cond [(null? ls) rs]
          [(not (pair? (car ls))) (helper (append rs (list (car ls))) (cdr ls))]
          [else                   (helper rs (append (car ls) (cdr ls)))]))
  (helper '() xs))

; Task 10:
(define (diagonal mat)
  (if (null? mat)
      '()
      (cons (car (map car mat)) (diagonal (cdr (map cdr mat))))))

; Task 11:
(define (tabulate f)
  (λ (a b)
    (if (= a b)
        (list (cons a (f a)))
        (cons (cons a (f a)) ((tabulate f) (+ 1 a) b)))))

; Task 12:
(define (pair-compose fs)
  (define (helper xs)
    (cond [(null? xs)       '()]
          [(null? (cdr xs)) (list (compose (car xs) identity))]
          [else             (cons (compose (car xs) (cadr xs)) (helper (cddr xs)))]))
  (λ (x) (foldr + 0 (map (λ (f) (f x)) (helper fs)))))















