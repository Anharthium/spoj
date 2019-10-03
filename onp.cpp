// ------------------- infix to postfix conversion ---------------

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <utility>

using std::stack;
using std::pair;
using std::cout;
using std::cin;
using std::endl;
using std::string;

stack< pair<char, short> > op_st; // operator stack

short op_precedence(char op) {
    // return operator precedence
    // input: operator; output: its precedence value

    switch (op) {
        case '+': return 0;
        case '-': return 1;
        case '*': return 2;
        case '/': return 3;
        case '^': return 4;
        case '(': return 6; 
    }
}

inline bool is_operator(char sym) {
    return (sym == '+' || sym == '-' || sym == '*' || sym == '/' || sym == '^' || sym == '(');
}

inline bool is_operand(char sym) {
    return (sym >= 'a' && sym <= 'z');
}

void in_to_post(string & expr) {
    // infix to postfix converter
    // input: infix expression
    
    
    for (int i = 0; i < expr.length(); ++i) {
        if (is_operator(expr[i])) { // operator
            // pop op_stack until the 
            // top of the stack has less precedence 
            // than curr operator
            if (op_st.empty()) { // stack is empty; straight away push
                op_st.push(std::make_pair(expr[i], op_precedence(expr[i])));
                continue;
            }
            while(1) {
                pair <char, short> & top_op = op_st.top();
                if (op_precedence(top_op.second) >= op_precedence(expr[i])) {
                    cout << top_op.first;
                    op_st.pop();
                }
                else {
                    op_st.push(std::make_pair(expr[i], op_precedence(expr[i])));
                    break;
                }
            }
        }
        else if (is_operand(expr[i])) { // operand; push it to output queue immediately
            cout << expr[i];
        }
        else if (expr[i] == ')') {  // right paranthesis
            while (1) {
                if (op_st.empty()) { // invalid expression; ')' reached before matching '('
                    //cout << "No matching '(' found\n";
                    abort();
                }
                pair <char, short> & top_op = op_st.top();
                if (top_op.first == '(') { // matching '(' found; stop
                    op_st.pop();
                    break;
                }
                else {
                    op_st.pop();
                    cout << top_op.first;
                }
            }
        }
    }

    // pop out the whole op_st (if any)
    while (!(op_st.empty())) {
        pair <char, short> & top_op = op_st.top();
        cout << top_op.first;
        op_st.pop();
    }
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        string expr;
        cin >> expr;
        in_to_post(expr);
        cout << "\n";
    }
}
