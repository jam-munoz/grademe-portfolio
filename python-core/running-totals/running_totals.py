def running_totals(values: list[int]) -> list[int]:
    if not values:
        return []
    acc = 0
    lst = []
    for element in values:
        lst.append(element + acc)
        acc += element
    return lst
