def score(name: str, position: int) -> int:
    """returns the score of a name in the sorted list"""
    value = sum((ord(x) - ord("A") + 1) for x in name)
    return value * position


with open("names.txt", "r", encoding="utf-8") as file:
    content = file.read()
    sorted_names = sorted(content.replace('"', "").split(","))
    total_score = 0
    for i in range(len(sorted_names)):
        total_score += score(sorted_names[i], i + 1)
    print("the total of all the name scores in the file is ", end="")
    print(total_score)
