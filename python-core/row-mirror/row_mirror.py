def mirror_rows(grid: list[list[int]]) -> list[list[int]]:
    lst = []
    for row in grid:
        lst.append(list(reversed(row)))
    return lst
