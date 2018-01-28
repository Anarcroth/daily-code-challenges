-- Difficulty: [Easy/Warmup]
-- Computing the Greatest Common Divisor (warmup)

module Main where

-- Compute the gcd' using guards and recursion
gcd' :: Integral a => a -> a -> a
gcd' n m
    | n == m = n
    | n > m  = gcd' (n-m) m
    | n < m  = gcd' n (m-n)


-- This part is related to the Input/Output and can be used as it is
-- Do not modify it
main = do
  input <- getLine
  print . uncurry gcd' . listToTuple . convertToInt . words $ input
 where
  listToTuple (x:xs:_) = (x,xs)
  convertToInt = map (read :: String -> Int)
