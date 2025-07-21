#include <iostream>
#include <string>

int main() {
    int N;
    std::cin >> N;
    std::string S;
    std::cin >> S;

    int ans = 0;
    char last_char = '\0';

    for (char c : S) {
        if (c != last_char) {
            ans++;
            last_char = c;
        }
    }

    std::cout << ans << std::endl;
    return 0;
}