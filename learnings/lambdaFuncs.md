### **Lambda Functions in C++**

A **lambda function** (or **lambda expression**) in C++ is a concise way to define an **anonymous function**. These functions are often used when you need a short, temporary function that won't be reused elsewhere.

Introduced in **C++11**, lambda functions are especially useful in STL algorithms and functional programming paradigms.

---

### **Basic Syntax**
```cpp
[ capture-list ] ( parameters ) -> return-type {
    function-body
};
```

### **Components**
1. **Capture List** (`[]`):
   - Specifies which variables from the enclosing scope are accessible inside the lambda.
   - Example: `[x, y]`, `[&x, &y]`, `[=]`, `[&]`, etc.
   
2. **Parameters** (`(parameters)`):
   - The arguments the lambda accepts, similar to a regular function.
   - Example: `(int a, int b)`.

3. **Return Type** (`-> return-type`):
   - Specifies the return type explicitly (optional if the compiler can deduce it).

4. **Function Body** (`{}`):
   - Contains the actual logic of the lambda.

---

### **Examples**

#### **1. A Simple Lambda**
```cpp
auto add = [](int a, int b) {
    return a + b;
};
std::cout << add(5, 3);  // Output: 8
```

#### **2. Lambda with Capture List**
```cpp
int x = 10, y = 20;

// Capture variables by value
auto sum = [x, y]() {
    return x + y;
};
std::cout << sum();  // Output: 30
```

#### **3. Capturing by Reference**
```cpp
int count = 0;

auto increment = [&count]() {
    count++;
};
increment();
std::cout << count;  // Output: 1
```

#### **4. Capture All Variables**
```cpp
int x = 5, y = 10;

// Capture all by value
auto valueCapture = [=]() {
    return x + y;
};

// Capture all by reference
auto referenceCapture = [&]() {
    x++;
    y++;
};
referenceCapture();
std::cout << x << " " << y;  // Output: 6 11
```

#### **5. Using Lambda with STL Algorithms**
```cpp
std::vector<int> nums = {1, 2, 3, 4, 5};

std::for_each(nums.begin(), nums.end(), [](int n) {
    std::cout << n * n << " ";
}); 
// Output: 1 4 9 16 25
```

---

### **Capture List in Detail**

| Capture Syntax       | Meaning                                                       |
|-----------------------|---------------------------------------------------------------|
| `[ ]`                | No variables are captured.                                    |
| `[=]`                | All variables in scope are captured by **value**.             |
| `[&]`                | All variables in scope are captured by **reference**.         |
| `[x, y]`             | `x` and `y` are captured by value.                            |
| `[&x, &y]`           | `x` and `y` are captured by reference.                        |
| `[=, &x]`            | All variables by value, except `x`, which is captured by reference. |
| `[&, x]`             | All variables by reference, except `x`, which is captured by value. |

---

### **Return Type Deduction**
- If the return type is not explicitly specified, the compiler deduces it.
```cpp
auto multiply = [](int a, int b) { 
    return a * b;  // Compiler deduces int
};
```
- For complex return types, you can specify the return type explicitly:
```cpp
auto divide = [](double a, double b) -> double {
    return a / b;
};
```

---

### **Advantages of Lambda Functions**
1. **Concise Syntax**: Allows defining small functions inline without cluttering the code.
2. **Flexibility**: Capturing variables allows easy integration with the surrounding context.
3. **Powerful with STL**: Simplifies the use of algorithms like `std::sort`, `std::for_each`, etc.

---

### **Practical Use Cases**
1. **Custom Comparators**:
```cpp
std::vector<int> nums = {5, 1, 4, 2, 3};
std::sort(nums.begin(), nums.end(), [](int a, int b) {
    return a > b;  // Descending order
});
```

2. **Filtering Data**:
```cpp
std::vector<int> nums = {1, -2, 3, -4, 5};
nums.erase(std::remove_if(nums.begin(), nums.end(), [](int x) {
    return x < 0;  // Remove negative numbers
}), nums.end());
```

3. **Event Handling** (in GUI programming).

---

By mastering lambda functions, you can write **cleaner, shorter, and more efficient C++ code**, especially when working with algorithms or callbacks.