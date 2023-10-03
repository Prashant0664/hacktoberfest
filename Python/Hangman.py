import random

# List of words to choose from
word_list = ["python", "programming", "hangman", "computer", "code", "game"]

def choose_word():
    return random.choice(word_list)

def hangman():
    word = choose_word()
    guessed_letters = []
    attempts = 6  # Number of incorrect guesses allowed

    print("Welcome to Hangman!")
    
    while True:
        # Display the current state of the word
        display_word = ""
        for letter in word:
            if letter in guessed_letters:
                display_word += letter
            else:
                display_word += "_"
        print(display_word)

        if display_word == word:
            print("Congratulations! You guessed the word!")
            break

        guess = input("Guess a letter: ").lower()

        if len(guess) != 1 or not guess.isalpha():
            print("Invalid input. Please enter a single letter.")
            continue

        if guess in guessed_letters:
            print("You've already guessed that letter.")
            continue

        guessed_letters.append(guess)

        if guess not in word:
            attempts -= 1
            print(f"Wrong guess! You have {attempts} attempts left.")
            if attempts == 0:
                print(f"Game over! The word was '{word}'.")
                break

if __name__ == "__main__":
    hangman()
``
