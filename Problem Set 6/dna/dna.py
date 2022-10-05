import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py data.csv sequence.txt")
    # TODO: Read database file into a variable
    try:
        with open(sys.argv[1]) as a:
            reader = csv.DictReader(a)
            headers = reader.fieldnames
            h = []
            for i in headers[1:]:
                h.append(i)

            # TODO: Read DNA sequence file into a variable
            try:
                with open(sys.argv[2]) as b:
                    sequence = b.read()
            except FileNotFoundError:
                sys.exit("sequence file does not exist")

            # TODO: Find longest match of each STR in DNA sequence
            lm = []
            for i in h:
                lm.append(longest_match(sequence, i))

            # TODO: Check database for matching profiles
            c = 0
            for row in reader:
                l = []
                for i in h:
                    l.append(int(row[i]))
                if lm == l:
                    print(row["name"])
                    c += 1
            if c == 0:
                print("No match")
    except FileNotFoundError:
        sys.exit("database file does not exist")
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()