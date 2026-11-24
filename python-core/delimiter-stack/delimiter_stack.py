def delimiters_balanced(text: str) -> bool:
    stack = []
    for c in text:
        if c in "([{":
            stack.append(c)
        elif c in ")]}":
            if len(stack) < 1:
                return False
            match c:
                case ')': 
                    if stack.pop() != '(':
                        return False
                case ']':
                    if stack.pop() != '[':
                        return False
                case '}':
                    if stack.pop() != '{':
                        return False
    if len(stack) > 0:
        return False
    return True

