// cmpls -- complete the sequence (using method of differences)

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

void compl_seq(vector<int> & in_num, int num_given, int num_to_find) {
    // complete the sequence given in in_num by 
    // finding num_to_find numbers 
    
    vector <vector<int> *> diff_table; // pointers to diff table vectors
    int dtable_n = 0; // diff table number
    while (1) {
        
        vector <int> * curr_diff = new vector<int>; // curr diff table
        bool equal = true; // are the current diff table entries equal or not?
        bool check_over = false; // should the curr diff table entries comparision stopped or not
        
        // calculate curr diff_table
        for (int i = 0; ; ++i) {

            if (diff_table.size() == 0) { // calculate diff table from input numbers
                if (i == in_num.size() - 1) {

                    if (in_num.size() == 1) // special case only 1 input number; diff should be 0
                        (*curr_diff).push_back(0);
                    
                    diff_table.push_back(curr_diff); // push back curr diff table
                    ++dtable_n; 
                    break;
                }
                
                (*curr_diff).push_back(in_num[i+1] - in_num[i]);
            }
            else {  // calculate diff table for i from diff_table of i-1
                if (i == (*diff_table[dtable_n - 1]).size() - 1) {
                    diff_table.push_back(curr_diff); // push back curr diff table
                    ++dtable_n; 
                    break;
                }
                
                (*curr_diff).push_back((*diff_table[dtable_n - 1])[i+1] - (*diff_table[dtable_n - 1])[i]);
            }
            
            // check if all values of curr diff table is equal 
            if (i > 0) {
                if (!check_over) {
                    if ((*curr_diff)[i] != (*curr_diff)[i-1]) {
                        equal = false;
                        check_over = true; // no need to check now
                    }
                }
            }
        }

        if (equal) break;
        if ((*curr_diff).size() == 1) break; // only one element present
    }

    //cout << "dtable size: " << dtable_n << endl;
    
    // extend the final diff table entries
    vector <int> & last_diff = *diff_table[dtable_n - 1];
    int comm_num = last_diff[0]; // common number; at least one entry should be present
    for (int i = last_diff.size();
            i < num_given + num_to_find; ++i) {
        last_diff.push_back(comm_num);
    }
    
    // calculate results
    for (int i = dtable_n - 2; i >= 0; --i) {
        
        if (dtable_n == 1) break; // special case; only one difference table, 
                                  // code after this loop will handle that
        
        vector<int> & curr_diff = *diff_table[i];
        vector<int> & next_diff = *diff_table[i+1];
        for (int j = curr_diff.size(); j < next_diff.size(); ++j) { // go till next diff_table's size
            curr_diff.push_back(next_diff[j-1] + curr_diff[j-1]);
        }
    }

    // extend input numbers
    vector<int> & next_diff = *diff_table[0];
    for (int j = in_num.size(); j < next_diff.size(); ++j) { // go till next diff_table's size
        in_num.push_back(next_diff[j-1] + in_num[j-1]);
    }

    // print results
    int i;
    for (i = num_given; i < (num_given + num_to_find) - 1; ++i)
        cout << in_num[i] << " "; 
    cout << in_num[i]; // final number

    // clean up
    for (int i = 0; i < dtable_n; ++i)
        delete diff_table[i];
}


int main() {
    int t; // test cases
    cin >> t;
    for (int i = 0; i < t; ++i) {
        vector<int> in_num;         // to hold input numbers
        int num_given, num_to_find; // numbers given and numbers to find
        cin >> num_given;
        cin >> num_to_find;
        for (int j = 0; j < num_given; ++j) {
            int n;
            cin >> n;
            in_num.push_back(n);
        }
        compl_seq(in_num, num_given, num_to_find);
        cout << endl;
    }
}

