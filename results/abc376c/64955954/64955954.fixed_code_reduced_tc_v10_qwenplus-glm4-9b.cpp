#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> toys(n);
    std::vector<int> boxes(n - 1);
    
    for (int i = 0; i < n; ++i) {
        std::cin >> toys[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        std::cin >> boxes[i];
    }
    
    // æåº
    std::sort(toys.begin(), toys.end());
    std::sort(boxes.begin(), boxes.end());
    
    // ä»æå¤§å¼å§æ£æ¥
    for (int i = n - 1; i >= 0; --i) {
        bool placed = false;
        for (int j = 0; j < n - 1; ++j) { // æ£æ¥ç°æçå­
            if (boxes[j] >= toys[i]) {
                placed = true;
                break;
            }
        }
        if (!placed) { // å¦æä¸è½æ¾ç½®ï¼éè¦ä¸ä¸ªæ°ççå­
            std::cout << toys[i] << std::endl;
            return 0;
        }
    }
    
    // å¦æææé½å¯ä»¥æ¾ç½®ï¼ä¸éè¦æ°çå­
    std::cout << "0" << std::endl;
    return 0;
}