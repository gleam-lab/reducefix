#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> toys(N), boxes(N - 1);

    for (int i = 0; i < N; ++i) {
        std::cin >> toys[i];
    }
    for (int i = 0; i < N - 1; ++i) {
        std::cin >> boxes[i];
    }

    // Sort the toy and box sizes
    std::sort(toys.begin(), toys.end());
    std::sort(boxes.begin(), boxes.end());

    // Find the minimum box size x
    int minBoxSize = 0;
    for (int i = 0; i < N; ++i) {
        // Find the smallest box that can hold the current toy
        // We start from the previous box size because we need a box larger than the previous one
        while (minBoxSize < N - 1 && boxes[minBoxSize] < toys[i]) {
            minBoxSize++;
        }

        // If we have reached the end of the boxes and still cannot find a box of suitable size
        if (minBoxSize == N - 1) {
            // We need to find the smallest box that is larger than any previously used box size
            while (minBoxSize < N - 1 && boxes[minBoxSize] <= toys[i]) {
                minBoxSize++;
            }
            // If there's no suitable box, return -1
            if (minBoxSize == N - 1) {
                std::cout << -1 << std::endl;
                return 0;
            }
        }
    }
    std::cout << boxes[minBoxSize] << std::endl;
    return 0;
}