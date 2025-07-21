#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> health(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> health[i];
    }
    
    int T = 0, cu = 0;
    bool done = false;
    
    while (!done) {
        done = true;
        for (int i = 0; i < n; ++i) {
            if (cu != 0) { // cu is the accumulated health that needs to be reduced to 0
                if (T % 3 == 0) {
                    cu -= 3;
                } else {
                    cu--;
                }
                if (cu <= 0) {
                    cu = 0;
                    done = false; // If there's still health remaining, continue the loop
                }
            }
            if (health[i] > 0) { // Only attack if the enemy hasn't already been defeated
                T++;
                health[i]--;
                if (health[i] == 0 && cu == 0) {
                    break; // If this enemy is the last one and its health is reduced to zero, we are done
                }
                if (T % 3 == 0) {
                    cu -= 3;
                } else {
                    cu--;
                }
            }
        }
    }
    
    std::cout << T << std::endl;
    
    return 0;
}