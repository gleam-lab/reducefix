#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;
    std::vector<long long> A(N), B(N - 1);
    for (int i = 0; i < N; ++i) std::cin >> A[i];
    for (int i = 0; i < N - 1; ++i) std::cin >> B[i];

    // Sort the toy sizes in descending order
    std::sort(A.begin(), A.end(), std::greater<long long>());

    // Iterate through each toy and check if it can fit into any box
    long long maxToySize = 0;
    for (int i = 0; i < N; ++i) {
        bool canFit = false;
        for (int j = 0; j < N - 1; ++j) {
            if (A[i] <= B[j]) {
                canFit = true;
                break;
            }
        }
        // If the toy cannot fit into any box, it will be our candidate for the box size
        if (!canFit) {
            maxToySize = A[i];
            break;
        }
    }

    // Check if all other toys can fit into the box of size maxToySize
    bool allCanFit = true;
    for (int i = 0; i < N; ++i) {
        bool canFit = false;
        for (int j = 0; j < N - 1; ++j) {
            if (A[i] <= B[j]) {
                canFit = true;
                break;
            }
        }
        if (!canFit) {
            allCanFit = false;
            break;
        }
    }

    // If all toys can fit into the box of size maxToySize, print maxToySize, otherwise print -1
    if (allCanFit) {
        std::cout << maxToySize << std::endl;
    } else {
        std::cout << -1 << std::endl;
    }

    return 0;
}