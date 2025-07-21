#include <iostream>
#include <unordered_set>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::string s;
    std::cin >> s;
    
    // Use an unordered set to store unique characters
    std::unordered_set<char> unique_moves(s.begin(), s.end());
    
    // The size of the set will give us the number of unique moves
    std::cout << unique_moves.size() << std::endl;

    return 0;
}