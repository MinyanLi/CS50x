import re


def get_number():
    while True:
        n = input("Number: ")
        if re.fullmatch("\d+", n):
            return n
        else:
            pass


def main():
    n = get_number()
    # get every other digit, starting with the number’s second-to-last digit
    a = []
    for i in range(1, len(n), 2):
        a.append(n[~i])
    # multiply each of the underlined digits by 2
    b = []
    for i in range(len(a)):
        b.append(str(int(a[i]) * 2))
    # add products’ digits
    c = []
    for i in range(len(b)):
        if len(b[i]) == 1:
            c.append(int(b[i]))
        else:
            c.append(int(b[i][0]))
            c.append(int(b[i][1]))
    sum_c = sum(c)
    # get every other digit, starting with the number’s last digit
    d = []
    for i in range(0, len(n), 2):
        d.append(int(n[~i]))
    sum_c += sum(d)

    # last digit in that sum should be 0
    if str(sum_c)[~0] == "0":
        if len(n) == 15:
            if n[0] == "3" and (n[1] == "4" or n[1] == "7"):
                print("AMEX")
            else:
                print("INVALID")
        elif len(n) == 16:
            if n[0] == "5" and (n[1] == "1" or n[1] == "2" or n[1] == "3" or n[1] == "4" or n[1] == "5"):
                print("MASTERCARD")
            elif n[0] == "4":
                print("VISA")
            else:
                print("INVALID")
        elif len(n) == 13:
            if n[0] == "4":
                print("VISA")
            else:
                print("INVALID")
        else:
            print("INVALID")
    else:
        print("INVALID")


main()