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
Classes are like an expanded type of struct, except they also contain functions.

Within a class, you can specify the access rights of the attributes and methods 
that follow them.

```cpp
class Rect {
    int w, h;

    public:
        void set_values(int,int);
        int area();
} rect; 

// Creating a method
void Rect::set_values(int x, int y) {
    w = x;
    h = y;
}
```

Private members of a class are accessible only from within other members of the
same class, Protected members are accessible also from within child classes, 
Public members can be accessed anywhere the object is able to be accessed. By 
default everything is private.

You can access any members of a class with dot notation (ex `rect.area();`).

Methods with templates in the class are considered `in-line` already. This may 
cause some slight slowdown at compiler optimisations, but nothing significant.

You can have constructor methods like python's `__init__()` to specify attributes
when the class is created. These can also be overloaded, just like any other
method, although creating a class with a default constructor should use no 
parenthesis.

If a class only has a single parameter in it's constructor, you can create it 
similarly to creating a new variable (ex 'class_name obj_name = val') and if 
it has multiple values,you can use braces instead

```cpp
// Assume the class Circle has only a single attr called radius
Circle foo (10.0);   // functional form
Circle bar = 20.0;   // assignment init.
Circle baz {30.0};   // uniform init.
Circle qux = {40.0}; // POD-like
```

Objects can also be pointed to with pointers. They can also be defined with a 
`struct` or `union` keyword, confusingly. 

You can also overload various operators so that the code knows what to do when 
you use those operators on two objects.

The `this` keyword can be used as a pointer to the object who's methods are 
being executed. They're close to the python `self`, but aren't exactly 1:1. 

`static members` are also known as `class variables`. They're attributes that 
apply at the class level instead of the object level. One example of this 
could be a class that counts the number of objects that exists. 

```cpp
// This is an example of a class with a class attribute that increments
// every time you create a new object
class Dummy {
    public:
        static int n;
        Dummy() { n++;}
}

int Dummy::n = 0; // Classattrs need to be initialised outside of the class 
                // or there'll be a new instance with each object. 
```

You can also use the `static` keyword to create classmethods. They can't use 
the `this` keyword within them.

Just as we can have function templates, we can also have class templates. These 
are useful mostly so that the methods can use template parameters as types. 
```cpp
template <class T>
class mypair {
    T values [2];
  public:
    mypair (T first, T second)
    {
      values[0]=first; values[1]=second;
    }
};

//Create an object
mypair<int> myobject (115, 36);
mypair<double> myfloats (3.0, 2.18); 
```

**See `basics/template_specialisation.cpp` for an example**


### CLass special members
If a class has no constructors at all, it implicitly has an empty constructor,
IE a constructor that sets not attributes. Once any other constructor is 
added, this is no longer implicit and needs specifying by the programmer.

A destructor does the opposite, and basically runs at the end of the object's 
lifetime, emptying out the memory taken up by the object and it's attributes. 
It's defined with no type, not even void, and is preceeded by a tilde.

```cpp
// destructors
#include <iostream>
#include <string>
using namespace std;

class Example4 {
    string* ptr;
  public:
    // constructors:
    Example4() : ptr(new string) {}
    Example4 (const string& str) : ptr(new string(str)) {}
    // destructor:
    ~Example4 () {delete ptr;}
    // access content:
    const string& content() const {return *ptr;}
};

int main () {
  Example4 foo;
  Example4 bar ("Example");

  cout << "bar's content: " << bar.content() << '\n';
  return 0;
}
```

It's common that a destructor is called at the end of `main()` if not specified

the `copy constructor` is triggered when you pass an object another of it's own 
type as a arguement. ex `myClass::myClass (const myClass&);` - this only 
needs a pointer to itself as the parameter.

An implicit copy constructor only shallow copies the attributes, and when the 
destructor triggers, they would both try to delete the same block of memory. 
To avoid this, we create custom copy constructors that perform deep copies.

```cpp

// copy constructor: deep copy
#include <iostream>
#include <string>
using namespace std;

class Example5 {
    string* ptr;
  public:
    Example5 (const string& str) : ptr(new string(str)) {}
    ~Example5 () {delete ptr;}
    // copy constructor:
    Example5 (const Example5& x) : ptr(new string(x.content())) {}
    // access content:
    const string& content() const {return *ptr;}
};

int main () {
  Example5 foo ("Example");
  Example5 bar = foo;

  cout << "bar's content: " << bar.content() << '\n';
  return 0;
}
```

Copy constructors also trigger when creating a new object and applying an 
existing one to it. Eg `myClass bar = foo` where `foo` already exists as an 
object of `myClass`

Similarly, you can use the `move constructor` to move a value from one object 
to another, making sure that it doesn't stay in the source location. It's 
triggered when an object is initialised on construction using an unnamed 
object. 

```cpp
MyClass fn();            // function returning a MyClass object
MyClass foo;             // default constructor
MyClass bar = foo;       // copy constructor
MyClass baz = fn();      // move constructor
foo = bar;               // copy assignment
baz = MyClass();         // move assignment 
```

`fn` and `myClass()` are unnamed classes in this instance. The move constructor 
is an implicit overloaded `=` operator that takes an _rvalue_ specified with 
two ampersands. 

```
MyClass (MyClass&&);             // move-constructor
MyClass& operator= (MyClass&&);  // move-assignment 
```

The difference between the constructor and the assignment is that the move 
constructor triggers when you create a class, wheras the assignment triggers
when you use the `=` operator

You can also explicitly remove the implicit functionality of these constructors 
using the `default` and `delete` keywords. For example, this line will disable 
the functionality of the _copy constructor_ on the Rectangle class:
`Rectangle (const Rectangle& other) = delete`. Instead using the `default` 
keyword in the same place can mostly be used for readability purposes and to 
make the implicit functionality explicit. 

### Friendship and Inheritance
The `friend` keyword allows you can specify a class or method that can access 
the private and protected methods/attributes of the class.

Pointers to a child class is type-compatible with a pointer to it's base class.

A virtual member is a method/attribute that can be redefined in a child, while 
preserving it's features in the parent. This uses the `virtual` keyword

```cpp
class Polygon{
    protected:
        int width, height;
    public:
        virtual int area() {return 0;}
}

class Rectangle : public Polygon {
    public:
        int area() {return width * height;}
}

class Triangle : public Polygon {
    public:
        int area() {return (width * height / 2);}
}
```

The `area` method is specified as virtual in the parent as it's redefined 
in the children.

You can also have a metaclass called an `abstract base class` that are designed
to only act as a base class instead of a standalone class, and have 
virtual member functions without definition. 

```cpp
// abstract class CPolygon
class Polygon {
  protected:
    int width, height;
  public:
    void set_values (int a, int b) { width=a; height=b; }
    virtual int area () =0;
};
```

In this example, the area method is a pure virtual function as it has no 
definition and instead ends with the `=0`. These ABC classes are mostly used 
to create pointers to it and to use it's polymorphic features.

You can use the `this` keyword in virtual methods that aren't pure virtuals.

### Type conversions
Implicit conversions are automatically performed when a value is copied to a 
suitable compatible type, such as a `short` and an `int`

Converting to int from a smaller type is called a promotion. Same as double to 
float. Conversions to/from bool consider False as 0 or nullptr, and True as 
everything else. 

Arrays and functions convert to pointers. nullptr can convert to pointers of 
any type. 

There are three ways to convert between classes: using constructors, using 
assignment, and using a type-cast operator.

```cpp
// implicit conversion of classes:
#include <iostream>
using namespace std;

class A {};

class B {
public:
  // conversion from A (constructor):
  B (const A& x) {}
  // conversion from A (assignment):
  B& operator= (const A& x) {return *this;}
  // conversion to A (type-cast operator)
  operator A() {return A();}
};

int main ()
{
  A foo;
  B bar = foo;    // calls constructor
  bar = foo;      // calls assignment
  foo = bar;      // calls type-cast operator
  return 0;
}
```

The third method there, the type-cast operator, is using the `operator` keyword 
to convert to the specified class, and also returns that specific class.

You can also use the `explicit` keyword when creating the method to specify 
that it should _only_ take a type that it's given and not convert from another 
type, such as the first constructor above. 

You can cast one type to another using two different methods - functional, or 
C-like (inherited from C)

```cpp
double x = 10.3;
int y;
y = int (x);    // functional notation
y = (int) x;    // c-like cast notation
```

In order to control conversions between classes, we use different operators 
with the following syntax: `type_cast <new_type> expression`
    - dynamic_cast 
    - static_cast
    - reinterpret_cast
    - const_cast

**Dynamic cast** can only be used with pointers and references to classes or
void. It can also be used to move between a pointer on a parent class to a 
pointer on a child class. Note that this will need RTTI and some compilers 
disable this by default. 

Without dynamic cast, a pointer to a parent class can't be converted to a child
pointer as there will be incomplete information, such as attributes that aren't 
filled or methods that aren't pointed to.

**static cast** can convert between pointers of parent and child classes 
without any form of checking, and the safety here is up to the programmer. 
It's more memory efficient than dynamic casting, however. It can also be used 
to convert between integers and floats to enums.

**reinterpret cast** can convert any pointer to any other pointer, regardless
of if the two classes are related at all. It acts as a simple binary copy. 
You can't dereference safely a reinterpreted pointer. 

**const cast** can basically toggle between a const object and a non-const
object. This is primarily useful when passing pointers to functions that 
specify they have to be consts. 

You can also use the `typeid()` function to check the type of an object or 
expression. To use this, you'll need to `#include <typeinfo>` at the top of 
the file too. You can also use operators such as `==` and `!=` on this function

When applied to classes, `typeid()` uses RTTI (RunTime Type Information) to 
track dynamic objects. 

### Exceptions

Exceptions are errors that may arise in the code. Each exception has it's own 
type and is thrown with teh `throw` keyword within the `try` block of a 
`try/catch` statement.

A now deprecated but still used way of raising an exception is by using 
notation similar to a function definition with a `throw` specifier on it. 
`double foo (char param) throw (int);`

You can also import the <exception> header to provide general exceptions that 
we are used to from other languages. You can also create your custom 
exceptions using child classes off the exception class, which also provides the
`what` method that returns a char* with a description.

Valid provided exceptions include:
    - bad_alloc - thrown by `new` on allocation failure
    - bad_cast - thrown by `dynamic_cast` when it fails
    - bad_exception - thrown by dynamic exception specifiers
    - bad_typeid - thrown by `typeid`
    - bad_function_call - thrown by empty function objects
    - bad_weak_ptr - thrown by `shared_ptr` when passed a bad `weak_ptr`

These will all automatically be caught by `catch (exception& e) {}`

The `<exception>` header also offers two generic exception types to raise:
`logic_error` and `runtime_error`.

Any time you do anything with memory allocation, wrap it in a try/catch for 
`bad_alloc` as that's a very common error. 

### Preprocessor directives
These are any lines at the top of the file that start with a `#` - the only 
one we've seen so far is the `#include` directive to include specific header 
files. These lines are read before the code is compiled together.

We can define consts at pre-processor level by using the `#define` statement. 
`#define VAR val` - these can be statements, blocks, or any valid C++ and 
replace where they're called at compilation time. They can also work with 
parameters to define macros `#define getmax(a,b) a>b?a:b`

Note that directives don't need to end in a semicolon.

Defined macros aren't affected by block structure and last until they're 
undefined with the `#undef` statement.

You can also use `#` symbols inline followed by a parameter name as a 
replacement sequence.
```cpp
#define str(x) #x 
cout << str(test);

// This would become
cout << "test";
```

You can also use the `##` operator to concatenate two arguments between them

Condintional inclusions let you specify if specific code should be included 
only if conditions are met. You can combine these with the `defined` and 
`!defined` keywords to specify certain variables. 

```cpp
#if defined ARRAY_SIZE
#define TABLE_SIZE ARRAY_SIZE
#elif !defined BUFFER_SIZE
#define TABLE_SIZE 128
#else
#define TABLE_SIZE BUFFER_SIZE
#endif 
```

There is also the `#line` directive that lets you specify the line number of 
the next line in your file - which will show up in error messages. You 
can also specify the filename afterwards as an optional parameter. It's unclear 
what the purpose of this is.

The `#error` directive aborts the compilation process when it's found, 
generating an error message specified as a parameter. 

Not mentioned above, you can also use #include to import another file, calling 
it instead with double quotes instead of angle brackets.

`#pragma` is used to specify options in the compiler. Check your compiler 
docs for specifics. If a specific argument doesn't exist, it's just ignored
and no error message is raised.

### File IO
There are multiple headers you can use for various read/write stuff
    - ofstream - stream to write to files
    - if stream - stream to read from files
    - fstream - both write and read

You can check if the file has successfully opened with the `myFile.is_open()`
method, often combined with an IF statement.

You can also use the following boolean methods on your file stream
    - `bad()` - returns true if IO operation fails
    - `fail()` - Same as `bad()` but also returns true on formatting errors
    - `eof()` - return true if end of file reached
    - `good()` - most generic, returns false when any other would return true
    - `clear()` - reset these flags. 

ifstream/istream store a `get` position of the next element to be read, and 
ofstream/ostream store a `put` position which is the next location to write 
to. fstreams keep both, as well as iostream. These can be observed and modified

`tellg()` and `tellp()` return a value of type `streampos` representing these 
values. You can change these positions with `seekg()` and `seekp()` which 
accept a value of streampos as well. You could also pass in an offset and a 
direction together. The direction is an enum that holds some of the `ios::` 
values. 

#### Binary files
Instead of using `getline`, we can use `read` and `write` functions on binary 
file streams, based on how they are opened. However, instead of text, they need 
to be passed a memory block and a size as we are working in bytes instead of 
absolute file contents. The memory block is a char pointer pointing to the 
mem address of the data that you want to read from or write to. Size is an 
integer that specifies the number of characters. 

We can open a file in `ios::ate` mode to open it with a pointer pointing at the 
end of the file. We also need to remember to open it with `ios::binary` mode

### LearnCPP Notes
* The `static` keyword before a variable meaks that it only applies to the
current file - eg `static int foo = 3;`. This is related to the concept of 
linkage.
* The opposte to this is the `extern` keyword, that's used to force a variable
to be accessible outisde of the file it's defined in.
* Global variables by convention begin with `g_` ex `int g_foo;`
* It's good practice to initialise all your global vars in a header file, 
although they'll want to be `extern const` variables. Also, use a namespace
around them.
* `constexpr` is used on a variable or function that's a constant to make sure
that it can be used in expressions
* In C++20, you can use `consteval` on a function to make sure that it compiles
at compile-time over `constexpr`.
* Unnamed namespaces are namespaces defined without a name. They're treated as
if everything in their scope is in the parent scope but marked as static.
* Using the `inline` keyword when defining a namespace (`inline namespace foo`)
is used for mostly versioning something. This allows you to call multiple
namespaces with similar content.
* If you intend for multiple case statements to be triggered at once in a
switch/case, you can use `[[fallthrough]];` to show you intentionally have not
broken out using a `break` or `return` statement. (c++17 or newer). (See 
`learnCPP/isVowel.cpp`)
* `cin.ignore()` will take an int of characters to clear from the buffer, or
can also be given a character to near up to (usually a newline)
* `#include <assert>` and the `assert()` function are useful for checking your
code. You can also pass an `assert()` an error message to raise as a string
using logical AND (ex `assert(foo && "No foo found")`) - this works because of
a quirk when it comes to logic and output.
* A `static_assert()` is checked at compile time instead of run time and can 
take a condition and a diagnostic message.
* static_cast and dynamic_cast are the only casts you really need to worry 
about as the others are all avoided as best practice.
* `auto` can be used as a var type definition based on the initialised value 
it's given. It can also be used as the return type for functions although those
are unfavourable.
    * A function can also use `auto foo(int x, int y) -> int` to specify it's
    return type - this is important mostly for anonymous functions.
* `nullptr` mplicitly convert to `false`, whereas every other pointer equates
to `true`
* Dangling pointer is a pointer who's object has been destroyed/out of 
scope. For this reason, you want to **prefer reference** (&) over a pointer (*)
* return from a function by reference over by pointer as otherwise you'll need 
to check for `nullptr` each time
* You can set an auto type var to a const as well to enforce it: 
`const auto foo = 2`

Custom data types
-----------------
* An enum is a compound data type where every possible value is pre-defined. 
* You can't have multiple enums in the same namespace use the same valid 
value name. It's best practice to put them inside `namespace` blocks.
* You can specify the data type used in an enum instead of an int using this
syntax: `enum Foo : stud::uint8_t {};`
* A **scoped enum** is an enum that belongs only to the current scope, and is 
defined inside a block  (such as a function). These are `enum class` and the
values don't narrow down to ints. 
* A `struct` is basically a dataclass from python (not really), holding 
multiple attributes under the same name.
* You can create const struct variables.
* You can pass a struct object around by const reference to access the
attributes.
* Structs can be nested within each other, however the inner one will only
exist for the length of the outer one.
* When you have a pointer to an object (such as a struct), you use the `->`
operator to get the attributes instead of the `.` operator. (see 
`learnCPP/structs.cpp`)

* When working with C-style strings, which are just char arrays, the best way
to get input from `cin` is like this (`std::cin.getline(foo, std::size(foo));`)

Pointers and arrays
-------------------
* Arrays are not pointers. A pointer will only point to a single element and
know nothing about the other elements in the array.
* `sizeof(array)` will return the size of the whole array, whereas
`sizeof(ptr)` will only see the single value.
* When passing an array into a function, it decays into a pointer.

* A void pointer `void* ptr` can point to any data type, but can't be 
dereferenced using `*ptr` because the compiler doesn't know what type its
contents is meant to be.
    * However, we can static cast it over instead.
* When initialising a `std::array` of a struct, you need to wrap the 
initialisation of each item in a second set of curly braces:
(`myStruct arr = {{{item 1}, {item 2},}}`)

Pointers and functions
----------------------
* Creating a pointer to a function call looks something like this: 
`int (*ptr)();` where you make sure the return type is on the left and the 
list of params are in the second set of brackets.
    * To make it const, you include the const keyword in the first
    set of brackets before the ptr name

* Vectors can be used as a stack because of their `push_back()`, `push()` and
`pop()` methods.

Command line arguments
----------------------
* We pass two separate parameters to `main()`:
    * `int argc` is argument count, which is the number of arguments passed
    to the program. This will always be at least 1 because we're passing in 
    the name of the program itself.
    * `char* argv[]` is argument values/vectors, which is the actual contents
    of what we're passing in. It's an array of c-strings of length argc

Object Oriented Programming
---------------------------
* While there are multiple ways to create a default constructor, including 
treating it as any other function, with the definitions in the body, the best
practice is to use a member initialisation list, which holds all the attribute
assignments in a single line. (ex `foo(): a{1}, b{2} {}`)
    * This goes the same for constructors that set values
    * The purpose for this is to be able to set const values
* You can have one constructor that has some functionality in it's body and
another constructor can access that. This uses a colon then calling the name 
of the other constructor like so: `foo(int x): foo{}`
    * This is called a delegating constructor
    * You can also use this if you have multiple constructors using default
    param values. 
* Constructors can call non-constructor methods as well, so it's better to 
have setup functionality in it's own method.
* Destructors are typically used when a class holds a connection to a database
or an open file stream, or otherwise utilises dynamic memory that needs 
releasing to the OS
    * They have the name of the class with a tilde at the start `~Foo() {}`
    * These should not be called explicitly
    * If you used the keyword `new` in your constructor, you'll want to 
    have a destructor using the `delete` keyword on the same attributes
* `this` is a const pointer that points to the current object. 
    * You'll only really need it when you have a parameter and a attribute
    with the same name in a constructor, most likely
* A static attribute is at the class level, not the object level, and can be
accessed by multiple objects of the same class. It's default value has to be 
set outside of the class otherwise it'll be reset each time a new object is
created. 
* Classes can act as a namespace for custom types/enums. You'll want your enum
in a public space before the private space that the attributes are defined in
so that you can use the type in those attributes

* operators are treated as functions, so you cn overload them as well. 
* You cant create new operators, however
* There are multiple methods of overloading an operator for a class
    * You can create a friend function that you attach to the class
    * Create them as standard functions that you call with a return
    type of the class
    * Overloading operators as member functions/methods.
        * using this method, the left operand becomes the a pointer to this:
        `*this` - which is implicit.
        * This doesn't work for things that require set left operands, such as
        the `<<` operator.
* You need to make sure that your new functions have the right argument types.
This can catch you out if you use anonymous classes
* Overloading the `<<` operator is a good way to print out the contents of an
object. Using a friend function, it would look like this:

```cpp
friend std::ostream& operator<< (std::ostream& out, const Point& point);

// This will print out the object point of class Point
std::cout << point;
```

* It's usually preferred to use a standard function in this case, although 
sometimes there are reasons to use other methods. 
* Only overload operators that make sense for your class.
    * If you want functionality that involves sorting, you may need to overload
    all the comparison operators
* When overloading `++` and `--`, you can check if they're before or after a 
variable (IE the difference between `x++` and `++x`) by having an int parameter
in your overloaded functions for the postfix (`x++`) operators
* When overloading the `()` operator, you have to do it as a method as 
otherwise it'll typing `operator()` will just count it as trying to call a 
function.
    * Overloading this operator is useful for input validation when creating
    an objecct
* You can also overload type casting with `static_cast` to tell your class 
how to behave when it's converted into a fundamental data type. 

* Using the `explicit` keyword on a constructor (ex: `explicit Foo() {}`) will
tell the compiler to make the constructor ineligable for implicit conversions.
* you can also use the `delete` keyword to stop any class construction from
occuring using specific parameters. (ex: `Foo(char) = delete;`)
* Note that using the `new` keyword also allows you to deep copy from one 
variable to another.

Object relations
----------------
* Objects and complex data types are built up of various smaller fundamental
data types using things like structs, classes, and enums. Arrays are also a
part of this, as they allow you to create more complex groups of data.
* A **composition** is a complex object that includes the following 
    * A part is part of a class 
    * The part can only belong to one object at a time
    * The part has it's existance managed by the object
    * The part does not know about the existance of the object
* Compositions are one of the easiest types of relationships to define in C++
as they usually only require simple classes as usually any attribute isn't 
aware of the object they're part of, but the object is aware of the attribute
* One way to remember this is that they're a composition of their parts

* The other hand is **Aggregation** - this has the following description
    * The part is part of the object
    * The part can belong to more than one object at a time
    * The part does not have it's existance managed by the object
    * The part does not know about the existance of the object.
* These typically rely on pointer members, although they can use value members
as well.
* This is usually an `is a` relationship
    * Inheritance is an example of this

* Implement the simplest relationship your code needs, not the correct one for
real life.

* An **association** has the following relationship properties:
    * The associated object is otherwise unrelated to the main object
    * The associated object can belong to more than one main object at a time
    * The associated object doesn't have it's existance managed by an object
    * The associated object may or may not know about the existance of the
    object
* This relationship can be bi-directional, unlike an aggregate relationship
that's always uni-directional
* This is usually a `has a` relationship

* Dependancies are the last type of relationship, and the simplest. One object
can have a reliance on some code in another, a dependancy on the other.

* **Container classes** are classes that are designed to hold and organise 
multiple instances of another type. The most commonly used example of this is
the array - specifically <array> and <vector> are array-style container 
classes. 
* If you're creating a container class such as your own version of an array,
you can use the `<initializer_list>` to initialise things like you would a
standard array (ex `int array[] {1,2,3,4,5}`)

* When using Inheritance, you want to make sure that the child's constructor
calls the parent's constructor as well. This is the best way to pass values
through to the attributes the parent initialises.
    * This is especially true when the parent's attributes are private
* Favour private attributes over protected attributes
* Child classes can also overload parent methods with their own definitions
of those methods.
    * You can still call the parent method within the child method to extend
    functionality instead of writing it again from scratch
* You can also static_cast a derived object into a parent object 
* You can add a parent's protected method to the child classes using the 
`using` keyword - ex `using parent::method`. This doesn't change the access 
level

* You can have a child class with multiple parent classes by using a comma:
(`class Child: public Parent1, public Parent2`)
    * This can add a high level of complexity and hidden issues to some code
* You can have a reference or pointer of type parent pointing to the child
object
    * These are useful so that you dont have to overload methods, instead you 
    can call a method with a reference to the parent and go from there.
* A Virtual Function is an example of polymorphism, and it tells the compiler
to use the most-derived version of the function it can. This usually means 
that the child method would have the same signature as the parent.
    * This is easily done by just adding `virtual` to the start of the function
    definition.
    * Do not call these from constructors/destructors due to object creation
    and stack resolution reasons
* Instead of using `virtual` on the derived/child methods, you can add 
`override` at the end (before the  {}) and this will help make sure that you've
actually overridden the method you think you have. 
* The `final` operator on the end of a method signature stops anything from 
overriding it, that will raise a compiler error instead. 
* Covariant virtual functions are functions with different return types to 
their parent's method yet are still a virtual function.
    * This only works if what you're returning is a pointer to the class, so
    the child class method would have to return the a child pointer
* You could **always** make your destructors virtual if you're working with 
inheritance
    * If a parent's destructor is virtual, the implicit destructor on a child
    class will be too
    * A destructor should either be public and virtual or protected and
    non-virtual
    * If you intend to inherit from your class, make your destructor virtual
    otherwise, make it final.

* Pure virtual functions are functions with no body that are intended only
to be inherited and redefined later down the line, and are initially assigned
the value 0. (ex `virtual int getValue() const = 0;`)
* Classes with multiple pure virtual functions are called Abstract Base Classes
and you cant create objects from them.
    * see `learnCPP/ABC.cpp`
* Interface classes are classes with no attributes, only pure virtual methods. 
* Slicing is when you pass a child object when creating a parent object because
you're cutting off half of the object that way. It's usually benign, you just 
need to be aware of what you're doing.
    * This can catch you out if you have an array/vector of type Parent and you
    try to append an object of type Child. (It's recommended to make an array 
    of pointers to objects instead - nullptr also becomes a valid option)
    * This can also get a bit screwy if you're working with functions that take
    specific object parameters, so you should instead make sure that your 
    functions take references or pointers to the objects instead.
* `dynamic_cast` is used most often for downcasting, which is turning a parent
class object into a child object.
    * If this fails, this will return a nullptr instead 

template classes
----------------
* Just like functions, you can create a class template using different data 
types
* methods need their own templates as well.
* Most standard library things are templates as well (ex `std::vector<int>`)
* Unlike standard classes, class templates should have the body of their
methods in their header files as well due to issues with imports and the
linker.
* When you define the template line, you can also have attributes that aren't
of an unknown typeline. Ex `template <typename T, int size>` - and this acts 
basically like a parameter for a class instantiation.
* We can use function template specialisation to create methods that use 
pre-defined data types. This looks something like this:

```cpp
template <>
int Class<int>::number() { return 1; }
```

There are no template parameters to be passed in, but this method will only 
be available when the class is of the int type as that's the one specified.
There are no template parameters there that are being passed in, so the 
`template <>` angle brackets are empty, but they're still needed as this is
a template method.

Exceptions
----------
* One of the easiest ways to handle errors is via return codes, making the
function return an integer
    * However, actually checking for them has a number of issues
        * They need to be regularly checked for
        * You can't tell the difference between a return code and a 
        legitimate integer
* Exception handling uses three separate important keywords: `throw`, `catch` 
and `try`
* `throw` is used to raise an exception. This can include a return code, an 
enum value, a c-string, or an exception object.
* A `try` block is set around any code that may throw an error. Basically, a
`try` should always have a `throw` inside it, or a function call that raises a
`throw`
* The `catch` block tells the code what to do when a specific data type is 
thrown. 
* After a `throw` is found, any code below it is never triggered in the rest
of the `try` block it goes straight out to the `catch`
* You can `throw` exceptions outside of a `try` block. 
* There's also a `catch-all` handler that acts as it sounds, handing all 
uncaught exceptions throughout the code. This is just a `catch` with the 
catch type of an ellipses `catch (...) {}`
    * This is often left empty. 
    * It's thought of as good practice to wrap main() in a catch-all
* You can use exception handling in methods where you overload operators
for input checking and error handling there. 
* An exception class is a class designed to be thrown as an exception.
    * You can use exception classes for specific information
    * You can also have child classes of specific self defined exception types
    and can match them on the parent class in the `catch` block.
* There's also `std::exception` in the `<exception>` header, which we can 
import to use a number of different built-in exceptions instead.
    * You use `exception.what()` to get the name and contents of the exception
    * You also don't want to raise the base exception class as it's just an 
    interface class. Instead, you want to throw specific errors, and then try
    to catch the interface class as it'll cover all those errors raised.
* Using an empty `throw` statement allows you to reraise the previously 
raised error. This is like using an empty `raise` in python.
* You can also wrap the creation of a constructor in a try block in a different
way, which is beneficial when you're trying to make sure that a parent class
is constructed correctly in a child class. See the below snippet.

```cpp
class A {
    int x {};

    public:
        A(int foo) : x{foo} {
            if (foo < 1) { throw 1; }
        };
}

class B : public A {
    public:
        B(int bar) try : A(bar) {} catch(...) { 
            std::cout << "Exception caught" << '\n';
        }
}
```

You can see that the `try` is part of the constructor here, and that the 
`catch` is catching whatever the constructor raises.
* You need to remember to clear up resources when triggering a catch, as it 
doesn't happen automatically, such as a database connection or open file.
    * Destructors also aren't called at this point either, so you will have
    to clean up objects too
    * Destructors should not throw exceptions
* There are also keywords that can be added to the end of a function signature 
to specify if they raiwse an error or not.
* The `noexcept` keyword states that a function does not throw an exception.
This does not stop an exception from actually being thrown, it just instead
triggers `std::terminate`, which can cause issues and is best avoided.
    * `noexcept` can accept a boolean parameter, and if that's set to false
    then the function could potentially throw an error. This is generally only
    used with a function template.
    * You can also use `noexcept` in the body of a function to check if a
    specific expression could throw an exception or not. This returns a bool 
    and you can check against that bool to trigger code or not. THis is called
    an exception safety guarantee. 

Smart pointers
--------------
* Smart pointers allow for memory management while using pointers and making 
sure that they don't get let behind or dropped at the wrong times. 
* A smart pointer is a class that takes in a pointer, and has a copy 
constructor and move operator that's designed to make sure that the pointer
is safely used. 
* They also have defined destructors to empty that space of memory when they go
out of scope.
* Don't use `std::auto_ptr` - it's deprecated, and was removed in C++17
* Smart pointers tend to use class templating and is often constructed with
another class type as opposed to a fundamental type.
* Smart pointers are very regularly used as they make the code safer when it 
comes to memory management, as otherwise you'd have to wrap basically 
everything in a try-catch, which is inefficient. It's better to use smart
pointers and wrap main() in a catch-all

