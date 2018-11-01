#include <iostream>
// only difference is on lines 93 and 95
// we will not check for "4 in a row", so you can use either code

using namespace std;

const int RSIZE = 6;
const int CSIZE = 7;
const char BLANK = '.';
const char P1 = 'X';
const char P2 = 'O';

char winner(char board[RSIZE][CSIZE]);
string play(char board[RSIZE][CSIZE], int col, char who);
bool fourInARow(char board[RSIZE][CSIZE], int i, int j, int dr, int dc);
void print(char board[RSIZE][CSIZE]);

int main()
{
    char board[RSIZE][CSIZE];
    for(int i=0; i< RSIZE; i++)
    {
        for(int j=0; j < CSIZE; j++)
        {
            board[i][j] = BLANK;
        }
    }

    string message = "";
    char player = P2;
    while( !winner(board))
    {
        if(player == P2 && message == "") // rotate player turns
        {
            player = P1;
        }
        else if(player == P1 && message == "")
        {
            player = P2;
        }

        print(board);
        cout << message << endl;
        message = "";

        cout << "Which column do you wish to play in?\n";
        char ans;
        cin >> ans;
        string dump;
        getline(cin, dump);

        if('1' <= ans && ans <= '7')
        {
            message = play(board,ans-'1', player);
        }
        else
        {
            message = "Not a valid move, try again...";
        }
    }

    print(board);
    cout << endl;
    if(winner(board) == P1)
    {
        cout << "The mighty " << P1 << "s reign supreme!\n";
    }
    else if(winner(board) == P2)
    {
        cout << "The " << P2 << "s have completed world domination!\n";
    }
    else if(winner(board) == BLANK)
    {
        cout << "Zzzzzzzzzzzzz... draw\n";
    }
    else
    {
        cout << "Derp... something went wrong!";
    }
}

char winner(char board[RSIZE][CSIZE])
{
    int blanks = 0;
    for(int i=0; i< RSIZE; i++)
    {
        for(int j=0; j < CSIZE; j++) // loop through all cells on board
        {
            if(board[i][j] == BLANK) // count how many blanks
            {
                blanks++;
            }
            for(int k=2; k < 6; k++) // check all four directions (up/down, left/right, up-right/down-left, up-left/down-right).
            {
                int dr=k/3, dc=3+dr-k ; // dr & dc change in row/column. so up/down means dr=1, dc=0
                if(board[i][j] != BLANK && fourInARow(board,i,j,dr,dc)) // if 4 in a row (or more) return which player won (char)
                {
                    return board[i][j]==P1?P1:P2;
                }
            }
        }
    }

    if(blanks == 0) // board full and no winner
    {
        return BLANK;
    }
    else // still going!
    {
        return 0;
    }
}

bool fourInARow(char board[RSIZE][CSIZE], int i, int j, int dr, int dc)
{
    // FILL ME IN FOR PART B!
    if((i+3*dr)>=RSIZE||(i+3*dr)<0||(j+3*dc)>=CSIZE||(j+3*dc)<0)
    {
        return false;
    }

    for (int z=0; z<4; z++)
    {
        if (board[i][j]!=board[(z*dr)+i][(z*dc)+j])
        {
            return false;
        }
    }
    return true;
}

string play(char board[RSIZE][CSIZE], int col, char who)
{
    for(int i=RSIZE-1; i >= 0; i--)
    {
        if(board[i][col] == BLANK)
        {
            board[i][col] = who;
            return "";
        }
    }
    return "That column is full (idiot).";
}

void print(char board[RSIZE][CSIZE])
{
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    for(int i=0; i < RSIZE; i++)
    {
        for(int j=0; j < CSIZE; j++)
        {
            cout << board[i][j];
        }
        cout << endl;
    }
    for(int i=1;i<8;i++)
    {
        cout << i;
    }
    cout << endl;
}
