def sum_of_squares(n: int) -> int:
    """returns the sum of squares of all natural numbers up to n"""
    return (n * (n + 1) * (2 * n + 1)) // 6


def square_of_sum(n: int) -> int:
    """returns the square of the sum of first n natural numbers"""
    return ((n * (n + 1)) // 2) ** 2


num = int(input("enter the natural number: "))
diff = square_of_sum(num) - sum_of_squares(num)

print(f"""
the difference between the square of the sum and the sum of the squares 
for the first {num} natural numbers is {diff}
""")
