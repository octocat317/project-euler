from math import isqrt


def is_triangle(word: str) -> bool:
    """returns true if the word is triangle and false otherwise"""
    letter_sum = 0
    for ch in word:
        letter_sum += ord(ch) - ord("A") + 1

    D = 8 * letter_sum + 1  # the discriminant 'D'
    sqrt_D = isqrt(D)

    return (sqrt_D * sqrt_D == D) and (sqrt_D % 2 == 1)


with open("words.txt", "r", encoding="utf-8") as file:
    content = file.read()
    words = content.replace('"', "").split(",")

    count = 0
    for word in words:
        if is_triangle(word):
            count += 1

    print(f"there are {count} triangle words in the text file")
