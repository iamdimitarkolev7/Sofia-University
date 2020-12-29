#lang racket

(define (shuffle xs)
  (define middle (quotient (length xs) 2))
  
  (define (prefix-list ls counter rs)
    (cond [(= (length rs) middle)     rs]
          [(<= counter middle)        (prefix-list (cdr ls) (+ 1 counter) (append rs (list (car ls))))]))
  
  (define (postfix-list ls counter rs)
    (cond [(null? ls)                rs]
          [(>= counter middle)        (postfix-list (cdr ls) (+ 1 counter) (append rs (list (car ls))))]
          [else                      (postfix-list (cdr ls) (+ 1 counter) rs)]))

  (define (merge pre-list post-list counter rs)
    (cond [(null? post-list) rs]
          [(odd? counter )   (merge (cdr pre-list) post-list (+ 1 counter) (append rs (list (car pre-list))))]
          [else              (merge pre-list (cdr post-list) (+ 1 counter) (append rs (list (car post-list))))]))

  (merge (prefix-list xs 0 '()) (postfix-list xs 0 '()) 1 '()))

(shuffle '(2 5 1 3 4 7))
(shuffle '(1 2 3 4 4 3 2 1))
(shuffle '(1 1 2 2))
