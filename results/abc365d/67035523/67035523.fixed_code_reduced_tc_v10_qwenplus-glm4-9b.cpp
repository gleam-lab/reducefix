#include <iostream>
#include <string>

int main() {
    int n;
    std::string s;
    std::cin >> n >> s;
    
    // Initialize the previous character to 'X' to handle the case where the first character is not 'R', 'S', or 'P'.
    char prev = 'X';
    int ans = 0;
    
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'R' || s[i] == 'S' || s[i] == 'P') {
            if (prev != 'X' && prev != s[i]) {
                // If the previous character was different and is not equal to the current character, increment the answer.
                ans++;
            }
            prev = s[i]; // Update the previous character to the current one.
        }
    }
    
    // Output the result.
    std::cout << ans << std::endl;
    
    return 0;
}