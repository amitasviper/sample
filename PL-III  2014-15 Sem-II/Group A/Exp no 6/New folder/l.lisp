(use-package :sb-thread)
(defvar a)
(defvar b)
(defvar c)
(write-line "Enter the first number:")
(setq a (read))

(write-line "Enter the second number:")
(setq b (read))

(setq c 0)

(make-thread ( lambda () ( progn 
(write-line "1.Addition")

(print (+ a b))
(terpri) 
)
)
)

(make-thread ( lambda () ( progn
(terpri) 
(format t "2.Subtraction")
(terpri) 
(print (- a b))
(terpri) 
)
)
)
(make-thread ( lambda () ( progn
(terpri) 
(write-line "3.division")
(terpri) 
(print (/ a b ))
(terpri) 
)
)
)
(make-thread ( lambda () ( progn
(terpri) 
(write-line "4.multiplication")
(terpri) 
(print (* a b ))
(terpri) 
)
)
)
(make-thread ( lambda () ( progn 
(terpri) 
(write-line "5.square")
(terpri) 
(print (* a a ))
(terpri) 
)
)
)
(make-thread ( lambda () ( progn 
(terpri) 

(write-line "6.Cube")
(terpri) 
(print (* a a a))
(terpri) 
)
)
)



(make-thread ( lambda () ( progn
(terpri)  
(write-line "7.sin")
(terpri) 
(write (sin a))
(terpri) 
)
)
)

(make-thread ( lambda () ( progn 
(terpri) 
(write-line "8.cos")
(terpri) 
(write (cos a))
(terpri) 
)
)
)


(make-thread ( lambda () ( progn 
(terpri) 
(write-line "9.maximum")
(terpri) 
(print (* a b ))
(terpri) 
)
)
)
[student@localhost ~]$ sbcl
* (load "l.lisp")
Enter the first number:
5
Enter the second number:
5
1.Addition

10 

2.Subtraction

0 

3.division


1 

4.multiplication


25 

5.square


25 

6.Cube


125 

7.sin

-0.9589243

8.cos

0.2836622
T
* 
9.maximum


25 





