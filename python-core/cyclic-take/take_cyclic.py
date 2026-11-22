def take_cyclic(values: list[int], start: int, count: int) -> list[int]:
    if not count or not values:
        return []
    lst = []
    i = start
    for j in range(count):
        if i >= len(values) or i <= -len(values):
            i %= len(values)  
        lst.append(values[i])
        i += 1
    return lst