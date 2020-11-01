#lang racket

; Task 1: check if a is a substring of b (a and b are numbers)
(define (suffix? a b)
  (or (and (< a 10)
           (= a (remainder b 10)))
      (and (= (remainder a 10) (remainder b 10))
           (suffix? (quotient a 10) (quotient b 10)))))

(define (substr? a b)
  (and (<= a b)
       (or (suffix? a b)
           (substr? a (quotient b 10)))))

; Task 2:
  ; Identity function
(define (my-identity x)
  x)
  ; Compose function
(define (f1 x)
  (* x x))
(define (f2 x)
  (- x 3))

(define (my-compose f g)
  (λ (x) (f(g x))))

((my-compose f1 f2) 5)
  ; Negate function
(define (my-negate p?)
  (λ (x) (not (p? x))))
  ; Curry function


; Task 3: find F(a)-F(b)
(define (difference F a b)
  (- (F a) (F b)))

(difference (λ (x) (+ x 10)) 3 1)

; Task 4: find first derivative of f
(define (derivative f eps)
  (λ (x) (/ (- (f (+ x eps)) (f x)) eps)))

((derivative (λ (x) (+ (* x x) (* x 2))) 0.1) 5)


