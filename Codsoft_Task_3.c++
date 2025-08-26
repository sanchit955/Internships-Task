#include <iostream>
#include <vector>
using namespace std;

void showBoard(const vector<char>& b) {
    cout << "\n";
    for (int i = 0; i < 9; i++) {
        cout << b[i];
        if ((i+1)%3) cout << " | ";
        if ((i+1)%3==0 && i<8) cout << "\n---------\n";
    }
    cout << "\n";
}

bool win(const vector<char>& b) {
    for (int i = 0; i < 3; i++)
        if (b[i]==b[i+3] && b[i+3]==b[i+6] && b[i]!=' ') return true;
    for (int i = 0; i < 9; i+=3)
        if (b[i]==b[i+1] && b[i+1]==b[i+2] && b[i]!=' ') return true;
    if ((b[0]==b[4] && b[4]==b[8] && b[0]!=' ') || (b[2]==b[4] && b[4]==b[6] && b[2]!=' '))
        return true;
    return false;
}

bool draw(const vector<char>& b) {
    for (auto x : b)
        if (x == ' ')
            return false;
    return true;
}

int main() {
    while (true) {
        vector<char> board(9, ' ');
        char player = 'X';
        bool game_over = false;

        while (!game_over) {
            showBoard(board);
            int move;
            cout << "Player " << player << ", enter position (1-9): ";
            cin >> move;
            move--;
            if (move < 0 || move > 8 || board[move] != ' ') {
                cout << "Invalid move. Try again.\n";
                continue;
            }
            board[move] = player;
            if (win(board)) {
                showBoard(board);
                cout << "Player " << player << " wins!\n";
                game_over = true;
            }
            else if (draw(board)) {
                showBoard(board);
                cout << "It's a draw!\n";
                game_over = true;
            } else
                player = (player == 'X') ? 'O' : 'X';
        }
        char again;
        cout << "Play again? (y/n): ";
        cin >> again;
        if (again != 'y' && again != 'Y') break;
    }
    return 0;
}
