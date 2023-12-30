#include <iostream>
#include <string>
#include <time.h>
#include <fstream>
#include <vector>


using namespace std;

// List being used to store the length of the guess word and initialize it by underscore(_).
// As the user guesses the correct letter, the linked list gets updated and displayes the letter guessed 
// along with the unguessed letters.
class doublyLinkedList
{
public:
    struct Node
    {
        char data;
        Node *previous;
        Node *next;
    };

    Node *head = NULL;

 // Below function being used to store the guess word in the list
    void insertNode(char value)
    {
        Node *newNode = new Node();
        newNode->data = value;

        if (head == NULL)
        {
            head = newNode;
            return;
        }
        else
        {
            Node *temp = new Node();
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = NULL;
        }
    }

 // Displaying the list which contains both guessed and unguessed letters.
    void display()
    {
        Node *temp;
        temp = head;
        while (temp != NULL)
        {
            cout << temp->data << '\t';
            temp = temp->next;
        }
    }

// replacing the underscore by the correct guessed letter in its designated position.
    void replace(char letter, int location)
    {
        Node *ptr = head;
        for (int i = 0; i < location; i++)
        {
            ptr = ptr->next;
        }
        ptr->data = letter;
    }

// Checking whether the player has guessed all the letters or not.
    bool winSituation()
    {
        bool win = true;
        Node *ptr = head;

        while (ptr != NULL)
        {
            if (ptr->data == '_')
            {
                win = false;
            }
            ptr = ptr->next;
        }
        return win;
    }
};

// storing all the guesses made by the player so that no duplicate letters are entered.
class bst
{
    struct Node
    {
        char data;
        Node *right;
        Node *left;
    };

public:
    Node *root = NULL;

// inserting the guessed letter into the tree. If a duplicate is entered it will display a message.
    void insertNode(char value, bool &duplicate)
    {
        Node *newNode = new Node(); // creating new node because root is now NULL
        newNode->data = value;
        if (root == NULL)
        {
            root = newNode;
            return;
        }
        else
        {
            Node *previous = root;

            while (previous != NULL)
            {
                // taking previous pointer to leafs

                if (value == previous->data) // BST cannot add duplicate letters.Display a message when the duplicate is present
                {
                    cout << "You have already entered " << value << ". Enter another value" << endl
                         << endl;
                    duplicate = true;
                    break;
                }
                else if (value < previous->data)
                {
                    if (previous->left != NULL)
                    {
                        previous = previous->left; // if previous has not reached leafs, keep going
                    }
                    else
                    {
                        previous->left = newNode; // if previous has reached leafs, add node
                        break;
                    }
                }
                else
                {
                    if (previous->right != NULL)
                    {
                        previous = previous->right; // if previous has not reached leafs, keep going
                    }
                    else
                    {
                        previous->right = newNode; // if previous has reached leafs, add node
                        break;
                    }
                }
            }
        }
    }
};

// displays the word "HANG MAN" on the output screen.
void DisplayHangman()
{
    cout << endl
         << endl;
    cout << "\t\t\t ___\t\t ___\t\t\t ___" << endl;
    cout << "\t\t|   | \t|   |\t|\\  |\t|\t\t|\\  /|\t|   |\t|\\  |" << endl;
    cout << "\t\t|---|\t|---| \t| \\ | \t|  ___\t\t| \\/ |\t|---| \t| \\ | " << endl;
    cout << "\t\t|   | \t|   | \t|  \\| \t|___| |\t\t|    |\t|   | \t|  \\| " << endl;
    cout << endl
         << endl;
}

// returns the category filename wihch corresponds with the number in the function parameter.
string category(int number)
{
    string str;
    switch(number)
    {
        case 1:
        str="animals.txt";
        break;
        case 2:
        str="fruits.txt";
        break;
        case 3:
        str="vegetables.txt";
        break;
        case 4:
        str="words.txt";
        break;
        case 5:
        str="countries.txt";
        break;
    }

    return str;
}

// displays the category of the guess word.
void DisplayCategory(int num)
{
    switch(num)
    {
        case 1:
        cout<<"\t\tCategory:Animals\n";
        break;
        case 2:
        cout<<"\t\tCategory:Fruits\n";
        break;
        case 3:
        cout<<"\t\tCategory:Vegetables\n";
        break;
        case 4:
        cout<<"\t\tCategory:Words\n";
        break;
        case 5:
        cout<<"\t\tCategory:Countries\n";
        break;
    }
}

int main()
{
    while (1)
    {
        bool exit = false;
        doublyLinkedList GameWord;
        bst userInputs;
        DisplayHangman();
// main menu dislpay
        cout << "\t\t*************************************************************" << endl;
        cout << "\t\t\t\t\t                  O" << endl;
        cout << "\t\t\t\t\t  Main Menu      /|\\" << endl;
        cout << "\t\t\t\t\t                  |" << endl;
        cout << "\t\t\t\t\t                 / \\" << endl;
        cout << "\t\t*************************************************************" << endl
             << endl;

// player options
        cout << "1.Play" << endl;
        cout << "2.Exit" << endl
             << endl;

        int input;
        cout << "Enter your option : ";
        cin >> input;
        // runs if the input is invalid until a valid input is entered.
        while(input!=1&&input!=2)
        {
            cout<<"Invalid input. Enter again : ";
            cin>>input;
        }
        cout << endl;
        switch (input)
        {
        // if the "Play" option is entered
        case 1:
        {
            fstream dictionary;
            // randomly selecting the category file.
            srand(time(0));

           int cat = rand() % 5 + 1;

            dictionary.open(category(cat), ios::in);
           // storing all the words in the category flie selected.
            vector<string> GameDictionary;
            string line;

            while (!dictionary.eof())
            {
                getline(dictionary, line);
                GameDictionary.push_back(line);
            }

            dictionary.close();
            string word;
            char letter;
            int random;
            // randomly selecting the guess word from the stored words.
            random = rand() % 30;
            word = GameDictionary[random];
            // generating lives based on the word length.
            int lives = word.length();
            // initializing the list guess word with underscore. 
            for (int i = 0; i < word.length(); i++)
            {
                if (word[i] == ' ')
                    GameWord.insertNode(' ');
                else
                    GameWord.insertNode('_');
            }
            cout << endl
                 << endl;
            // giving hint to the player
            DisplayCategory(cat);
            cout<<"\n";
            // runs until the word is guessed or no more lives remain.
            while (lives != 0 && !GameWord.winSituation())
            {
                // becomes true if a duplicate is entered
                bool duplicate = false;
                // becomes true if the entered guess letter matches with one of the letters in the word.
                bool exist = false;
                GameWord.display();
                cout << endl
                     << endl
                     << endl;
                cout << "Lives remaining: " << lives << endl
                     << endl;
                cout << "Enter letter: ";
                cin >> letter;
                cout << endl
                     << endl;
                // runs until a valid input is entered i.e a small case letter
                while (letter < 97 || letter > 122)
                {
                    cout << "Invalid input. Enter again : ";
                    cin >> letter;
                }
                // inserts the letter into the tree to check for duplicates.
                userInputs.insertNode(letter, duplicate);

                if (!duplicate)
                {
                    // checks whether the letter is a part of the word
                    for (int i = 0; i < word.length(); i++)
                    {
                        if (letter == word[i])
                        {
                            exist = true;
                            GameWord.replace(letter, i);
                        }
                    }
                  // displays if the letter is part of word
                    if (exist)
                    {
                        cout << "Correct guess!! " << endl
                             << endl;
                    }
                  // displays if the letter is not part of the word
                    else if (!exist)
                    {
                        cout << "Wrong guess!! " << endl
                             << endl;
                        lives--;
                    }
                }
            }
           // displays when the player runs out of lives
            if (lives == 0)
            {
                cout << "You lost. The correct word is : " << word << endl
                     << endl
                     << endl
                     << endl
                     << endl;
            }
            // dislayes when the player has won(Guessed the word).
            else
            {
                GameWord.display();
                cout << "\nYou won!!!!!!" << endl
                     << endl
                     << endl
                     << endl
                     << endl;
            }
        }
        break;
        // if the "Exit" option is entered.
        case 2:
            exit = true;
            break;
        }
        // Breaks the loop if "Exit" is entered.
        if (exit)
            break;
    }

    return 0;
}
