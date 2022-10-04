def count_letters(text):
    count = 0
    for i in range(len(text)):
        if text[i].isalpha():
            count += 1
    return count


def count_words(text):
    count = 0
    for i in range(len(text)):
        if text[i].isspace():
            count += 1
    return count + 1


def count_sentences(text):
    count = 0
    for i in range(len(text)):
        if text[i] == "." or text[i] == "!" or text[i] == "?":
            count += 1
    return count


def main():
    text = input("Text: ")
    l = count_letters(text)
    w = count_words(text)
    s = count_sentences(text)
    # L is the average number of letters per 100 words in the text
    L = (100.0 * l) / w
    # S is the average number of sentences per 100 words in the text
    S = (100.0 * s) / w

    index = round(0.0588 * L - 0.296 * S - 15.8)

    if (index < 1):
        print("Before Grade 1")
    elif (index > 16):
        print("Grade 16+")
    else:
        print(f"Grade {index}")


main()