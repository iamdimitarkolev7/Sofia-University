#lang racket

(define (prime? n)
  (define (helper d)
    (cond [(= d n)               #t]
          [(= (remainder n d) 0) #f]
          [else                  (helper (+ d 1))]))
  (if (= n 1)
      #f
      (helper 2)))

(define (numbers n)
  (define (helper currentNum k result)
    (cond [(= currentNum n)                                       result]
          [(and (prime? currentNum) (= (remainder n currentNum))) (helper (+ currentNum 1) (- k 1) (list result currentNum))]
          [else                                                   (helper (+ currentNum 1) k result)]))
  (λ (k) (helper 0 k '())))

((numbers 20) 2)