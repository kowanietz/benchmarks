### First Build

*GMP must be installed*

`mkdir build && cd build`

`cmake ..`

`cmake --build .`

### Rebuild

`cd build`

`cmake --build .`

### Usage



```python
from fibonacci import fib_linear, fib_naive

print(fib_linear(5))
```