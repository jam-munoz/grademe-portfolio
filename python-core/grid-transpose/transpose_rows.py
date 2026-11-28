def transpose_rows(rows: list[str]) -> list[str]:
    if not rows:
        return []
    return [''.join(col) for col in zip(*rows)]
