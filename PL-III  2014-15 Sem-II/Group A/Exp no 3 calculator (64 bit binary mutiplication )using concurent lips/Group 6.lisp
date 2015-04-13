

(defvar a) (defvar b) (defvar c) (defvar d) 
(write-line " Enter two numbers : ") 
(setf a(read)) (setf b(read)) 


(print(sb-thread:list-all-threads))






(sb-thread:make-thread(lambda()(progn(sleep 0) 
(print(sb-thread:list-all-threads))
(setf c(+ a b)) 
(print "ADDITION : ")
(print c))):name "sum thread is running")







(sb-thread:make-thread(lambda()(progn(sleep 0) 	
(print(sb-thread:list-all-threads))
(setf c(- a b)) 
(print "SUBTRACTION : ")
(print c))):name "sub thread is running")	








(sb-thread:make-thread(lambda ()
(print(sb-thread:list-all-threads))
(setf c(* a b)) 
(print "multiplication")
(print c)):name "mul thread is running")





(sb-thread:make-thread(lambda ()
(print(sb-thread:list-all-threads))
(setf c(/ a b)) 
(print "div")
(print c)):name "div thread is running")



(sb-thread:make-thread(lambda ()
(print "exit")):name "exit thread is running")














	




































