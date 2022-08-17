#include <iostream>     //docs faheem
using namespace std;
int player = 1, opponent = 2;
class TicTacToe
{
    public:
    int row, col;
    bool isMovesLeft(int** board)
    {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (board[i][j] == 0)
                    return true;
        return false;
    }

    int evaluate(int** b)
    {

        // Checking for Rows for X or O victory.
        for (int row = 0; row < 3; row++)
        {
            if (b[row][0] == b[row][1] &&
                b[row][1] == b[row][2])
            {
                if (b[row][0] == player)
                    return 10; // maximizer
                else if (b[row][0] == opponent)
                    return -10; // minimizer
            }
        }

        // Checking for Columns for X or O victory.
        for (int col = 0; col < 3; col++)
        {
            if (b[0][col] == b[1][col] &&
                b[1][col] == b[2][col])
            {
                if (b[0][col] == player)
                    return 10;

                else if (b[0][col] == opponent)
                    return -10;
            }
        }

        // Checking for Diagonals for X or O victory.
        if (b[0][0] == b[1][1] && b[1][1] == b[2][2])
        {
            if (b[0][0] == player)
                return 10;
            else if (b[0][0] == opponent)
                return -10;
        }

        if (b[0][2] == b[1][1] && b[1][1] == b[2][0])
        {
            if (b[0][2] == player)
                return 10;
            else if (b[0][2] == opponent)
                return -10;
        }

        // Else if none of them have won then return 0
        return 0; // draw
    }

    int check(int** b)
    {
        int p1num = 0, p2num = 0;
        for (int i = 0; i < 3; i++) // check for invalid board
        {
            for (int j = 0; j < 3; j++)
            {
                if (b[i][j] == 1)
                    p1num++;
                else if (b[i][j] == 2)
                    p2num++;
            }
        }
        // cout << "p1num = " << p1num << " p2num = " << p2num << endl;
        if (p1num - p2num > 1)
            return -1;
        // Checking for Rows for X or O victory.
        for (int row = 0; row < 3; row++)
        {
            if (b[row][0] == b[row][1] &&
                b[row][1] == b[row][2])
            {
                if (b[row][0] == player)
                    return 1; // maximizer
                else if (b[row][0] == opponent)
                    return 2; // minimizer
            }
        }

        // Checking for Columns for X or O victory.
        for (int col = 0; col < 3; col++)
        {
            if (b[0][col] == b[1][col] &&
                b[1][col] == b[2][col])
            {
                if (b[0][col] == player)
                    return 1;

                else if (b[0][col] == opponent)
                    return 2;
            }
        }

        // Checking for Diagonals for X or O victory.
        if (b[0][0] == b[1][1] && b[1][1] == b[2][2])
        {
            if (b[0][0] == player)
                return 1;
            else if (b[0][0] == opponent)
                return 2;
        }

        if (b[0][2] == b[1][1] && b[1][1] == b[2][0]) // reverse diagonal
        {
            if (b[0][2] == player)
                return 1;
            else if (b[0][2] == opponent)
                return 2;
        }

        // Else if none of them have won then return 0
        return 0; // draw
    }
    bool check2(int** b)
    {
        int temp[3][3] = {2, 0, 0,
                        0, 1, 0,
                        0, 0, 1};

        for(int x = 0; x < 3; x++)
        {
            for(int y = 0; y < 3; y++)
            {
                if(b[x][y] != temp[x][y]) return false;
            }
        }
        return true;
    }

    // This is the minimax function. It considers all
    // the possible ways the game can go and returns
    // the value of the board
    int minimax(int** board, int depth, bool isMax)
    {
        int score = evaluate(board);

        // If Maximizer has won the game return his/her
        // evaluated score
        if (score == 10)
            return score;

        // If Minimizer has won the game return his/her
        // evaluated score
        if (score == -10)
            return score;

        // If there are no more moves and no winner then
        // it is a tie
        if (isMovesLeft(board) == false)
            return 0;

        // If this maximizer's move
        if (isMax)
        {
            int best = -1000;

            // Traverse all cells
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    // Check if cell is empty
                    if (board[i][j] == 0)
                    {
                        // Make the move
                        board[i][j] = player;

                        // Call minimax recursively and choose
                        // the maximum value
                        best = max(best,
                                minimax(board, depth + 1, !isMax));

                        // Undo the move
                        board[i][j] = 0;
                    }
                }
            }
            return best;
        }

        // If this minimizer's move
        else
        {
            int best = 1000;

            // Traverse all cells
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    // Check if cell is empty
                    if (board[i][j] == 0)
                    {
                        // Make the move
                        board[i][j] = opponent;

                        // Call minimax recursively and choose
                        // the minimum value
                        best = min(best,
                                minimax(board, depth + 1, !isMax));

                        // Undo the move
                        board[i][j] = 0;
                    }
                }
            }
            return best;
        }
    }
    // This will return the best possible move for the player
    TicTacToe findBestMove(int** board)
    {
        int bestVal = -1000;
        TicTacToe bestMove;
        bestMove.row = -1;
        bestMove.col = -1;

        // Traverse all cells, evaluate minimax function for
        // all empty cells. And return the cell with optimal
        // value.
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                // Check if cell is empty
                if (board[i][j] == 0)
                {
                    // Make the move
                    board[i][j] = player;

                    // compute evaluation function for this
                    // move.
                    int moveVal = minimax(board, 0, false);

                    // Undo the move
                    board[i][j] = 0;

                    // If the value of the current move is
                    // more than the best value, then update
                    // best
                    if (moveVal > bestVal)
                    {
                        bestMove.row = i;
                        bestMove.col = j;
                        bestVal = moveVal;
                    }
                }
            }
        }
        return bestMove;
    }

    int getI(int** arr)
    {
        int count = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (arr[i][j] != 0)
                    count++;
            }
        }
        return count;
    }
};




int main()
{
    int** board=new int*[3];
    TicTacToe Game;
    for (int i = 0; i < 3; i++)
    {
        board[i]=new int[3];
        for (int j = 0; j < 3; j++)
        {
            cin >> board[i][j];
        }
    }
    if(Game.check2(board))   
    {
        cout << 0 << endl;
        return 0;
    }

    int i = Game.getI(board);
    for (i; i < 9; i++)
    {
        TicTacToe bestMove = Game.findBestMove(board);
        if (i % 2 == 0)
            board[bestMove.row][bestMove.col] = 1;
        else
            board[bestMove.row][bestMove.col] = 2;
    }
    int res = Game.check(board);
    cout << res << endl;
    return 0;
}