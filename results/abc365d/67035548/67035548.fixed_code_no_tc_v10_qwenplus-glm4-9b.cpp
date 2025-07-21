#include <iostream>
#include <string>

int cmp(char x, char y) {
    if (x == 'P') return (y == 'S') - (y == 'R');
    if (x == 'R') return (y == 'P') - (y == 'S');
    if (x == 'S') return (y == 'R') - (y == 'P');
    return -100;
}

char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    if (x == 'P') return 'S';
    return 'X';
}

int main() {
    int n;
    std::string s;
    std::cin >> n >> s;
    
    int left = 0, right = n - 1;
    int maxSeq = 0;
    
    // Find the longest sequence from left to right
    while (left < n && cmp(s[left], win(s[left])) >= 0) {
        left++;
    }
    
    // Find the longest sequence from right to left
    while (right >= 0 && cmp(s[right], win(s[right])) <= 0) {
        right--;
    }
    
    // Calculate the maximum sequence length
    maxSeq = std::max(left, n - right - 1);
    
    std::cout << maxSeq << std::endl;
    return 0;
}