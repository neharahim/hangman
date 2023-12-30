Hangman Game 
DETAILS:
University: Ghulam Ishaq Khan Institute of Engineering Sciences and Technology
Course: Data Structures and Algorithms Lab (CS221 L)
Instructor: Sir Usama Arshad
GROUP  MEMBERS:
Javeria Sahar       2022241
Neha Rahim         2022481


Introduction
The Hangman game implemented in C++ is an interactive and engaging application where the player is tasked with guessing a random word based on a given category and hint. The game incorporates various data structures, including linked lists, binary search trees, and vectors, to manage the word, user inputs, and categories.

Implementation Details
1. Word Representation with Linked List:
   - The game represents the word to be guessed using a linked list, where each node corresponds to a letter in the word. Initially, the word is concealed with underscores, and as the player correctly guesses letters, the underscores are replaced with the guessed letters.
2. Avoiding Duplicate Guesses with Binary Search Tree:
   - To prevent the player from entering duplicate letters, a binary search tree (BST) is employed. The player's guesses are inserted into the BST, and a check is performed to ensure that no duplicate letters are entered. If a duplicate is detected, the player is notified, and they are prompted to enter a different letter.
3. Random Word Selection from Categories:
   - The game offers a variety of categories, each stored in a separate file. A random category is selected, and the corresponding file is loaded. Words from the selected category are stored in a vector, from which a random word is chosen as the word to be guessed by the player.

Gameplay Flow
1. Main Menu:
   - The game starts with a user-friendly main menu where the player can choose to play or exit.
2. Category Selection:
   - A category is randomly chosen, adding an element of unpredictability to each round.
3. Word Initialization:
   - The word to be guessed is randomly selected from the chosen category. The length of the word is stored in a linked list, and underscores are used to represent the unguessed letters.
4. Game Loop:
   - The player is provided with a hint about the selected word's category.
   - The game loop allows the player to input letters one at a time.
   - The input is checked against the BST to prevent duplicate guesses.
   - Correct guesses update the linked list, revealing the position of the guessed letters.
   - Incorrect guesses result in a deduction of lives.
5. Win/Loss Conditions:
   - The game continues until the player correctly guesses the word or runs out of lives.
   - A victory or loss message is displayed accordingly.

Conclusion
The Hangman game successfully combines elements of strategy, word recognition, and randomness, providing an entertaining experience for the player. The utilization of linked lists, binary search trees, and vectors enhances the efficiency and functionality of the game, creating a well-rounded and enjoyable gaming experience.
