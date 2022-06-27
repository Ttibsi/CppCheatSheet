# C++ Cheatsheet
I'm building this document out by following the official docs [here](https://cplusplus.com/doc/tutorial/)

 ### Nvim setup
 - Add `cpp` to your treesitter config
 - Add `clangd` to the standard neovim-lsp
    - Macos 12.4 already ships with v11.0.3 (`g++ -version`)

## Syntax
Comments are either `//` or `/* */` - block comments need a star at the start
of each line.

Each program starts with the `include` statements, that basically act like 
imports. They tell the _preprocessor_ what fucntions are needed by the code

Hello world:
```cpp
#include <iostream>

int main()
{
  std::cout << "Hello World!";
}
```

`std::cout` is a Standard Character Output device, which is used to print to 
the console at runtime. It doesn't automatically append a newline.

Alternatively, you can do the below snippet, which is bringing the `std` library
into the scope of the project and allowing you to use something without
referring to the library it's from

```cpp
#include <iostream>
using namespace std;

int main ()
{
  cout << "Hello World!" << endl;
  cout << "I'm a C++ program";
}
```

The `endl` part here is an End Line character, or a `\n`

To run your code, you want to run `g++ file.cpp -o output`, specifying the file
you want to compile and the output it generates using the `-o` flag. You can
run your code by doing `./output` in the same directory.

### Fundamental data types:
    - Characters
    - Numerical integers
    - floating point numbers
    - bool
    - void

You must specify the type of a variable when you initialise it. If you have
multiple variables with the same data type, you can inline them together. You
can also assign values to a variable as you initialise in three different ways.
```cpp
int a;
float pi;

//inline together
int a, b, c;

// assign at initialisation time - these are all set to 1
int x = 1;
int y (1); //TIHI
int z {1}; //TIHI
```

If you use an initialiser (eg `int x = 1;`), you can use the `auto` type for 
the compiler to figure out what the data type of the variable is. 
(ex `auto x = 1;`). If you don't want to assign at this point, you can instead 
use the `decltype` type to pass over the type of another varialbe. 
```cpp
int foo = 5;
decltype(foo) bar;
```

### Strings

Strings need to be imported as an include `#include <string>`.
They otherwise are treated like any other data type.

While `char`s can be surrounded in single quotes `'a'`, strings are always 
surrounded in double quotes `"hello"`

### Constants and numbers
You can easily define denary, octal, or hex numbers in c++ as number literals.

```cpp
// These are all the same number in different bases
int foo = 75;
int bar = 0113; // octal numbers begin with a 0
int baz = 0x4b; // hex numbers begin with 0x
```

You can also end the numbers in specific symbols to mark if they're unsigned 
(ex `a = 75u`), long numbers (ex `b = 75l`) or long long (ex `c=75ll`)

CPP also supports floating point numbers with exponents

```cpp
3.14159    // 3.14159 - pi
6.02e23    // 6.02 x 10^23 - Avogadro's number
1.6e-19    // 1.6 x 10^-19 - est electric charge of an electron
3.0        // 3.0 - three
```

the default type for floating numbers is a `double` (ex `3.14l`) or you can use
a float (ex `3.14f`)

String literals tend to be return characters of various types:
```cpp
\n  newline
\r  carriage return
\t  tab
\v  vertical tab
\b  backspace
\f  form feed (page feed)
\a  alert (beep)
\'  single quote (')
\"  double quote (")
\?  question mark (?)
\\  backslash (\)
```

You can also use a backslash at the end of a line as a way to escape the newline
character and continue a string.

Constants can also be defined at the point where the pre-processor can handle 
them using the `#define` keyword.

```cpp
#include <iostream>
using namespace std;

#define PI 3.14159
#define NEWLINE '\n'

int main ()
{
  double r=5.0;               // radius
  double circle;

  circle = 2 * PI * r;
  cout << circle;
  cout << NEWLINE;

}
```

### Operators
While my `basics/operators.cpp` file shows off the majority of the operators
that you'd expext to find within C++, there are also the standard boolean 
operators (`&& || !`).

We also have the conditional operator, which evaluates a statement, does one
thing if it's true, and another if it's false. Basically, it's an inline IF 
statement of sorts.

```cpp
// conditional operator
#include <iostream>
using namespace std;

int main ()
{
  int a,b,c;

  a=2;
  b=7;
  c = (a>b) ? a : b;

  cout << c << '\n';
}
```

Bitwise operators modify the variable based on the bit patterns that reporesent
the data they store.

```
&   AND  Bitwise AND
|   OR   Bitwise inclusive OR
^   XOR  Bitwise exclusive OR
~   NOT  Unary complement (bit inversion)
<<  SHL  Shift bits left
>>  SHR  Shift bits right
```

Type casting is an operator that allows you to change the data type on a 
variable. There are two ways to do this  

```cpp
// Inherited from C
int i;
float f = 3.14;
i = (int) f;

// Second method
i = int (f);
```

You can use `sizeof()` to get the size _in bytes_ of the type or variable 
passed to it.

### Input/Output

- cin - standard in
- cout - standard out
- cerr - standard error output
- clog - standard logging output 

You can chain together multiple elements into a `cout` statement.
(ex `cout << "this is " << " a statement"`) - which is useful for concatenating
variables into strings

Using `endl` at the end of the `cout` statement flushes the statement, and is 
generally inadvisable against using a `\n`

Just like you use `<<` to write to `cout`, you can use `>>` to write from `cin`
```cpp
int foo;
cin >> foo;
```
You can also chain multiple `cin` statements together to ask for and store 
multiple pieces of data (ex `cin >> foo >> bar`)

`cin` will always terminate at whitespace, which includes a space character.
To get around this if you want to collect multiple words in a string, you can
use the `getline()` function that takes `cin` as the first value and a string
variable as the second

```cpp
// cin with strings
#include <iostream>
#include <string>
using namespace std;

int main ()
{
  string mystr;
  cout << "What's your name? ";
  getline (cin, mystr);
  cout << "Hello " << mystr << ".\n";
  cout << "What is your favorite team? ";
  getline (cin, mystr);
  cout << "I like " << mystr << " too!\n";
  return 0;
}
```

You can also use the `stringstream` function from the `sstream` header to extract
an int from a string or vice versa.

### Control flow

```cpp
//IF statements
if (x > 0)
  cout << "x is positive";
else if (x < 0)
  cout << "x is negative";
else
  cout << "x is 0";
```

THere are three different types of loops `while-do`, `do-while` and `for-do`
Within a for loop, you specify the start point, the end point, and how to get 
between them for a value you want to check. However, you can also include 
multiple values that change with each iteration of the loop. See the below 
example.

```cpp
for ( n=0, i=100 ; n!=i ; ++n, --i )
{
   // whatever here...
}
```
You can also loop through all the elements in a range using this syntax instead
(This is similar to doing `for x in range(y):` in python)

```cpp
string str = "hello";
for (char c: str) 
{
}
```

Within a loop, you can use the `continue` statement to skip to the next 
iteration, or the `break` statement to exit the loop completely.

CPP also has a `goto` statement, which allows you to jump absolutely to a point
with a `label` in. **This is a low level feature not commonly used in modern
programming**

```cpp
// goto loop example
#include <iostream>
using namespace std;

int main ()
{
  int n=10;
mylabel:
  cout << n << ", ";
  n--;
  if (n>0) goto mylabel;
  cout << "liftoff!\n";
}
```

C++ also has `switch` statements that check against specified constants to 
trigger sections of code.

```cpp
switch (x) {
  case 1:
  case 2:
  case 3:
    cout << "x is 1, 2 or 3";
    break;
  default:
    cout << "x is not 1, 2 nor 3";
  }
```

It's worth noting that each case needs a break at the end otherwise the code
will carry on running. I think switch statements also only take a single char
or int as the thing to check against

### Functions
Functions operate practically the same as they do in other languages. When you
specify the paramenters, you also need to specify their data types. You also
need to make sure that the function is declared before it's called. (This may 
be different in other versions of c++ based on the docs, but not for the version
I'm learning with on my macbook)

If you have a function that returns no value, the function will have a type of 
void. You may also see functions that take no parameters have the parameter 
brackets filled with the word `void` - this isn't required, and dates back to 
C 

You can also pass a variable to a function as a reference instad of as a value
by adding the ambersand (ie `void f(int& a)`)

You can also specify that these referenced variables don't change during the 
function's runtime by specifying them as consts insted of as data types in the 
function parameters (eg `void f(const int& a)`) - which may be useful if you 
are passing around large or complex data types such as strings.

You can specify a default value for a function the same way that you can in 
python `int f(int a=2)`

You can also create a "protofunction" that is written before the code of the 
function but is used to tell the compiler that it exists. This is mostly done 
if you have functions that call each other, so one can't be specified before 
the other. These look like the function definition line, ie you may have some 
code that looks like this:

```cpp
void isOdd (int a);
void isEven (int a);

int main()
{
  int i;
  do {
    cout << "Please, enter number (0 to exit): ";
    cin >> i;
    odd (i);
  } while (i!=0);
  return 0;
}

void odd (int x)
{
  if ((x%2)!=0) cout << "It is odd.\n";
  else even (x);
}

void even (int x)
{
  if ((x%2)==0) cout << "It is even.\n";
  else odd (x);
}
```

#### Overloaded Functions
You can have two functions with the same name if they have different return 
types and parameter types. When calling the function, the compiler will usually
correctly decide which one to use. It's generally considered good pracice that
they both have the same behavior, although they don't have to. 

Note that a function cannot be overloaded only by it's return type, at least one
of the parameters mst have a different type.

#### Function templates

Sometimes you want to do the same thing to the same data with different types 
(eg a `sum()` function should return the same data type as the numbers put in 
eg double or int). For this, you can create a template.

Function templates use the syntax `template <class myType>` to create a custom
type for the purposes of this templating. This `myType` is what the function 
can return and can be the specified type of parameters as well. Instead of the 
`class` keyword here, you can also use `typename`, which is slightly more 
readable and less explicit.

You can also specify the type when calling the function (ex `sum<int>(1,2);`)
It's standard to call these templates `T`. You can also use these generic 
types to create variables of those types. 

### Scopes
* Global - defined outside of any block
* Block - Any value defined within a single block, such as a function or a loop
    * These are known as local variables

There cannot be two entities in the same scope with the same name

Custom namespaces
```cpp
namespace foo
{
    int a, b;
}

int main()
{
    cout << foo::a; // Calling the variables defined within the `foo` namespace
    cout << foo::b;
}
```

You can also have functions defined within namespaces as well, and call them in 
the same way as above.

The keyword `using` brings the selected namespace into the current one. This is 
akin to doing `from foo import *` in python. You can also use `using` within a 
block, such as a function. If you use `using namespace foo` (over `using foo`)
this will allow you to use features of the foo namespace without specifying that 
theyre part of foo. 

You can also alias namespaces so they're easier to type (ex `namespace f = foo;`)

### Arrays
You can't straight up pass an array to a function, although you can pass it's 
address instead. This has the same effect, but is more efficient/faster. It's 
basically the same syntax (`void foo (int arg[]) {};`). Sometimes, to handle 
things like looping through an array, you will also need to pass in it's 
length as the array created as an arg has an unknown length.

This may be a good use of namespaces and just using arrays within their own NS 

Most of this functionality is inherited from C, and C++ offers it's own 
`<array>` header that is easier to use. In short, this header allows for arrays 
to be copied,although that is an expensive operation and they will only decay
into pointers when told to by the programmer. You can also use `myarray.size()`
to get the size of the array in a C++ array.

### Character sequences
You can represnt a string as an array of characters eg `char foo [20];`.

Note that by convention, character arrays tend to end with a `\0` null char

Strings surrounded in double quotes `"` are _String literals_, and they are an 
array of characters with a null-terminator at the end. 

```cpp
//initialise
char word[] = {'H', 'e', 'l', 'l', 'o', '\0'};

// This does the same thing
char word[] = "Hello";
```

This is inherited from C, although as before mentioned, C++ offers the `<string>`
header. Char arrays are also known as `C-strings`

Note that unlike a string type variable, you cannot overwrite a char array in 
the same way, although you can overwrite individual characters the same way you 
would usually access elements in an array. They also have a fixed length which 
is defined at instantiation time, unlike a string, which can have a variable 
length.

You can turn a string into a char array/C-string using `mystring.c_str()`, or 
the other way around using `mystring.data`

### pointers
`&` - Address-of operator
`*` - dereference operator
    - When used on the data type of a pointer (see below), this is instead part 
    of a compound type specifier.

```cpp
int foo = 12;
int* bar = &foo; // This is NOT the dereference operator
cout << &foo;
cout << bar;
```

here, `bar` points to the memory address of foo, and doesn't hold the value of 
foo itself. bar is an `int*` (as opposed to an `int`) because we aren't accessing
the value, but the location.

The properties of a pointer change based on the data type it is pointing to. 
once dereferenced, the data type needs to be known. This is the data type that 
is used to instanciate the pointer - not the data type of the pointer itself. 
In the above code snippet, it's the reason the `bar` is an int. 

#### Pointers and arrays
Arrays are basically pointers to a list of data.

Brackets for an array are a type of operator called the `offset operator`. 
When you define an array, you store the location of item 0 and how many address 
locations we need. You can access these other locations using pointers by 
specifying the offset.

If you are pointing to a value with no intention of changing it, you can also 
specify it as a const (eg `const int* ptr;`). This is useful to pass as a 
function parameter. 

We can also access string literals using pointers as they are technially also 
arrays of `const char` (as literals, they can't be modified)
`const char* foo = "hello";` is valid syntax

You can create pointers that point to other pointers, with another level of 
asterisk for each level of pointer before you hit actual data.

```cpp
char a;
char* b;
char** c;
a = 'z';
b = &a; //points to a
c = &b; // points to b pointing to a
```

#### void pointers
Void pointers are pointers that point to values with no type. This means that 
they can point to any data type, althugh they cannot be directly dereferenced
(They can't be `&`ed). Addresses in a void pointer need to be transformed into
another pointer type first.

These are generally useful for passing generic parameters to a function.

#### Null Pointers
Basically these are pointers that point to addresses that don't exist/are empty.
Uninitialised pointers are a good example of this, as they have yet to be told
where to point. This will only cause an error if you try to dereference it. 

You can also make a pointer explicitly point nowhere (not just an invalid address).
This is a nullpointer value. (ex `int* foo = nullptr;`) or you can create a pointer
that points to 0 (ex `int* bar = 0;`). It's also common in older code to see 
`NULL` used here.

Null pointers and void pointers are different. 

#### Pointers to functions
This is also allowed, and is most used to pass a function as an argument to 
another function. 
See the `basics/pointer_functions.cpp` file for an example of this

### Dynamic memory
Usually memeory usage is determined by the compiler However there are times the
memory will only be determined during runtime - ie user Input.

Allocate dynamic memory with the `new` and `new[]` operators. You get a pointer 
to the beginning of a new block of memory returned.

```cpp
ptr = new int
ptr = new string [4]
```

You can access these the same way you'd access any other pointers, or for the 
pointer arrays, the same way you'd use any other array.

The difference between normal arrays and dynamic memory is that the latter can 
be set during runtime using any variable value as it's size.

There are two ways to check if allocation was successful. 
    - The first is by handling exceptions - `bad_alloc` is thrown when the 
    allocation fails. 
    - The second is called `nothrow`, and instead of raising an exception, the 
    program continues on as if the new pointer is a null pointer. To use a 
    nothrow, you need to specify it using this syntax: `t = new (nothrow) int [5]`

```cpp
int* foo;
foo = new (nothrow) int [5];
if (foo == nullptr) {
    // error assigning memory, do something
}
```

The exception checking is preferred as otherwise you need to check every 
new pointer you create manually in the code.

You only need to hold onto the memory for as long as the program needs it, and 
should release that space once it's no longer needed. You do this with the 
`delete` and `delete[]` keywords. 

### Data Structures

Declaring data structures are similar to how it's done in go using the `struct`
keyword.

```cpp
struct human {
    string name;
    int age;
    string hair_colour;
} Joe, Bob; // Inline create new objects

// Create a new object
human Rosanna;

// Accessing the attributes
Rosanna.age = 25;
```

If you create an object in-line, you dont need to give the struct a name itself 
as it's automatically assigned to the object created.

As structs are basically custom data types, they're able to be pointed to with 
their own pointers.

```cpp
human* ptr
```

You can also use the `->` operator as a dereference operator (similar to the 
`&` operator) to get a struct object's attributes. 

```cpp
human bob;
human* bobptr;
// pointer pointing to the bob object
bobptr = &bob;

cout << "enter name ";
// write to the name attribute of the object bobptr is pointing at
getline(cin, bobptr->name)
```

In the above instance, `bobptr->name` is functionally identical to 
`(*bobptr).name` and either can be used interchangably. 

Structures can also be nested so that one structure can have an element that's 
another structure.

### Type alias
A type alias is another name for any type. There are two ways to create a 
type alias.

The first way is using the `typedef` keyword, and is inherited from C. 
`typedef char mychar;` - You specify the existing type and then give it it's new 
name.

The second type uses the `using` keyword: `using mychar = char;` where you name 
the new alias before you assign a specific type to it. 

`using` is more generic, and although they're both basically the same, `typedef`
may have some limitations when it comes to templates. 

You can also use `union`s, which basically assign multiple data types to the 
same space in memory. These are commonly used to create a value that you can 
either access or use as an array of it's elements. 

```cpp
union mix {
    int num;
    struct {
        short hi;
        short lo;
    } s;
    char c[4];
}
```

We can use the above union to access a whole number of 4 bytes, or split it into
two halves of 2 bytes each, or get each byte individually as a char. 

When unions are members of a class/struct, they can be declared with no name, 
making them anonymous. If they're anonymous, you can access data types within 
by just calling them directly using dot notation. See the below example:

```cpp
struct book {
    char title[50];
    char author[50];
    union {
        float dollars;
        int yen;
    } price;
}

struct book {
    char title[50];
    char author[50];
    union {
        float dollars;
        int yen;
    } 
}
```

See that the only difference is that the union isn't assigned the `price` name.
In the first one, you can access the dollar value by doing `book.price.dollars`
however in the second, all you need to do is `book.dollars`. 

#### Enums/Enumerated types
Enumerated types are types defined with a set of possible values, called 
enumerators.

```cpp
enum type {
    value1,
    value2,
    value3
} object;
```

This creates a new type that can only accept specific values.

```cpp
enum months {
    january=1, // Set the starting integer value when enumerating through these
    february,
    march,
    april,
    may,
    june,
    july,
    august,
    sept,
    oct,
    nov,
    dec
};

The `=1` on january basically means that it starts from 1 instead of from 0.

You can also create enums that aren't just convertible to ints by using 
`enum class` or `enum struct` instead. These are commonly used for type safety
and need to be scoped into the code.

```cpp
enum class EyeColour : char {blue, green, brown};
EyeColour ec;

my_ec = EyeColour::green;
```

## Classes in C++

