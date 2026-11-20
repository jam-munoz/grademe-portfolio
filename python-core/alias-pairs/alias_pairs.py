def alias_pairs(rows: list[list[int]]) -> list[tuple[int, int]]:
    pairs = []
    for i in range(len(rows)):
        j = i + 1
        while j < len(rows):
            if rows[i] is rows[j]:
                pairs.append((i, j))
            j += 1
    return pairs
