#import python library
import re

#create custom functions
def count_letters(paragraph):
    return sum(letter.isalpha() for letter in paragraph)

def count_words(paragraph):
    return len(paragraph.split())

def count_sentences(paragraph):
    return len(re.findall(r'[.!?]', paragraph))

#main function
def main():
    text = input("Please enter the text: ")

    lettersc = count_letters(text)
    wordsc = count_words(text)
    sentencesc = count_sentences(text)

    L = (lettersc / wordsc) * 100
    S = (sentencesc / wordsc) * 100

    floatindex = 0.0588 * L - 0.296 * S - 15.8
    index = round(floatindex)

    if 1 <= index < 16:
        print(f"Grade {index}")
    elif index >= 16:
        print("Grade 16+")
    else:
        print("Before Grade 1")

if __name__ == "__main__":
    main()
