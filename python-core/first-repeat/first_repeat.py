def first_repeat(values: list[int]) -> int | None:
    lst = []
    for n in values:
        if n in lst:
            return n
        lst.append(n)
    return None
