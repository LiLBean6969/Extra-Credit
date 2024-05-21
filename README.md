# Extra-Credit
For extra credit you have to perform all four ways of hashing. The code has following 4 functions:

1) div_hash(int key, int M): divides key k with M size of hash table and use remainder of it, returns hash value

            h(K) = k mod M
            k = 12345
           M = 95
           h(12345) = 12345 mod 95
                            = 90
2) mid_sqr_hash(int key, int  M): it has 2 steps:
        1) Square the key k, which is k*k.
        2) Take  digits from square of key by dividing it by M and further mode by M, return hash value
                   h(K) = h(k x k)
                   k = 60
                   M = 100
                   k x k = 60 x 60
                            = 3600
                   h(60) = 60//100%100
                   The hash value obtained is 60
3) double_hash (int key, int M):
      h1(key) = key%M
      h2(key) = 1+(key%13)
      rehash(key) = h1(key)+i*h2(key) i starts from 1 repeat untill you get hashvalue which is palindrome number
      example : key = 12345
                       M = 1000
                       h1(12345) = 345
                       h2(12345) = 1 + (12345%13) = 1+8 = 9
              i = 1 rehash = 345 + 1*9 = 354    354 is not palindrome
              i= 2  rehash = 345+18 = 363 is palindrome  stop
              if i>5 and rehash value is not palindrome then make reverse of rehash as hash value.
              return hash value
        
4) mult_hash(int key, int A):
     Perform following steps:
    1) Choose a value A from 0<A<1
    2) Multiply key value with A
    3) Extract fractional part
    4) Multiply it with size of hash table and take floor value of it.
             h(K) = floor (M (kA mod 1)
             k = 12345
             A = 0.357840
             M = 100
             h(12345) = floor[ 100 (12345*0.357840 mod 1)]
                              = floor[ 100 (4417.5348 mod 1) ]
                              = floor[ 100 (0.5348) ]
                              = floor[ 53.48 ]
                              = 53
             return hash value
You are not given any template files. I am not providing any test cases. Create your own test cases with diverse inputs. It has points. Input has both key and hashtable size M. Diverse test cases have all possible test cases. Since there are so many possibilities,. But I want you to create any 20 test cases with diversity. The test case input key can be null or a string, and it can be one of the test cases. You have to manage those errors with messages. 
Grading Rubric:
 1) All functions are written correctly: 20 marks (5 of each)
 2) Creating diverse test cases - 20 marks
 3) Compilation -  5 marks
4) Successful run - 5 marks
