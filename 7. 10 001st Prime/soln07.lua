function IsPrime(num)
    if num <= 1 then
        return false
    end
    if num ~= 2 and num % 2 == 0 then
        return false
    end

    for i = 3, math.floor(math.sqrt(num)), 2 do
        if num % i == 0 then
            return false
        end
    end

    return true
end

io.write("want to find kth prime number?\nenter k: ")
local k = io.read("*n")

local n = -1
if k == 1 then
    n = 2
elseif k == 2 then
    n = 3
else
    n = 3
    local count = 2
    while count < k do
        n = n + 2
        if IsPrime(n) then
            count = count + 1
        end
    end
end

local ord = ""
if k % 10 == 1 and k % 100 ~= 11 then
    ord = "st"
elseif k % 10 == 2 and k % 100 ~= 12 then
    ord = "nd"
elseif k % 10 == 3 and k % 100 ~= 13 then
    ord = "rd"
else
    ord = "th"
end

print(string.format("\nthe %d%s prime number is %d", k, ord, n))
