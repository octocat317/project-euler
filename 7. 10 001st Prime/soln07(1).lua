function SieveOfEratosthenes(num)
    local isPrime = {}
    for i = 1, num do
        isPrime[i] = true
    end
    isPrime[1] = false
    local p = 2
    while p * p <= num do
        if isPrime[p] then
            for q = p * p, num, p do
                isPrime[q] = false
            end
        end
        p = p + 1
    end
    return isPrime
end

io.write("want to find the kth prime number?\nenter k: ")
local k = io.read("*n")

local function ln(x)
    return math.log(x, math.exp(1))
end

-- 'N' is the sieve limit
local N = math.max(15, math.floor(k * (ln(k) + ln(ln(k)))))

local isPrime = SieveOfEratosthenes(N)

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
        if isPrime[n] then
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
