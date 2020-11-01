#lang racket

; Task 1: create a function that return the smaller between 2 values
(define (mymin a b)
  (if (< a b)
      a
      b))

; Task 2: create a function inside? to define whether x is between [a;b]
(define (inside? x a b)
  (if (<= a x b )
      "yes"
      "no"))

; Task 3: create a function which returns the average of the squares of 2 numbers
(define (average x y)
  (/ (+ x y) 2))

(define (average-sqr x y)
  (average (* x x) (* y y)))

; Task 4: fibonacci
(define (myfib n)
  (if (<= n 1)
   1
   (+ (myfib (- n 1)) (myfib (- n 2)))))

; Task 5: factorial
(define (fact n)
  (if (= n 0)
      1
      (* (fact (- n 1) ) n)))