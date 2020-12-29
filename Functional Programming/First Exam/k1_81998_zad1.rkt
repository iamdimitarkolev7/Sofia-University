#lang racket

(define (dig-pow n p)
  (define (digits n)
    (define (helper counter n)
      (if (= (quotient n 10) 0)
          counter
          (helper (+ 1 counter) (quotient n 10))))
    (helper 1 n))
  
  (define (helper num p result)
    (cond [(= (quotient num 10) 0) (+ result (expt (remainder num 10) p))]
          [else                    (helper (quotient num 10) (- p 1) (+ result (expt (remainder num 10) p)))]))
  
  (define result (helper n (+ (- p 1) (digits n)) 0))
  (define k (quotient result n))

  (if (not (= k 0))
      k
      -1))

(dig-pow 89 1)
(dig-pow 92 1) 
(dig-pow 695 2)
(dig-pow 46288 3)


