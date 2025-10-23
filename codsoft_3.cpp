#include <iostream>
using namespace std;

char board[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };

void boardmaker(char arr[3][3])
{
    cout << "-------\n";
    cout << "|" << arr[0][0] << "|" << arr[0][1] << "|" << arr[0][2] << "|\n";
    cout << "-------\n";
    cout << "|" << arr[1][0] << "|" << arr[1][1] << "|" << arr[1][2] << "|\n";
    cout << "-------\n";
    cout << "|" << arr[2][0] << "|" << arr[2][1] << "|" << arr[2][2] << "|\n";
    cout << "-------\n";
}

bool checkWinner(char arr[3][3]) 
{
    for (int i = 0; i < 3; i++)
    {
        if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2])
            return true;
        if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i])
            return true;
    }
    if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2])
        return true;
    if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0])
        return true;
    return false;
}

void game() {
    char currentPlayer = 'X';
    int count = 0;
    int slot;

    cout << "Player 1 has X symbol\n";
    cout << "Player 2 has O symbol\n";

    while (true) {
        boardmaker(board);
        cout << "Player " << ((currentPlayer == 'X') ? 1 : 2) << ", enter slot (1-9): ";
        cin >> slot;

        // ✅ Fix added here (handles character or invalid input)
        if (cin.fail()) {
            cin.clear();            // clear error flag
            cin.ignore(1000, '\n'); // discard invalid input
            cout << "Invalid input! Please enter a number between 1 and 9.\n";
            continue;
        }

        if (slot < 1 || slot > 9) {
            cout << "Invalid slot! Try again.\n";
            continue;
        }

        int row = (slot - 1) / 3;
        int col = (slot - 1) % 3;

        if (board[row][col] == 'X' || board[row][col] == 'O') {
            cout << "Slot already taken! Try again.\n";
            continue;
        }

        board[row][col] = currentPlayer;
        count++;

        if (checkWinner(board)) {
            boardmaker(board);
            cout << "Player " << ((currentPlayer == 'X') ? 1 : 2) << " wins!\n";
            break;
        }

        if (count == 9) {
            boardmaker(board);
            cout << "It's a draw!\n";
            break;
        }

        // player switch
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
}

int main() {
    game();
    return 0;
}
