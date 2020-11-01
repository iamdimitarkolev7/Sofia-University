#lang racket

; Task 1: n-th number in fibonacci series
(define (myfib n)
  (cond [(= n 0) 1] 
        [(= n 1) 1] 
        [else (+ (myfib (- n 1)) (myfib (- n 2)))]))

; Task 2: greatest common divisor
(define (gcd a b)
  (cond [(< a b) (gcd a (- b a))]
        [(> a b) (gcd (- a b) b)]
        [else a]))

; Task 3: max divisor d < x and x > 1
(define (mymaxdivisor x)
  (define (helper x d)
    (if (= (remainder x d) 0)
        d
        (helper x (- d 1))))
  (helper x (- x 1)))

; Task 4: sum odds in the interval [a;b]
(define (sum-odds a b)
  (cond [(> a b)               0]
        [(= (remainder a 2) 0) (sum-odds (+ a 1) b)]
        [else                  (+ a (sum-odds (+ a 1) b))]))

; Task 5: check if a number is prime or not
(define (prime? n)
  (define (helper d)
    (cond [(= d n)               #t]
          [(= (remainder n d) 0) #f]
          [else                  (helper (+ d 1))]))
  (if (= n 1)
      #f
      (helper 2)))

; Task 6: counting palindromes in the interval [a;b] UNFINISHED!!!
(define (counter-digits n)
    (if (< n 10)
        1
        (+ 1 (counter-digits (quotient n 10)))))

; I-st way to reverse a number
(define (reverse-number n)
  (define (helper res k)
    (if (< k 10)
        (+ (* res 10) k)
        (helper (+ (remainder k 10) (* res 10)) (quotient k 10))))
  (helper 0 n))

; II-nd way to reverse a number
(define (reverse-number-rec n)
  (define (helper k digits)
    (if (< k 10)
        k
        (+ (* (remainder k 10) (expt 10 (- (counter-digits k) 1)))
           (helper (quotient k 10) (- digits 1)))))
  (helper n (counter-digits n)))

; now using the counter-digits and reverse-number functions i will find the number of palindromes in the interval [a;b] a < b
(define (count-palindromes a b)
  (cond [(> a b) 0]
        [(= a (reverse-number a)) (+ 1 (count-palindromes (+ a 1) b))]
        [else (count-palindromes (+ a 1) b)]))

; Task 7: count divisors function
(define (count-divisors n)
  (define (helper num k)
    (cond [(= k num) 1]
          [(= (remainder num k) 0) (+ 1 (helper num (+ 1 k)))]
          [else (helper num (+ 1 k))]))
  (helper n 1))












