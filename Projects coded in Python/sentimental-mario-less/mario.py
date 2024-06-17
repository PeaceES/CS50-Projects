# Define a function called get_int that takes a positive integer
def get_int(prompt):
    while True:
        try:
            return int(input(prompt))
        except ValueError:
            print("height must be an integer")

# get the height from the user
height = get_int("Height: ")
while height < 1 or height > 8:
    print("Height must be between 1 and 8 ")
    height = get_int("Height: ")

#print the pyramid

for i in range(1, height + 1):
    print(" " * (height - i) + "#" * i)
