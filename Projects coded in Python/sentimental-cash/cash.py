from cs50 import get_float

# ask the user for the change owed and run function that calculates the change
def main():
    while True:
        try:
            change = float(input("Please enter the amount owed: "))
            if change >= 0:
                break
        except ValueError:
            continue

    coins = calculate_coins(change)
    print(coins)

def calculate_coins(change):
    cents = round(change * 100)
    total_coins = 0

    # List of coin values in cents
    coins_values = [25, 10, 5, 1]

    for value in coins_values:
        # Calculate the number of coins of this type
        num_coins = cents // value
        total_coins += num_coins
        # Reduce the remaining amount by the value of these coins
        cents -= num_coins * value

    return total_coins

if __name__ == "__main__":
    main()
