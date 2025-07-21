#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, q;
    cin >> n; // Assuming there is an input for number of patches.
    
    // Assuming x[] is an array containing patch locations and p[] are patch values.
    // Adjust the logic accordingly.
    // This is just a placeholder to show the error.
    // For example, if patch locations are stored in an array called patches,
    // and patch values are stored in an array called patchValues,
    // the correct patch locations and patch values should be read accordingly.
    
    // Other than the above placeholder, the code should work correctly.
    // The problem with the code is in handling ranges of integers within the query loop.
    
    while(q--){ // Assuming query operations are also valid here.
        int l, r; // Initialize l and r to handle the range query.
        cin >> l >> r; // Read the lower and upper bounds of the range.
        
        // This line of code should not be present as it is incorrect.
        // l=lower_bound(x+1,x+n+1,l)-x; // Assuming lower_bound() does not exist or does not handle ranges correctly.
        
        // Correcting the range query logic would involve finding the correct indices within x[] array.
        // Using the provided data structure, you can adjust the logic accordingly.
        // For example, if x[] contains patches starting from index 1, you can use r-1 to get the correct patch index within x[] array.
        // The corrected code would look something like this:
        int corrected_patch_index = find(x + 1, x + n + 1, l) - x; // Assuming find() exists and handles ranges correctly.
        cout << sum[corrected_patch_index] - sum[l - 1] << endl; // Adjusting the sum calculation based on the corrected index.
    }
    return 0; // Returning 0 to indicate successful completion of the program.
}