// generate permutations of string

#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::swap;
using std::vector;

void gen_permut(string & s, int start, vector<string> & result) {
    // generate permutation of string s starting from 'start' character
    // store all permutations in result
    
    static int permut_cnt = 0;
    
    if (start == s.length() - 1) {  // last character, permutation generated
        //cout << "P" << ++permut_cnt << " : " << s << endl;
        result.push_back(s);
        return;
    } 
    
    vector<bool> duplicate(26, false); // to track duplicate characters

    for (int i = start; i < s.length(); ++i) {
        if (duplicate[s[i] - 'A']) { // already used up the character s[i], 
                                     // replacing it would only produce same 
                                     // string we have already produced in this function call.
            continue;
        }
        else
            duplicate[s[i] - 'A'] = true;
    
        string s_copy = s; // make copy since we don't want the original string to get affected
        swap<char>(s_copy[start], s_copy[i]);
        gen_permut(s_copy, start + 1, result);
    }
}

void gen_permut_std(string & s, vector<string> & result) {
    // generate permutations of string s using std::next_permutation
    // and store them in result

    do {
        result.push_back(s);
    } while (std::next_permutation(s.begin(), s.end()));
}

int main() {
    string s = "ABCAAGGHH"; // test string
    vector<string> result1;
    gen_permut(s, 0, result1);
    sort(result1.begin(), result1.end());
    
    string s1 = s;
    sort(s1.begin(), s1.end());
    vector<string> result2;
    gen_permut_std(s1, result2);
    sort(result2.begin(), result2.end());
    cout << "result1.size() " << result1.size();
    cout << " result2.size() " << result2.size() << endl;
    //for (int i = 0, j = 0; i < result1.size(), j < result2.size(); ++i, ++j)
    //    if (result1[i] != result2[j])
    //        cout << result1[i] << " " << result2[j] << endl;
    cout << "test string: " << s << ", result: " 
        << (result1 == result2) << endl;
}
