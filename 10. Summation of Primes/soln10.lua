local isPrime = {}
-- a boolean list wherein prime indices are marked 'true' and the rest 'false'

function SieveOfEratosthenes(num)
    -- isPrime = load("return { " .. ("true, "):rep(num) .. "}")()
    -- This builds a roughly 12 MB source string for num = 2000000 and
    -- compiles it just to fill a table. That is slow and memory-hungry,
    -- and it can fail on more constrained builds.
    -- A plain loop is simpler and faster:

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
end

do
    local i = 1
    function GenerateNextPrime()
        while i <= #isPrime do
            if isPrime[i] then
                local found = i
                i = i + 1
                return found
            end
            i = i + 1
        end
        return -1
    end
end

local num = 2000000
SieveOfEratosthenes(num)

local primeSum = 0
local prime = GenerateNextPrime()
while prime ~= -1 do
    primeSum = primeSum + prime
    prime = GenerateNextPrime()
end

print(string.format("the sum of all primes up to %d is %d", num, primeSum))
