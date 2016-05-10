main = do
         x <- readNum
         if x == 42
           then putStr("")
           else do
             putStr  (show (x) ++ "\n")
             main
       where
         readNum :: IO Integer
         readNum = do
           line <- getLine
           readIO line
