#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    // Initialize variables
    int max_merged = 0;
    int current = 1;
    
    // Traverse from the start to the end
    for (int i = 0; i < n; ++i) {
        if (i == 0 || (i > 0 && s[i] != s[i - 1])) {
            current = 1;
        } else {
            current++;
        }
        max_merged = max(max_merged, current);
    }
    
    current = 1;
    // Traverse from the end to the start
    for (int i = n - 1; i >= 0; --i) {
        if (i == n - 1 || (i < n - 1 && s[i] != s[i + 1])) {
            current = 1;
        } else {
            current++;
        }
        max_merged = max(max_merged, current);
    }
    
    cout << max_merged << endl;
    return 0;
}