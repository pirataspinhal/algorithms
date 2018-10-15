powerlist l
    | l == [] = [[]]
    | otherwise = (powerlist (tail l)) ++
                  (map (\x -> (head l):x) (powerlist (tail l)))


{- open shell and enter:
   ghci
   :load powerlist.hs
   powerlist [1,2,3] 
   
   Should return: [[],[3],[2],[2,3],[1],[1,3],[1,2],[1,2,3]] -}