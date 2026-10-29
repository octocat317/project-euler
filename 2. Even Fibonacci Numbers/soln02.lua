function Fibo(n)
	local phi = (1 + math.sqrt(5)) / 2
	local psi = (1 - math.sqrt(5)) / 2

	return math.floor(((phi ^ n) - (psi ^ n)) / math.sqrt(5))
end

local i = 3 -- Fibo(3) = 2 is the first even fibonacci
local evenSum = 0
while true do
	local fib = Fibo(i)
	if fib > 4000000 then
		break
	end
	-- print(fib)
	evenSum = evenSum + fib
	i = i + 3 -- jumps directly to the next even fibonacci number
end

print(evenSum)
print()

-- more efficient method
--[[
-- consider arbitrary F_{k-3}, F_{k}, F_{k+3}
-- F_{k+3} = F_{k+2} + F_{k+1} = 2 * F_{k+1} + F_{k}
--         = 3 * F_{k} + 2 * F_{k-1}
--         = 3 * F_{k} + 2 * F_{k-2} + 2 * F_{k-3}
--         = 3 * F_{k} + F_{k-2} + F_{k-1} + F_{k-3}
--         = 4 * F_{k} + F_{k-3}
--         this holds for any k >= 3 
--]]
-- using the above relationship we can directly generate the required
-- even fibonacci numbers without determining the intermediate ones or
-- using the Binet's Formula (Golden Ratio formula) that involves
-- costly exponentiation and division operations, while also avoiding
-- floating-point accuracy issues

local a, b = 2, 8
local sumEven = 0
while a < 4000000 do
	sumEven = sumEven + a
	a, b = b, (4 * b) + a
end

print(sumEven)
