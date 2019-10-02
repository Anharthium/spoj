#include <iostream>
#include <cmath>
#include <unordered_map>

std::unordered_map<int, bool> prime_table; // look up table for prime numbers

bool is_prime(int n) {
    if (n == 2) {
        prime_table[n] = true; 
        return true;
    }
    int sqrt_n = std::sqrt(n) + 1;

    for (int i = 2; i < sqrt_n; ++i) {
        if (n % i == 0) { // evenly divisible by i
            prime_table[n] = false;
            return false;
        }
    }
    prime_table[n] = true;
    return true;
}

int main() {
    using std::cin;
    using std::cout;
    using std::endl;
    int t;
    cin >> t; // test cases
    for (int i = 0; i < t; ++i) {
        int m, n; // start and end
        cin >> m;
        cin >> n;
        for (int i = m; i <= n; ++i) {
            if (i == 1) continue; // 1 is not prime
            if (i % 2 == 0 && i != 2) continue; // even numbers are not prime except 2
            if (prime_table.find(i) == prime_table.end()) { // i not present in hash table
                if (is_prime(i)) 
                    cout << i << "\n";
            }
            else {
                if (prime_table[i])
                    cout << i << "\n";
            }
        }
    }
}
