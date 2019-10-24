#include <iostream>
#include <vector>

using std::vector;

void print_sol(vector<vector<bool>> & board) {
    static int soln_cnt = 0;

    std::cout << "Soln" << ++soln_cnt << " :"<< std::endl;
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}


void n_queens(int col, vector<vector<bool>> & board, 
        vector<bool> & oc_row, vector<bool> & oc_ld, vector<bool> & oc_rd) {
    // find all solutions of n_queens problem

    static int b_size = board.size();

    if (col == b_size) {
        print_sol(board);
        return;
    }

    for (int i = 0; i < b_size; ++i) {
        // check if it's safe to place queen in row 'i' and column 'col'
        
        if (oc_row[i] || oc_ld[i + col] || oc_rd[(i - col) + (b_size - 1)]) continue;

        // place queen
        board[i][col] = true;
        oc_row[i] = oc_ld[i + col] = oc_rd[(i - col) + (b_size - 1)] = true; // adding (b_size - 1) done to shift -ve numbers to +ve side
        
        // for next column
        n_queens(col + 1, board, oc_row, oc_ld, oc_rd);

        // backtrack
        board[i][col] = false;
        oc_row[i] = oc_ld[i + col] = oc_rd[(i - col) + (b_size - 1)] = false;
    }
}

void solve_nqueens(int n) {
    // solve n queens problem in chessboard nxn

    vector<vector<bool>> board(n, vector<bool>(n, false));
    vector<bool> oc_row(n, false);
    vector<bool> oc_rd(2*(n-1) + 1, false); // max sum (row + col) possible in n*n matrix
    vector<bool> oc_ld(2*(n-1) + 1, false); 
    
    n_queens(0, board, oc_row, oc_ld, oc_rd);
}

int main() {
    solve_nqueens(16);
}
