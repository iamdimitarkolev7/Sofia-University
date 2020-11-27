#lang racket

; Task 1: Create a function that removes duplicate elements from a list
(define (removeDuplicates xs)
  (if (null? xs)
      '()
      (cons (car xs) (removeDuplicates (filter (λ (x) (not (= x (car xs)))) (cdr xs))))))

; Task 2: Create a function that returns a sublist of a list by given start and end position
; First solution
(define (sublistBetween start end xs)
  (cond [(null? xs) xs]
        [(= start 0) (take xs (+ end 1))]
        [else (sublistBetween (- start 1) (- end 1) (cdr xs))]))

; Second solution
(define (sublistBetween2 start end xs)
  (take (drop xs start) (+ 1 (- end start))))