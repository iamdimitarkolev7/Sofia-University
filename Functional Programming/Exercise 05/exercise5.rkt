#lang racket

; Task 1: Find the second derivative of a function
  ; Helper function to find the first derivative
(define (derive f eps)
  (λ (x) (/ (- (f (+ x eps)) (f x)) eps)))

(define (derive2 f eps)
  (derive (λ (x) (/ (- (f (+ x eps)) (f x)) eps)) eps))

; Task 2: Find the n-th derivative of a function
(define (derive-n f n eps)
  (if (= n 0)
      f
      (derive-n (derive f eps) (- n 1) eps)))

; Task 3: Create a function to find the n-th composition of a function
(define (repeated f n)
  (λ (x)
    (if (= n 1)
        (f x)
        (f ((repeated f (- n 1)) x)))))

; Task 4: Create derive-x and derive-y functions
(define (derive-x f eps)
  (λ (x y) (/ (- (f (+ x eps) y) (f x y)) eps)))

(define (derive-y f eps)
  (λ (x y) (/ (- (f x (+ y eps)) (f x y)) eps)))



