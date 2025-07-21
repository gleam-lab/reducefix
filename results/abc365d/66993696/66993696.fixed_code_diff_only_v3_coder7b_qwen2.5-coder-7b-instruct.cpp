#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s(n, ' ');
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    
    // Transforming the string based on given rules
    vector<char> transformed(n, ' ');
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'P') transformed[i] = 'S';
        else if (s[i] == 'R') transformed[i] = 'P';
        else transformed[i] = 'R';
    }

    // Function to calculate maximum length of non-consecutive equal characters
    auto maxNonConsecutiveLength = [](const vector<char>& arr) {
        int maxLength = 1, currentLength = 1;
        for (size_t i = 1; i < arr.size(); ++i) {
            if (arr[i] != arr[i - 1]) {
                maxLength = max(maxLength, currentLength);
                currentLength = 1;
            } else {
                ++currentLength;
            }
        }
        return max(maxLength, currentLength);
    };

    // Calculate the result by considering two scenarios:
    // 1. Using the initial transformation
    // 2. Reversing the first character's transformation if it matches the second character
    int result = maxNonConsecutiveLength(transformed);
    if (s[0] == s[1]) {
        transformed[0] = s[0];
        result = max(result, maxNonConsecutiveLength(transformed));
    }

    cout << result << endl;
    return 0;
}