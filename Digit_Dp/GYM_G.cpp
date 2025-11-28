// https://codeforces.com/gym/100886/problem/G

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// Function to calculate the product of digits of a number
long long digitProduct(long long x) {
    long long product = 1;
    while (x > 0) {
        product *= (x % 10);
        x /= 10;
    }
    return product;
}

// Function to generate candidates by manipulating digits
vector<long long> generateCandidates(long long num) {
    string s = to_string(num);
    vector<long long> candidates;
    candidates.push_back(num); // include the number itself

    // Generate candidates by changing trailing digits to 9
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '0') continue; // skip if digit is zero
        string temp = s;
        temp[i] = (temp[i] - 1);
        for (int j = i + 1; j < s.size(); ++j) {
            temp[j] = '9';
        }
        candidates.push_back(stoll(temp));
    }
    return candidates;
}

// Main function to find the number with the maximum product of digits in the range [a, b]
long long maxDigitProductInRange(long long a, long long b) {
    vector<long long> candidates;
    candidates.push_back(a);
    candidates.push_back(b);

    // Generate candidates around the boundaries
    vector<long long> cand_a = generateCandidates(a);
    vector<long long> cand_b = generateCandidates(b);

    candidates.insert(candidates.end(), cand_a.begin(), cand_a.end());
    candidates.insert(candidates.end(), cand_b.begin(), cand_b.end());

    long long maxProduct = 0;
    long long bestNumber = a;

    // Evaluate all candidates
    for (long long num : candidates) {
        if (num >= a && num <= b) {
            long long product = digitProduct(num);
            if (product > maxProduct) {
                maxProduct = product;
                bestNumber = num;
            }
        }
    }

    return bestNumber;
}

int main() {
    long long a, b;
    cin >> a >> b;
    cout << maxDigitProductInRange(a, b) << endl;
    return 0;
}
