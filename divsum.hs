/*
http://www.spoj.pl/problems/DIVSUM/
SPOJ Problem Set (classical)
74. Divisor Summation
Problem code: DIVSUM
Here is a Haskell solution taken from https://mukeshiiitm.wordpress.com/2011/07/08/spoj-1754-divisor-summation-hard/
*/

import Data.List
import Random
import Control.Monad
	 
helpMod::Integer->Integer->Integer->Integer
helpMod a d n= fun a d where
    fun a 1 = mod a n
    fun a 2 = mod (a^2) n
    fun a d = let
        p = fun(mod (a^2) n) (div d 2)
        q = if odd d then mod (a*p) n else p
        in mod q n

	 
isProbable::Integer-> Bool
isProbable n |n<=1 = False
16	         |n==2 = True
17	         |even n = False
18	         |otherwise = rabinMiller [2,3,5,7,11,13,17,19] n s d where
19	             d=until (\x->mod x 2/=0) (`div` 2) (n-1) --(n-1=2^s*d)
20	             s=until (\x->d*2^x==pred n) (+1) 0  --counts the power
21	              
22	 
23	rabinMiller::[Integer]->Integer->Integer->Integer-> Bool
24	rabinMiller [] _ _ _ = True
25	rabinMiller (a:xs) n s d =  if a == n then True
26	                 else  case x==1 of
27	                    True -> rabinMiller xs n s d
28	                    _ -> if any ( ==pred n) $ take (fromIntegral s) $ iterate (\e->mod (e^2) n)  x then rabinMiller xs n s d
29	                          else  False
30	                   where x=helpMod a d n
31	                     
32	 
33	 
34	 
35	fn :: Integer -> Integer -> Integer -> Integer
36	fn x c n = mod ( x^2 + c ) n
37	 
38	pollard :: Integer -> IO  Integer 
39	pollard n
40	  | even n = return  2
41	  | otherwise =
42	      randomRIO ( 2 , n - 1 ) >>=
43	     (\x' -> randomRIO ( 2 , n - 1 ) >>=
44	        (\c ->  return ( until ( \( _ , _ , d ) -> d /= 1 || d == n )  ( \( x , y , d ) -> ( fn x c n , fn ( fn y c n ) c n , gcd ( fn x c n - fn ( fn y c n ) c n  ) n ) )  ( x' , x' , 1 ) ) >>=
45	        ( \( _ , _ , k ) -> return k  ) ) )
46	 
47	 
48	 
49	factor :: Integer -> IO [ Integer ]
50	factor 1 = return []
51	factor n =
52	   (return . isProbable $ n ) >>=
53	    (\x -> case x of
54	        True -> return [n]
55	        _    -> pollard n >>=
56	              (\d -> case d of
57	                   1 -> factor n
58	                   _ -> factor d  >>= (\l -> ( factor.div n $ d ) >>= ( \m -> return $ l ++ m ) ) ) )
59	             
60	     
61	divSum :: [[Integer]] -> Integer
62	divSum [] = 1
63	divSum (x:xs) = div (  ( head x )^( genericLength x + 1 ) -1 ) ( head x - 1 ) * divSum xs
64	 
65	 
66	main = do
67	     n <- liftM read getLine
68	     let helpfun n cnt
69	        | cnt == n = return []
70	        | otherwise = do
71	                m <- liftM read getLine
72	                    lst <- factor m
73	                putStrLn.show $ ( divSum.groupBy (\x y -> x == y ).sort $ lst ) - m
74	                helpfun n (cnt+1)
75	 
76	     helpfun n 0
77	    

