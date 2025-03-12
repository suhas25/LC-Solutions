//
// Created by Suhas Reddy on 3/9/25.
//

class TicTacToe
{
  public:
  struct Board{
    int size;
    Board(int n)
    {
      this->size=n;
    }
    vector<int>rows, cols;
    int diagonal, anti_diagonal;
  };

  Board *board;
  TicTacToe(int n)
  {
    board = new Board(n);
    board->rows.resize(n, 0);
    board->cols.resize(n, 0);
    board->diagonal=0, board->anti_diagonal=0;
  }

  int move(int row, int col, int player)
  {
    int value=(player==1)?1:-1;

    board->rows[row]+=value;
    board->cols[col]+=value;

    if(row==col)
      board->anti_diagonal+=value;
    if(row+col==board->size-1)
      board->diagonal+=value;

    if((abs(board->rows[row])==board->size) ||(abs(board->cols[col])==board->size)
        ||(abs(board->anti_diagonal)==board->size) ||(abs(board->diagonal)==board->size))
      return player;

    return 0;
  }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */