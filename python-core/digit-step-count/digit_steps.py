def count_digit_steps(text: str) -> int:
    steps = 0
    for i in range(len(text) - 1):
        if text[i].isdigit() and text[i + 1].isdigit():
            if int(text[i]) < int(text[i + 1]):
                steps += int(text[i + 1]) - int(text[i])
    return steps
