def is_alpha_palindrome(text: str) -> bool:
    if not any(c.isalpha() for c in text):
        return False
    start = 0
    end = len(text) - 1
    while start < end:
        if not text[start].isalpha():
            start += 1
        elif not text[end].isalpha():
            end -= 1
        elif text[start].lower() == text[end].lower():
            start += 1
            end -= 1
        else:
            return False
    return True
