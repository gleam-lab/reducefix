ans=min(ans,sum*p[i].first);
   ```
   The multiplication of two integers (`sum`, which can be up to `2e5 * 1e6 = 2e11`) and `p[i].first` (up to `1e6`) results in a value up to `2e17`. However, since both are `int`, their product is computed as an `int`, leading to **overflow**, and then it's stored into a larger type like `int64_t` or `long long`. This causes **undefined behavior**.

2. **Fixing Overflow**: To avoid this, we must cast one of the operands to a 64-bit type before performing the multiplication. This ensures the product is calculated correctly without overflowing.

---

### Fixes Applied:
- Replace all expressions like `a * b` with `(long long)a * b` when `a` and `b` are large.
- Specifically, change:
  ```cpp
  ans=min(ans, sum * p[i].first);
  ```
  to:
  ```cpp
  ans = min(ans, (long long)sum * p[i].first);
  ```

- Also initialize `ans` using `LLONG_MAX` instead of relying on initial values derived from uncasted products.

---

### Final Optimized Code: