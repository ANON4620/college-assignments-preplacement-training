def checkMagazine(magazine, note):
    word_count = {}

    for word in magazine:
        word_count[word] = word_count.get(word, 0) + 1

    for word in note:
        if word_count.get(word, 0) == 0:
            print("No")
            return
        word_count[word] -= 1

    print("Yes")
