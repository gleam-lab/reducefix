#include <bits/stdc++.h>
using namespace std;

int nums[200000];

int main(void){
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }

    sort(nums, nums + n);

    int l = 0;
    int r = n - 1;

    while (k--) {
        int dl = nums[l + 1] - nums[l]; // Calculate difference between consecutive elements on the left side
        int dr = nums[r] - nums[r - 1]; // Calculate difference between consecutive elements on the right side

        if (dl > dr){ // If removing an element from the left results in a larger difference than removing one from the right
            l++; // Remove the smaller element from the left
        } else { // Otherwise, remove the smaller element from the right
            r--; // Remove the smaller element from the right
        }
    }

    cout << nums[r] - nums[l] << endl; // Output the minimum possible value of the maximum value of B minus the minimum value of B

    return 0;
}