#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int dp[20][2][20][20];

// Convert a number to a string
string numToString(int num) {
    return to_string(num);
}

// Digit DP function to count palindromes
int digitDP(const string &s, int pos, int tight, int left, int right) {
    if (pos > right) return 1;
    if (left > right) return 1;

    int &res = dp[pos][tight][left][right];
    if (res != -1) return res;

    int limit = tight ? s[pos] - '0' : 9;
    res = 0;

    for (int digit = 0; digit <= limit; ++digit) {
        int new_tight = (tight && (digit == limit));
        if (pos == left) {
            res += digitDP(s, pos + 1, new_tight, left + 1, right - 1);
        } else if (pos == right) {
            res += digitDP(s, pos + 1, new_tight, left, right - 1);
        } else if (digit == s[left] - '0') {
            res += digitDP(s, pos + 1, new_tight, left + 1, right - 1);
        }
    }

    return res;
}

// Function to count palindromic numbers up to a given limit
int countPalindromes(int x) {
    string s = numToString(x);
    memset(dp, -1, sizeof(dp));
    return digitDP(s, 0, 1, 0, s.size() - 1);
}

// Main function to count palindromic numbers between i and j
int countPalindromicNumbersInRange(int i, int j) {
    return countPalindromes(j) - countPalindromes(i - 1);
}

int main() {
    int i, j;
    cin >> i >> j;
    cout << countPalindromicNumbersInRange(i, j) << endl;
    return 0;
}
