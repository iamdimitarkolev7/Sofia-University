#lang racket

; Task 1: create a function that returns the reversed number n
(define (reverse-num n)
  (define (helper res k)
    (if (< k 10)
        (+ (* res 10) k)
        (helper (+ (remainder k 10) (* res 10)) (quotient k 10))))
  (helper 0 n))

; Task 2: create a function to find the number of the N divisors of a number
(define (divisor-count n)
  (define (helper k)
    (cond [(= k 0)               0]
          [(= (remainder n k) 0) (+ 1 (helper (- k 1)))]
          [else                  (helper (- k 1))]))
  (helper n))

; Task 3: create a function that finds the 'perfect' number(a number is perfect if it equals the sum of its divisors)
(define (perfect-num? n)
  (define (helper res k)
    (cond [(= k n)               res]
          [(= (remainder n k) 0) (helper (+ k res)(+ k 1))]
          [else                  (helper res (+ k 1))]))
  (= n (helper 0 1)))

; Task 4: create a function which checks whether the digits of a number are increasing
(define (increasing? num)
  (cond [(= num (remainder num 10)) #t]
        [(< (remainder num 10) (remainder (quotient num 10) 10)) #f]
        [else (increasing? (quotient num 10))]))

; Task 5: calculate 1 + x + x^2 + x^3 + ... + x^n
(define (sum x n)
  (if (> n 0)
      (+ (expt x n) (sum x (- n 1)))
      1))
