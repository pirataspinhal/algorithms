#lang racket

; (fibonacci n) - find the nth fibonacci number.
;   The numbers are considered to start at index 0 with value 0.
(define (fibonacci n)
  (cond [(> 0 n)
         (error "fibonacci: expected positive integer")]
         [(= 0 n)
          0]
         [(or (= 1 n) (= 2 n))
         1]
         [else
          (+ (fibonacci (- n 1)) (fibonacci (- n 2)))]))

; (fibonacciAt n) - return the nth fibonacci number.
;   Semantically the same as (fibonacci n).
(define (fibonacciAt n)
  (fibonacci n))

; (getFibonacci n) - return the list of first n fibonacci numbers, from 0 to n-1.
(define (getFibonacci n)
  (map fibonacci (build-list n values)))

; (getnhelp x n) - a helper function for getUpToFibonacci.
;   Finds the closest largest fibonacci number (at index x) to n.
;   Returns the index of said fibonacci number.
(define (getnhelp x n)
  (cond [(< n (fibonacciAt x))
         x]
        [else (getnhelp (+ x 1) n)]))
         
; (getUpToFibonacci n) - returns the list of fibonacci numbers less than or equal to n.
;   If n is a fibonacci number, the list ends at n.
;   If n is not a fibonacci number, the list ends at the largest fibonacci number f that satisfies f < n.
(define (getUpToFibonacci n)
    (getFibonacci (getnhelp 0 n)))