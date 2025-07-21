// Sort the array
sort(A.begin(), A.end());

// Set initial pointers
int left = 0;
int right = N - 1;

// Variable to store the minimum difference
long long min_diff = LLONG_MAX;

// While left pointer is less than right pointer and we have enough room to remove K elements
while (right - left >= K) {
    // Calculate current difference
    long long current_diff = A[right] - A[left];

    // Update min_diff if the current difference is smaller
    min_diff = min(min_diff, current_diff);

    // Slide the window
    if (right - left == K) {
        // If the window size is exactly K, move both pointers
        left++;
        right--;
    } else {
        // Otherwise, move the left pointer to maintain a window of size K
        left++;
    }
}

// Output the minimum difference found
cout << min_diff << endl;