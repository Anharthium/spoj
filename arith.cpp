#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;


#define MAX_DIGITS 500

void add_big_num(vector<int> & v1, vector<int> & v2, vector<int> & v3) {
    // add two big numbers v1 and v2 and store result in v3
    
    int i = 0;
    int j = 0;
    int k = 0;
    
    int dig1 = 0, dig2 = 0, sum = 0, carry = 0;
    while(1) {
        if (i >= v1.size()) dig1 = 0;
        else dig1 = v1[i];
        if (j >= v2.size()) dig2 = 0;
        else dig2 = v2[j];
        
        // time to stop summing
        if (i >= v1.size() && j >= v2.size()) break;

        sum = dig1 + dig2 + carry;
        if (sum >= 10) { // sum more than 1 digit 
            sum %= 10;
            carry = sum / 10; 
        }
        else { // sum has only 1 digit
            carry = 0;
        }
        v3.push_back(sum); // result
        ++k;
        ++i; 
        ++j;
    }
    
    // print formatted
    i = v1.size(); 
    j = v2.size() + 1; // 1 extra for '+'
    int sp[3] = { 0, 0, 0 }; // spaces for i, j, k
    int max_dash = -1; // maximum dash to print
    if (i >= j && i >= k) { // i is the biggest 
        max_dash = i;
        sp[0] = 0;
        sp[1] = i - j;
        sp[2] = i - k;
    }
    else if (j >= i && j >= k) { // j is the biggest
        max_dash = j;
        sp[1] = 0;
        sp[0] = j - i;
        sp[2] = j - k;
    }
    else if (k >= i && k >= j) { // k is the biggest
        max_dash = k;
        sp[2] = 0;
        sp[0] = k - i;
        sp[1] = k - j;
    }
    int plus_count = 0; // no. of '+' 
    for (int line_cnt = 0; line_cnt < 4; ++line_cnt) {
        if (line_cnt != 2) {
            if (plus_count == 0 && line_cnt == 1) {
                plus_count = 1;
                printf("+");
                sp[line_cnt]--;
            } 
            while (1) {
                if (sp[line_cnt]-- > 0) { 
                    printf(" ");
                    continue;
                }
                else {
                    if (line_cnt == 0) printf("%d", v1[--i]); 
                    else if (line_cnt == 1) printf("%d", v2[--j]);
                    else if (line_cnt == 3) printf("%d", v3[--k]);
                }
            }
        }
        else if (line_cnt == 2) { // print '-'
            while (max_dash > 0) {
                printf("-");
                --max_dash;
            }
        }
        printf("\n");
    }
    printf("\n");
}


int main() {
    int t; // test cases
    string expr;
    cin >> t;
    cin.ignore (1, '\n');
    
    vector<int> num1;
    vector<int> num2;
    vector<int> num3;

    num1.reserve(MAX_DIGITS);
    num2.reserve(MAX_DIGITS);
    
    for (int i = 0; i < t; ++i) {
        std::getline(cin, expr);
        bool op_encountered = false;
        char symbol = 0;
        int count1 = 0, count2 = 0;
        for (int j = expr.size() - 1; j >= 0; --j) {
            if (expr[j] == '+' || expr[j] == '-' || expr[j] == '*') {
                op_encountered = true;
                symbol = expr[j];
            }
            else {
                if (op_encountered) {
                    num1.push_back(expr[j]);
                    ++count1;
                }
                else {
                    num2.push_back(expr[j]);
                    ++count2;
                }
            }
        }
        switch (symbol) {
            case '+': add_big_num(num1, num2, num3); break;
            case '-': break;
            default : break;
        }
    }
    

}
