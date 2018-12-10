module Warmup
    ( change
    , stripQuotes
    , firstUppercasedOverLengthFive
    , powers
    , sumOfCubesOfOdds
    , swapAdjacents
    , Shape (Box, Sphere)
    , volume
    , surfaceArea
    ) where

import Data.Char

change :: Integer -> Either String (Integer, Integer, Integer, Integer)
change amount =
    if amount < 0 then
        Left "amount cannot be negative"
    else
        let
            (quarters, afterQuarters) = amount `divMod` 25
            (dimes, afterDimes) = afterQuarters `divMod` 10
            (nickels, pennies) = afterDimes `divMod` 5
        in
    Right (quarters, dimes, nickels, pennies)

stripQuotes :: String -> String
stripQuotes s = filter (\c -> c /= '\'' && c /= '"') s


firstUppercasedOverLengthFive :: [String] -> Maybe String
firstUppercasedOverLengthFive str =
    case (filter (\x -> length x > 5) str ) of
         [] -> Nothing
         text -> Just (map toUpper (text !! 0))

powers :: Num a => a -> [a]
powers y = [1] ++ [y ^ x | x <- [1..]]

sumOfCubesOfOdds :: [Integer] -> Integer
sumOfCubesOfOdds y = sum([ x^3 | x <- y, odd x])

swapAdjacents :: (Ord a) => [a] -> [a]
swapAdjacents [] = []
swapAdjacents (p:xs) = first ++ [p] ++ swapAdjacents second
    where first  = take 1 xs
          second = drop 1 xs


data Shape
    = Sphere Double
    | Box Double Double Double
    deriving (Eq, Show)

surfaceArea :: Shape -> Double
surfaceArea (Sphere r) = 4 * pi * r * r
surfaceArea (Box l h w) = 2 * ((w * l) + (h * l) + (h * w))

volume :: Shape -> Double
volume (Sphere r) = 4/3 * pi * r * r * r
volume (Box l h w) = w * h * l
