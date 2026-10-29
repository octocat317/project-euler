local max3 = math.floor(1000 / 3)
local max5 = math.floor(1000 / 5)
local max15 = math.floor(1000 / 15)

local sum3 = 3 * math.floor(max3 * (max3 + 1) / 2)
local sum5 = 5 * math.floor(max5 * (max5 + 1) / 2)
local sum15 = 15 * math.floor(max15 * (max15 + 1) / 2)

local sum3or5 = sum3 + sum5 - sum15
print(sum3or5)
print()

-- verification
local sum = 0
for i = 1, 1000 do
	if (i % 3 == 0) or (i % 5 == 0) then
		sum = sum + i
	end
end

print(sum3or5 == sum)
