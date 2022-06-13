#include <iostream>
#include <vector> // For Vector
#include <fstream> // To Open File
#include <string> // For getline
#include <time.h> // For time to use to seed srand()
using namespace std;

// Printing Hangman Box
void print_message(string message, bool print_top = true, bool print_bottom = true)
{
    // Print upper line box
    if (print_top)
    {
        cout << "+---------------------------------+" << endl;
        cout << "|";
    }
    else
    {
        cout << "|";
    }

    // Print Text Message inside the box
    bool front = true;

    // To centralize the text in the box
    for (int i = message.length(); i < 33; i++)
    {
        if (front)
        {
            message = " " + message;
        }
        else
        {
            message = message + " ";
        }

        // Reverses the bool so it adds space front and back for every for loop (i < 33)
        front = !front;
    }

    // Actually prints out the text
    cout << message;

    // Print lower line box
    if (print_bottom)
    {
        cout << "|" << endl;
        cout << "+---------------------------------+" << endl;
    }
    else
    {
        cout << "|" << endl;
    }
}

// Draws the hangman using print message function based on guess count
void draw_hangman(int guess_count = 1)
{
    if (guess_count >= 1)
        print_message("|", false, false);
    else
        print_message("", false, false);

    if (guess_count >= 2)
        print_message("|", false, false);
    else
        print_message("", false, false);

    if (guess_count >= 3)
        print_message("O", false, false);
    else
        print_message("", false, false);

    if (guess_count == 4)
        print_message("/  ", false, false);

    if (guess_count == 5)
        print_message("/| ", false, false);

    if (guess_count >= 6)
        print_message("/|\\", false, false);
    else
        print_message("", false, false);

    if (guess_count >= 7)
        print_message("|", false, false);
    else
        print_message("", false, false);

    if (guess_count == 8)
        print_message("/  ", false, false);

    if (guess_count == 9)
        print_message("/ \\", false, false);
}

// Prints the available letters with spaces
void print_letters(string input, char from, char to)
{
    string word_placeholder;

    // For loop from char A to M and N to Z
    for (char i = from; i <= to; i++)
    {
        // If i index is equal to the end of the list (npos), will add i (the character)
        if (input.find(i) == string::npos) // npos means greatest possible value for an elemnt of type size_t
        {
            word_placeholder += i;
            word_placeholder += " ";
        }
        // Else means the character is taken so will leave blank instead
        else
            word_placeholder += "  ";
    }
    // Prints the text
    print_message(word_placeholder, false, false);
}

// Prints the available letters
void print_available_letters(string taken)
{
    print_message("Available Letters");
    print_letters(taken, 'A', 'M');
    print_letters(taken, 'N', 'Z');
}

bool print_word_and_check_win(string word, string guessed)
{
    bool win = true;
    string word_placeholder;

    // For loop with the duration of the length of the word
    for (int i = 0; i < word.length(); i++)
    {
        // If the letter guessed is not in the word
        if (guessed.find(word[i]) == string::npos)
        {
            win = false;
            word_placeholder += "_ ";
        }
        // words are placed if it is guessed correctly
        else
        {
            word_placeholder += word[i];
            word_placeholder += " ";
        }
    }
    print_message(word_placeholder, false);
    return win;
}

// Loads a random word from .txt file
string load_random_word(string path)
{
    int line_count = 0;
    string word;

    // Vector is like an array but can grow dynamically
    vector<string> vector_string;

    // ifstream is variable type, reader is used to read text, path is the .txt file name
    ifstream reader(path.c_str()); // c_str makes the string content in the .txt file constant
    // if the .txt file is open
    if (reader.is_open())
    {
        // while reader is able to get a word from the .txt file, it will put into the vector as word
        while (getline(reader, word))
            vector_string.push_back(word);

        // generates a random line
        int random_line = rand() % vector_string.size();

        // uses the random line generated to find a word to use
        word = vector_string.at(random_line);

        // reader.close(); is optional here
    }
    return word;
}

// Returns how many times the player has guessed it wrongly
int tries_left(string word, string guessed)
{
    int error = 0;
    for (int i = 0; i < guessed.length(); i++)
    {
        if (word.find(guessed[i]) == string::npos)
            error++;
    }
    return error;
}

int main()
{
    // seeds computer time into rand()
    srand(time(0));
    string guesses;
    string word_to_guess;
    // loads the .txt file
    word_to_guess = load_random_word("words.txt");
    int tries = 0;
    bool win = false;
    // Do while loop, execute code first, before checking if the condition is true/false
    do
    {
        // Clears the screen
        system("cls");

        print_message("HANG MAN PROJECT");
        draw_hangman(tries);
        print_available_letters(guesses);
        print_message("Guess the word");
        win = print_word_and_check_win(word_to_guess, guesses);

        if (win)
            break;

        char input;
        cout << ">";
        cin >> input;

        if (guesses.find(input) == string::npos)
            guesses += input;

        tries = tries_left(word_to_guess, guesses);

    } while (tries < 10);

    if (win)
        print_message("You Won!");
    else
        print_message("Game Over!");
        print_message("Word is: " + word_to_guess);

    system("pause");
    return 0;
}