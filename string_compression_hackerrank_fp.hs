-- Enter your code here. Read input from STDIN. Print output to STDOUT
import Data.List

-- Get and append the length of repeating characters
shorten str
    | length str == 1 = [head str]
    | otherwise       = head str : (show . length) str

-- Map and "glue" strings together
compress str = 
    let grouped = group str in
    let result  = concatMap shorten grouped in
    result

main = do
    str <- getLine
    let compressed = compress str
    putStrLn compressed
