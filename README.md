# μstd - Jackson's Micro Standard Library

This is a collection of helpers classes that I've made that feel reusable enough to be kept in a central repository. The goal is to have each helper class be self-contained in at most one header or one header and one implementation file, so that including it in your project doesn't involve adding this library as a dependency.

### Example
---

```cpp
#include <ustd/expected.h>

ustd::expected<int> multiplyEvenNumber(int num, int by) {

    if (num % 2 != 0) {
        return ustd::unuexpected("Not an even number");
    }

    return num * by;
}
```
