#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    long long ans = 0;
    int count = 1;  // Start with a count of 1 assuming the first character is unique

    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            count++;
        } else {
            ans += (count + 1) / 2;  // Add the average of count and 1 to ans
            count = 1;  // Reset count for the next character
        }
    }
    ans += (count + 1) / 2;  // Add for the last group of characters

    cout << ans << "\n";

    return 0;
}