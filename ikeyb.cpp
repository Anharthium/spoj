#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <unordered_map>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::unordered_map;
using std::make_pair;
using std::sort;

void find_optimal_keyb(vector<pair<int, char>> & letter_f, string & keys) {
    // find optimal keyboard
    
    vector<vector<char>> soln(keys.length()); // soln. set
    unordered_map<char, int> key_map; // mapping between key characters 
                                      // and its index in keys string

    for (int i = 0; i < keys.length(); ++i)
        key_map[keys[i]] = i;

    // sort letter_f in descending order
    sort(letter_f.begin(), letter_f.end(), std::greater<pair<int, char>>());

}


int main() {
    
    int t; // test cases
    cin >> t;
    
    for (int i = 0; i < t; ++i) {
        int k, l; // number of keys and letters
        cin >> k >> l;
        vector<pair<int, char>> letter_f(l); // letter frequency 
                                             // (first: frequency, second: letter)
        string keys, letters;
        cin >> keys;
        cin >> letters;
        for (int j = 0; j < l; ++j) { // get frequency of each letter
            int freq;
            cin >> freq;
            letter_f[j] = make_pair(freq, letters[j]);
        }

        find_optimal_keyb(letter_f, keys);
    }
}
