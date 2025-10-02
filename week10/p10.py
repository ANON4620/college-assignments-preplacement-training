# Enter your code here. Read input from STDIN. Print output to STDOUT

def simple_text_editor(operations):
    text = ""
    history = []

    for op in operations:
        if op[0] == "1":
            history.append(text)
            text += op[1]
        elif op[0] == "2":
            history.append(text)
            k = int(op[1])
            text = text[:-k]
        elif op[0] == "3":
            k = int(op[1])
            print(text[k - 1])
        elif op[0] == "4":
            if history:
                text = history.pop()

if __name__ == "__main__":
    q = int(input().strip())
    operations = [input().split() for _ in range(q)]
    simple_text_editor(operations)
