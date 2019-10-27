// find all the paths in an nxn matrix from top left (0, 0) to bottom right (n-1, n-1).
// Path may not contain all squares necessarily.

#include <iostream>
#include <vector>

using std::vector;

void find_path(int b_size, int row, int col, int & soln_cnt) {
    // we can only move 1 step either left, right, up, or down.
    // not diagonally
    
    // std::cout << "row = " << row << " col = " << col << std::endl;
    if ((row == (b_size - 1)) && (col == (b_size - 1))) { // found solution
        ++soln_cnt;
        return;
    }
    
    if (row >= b_size || row < 0 || col >= b_size || col < 0) {
        return; // no solution
    }
    
    // move 1 step down
    find_path(b_size, row+1, col, soln_cnt);
    // move 1 step right
    find_path(b_size, row, col+1, soln_cnt);

}

int main() {
    int n = 4;
    int soln_cnt = 0;
    find_path(n, 0, 0, soln_cnt);
    std::cout << "for n = " << n << ", no. of paths = " 
        << soln_cnt << std::endl;
}
