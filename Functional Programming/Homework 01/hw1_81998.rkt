#lang racket

; Task 1: create a function which checks if a number is automorphic
(define (counter-digits n)
    (if (< n 10)
        1
        (+ 1 (counter-digits (quotient n 10)))))

(define (automorphic? n)
  (define (helper result k digitsCounter)
    (if (= (+ digitsCounter 1) (counter-digits n))
        (+ result (* (remainder k 10) (expt 10 digitsCounter)))
        (helper (+ result (* (remainder k 10) (expt 10 digitsCounter)))
                (quotient k 10)
                (+ digitsCounter 1))))
  (= n (helper 0 (expt n 2) 0)))

; Tests of task 1
(automorphic? 5) ;#t
(automorphic? 25) ;#t
(automorphic? 6) ;#t
(automorphic? 11) ;#f
(automorphic? 36) ;#f
(automorphic? 890625) ;#t
(automorphic? 1) ;#t
(automorphic? 2) ;#f

; Task 2: find the n-th cuban prime number
(define (isPrime? n)
  (define (helper i)
    (cond [(= i n)               #t]
          [(= 0 (remainder n i)) #f]
          [else                  (helper (+ i 1))]))
  (if (= n 1)
      #f
      (helper 2)))

(define (nth-cuban n)
  (define (helper x counter)
    (define crrNumber (- (expt (+ x 1) 3) (expt x 3)))
    (cond [(and (isPrime? crrNumber) (= counter n)) crrNumber]
          [(and (isPrime? crrNumber) (< counter n)) (helper (+ 1 x) (+ 1 counter))]
          [else (helper (+ 1 x) counter)]))
  (helper 1 1))

; Tests of task 2
"---------"
(nth-cuban 1) ;7
(nth-cuban 2) ;19
(nth-cuban 4) ;61
(nth-cuban 5) ;127
(nth-cuban 50) ;55897
(nth-cuban 100) ;283669








