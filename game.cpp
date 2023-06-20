#include <iostream>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;

void makeBoard(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
bool checkWinner(char *spaces, char player, char computer);
bool checkTie(char *spaces);
void allMoves(char *spaces);


int main()
{
    cout << "------------------------------------------------\n";
    cout << "|               TIC_TAC_TOE                     |\n";
    cout << "------------------------------------------------\n";
    cout << "All spots with their corresponding Numbers: \n";
    cout << endl;
    cout << "       |       |     \n";
    cout << "  "<< "[1]" << "  |  " << "[2]" << "  |   " << "[3]" << "  \n";
    cout << "       |       |     \n";
    cout << "-------|-------|-------\n";
    cout << "       |       |     \n";
    cout << "  "<< "[4]" << "  |  " << "[5]" << "  |   " << "[6]" << "  \n";
    cout << "       |       |     \n";
    cout << "-------|-------|-------\n";
    cout << "       |       |     \n";
    cout << "  "<< "[7]" << "  |  " << "[8]" << "  |   " << "[9]" << "  \n";
    cout << "       |       |     \n";
    cout << endl;
    cout << "Starting...\n";
    char spaces[9] = {'.', '.', '.', '.', '.', '.', '.', '.', '.'};
    char player = 'X';
    char computer = 'O';
    bool running = true;

    makeBoard(spaces);

    while(running)
    {
        playerMove(spaces, player);
        makeBoard(spaces);
        if(checkWinner(spaces, player, computer))
        {
            running = false;
            break;
        }
        else if(checkTie(spaces))
        {
            running = false;
            break;
        }
        computerMove(spaces, computer);
        makeBoard(spaces);
        if(checkWinner(spaces, player, computer))
        {
            running = false;
            break;
        }
        else if(checkTie(spaces))
        {
            running = false;
            break;
        }

    }
    allMoves(spaces);
    cout << "\n------------------------------------------------\n";
    cout << "|             Thanks for Playing!              |\n";
    cout << "------------------------------------------------\n";
    return 0;
}

void makeBoard(char *spaces)
{
    cout << endl;
    cout << "     |     |     \n";
    cout << "  "<< spaces[0] << "  |  " << spaces[1] << "  |   " << spaces[2] << "  \n";
    cout << "     |     |     \n";
    cout << "-----|-----|-----\n";
    cout << "     |     |     \n";
    cout << "  "<< spaces[3] << "  |  " << spaces[4] << "  |   " << spaces[5] << "  \n";
    cout << "     |     |     \n";
    cout << "-----|-----|-----\n";
    cout << "     |     |     \n";
    cout << "  "<< spaces[6] << "  |  " << spaces[7] << "  |   " << spaces[8] << "  \n";
    cout << "     |     |     \n";
    cout << endl;
}

void playerMove(char *spaces, char player)
{
    
    int number;
    do
    {
        cout << "Enter a spot number to place the marker (1 to 9): ";
        cin >> number;
        number--;
        if(number >= 0 && number <= 8 && spaces[number] == '.')
        {
            spaces[number] = player;
            break;
        }
    }
    while(number >= 0 || number <= 10);
}

void computerMove(char *spaces, char computer)
{
    cout << "Computer's Move\n";
    int number;
    srand(time(0));
    while(true)
    {
        number = rand() % 9;
        if(spaces[number] == '.')
        {
            spaces[number] = computer;
            break;
        }
    }
}

bool checkWinner(char *spaces, char player, char computer)
{
    if(spaces[0] != '.' && spaces[0] == spaces[1] && spaces[1] == spaces[2])
    {
        spaces[0] == player ? cout << "Player Wins!" : cout << "Computer Wins!";
    }
    else if(spaces[3] != '.' && spaces[3] == spaces[4] && spaces[4] == spaces[5])
    {
        spaces[3] == player ? cout << "Player Wins!" : cout << "Computer Wins!";
    }
    else if(spaces[6] != '.' && spaces[6] == spaces[7] && spaces[7] == spaces[8])
    {
        spaces[6] == player ? cout << "Player Wins!" : cout << "Computer Wins!";
    }
    else if(spaces[0] != '.' && spaces[0] == spaces[3] && spaces[3] == spaces[6])
    {
        spaces[0] == player ? cout << "Player Wins!" : cout << "Computer Wins!";
    }
    else if(spaces[1] != '.' && spaces[1] == spaces[4] && spaces[4] == spaces[7])
    {
        spaces[1] == player ? cout << "Player Wins!" : cout << "Computer Wins!";
    }
    else if(spaces[2] != '.' && spaces[2] == spaces[5] && spaces[5] == spaces[8])
    {
        spaces[2] == player ? cout << "Player Wins!" : cout << "Computer Wins!";
    }
    else if(spaces[0] != '.' && spaces[0] == spaces[4] && spaces[4] == spaces[8])
    {
        spaces[0] == player ? cout << "Player Wins!" : cout << "Computer Wins!";
    }
    else if(spaces[2] != '.' && spaces[2] == spaces[4] && spaces[4] == spaces[6])
    {
        spaces[2] == player ? cout << "Player Wins!" : cout << "Computer Wins!";
    }
    else
    {
        return false;
    }
    return true;
}

bool checkTie(char *spaces)

{
    for(int i = 0; i < 9; i++)
    {
        if(spaces[i] == '.')
        {
            return false;
        }
    }
    cout << "It's A Tie!";
    return true;
}

void allMoves(char *spaces)
{
    cout << "\nAll Moves performed during the game are: { ";
    for(int i = 0; i < 9; i++)
    {
        cout <<  spaces[i];
    }
    cout << " }";
}
