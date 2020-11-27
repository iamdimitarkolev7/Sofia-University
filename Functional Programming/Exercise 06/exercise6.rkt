#lang racket

; Task 1: Find the length of a list
(define (length list)
    (if (null? list)
        0
        (+ 1 (length (cdr list)))))

; Task 2: Find a number in a list
(define (isThere? x list)
  (cond [(null? list) #f]
        [(= x (car list)) #t]
        [else (isThere? x (cdr list))]))

; Task 3: Create a function which adds element to a list by given position
(define (add x pos list)
  (if (or (= pos 0) (null? list))
      (cons x list)
      (cons (car list) (add x (- pos 1) (cdr list)))))

(add 5 2 '(1 2 3 4))

; Task 4: Find the minimum number in a list
(define (min list)
  (define (helper crrMin list)
    (cond [(null? list)           crrMin]
          [(> crrMin (car list)) (helper (car list) (cdr list))]
          [else                  (helper crrMin (cdr list))]))
  (helper (car list) list))

; Task 5: Remove first occurence of an element from a list
(define (remove el list)
  (cond [(null? list)      list]
        [(= el (car list)) (cdr list)]
        [else              (cons (car list) (remove el (cdr list)))]))

; Task 6: Remove all occurences of an element from a list
(define (remove-occ el list)
  (cond [(null? list)      list]
        [(= el (car list)) (remove-occ el (cdr list))]
        [else              (cons (car list) (remove-occ el (cdr list)))]))

; Task 7: Create a function that concatenates 2 lists
(define (concat list1 list2)
  (if (null? list1)
      list2
      (cons (car list1) (append (cdr list1) list2))))

; Task 8: Create a reverse list function
(define (reverse list)
  (define (helper source result)
    (if (null? source)
      result
      (helper (cdr source) (cons (car source) result))))
  (helper list '()))

(reverse '(1 2 3 4 5 6 7 8 9))
