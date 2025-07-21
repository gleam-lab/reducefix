#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int n = s.size();

    // Initialize variables to track the number of changes needed
    int changes = 0;

    // Iterate through the string and count the number of changes needed
    for (int i = 1; i < n; ++i) {
        if (s[i] != s[i - 1]) {
            ++changes;
        }
    }

    // Output the result
    cout << changes + 1 << endl;

    return 0;
}