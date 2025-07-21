#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to solve the problem
long long solve(const string &s) {
    long long ans = 0;
    long long cnt = 1; // Start with 1 to count the first character
    vector<long long> v; // To store counts of repeated characters

    for (size_t i = 1; i < s.length(); ++i) {
        if (s[i] == s[i - 1]) {
            ++cnt; // Increment count if the current character is the same as the previous one
        } else {
            ans += (cnt + 1) / 2; // Add the average of the current count
            v.push_back(cnt); // Store the count
            cnt = 1; // Reset count for the next character
        }
    }
    ans += (cnt + 1) / 2; // Add the average of the last count
    v.push_back(cnt); // Store the last count

    // Adjust the answer by removing unnecessary counts
    for (size_t i = 1; i < v.size() - 1; ++i) {
        if (v[i] > 1 && v[i - 1] > 1) {
            ans -= 1;
        }
    }

    return ans;
}

int main() {
    long long n;
    cin >> n;
    string s;
    cin >> s;
    cout << solve(s) << endl;
    return 0;
}