#include "Piezas.h"
#include <vector>
/** CLASS Piezas
 * Class for representing a Piezas vertical board, which is roughly based
 * on the game "Connect Four" where pieces are placed in a column and 
 * fall to the bottom of the column, or on top of other pieces already in
 * that column. For an illustration of the board, see:
 *  https://en.wikipedia.org/wiki/Connect_Four
 *
 * Board coordinates [row,col] should match with:
 * [2,0][2,1][2,2][2,3]
 * [1,0][1,1][1,2][1,3]
 * [0,0][0,1][0,2][0,3]
 * So that a piece dropped in column 2 should take [0,2] and the next one
 * dropped in column 2 should take [1,2].
**/


/**
 * Constructor sets an empty board (default 3 rows, 4 columns) and 
 * specifies it is X's turn first
**/
Piezas::Piezas()
{
    reset();
    turn = X;
}

/**
 * Resets each board location to the Blank Piece value, with a board of the
 * same size as previously specified
**/
void Piezas::reset()
{
    for(int i = 0; i < BOARD_ROWS; i++)
    {
        for(int j = 0; j < BOARD_COLS; j++)
        {
            board[i][j] = Blank;
        }
    }
}

/**
 * Places a piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. dropPiece does 
 * NOT allow to place a piece in a location where a column is full.
 * In that case, placePiece returns Piece Blank value 
 * Out of bounds coordinates return the Piece Invalid value
 * Trying to drop a piece where it cannot be placed loses the player's turn
**/ 
Piece Piezas::dropPiece(int column)
{
    //Out of bounds placement means turn switches, return valid
    if(column > 3 || column < 0)
    {
        if(turn == X)
        {
            turn = O;
        }
        else
        {
            turn = X;
        }

        return Invalid;
    }

    //checking from bottom of column to the top, else return nothing
    if(board[2][column] == Blank)
    {
        board[2][column] = turn;

        if(turn == X)
        {
            turn = O;
        }
        else
        {
            turn = X;
        }

        return board[2][column];
    }
    else if(board[1][column] == Blank)
    {
        board[1][column] = turn;

        if(turn == X)
        {
            turn = O;
        }
        else
        {
            turn = X;
        }

        return board[1][column];
    }
    else if(board[0][column] == Blank)
    {
        board[0][column] = turn;

        if(turn == X)
        {
            turn = O;
        }
        else
        {
            turn = X;
        }

        return board[0][column];
    }
    else
    {
        return Blank;
    }
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece Piezas::pieceAt(int row, int column)
{
    if((row > 2 || row < 0) || (column < 0 || column > 3))
    {
        return Invalid;
    }

    if(board[row][column] != Blank)
    {
        return board[row][column];
    }
    else
    {
        return Blank;
    }
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won ("tie").
 * For a game to be over, all locations on the board must be filled with X's 
 * and O's (i.e. no remaining Blank spaces). The winner is which player has
 * the most adjacent pieces in a single line. Lines can go either vertically
 * or horizontally. If both X's and O's have the same max number of pieces in a
 * line, it is a tie.
**/
Piece Piezas::gameState()
{
    int max_x = 0;
    int max_o = 0;
    int x_amount;
    int o_amount;
    bool full_col_x = false;
    bool full_col_o = false;
    bool three_adj_x = false;
    bool three_adj_o = false;
    bool two_adj_x = false;
    bool two_adj_o = false;

    for(int i = 0; i < BOARD_ROWS; i++)
    {
        for(int j = 0; j < BOARD_COLS; j++)
        {
            if(board[i][j] == Blank)
            {
                return Invalid;
            }
        }
    }

    //check horizontal
    for(int i = 0; i < BOARD_ROWS; i++)
    {
        x_amount = 0;
        o_amount = 0;

        for(int j = 0; j < BOARD_COLS; j++)
        {
            if(board[i][j] == X)
            {
                x_amount++;
            }
            else
            {
                o_amount++;
            }
        }

        if(x_amount > max_x)
        {
            max_x = x_amount;
        }
        if(o_amount > max_o)
        {
            max_o = o_amount;
        }
    }

    //check for any max values of 4, that would automatically win or tie
    if(max_x == BOARD_COLS && max_o == BOARD_COLS)
    {
        return Blank;
    }
    else if(max_x == BOARD_COLS)
    {
        return X;
    }
    else if(max_o == BOARD_COLS)
    {
        return O;
    }

    //check verticals
    //check column 0
    if(board[0][0] == X)
    {
        if(board[1][0] == X)
        {
            if(board][2][0] == X)
            {
                x_amount = 3;
                full_col_x = true;
            }
            else
            {
                x_amount = 2;
            }
        }
        else
        {
            x_amount = 1;
        }
    }
    else
    {
        if(board[1][0] == O)
        {
            if(board[2][0] == O)
            {
                o_amount = 3;
                full_col_o = true;
            }
            else
            {
                o_amount = 2;
            }
        }
        else
        {
            o_amount = 1;
        }
    }
    if(x_amount > max_x)
    {
        max_x = x_amount;
    }
    if(o_amount > max_o)
    {
        max_o = o_amount;
    }

    //check column 1
    if(board[0][1] == X)
    {
        if(board[1][1] == X)
        {
            if(board[2][1] == X)
            {
                x_amount = 3;
                full_col_x = true;
            }
            else
            {
                x_amount = 2;
            }
        }
        else
        {
            x_amount = 1;
        }
    }
    else
    {
        if(board[1][1] == O)
        {
            if(board[2][1] == O)
            {
                o_amount = 3;
                full_col_o = true;
            }
            else
            {
                o_amount = 2;
            }
        }
        else
        {
            o_amount = 1;
        }
    }
    if(x_amount > max_x)
    {
        max_x = x_amount;
    }
    if(o_amount > max_o)
    {
        max_o = o_amount;
    }

    //check column 2
    if(board[0][2] == X)
    {
        if(board[1][2] == X)
        {
            if(board[2][2] == X)
            {
                x_amount = 3;
                full_col_x = true;
            }
            else
            {
                x_amount = 2;
            }
        }
        else
        {
            x_amount = 1;
        }
    }
    else
    {
        if(board[1][2] == O)
        {
            if(board[2][2] == O)
            {
                o_amount = 3;
                full_col_o = true;
            }
            else
            {
                o_amount = 2;
            }
        }
        else
        {
            o_amount = 1;
        }
    }
    if(x_amount > max_x)
    {
        max_x = x_amount;
    }
    if(o_amount > max_o)
    {
        max_o = o_amount;
    }

    //check column 3
    if(board[0][3] == X)
    {
        if(board[1][3] == X)
        {
            if(board[2][3] == X)
            {
                x_amount = 3;
                full_col_x = true;
            }
            else
            {
                x_amount = 2;
            }
        }
        else
        {
            x_amount = 1;
        }
    }
    else
    {
        if(board[1][3] == O)
        {
            if(board[2][3] == O)
            {
                o_amount = 3;
                full_col_o = true;
            }
            else
            {
                o_amount = 2;
            }
        }
        else
        {
            o_amount = 1;
        }
    }
    if(x_amount > max_x)
    {
        max_x = x_amount;
    }
    if(o_amount > max_o)
    {
        max_o = o_amount;
    }

    //check for 3 x's in a row
    if(max_x == BOARD_ROWS)
    {
        if(full_col_x == true)
        {
            three_adj_x = true;
        }
        else
        {
            for(int i = 0; i < BOARD_ROWS; i++)
            {
                if(board[i][0] == X)
                {
                    if(board[i][1] == X && board[i][2] == X)
                    {
                        three_adj_x = true;
                    }
                }
                else if(board[i][1] == X)
                {
                    if(board[i][2] == X && board[i][3] == X)
                    {
                        three_adj_x = true;
                    }
                }
            }
        }
    }

    //check for 3 o's in a row
    if(max_o == BOARD_ROWS)
    {
        if(full_col_o == true)
        {
            three_adj_o = true;
        }
        else
        {
            for(int i = 0; i < BOARD_ROWS; i++)
            {
                if(board[i][0] == O)
                {
                    if(board[i][1] == O && board[i][2] == O)
                    {
                        three_adj_o = true;
                    }
                }
                else if(board[i][1] == O)
                {
                    if(board[i][2] == O && board[i][3] == O)
                    {
                        three_adj_o = true;
                    }
                }
            }
        }
    }

    //check for tie of 3 in a row
    if(three_adj_x && three_adj_o)
    {
        return Blank;
    }
    else if(three_adj_x)
    {
        return X;
    }
    else if(three_adj_o)
    {
        return O;
    }

    //if max is 2 for either, check if they are in a row
    if(max_x == 2)
    {
        for(int i = 0; i < BOARD_ROWS; i++)
        {
            if(board[i][0] == X && board[i][1] == X)
            {
                two_adj_x = true;
            }
            else if(board[i][1] == X && board[i][2] == X)
            {
                two_adj_x = true;
            }
            else if(board[i][2] == X && board[i][3] == X)
            {
                two_adj_x = true;
            }
        }
        for(int j = 0; j < BOARD_COLS; j++)
        {
            if(board[0][j] == X && board[1][j] == X)
            {
                two_adj_x = true;
            }
            else if(board[1][j] == X && board[2][j] == X)
            {
                two_adj_x = true;
            }
        }
    }

    if(max_o == 2)
    {
        for(int i = 0; i < BOARD_ROWS; i++)
        {
            if(board[i][0] == O && board[i][1] == O)
            {
                two_adj_o = true;
            }
            else if(board[i][1] == O && board[i][2] == O)
            {
                two_adj_o = true;
            }
            else if(board[i][2] == O && board[i][3] == O)
            {
                two_adj_o = true;
            }
        }
        for(int j = 0; j < BOARD_COLS; j++)
        {
            if(board[0][j] == O && board[1][j] == O)
            {
                two_adj_o = true;
            }
            else if(board[1][j] == O && board[2][j] == O)
            {
                two_adj_o = true;
            }
        }
    }

    //check for tie of 2 in a row
    if(two_adj_x && two_adj_o)
    {
        return Blank;
    }
    else if(two_adj_x)
    {
        return X;
    }
    else if(two_adj_o)
    {
        return O;
    }

    //if all above fails to return, max is 1 for both, results in tie
    return Blank;
}