;; [2017-10-30] Challenge #338 [Easy] What day was it again?

;; Description
;;
;; What day of the week did hitler get elected on?
;; What day of the week did the Normans invade Britain on?
;; What day of the week did Jesus die on?
;; What day of the week did MacDonald get founded on?
;; Today we're gonna find out
;; For todays challenge you are allowed to use your languages built in Calender functions/classes.
;; But it's more interesting if you do the calculation yourself :)

;;Hint
;;
;; It's leap-year if the year is divisible by 4
;; Ignore leap-year if the year is divisible by 100
;; Ignore previous rule if the year is divisible by 400

;; Input example
;;
;; The input will be 3 integers as such:
;; YEAR MONTH DATE
;; Limits for the 3 integers:
;; 8000 > YEAR > 0
;; 13 > MONTH > 0
;; 32 > DATE > 0
;; Sorry to anyone starting at 0.
;; January is 1 and December is 12
;; Assume all dates to be correct (i.e. no 31th of february)
;; Input will look like:
;; 2017 10 30

;; Output example
;;
;; Output is simply the day of the week of the given date, for above it would be:
;; Monday

;; Challenge input
;;
;; 2017 10 30
;; 2016 2 29
;; 2015 2 28
;; 29 4 12
;; 570 11 30
;; 1066 9 25
;; 1776 7 4
;; 1933 1 30
;; 1953 3 6
;; 2100 1 9
;; 2202 12 15
;; 7032 3 26

;; Zeller's algorithm
(define (what-day-was-it-on y m d)
  (if (and (valid-year y)
           (valid-month m)
           (valid-day y m d))
      (get-day (check-year y m) (check-month m) d)))
(define (valid-year y)
  (if (and (> y 0) (< y 8000))
      y
      (error "Invalid Year")))
(define (valid-month m)
  (if (and (> m 0) (< m 13))
      m
      (error "Invalid Month")))
(define (valid-day y m d)
  (if (or (and (> d 0) (< d 32))
          (and (and (= m 2) (< d 29))
               (or (= (modulo y 4) 0) (= (modulo y 400) 0))))
      d
      (error "Invalid day")))
(define (check-month m)
  (if (>= m 3)
      m
      (+ m 12)))
(define (check-year y m)
  (if (< m 3)
      (- y 1)
      y))
(define (get-day y m d)
  (day-of-week (modulo (+ d
                          (floor (/ (* 13 (+ m 1)) 5))
                          y
                          (- (floor (/ y 4)) (floor (/ y 100)))
                          (floor (/ y 400)))
                       7)))
(define (day-of-week day)
  (cond ((= day 0) "Saturday")
        ((= day 1) "Sunday")
        ((= day 2) "Monday")
        ((= day 3) "Tuesday")
        ((= day 4) "Wednesday")
        ((= day 5) "Thursday")
        ((= day 6) "Friday")))

