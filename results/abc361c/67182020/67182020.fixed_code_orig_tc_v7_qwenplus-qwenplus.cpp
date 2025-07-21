A[i + (N - K) - 1] - A[i]
   ```
3. Track the **minimum** of these differences.

This approach runs in **O(N log N)** due to sorting, and then **O(N)** for checking each window — acceptable for `N ≤ 200000`.

---

### Here's the corrected C++ code: