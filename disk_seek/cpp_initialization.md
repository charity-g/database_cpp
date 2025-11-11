
# Initialization

```cpp
int a;         // default-initialization (no initializer)

// Traditional initialization forms:
int b = 5;     // copy-initialization (initial value after equals sign)
int c ( 6 );   // direct-initialization (initial value in parenthesis)

// Modern initialization forms (preferred):
int d { 7 };   // direct-list-initialization (initial value in braces)
int e {};      // value-initialization (empty braces)
```

## default initialization
```cpp
int a;        
```
- value is "garbage value"

## copy initialization (present in C)
```cpp
int b = 5;
```
- in C++ before C++17, was less efficient, but seen in code from C

## direct initialization 
```cpp
int c ( 6 );
```
- used in explicit casts, eg: via `static_cast` 

## List initialization
- prior to C++11, copy initialization looked similar to copy assignment, and direct initialization looked similar to function calls.
- list initialization is unique in being constructor only

```cpp
int width { 5 };    // direct-list-initialization of initial value 5 into variable width (preferred)
int height = { 6 }; // copy-list-initialization of initial value 6 into variable height (rarely used)
```

- List initialization prevents type casting into variable assignment
```cpp
    int w1 { 4.5 }; // compile error: list-init does not allow narrowing conversion

    int w2 = 4.5;   // compiles: w2 copy-initialized to value 4
    int w3 (4.5);   // compiles: w3 direct-initialized to value 4 
```

- note that list initialization type-cast prevention only protects initialization step, does not protect subsequent copy assignments
```cpp
    int w1 { 4.5 }; // compile error: list-init does not allow narrowing conversion of 4.5 to 4

    w1 = 4.5;       // okay: copy-assignment allows narrowing conversion of 4.5 to 4
``` 

## value initialization vs zero initialization
```cpp
int width {}; // value-initialization / zero-initialization to value 0
// if variable is not type int, will default to whatever is closest to 0 for that 
```
## when to do list init vs value init 
```cpp
int x { 0 };    // direct-list-initialization with initial value 0
std::cout << x; // we're using that 0 value here
int x {};      // value initialization
std::cin >> x; // we're immediately replacing that value so an explicit 0 would be meaningless
```

## Multi-variable initialization 
```cpp
int a, b = 5;     // wrong: a is not initialized to 5! This is because a doesn't have its own initializer
int a = 5, b = 5; // correct: a and b are initialized to 5
```

## preventing errors
```cpp
    [[maybe_unused]] double pi { 3.14159 };  // Don't complain if pi is unused
```

## Instantiation
- means variable has been created (allocated) and initialized (incl default initialization)
- usually occurs to class obj but can be any 

# TAKEAWAYS:
**Intialization**
- use list and value initializations