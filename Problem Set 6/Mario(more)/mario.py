def get_height():
    while True:
        n = input("Height: ")
        try:
            n = int(n)
            if 0 < n < 9:
                return n
        except ValueError:
            pass


def main():
    n = get_height()
    for i in range(n):
        print(" " * (n - i - 1) + "#" * (i + 1) + "  " + "#" * (i + 1))


main()