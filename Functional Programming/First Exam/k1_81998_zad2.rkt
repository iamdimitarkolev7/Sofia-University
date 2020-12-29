#lang racket

(define (kth-max-min xs)
  (define (helper ls counter result)
    (cond [(= counter 0)  result]
          [(null? ls)     (if (= counter 0) result "No such number")]
          [(and (< (car ls) 0) (< (car ls ) result)) (helper (cdr ls) (- counter 1) (car ls))]
          [else           (helper (cdr ls) counter result)]))
  (λ (k) (helper xs k 100)))

((kth-max-min '(-1 2 -1 -1 -5 5 5 5)) 1)