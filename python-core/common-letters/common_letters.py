def common_letters(left: str, right: str) -> str:
    string = []
    for c in left:
        if c in right:
            if c not in string:
                string.append(c)
    return "".join(string)