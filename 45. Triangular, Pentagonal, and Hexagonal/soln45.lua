function IsPentagonal(n)
    local pentD = 24 * n + 1
    local sqrtpD = math.floor(math.sqrt(pentD))
    if (sqrtpD * sqrtpD == pentD) and (sqrtpD % 6 == 5) then
        local pnum = math.floor((sqrtpD + 1) / 6)
        return true, pnum
    end
    return false, -1
end

function IsHexagonal(n)
    local hexD = 8 * n + 1
    local sqrthD = math.floor(math.sqrt(hexD))
    if (sqrthD * sqrthD == hexD) and (sqrthD % 4 == 3) then
        local hnum = math.floor((sqrthD + 1) / 4)
        return true, hnum
    end
    return false, -1
end

function Triangular(num)
    return math.floor((num * (num + 1)) / 2)
end

local found = false
local isPent, isHex
local pnum, hnum
local num = 285
while not found do
    num = num + 1
    local tri = Triangular(num)

    isPent, pnum = IsPentagonal(tri)
    isHex, hnum = IsHexagonal(tri)
    if isPent and isHex then
        found = true
    end
end


print(string.format("the next triangular number that is " ..
    "also pentagonal and hexagonal is %d", Triangular(num)))

print(string.format("\nT_{%d} = P_{%d} = H_{%d} = %d\n",
    num, pnum, hnum, Triangular(num)))
