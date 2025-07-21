// ... (previous code remains the same until here)

// Use binary search to find the indices for l and r
int findIndexByValue(const vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid; // found an exact match, return index
        } else if (arr[mid] < target) {
            low = mid + 1; // target is greater, search in the right half
        } else {
            high = mid - 1; // target is smaller, search in the left half
        }
    }
    // If not found, return -1 (or any other default value based on your use case)
    return -1; // or use a different approach to handle this case if needed
}

// ... (rest of the code remains the same)

// Inside the query loop:
int L, R; // Assuming these are already read from input as before
auto itLower = x_to_ptr.lower_bound(L); // Get the iterator for lower bound value in map
auto itUpper = x_to_ptr.upper_bound(R); // Get the iterator for upper bound value in map
// Use binary search to find actual indices for l and r based on the iterators obtained from map
int l = findIndexByValue(X, (*itLower).first); // Find index for l using binary search on X array based on lower bound value in map
int r = findIndexByValue(X, (*itUpper).first - 1); // Find index for r using binary search on X array based on upper bound value minus 1 in map (to handle equal values)
// Now use l and r to compute the answer as before...