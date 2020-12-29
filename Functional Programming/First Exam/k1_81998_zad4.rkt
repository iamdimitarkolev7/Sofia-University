#lang racket

(define (triangular? matrix)
  (define (zero-counter xs counter)
    (cond [(null? xs)     counter]
          [(= (car xs) 0) (zero-counter (cdr xs) (+ counter 1))]
          [else           (zero-counter (cdr xs) counter)]))
  
  ;(define square-length (length (car matrix)))
  
  (define (helper currentRow counter mat)
    (cond [(null? mat)                            #t]
          [(= (zero-counter (car mat) 0) counter) (helper (car mat) (+ 1 counter) (cdr mat))]
          [else                                   #f]))

  (helper (car matrix) 0 matrix))

(triangular? '((1 2 3)
 (0 5 6)
 (0 0 9))) ; -> #t
(triangular? '((0 2 3)
 (0 0 6)
 (1 0 0))) ; -> #f
(triangular? '((1 2 3)
 (1 5 6)
 (0 0 9))) ; -> #f
(triangular? '((1 2 3 4)
 (0 5 6 7)
 (0 0 8 9)
 (0 0 0 9))) ; -> #t