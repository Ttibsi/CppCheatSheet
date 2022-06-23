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

