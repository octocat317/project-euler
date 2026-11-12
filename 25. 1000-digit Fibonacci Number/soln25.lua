io.write("enter the number of digits: ")
local digits = io.read("*n")

--[[
--  Binet's formula:
--      F_{n} = (phi ^ n - psi ^ n) / sqrt(5)
--  psi = -0.618...; as n grows larger, psi becomes less significant
--
--  so, approximately
--  log10(F_{n}) = log10(phi ^ n) - log10(sqrt(5))
--               = n * log10(phi) - (log10(5) / 2)
--
--  #digits in number x in base 10 = floor(log10(x)) + 1
--  ==> d <= floor(log10(F_{n})) + 1
--  ==> floor(log10(F_{n})) >= d - 1
--  ==> floor(n * log10(phi) - (log10(5) / 2)) >= d - 1
--  d - 1 <= n * log10(phi) - (log10(5) / 2)
--  n >= (d - 1 + (log10(5) / 2)) / log10(phi)
--
--  the smallest 'n' which satisfies this inequality is given by
--  n = ceil((d - 1 + (log10(5) / 2)) / log10(phi))
--]]

local log10 = math.log10 or function(x)
    return math.log(x, 10)
end

local phi = (1 + math.sqrt(5)) / 2

local index
if digits == 1 then
    index = 1
else
    index = math.ceil((digits - 1 + (log10(5) / 2)) / log10(phi))
end

io.write("\nthe index of the first term in fibonacci sequence ")
io.write(string.format("to contain %d digits is %d\n", digits, index))
