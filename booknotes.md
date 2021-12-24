# Accelerated c++

## 0. Getting started

### 0.1 Comments
All comments begin with a // character, the compiler ignores comments.
```cpp
    // Denotes comments
```
### 0.2 #Include
Many fundamental facilites are part of the standard library, rather than being
part of the core language. This distinction is important because the core language
is always available to all C++ programs.

Programs ask for standard library facilities by using #include *directives*. Normally
appear at the beginning of a program.

### 0.3 The main function
Every C++ program must contain a function named main. When we ask the C++ implementation
to run a program, it does so by calling this function.

The main function is required to yield an integer as its result. A zero value indicates
success; any other value means there was a problem.
```cpp
    int main()
```

### 0.4 Curly braces
In C++, braces tell the implementation to treat whatever appears between them as a unit.
When there are two or more statements within braces, as there are in this function, the
implementation executes them in the order in which they appear.

### 0.5 Using the standard library for output
```cpp
    std::cout << "Hello, world! << std::endl;
```
This statement uses the standard library's output operator to write *Hello, world!* on
the standard output, and then to write the value of std::endl.

Preceding a name by std:: indicates that the names is a part of a namespace named std.
A namespace is a collection of related names.

The name std::cout refers to the standard output stream, which is whatever facility
the C++ implementation uses for ordinary output from programs.

### 0.6 The return statement
A return statement ends execution of the function in which it appears, and passes the
value that appears between the return and the semicolon back to the function that is 
returning. The value that is returned must have a type that is appropiate for the type
that the function says it will return.

## 1. Working with strings

### 1.1 Input
In order to read input, we must have a place to put it. Such a place is called a variable.
A variable is an object that has a name. An object, in turn, is a part of the computer's memory
that has a type. The distinction between objects and variables is important it is possible to have
objects with no name.
```cpp
    std::string name; // defines a variable of type string with identifer 'name'
```
This is a definition which defines a variable names name that has a type std::string.

Implicit in the type of an object is it's interface, the collection of operations that are possible
on an object of that type.

Once we have defined the variable, we execute the input
```cpp
    std::cin >> name; // read into the variable, in this case name
```

In general, the input-output library saves it's output in an internal data structure called a
*buffer*, which it uses to optimize output operations. To avoid overhead of writing in response
to each output request, the library uses the buffer to accumulate the characters to be written, 
and *flushes* the buffer, by writing it's contents to the output device, only when necessary.
By doing so, it can combine several output operations into a single write operation.

There are three events that cause the system to flush the buffer.
1. The buffer might be full. The library flushes automatically.
2. The library might be asked to read from the standard input stream. In that case the library 
   inmediately flushes the output buffer without waiting for the buffer to become full.
3. When we explicitly say to do so.

### 1.2 Framing a name
This chapter introduces some concepts:

Overloading, when an operator has different meanings for operands of different types, we say that
the operator is *overloaded*.

Keyword const, saying const as part of a variable's definition promises that we are not going to
change the value of the variable for the rest of it's lifetime. Note that if we say that a variables
is const, we must initializa it then and there, because we can't change it later.

### 1.3 Details
Types:
- char: built-in type that holds ordinary characters.
- wchar_t: built-in type intended to hold "wide characters", which are big enough to hold characters
  for languages such as japanese.

## 2. Looping and counting

### 2.1 The problem
Purely practice chapter.

### 2.2 Overall structure
Purely practice chapter.

### 2.3 Writing an unkown number of rows
#### 2.3.1 The while statement
A while statement has the form:
```cpp
    while (condition) 
    {
        statement
    }
```
The statement or block is often called the while body.

The while statement begins by testing the value of the condition. If the condition is
false, it does not execute the body at all. Otherwise, it executes the body once, after
which it tests the condition again, and so on.

### 2.4 Writing a row
### 2.5 Framing the program
### 2.6 Complete Program
These are purely practical.

### 2.7 Details
Correctly understanding complicated expressions is a fundamental prerequisite to effective
programming in C++.

Different operators have different precedence. Most of the operators are left-associative, 
although the assignment operators and the operators taking a single argument are right-associative.

Here are the most common operators ordered by precedence from highest to lowest:
- x.y ---------- the member y of object x.
- x[y] --------- the element in object x indexed by y.
- x++ ---------- increments x, returning the original value of x.
- x-- ---------- decrements x, returning the original value of x.
- ++x ---------- increments x, returning the incremented value.
- --x ---------- decrements x, returning the decremented value.
- !x ----------- logical negation. If x is true then !x is false.
- x\*y ---------- product of x and y.
- x/y ---------- quotient of x and y. If both operands are integers the implementation chooses whether to round toward zero or -infinite.
- x%y ---------- remainder of x divide by y.
- x+y ---------- sum of x and y.
- x-y ---------- result of substracting y from x.
- x >> y ------- for integral x and y, x is shifted right by y bits; y must be non-negative.
- x  y ------- for integral x and y, xi shifted left by y bits; y must be non-negative.
- x relop y ---- relational operators yield a bool indicating the truth of the relation.

Operands will be converted to the appropiate type when possible.

Types:
- unsigned: integral type that contains only non-negative values.
- short: integral type that must hold at least 16 bits.
- long: integral type that must hold at least 32 bits.
- size_t: unsigned integral type that can hold any object's size.
- string::size_type: unsigned integral type that can hold the size of any string.

## 3. Working with batches of data

### 3.1 Computing student grades
This chapter introduces new facilities *iomanip* and *ios*.

The *ios* header defines streamsize, which is the type that the input-output library
uses to represent sizes.
The *iomanip* header defines the manipulator setprecision, which let us say how many
significant digits we want our output to contain.

This chapter introduces double and float, double is guaranted to offer at least ten
significant digits, float is permitted to offer as little precision as six. On modern
computers, double is usually much more accurate than float, and not much slower.
Sometimes, double is even faster.

When we do not specify an initial value for a variable we are implicitly relying on 
default-initialization. The initialization that happens by default depends on the type
of the variable. For objects of class type, the class itself says what initializer to 
use if there is not one specified.
Local variables of built-in type that are not explicitly initialized are undefined, which
means that the variable's value consists of whatever random garbage already happens to 
occupy the memory in which the variable is created.

#### 3.1.1 Testing for end of input
The effect of a condition tha uses an istream as the subject is to attemp to read
from cin. If the read succeeds, the variable will hold the value that we just read, 
and the condition succeeds. If the read fails then the condition fails and we should
not rely on the value of the variable.

There are several ways in which trying to read from a stream can be unsuccessful:
- We might have reached the end of the input file.
- We might have encountered input that is incompatible with the type of the variable
  that we are trying to read, such as might happen if we try to read an int and find
  something that isn't a number.
- The system might have detected a hardware failure on the input device.

#### 3.1.2 The loop invariant
Purely practical.

### 3.2 Using medians instead of averages
Purely practical.

#### 3.2.1 Storing a collection of data in a vector
A vector holds a sequence of values of a given type, grows as needed to accommodate
additional values, and lets us get at each individual value efficiently.

Whenever we define a vector, we must specify the type of the values that the vector will
hold.
The vector type is defined using a language feature called template classes.

We specify the type of th eobjects inside angle brackets.
```cpp
    vector<type>
```

#### 3.2.2 Generating the output
This chapter introduces typedef.
When we include the word typedef as part of a definition, we are saying that we want
the name that we define to be a synonym for the given type, rather than a variable of
that type.
Example:
```cpp
    // we define the vector as vec
    std::vector<double> vec;
    // we define the name vec_sz as a synonym for std::vector<double>::size_type
    typedef std::vector<double>::size_type vec_sz;
    // we assign a new variable named size with the vector's size
    vec_sz size = std::vec.size();
```

### 3.3 Details
- Type definitions:
        typedef type name; // Defines name as a synonym for type.
- The vector type, important operations:
```cpp
        vector<T>::size_type
        v.begin()
        v.end()
        vector<T> v; // Creates an empty vector that can hold elements of type T.
        v.push_back(element)
        v[i]
        v.size()
```
- Other library facilities:
```cpp
        // Rearranges the elements into nondecreasing order.
        // Defined in <algorithm>.
        sort(beginning, end)

        // element and element2 must be the same type.
        // Defined in <algorithm>.
        max(element, element2) 

        // Sets the precision of stream s to n for future output.
        s.precision(n)

        // Return a value that, when written on an output stream s,
        // has the effect of calling s.precision(n).
        // Defined in <iomanip>                        
        setprecision(n)  

        // The type of the value expected by set precision and returned by precision.
        // Defined in <ios>
        streamsize
```

## 4. Organizing programs and data

### 4.1. Organizing computations
Whenever we do -or might do- a computation in several places, we should think about
putting it in a function. An obvious reason for doing so is that then we can
use the function instead of redoing the computation explicitly.
There is a more subtle advantage to using functions for such computations, a function
has a name. If we name a computation, we can think about it more abstractly, more
about what it does than how it does it.

We define most functions similarly, by specifying the return type, followed first by
the function name, next by the parameter list enclosed in (), and, finally, by the
function body.

In general each argument is used to initialize the corresponding parameter, after which
the parameters behave like ordinary local variables inside the function. This behavior
is often called call by value, because the parameter takes on a copy of the value of the
argument.

#### 4.1.1 Finding medians
The most importan part in this chapter is the generalization of the median calculation 
of a vector of doubles.

They introduce new object *exception object*, when a program throws an exception, 
execution stops in the part of the program in which the throw appears, and passes
to another part of the program, along with an exception object, which contains info
that the caller can use to act on the exception.

#### 4.1.2 Reimplementing our grading policy
This chapter introduces references.

Saying that a names is a reference to an object says that the name is another name for
the object.
For example:
```cpp
    vector<double> homework;
    vector<double>& hw = homework; // hw is a synonym for homework
```
Anything done to the reference is done to the original value.

Adding const still says that the reference is another name for the object but the const
promises that we will not do anything to the reference that might change it's value.

Another important thing introduced in this chapter is the concept of overladed functions,
overloading is the notion that we can have several functions with the same name. Even
though we have two functions with the same name, there is no ambiguity because
we will supply an argument list, and the implementation will be able to tell from the 
type of the arguments which function to use.

#### 4.1.3 Reading homework grades
A reference parameter without a const keyword usually signals an intent to modify the
object that is the functions's argument.
For example:
```cpp
    // function definition
    istream& read_hw(istream& in, vector<double>& hw);
    // Passing parameters
    vector<double> homework;
    read_hw(cin, homework);
```
Because we expect the function to modify its argument, we cannot call the function with
just any expression. Instead, we must pass an lvalue argument to a reference parameter.
An *lvalue* is a value that denotes a nontemporary object. For example, a variable is
an lvalue, as is a reference, or the result of calling a function that returns a 
reference.

Both of the parameters to read_hw are references, because we expect the function to
change the state of both arguments. We don't know the details of how cin works, but 
presumably the library defines it as a data structure that stores everything the library
needs to know about the state of our input file. Reading input from the standard input
file changes the state of the file, so it should logically change the value of cin as
well.

#### 4.1.4 Three kinds of function parameters
The & asks the implementation not to copy the argument, and the const promises that the
program will not change the parameter. Such parameters are an important technique for making
programs more efficient. They are a good idea whenever the function will not change the
parameter's value, and the parameter is of a type, such as vector or string, with values
that might be time-consuming to copy. It is usually not worth the bother to use const
references for parameters of simpe built-in types, such as int or double.

#### 4.1.5 Using functions to calculate a student's grade
Purely practical chapter.

### 4.2 Organizing data
Purely problem explanatory.

#### 4.2.1 Keeping all of a student's data together
This chapter introduces Structs; structs are a type of data structure, we can define the type
and data members. Because the struct is a new defined type we can define objects of that type,
each of wich will contain an instance of these data members defined.

#### 4.2.2 Managing the students records
Purely practical chapter.

#### 4.2.3 Generating the report
Purely practical chapter.

### 4.3 Putting it all together
Explanation on header files and partitioning, read page 101-104.

### 4.4 Partitioning the grading program
Explanation on header files and partitioning, read page 104-108.

### 4.5 The revised grading program
Self-explanatory.

### 4.6 Details
Angle brackets, <>, enclose system headers.
```cpp
    #include <system-header>
``` 

User-defined header files are included by enclosing the names in quotes.
```cpp
    #include "user-defined-header-file-name"
```
Header files should be guarded agains multiple inclusion by wrapping the file
```cpp
    #ifndef GUARD_header_name
    #define GUARD_header_name
        ...
    #endif
```
Headers should avoid declaring names that they do not use. In particular, they
should not include using-declarations.

Types:
- T& ---------- Denotes a reference to the type T. Most commonly used to pass a parameter
                that a function may change.

- const T& ---- Denotes a reference to the type T that may not be used to change the value
                to which the reference is bound. Usually used to avoid cost of copying a 
                parameter to a function.

- Structures -- A structure is a type that contains zero or more members. Each object of 
                the structure type contains its own instance of each of its members.
                Every structure must have a corresponding definition.

- Functions --- A function must be declared in every source file that uses it, and defined
                only once.
                Function names may be overloaded. The same function-name may define multiple
                functions so long as the functions differ in the number or types of the 
                parameters.

- Excep class - The library defines several exception classes whose names suggest the kinds 
                of problems they might be used to report.
                e.what() return a value that reports on what happened to cause the error.

Facilites:
- s.width(n) - Sets the width of the stream s to n for the next output operation. The output
               is padded on the left to the given width. Returns the previous width.

- setw(n)    - Return a value of type streamsize that, when written on an output stream s, has
               the effect of claling s.width(n).

## 5. Using sequential containers and analyzing strings

### 5.1 Separating students into categories
Purely problem explanatory chapter.

#### 5.1.1 Erasing elements in place
Vectors have a method named 'erase' that removes the element with index i, each element after
position i is copied to the preceding position. Thus although i does not change, erase has
the effect of adjusting the index to denote the next element in the vector, which means
that we must not increment it for the next iteration.

#### 5.1.2 Sequential versus random access
Iterators are an assortment of types which allow access to data structures in ways that the
library can control. This control lets the library ensure efficient implementation.

### 5.2 Iterators
An iterator is a value that:
- Identifies a container and an element in the container
- Lets us examine the value stored in that element
- Provides operations for moving between elements in the container
- Restricts the available operations in ways that correspond to what the container can handle
  efficiently.

#### 5.2.1 Iterator types
Every standard container defines two associated iterator types:
- container-type::const_iterator
- container-type::iterator
where container-type is the container type, such as vector, that includes the type of the
container elements. When we want to use an iterator to change the values sotred in the,
we use the iterator type. If we need only read access, then we use the const_iterator type. 

#### 5.2.2 Iterator operations
The important operation denoted in this chapter is the *dereference* operator *. When applied
to an iterator, the * operator return an lvalue that is the element to which te iterator refers.
The precedence of . is higher than the precedence of *, which means that if we want the * 
operation to apply only to the left operand of the ., we must enclose *iter in parenthesis
to get (*iter).

#### 5.2.3 Some syntactic sugar
In the code we just saw, we dereferenced an iterator, and then fetched with the . the requested
method. This combination of operations is so common that there is an abbreviation for it: instead
of 
    (*iter).method
we can write
    iter->method

#### 5.2.4 The meaning of students.erase(students.begin() + i)
Problem explanatory chapter.

### 5.3 Using iterators instead of indices
Purely practical chapter.

### 5.4 Rethinking our data structure for better performance
Explanatory chapter.

### 5.5 The list type
The need to insert or delete elements inside a data structure is pretty common so the std lib
provides a type named list and defined in the <list> header that is optimized for this kind
of access.

Because lists have to maintain a more complicated structure, they are slowers than vectors if
the container is accessed only sequentially. That is, if the container grows and shrink only or
primarily from the end, a vector will outperform a list. However, if a program deletes many
elements from the middle of the container then lists will be faster for large inputs.

One key operation that vectors support, but lists do not, is indexing. But we can access list
elements sequentially using iterators.

#### 5.5.1 Some importan differences
One important way in which the operations on lists differ from those on vectors is the effect
of some of the operation on iterators. For example, when we erase an element from a vector,
all iterators that refer to the element erased, or subsequent elements, are invalidated. Using
push_back to append an element to a vector invalidates all iterators refferring to that vector.
This behavior follos from the fact that erasing an element moves the following elements, and
appending to a vector might reallocate the entire vector to make room for the new element.
Loops that use these operations must be especially careful to ensure that they have not saved
copies of any iterators that may be invalidates. Inappropriately saving the value of vector.end()
is a particulary rich source of bugs.

For lists, on the other hand, the erase and push_back methods do not invalidate iterators
to the other elements. Only iterators that refer to the element actually erased are invalidated,
because that element no longer exists.

Because list doesn't support full random-access properties we cannot use the std-lib sort function
to sort values that are stored in a list. Because of this restriction, the list class provides
it's own sort member function, which uses an algorithm that is optimized for sorting data stored
in a list.

#### 5.5.2 Wht bother?
As with any performance-related question, the data structure that is 'best' depends on whether
performance even matters.

### 5.6 Taking strings apart
As it turns out, we can think of a string as a special kind of container: It contains only 
characters, and it supports some, but not all, of the container operations. The operations that it
does support include indexing, and the string type provides an iterator that is similar to a vector
iterator.

### 5.7 Testing our split function
Purely practical chapter.

### 5.8 Putting strings together

#### 5.8.1 Framing a picture
Purely practical chapter.

#### 5.8.2 Vertical concatenation
Purely practical chapter.

#### 5.8.3 Horizontal concatenation
Purely practical chapter.

### 5.9 Details
Containers and iterators - the std library is designed so that similar operations on different
containers have the same interface and the same semantics. All the sequential containers and the
string type provide the following operations:
- container<T>::iterator
- container<T>::const_iterator
- container<T>::size_type
- c.begin(), c.end() ---------- Iterators referring to the first and one past the last element.
- c.rbegin(), c.rend() -------- Iterators referring to the last and one beyond the first element.
- c.size() -------------------- Returns the number of elements in c as a size_type. 
- c.empty() ------------------- Predicate that indicates whether c has no elements.
- c.insert(d, b, e) ----------- Copies elements denoted by iterators in the range [b, e) and inserts
                                them into c inmediately before d.
- c.erase(it), c.erase(b, e) -- Removes the element denoted by it or the range of elements denoted by
                                [b, e)
- c.pusb_back(t)

Iterator operations:
- *it --------------- Dereferences the iterator it to obtain the value stored in the container at the
                      position that it denotes.
- it->x ------------- Equivalent to (*it).x

String type:
- s.substr(i, j) ---- Creates a new string that holds a copy of the characters in s with indices in the
                      range [i, i+j).
- getline(is, s) ---- Reads a line of input from is and stores it in s.

Vector type: offers the most powerful iterators, called random-access iterators, of any of the library
containers.
- v.reserve(n) ------ Reserves space to hold n elements, but does not initialize them. This operation
                      doesn't change the size of the container. It affects only the frequency with which
                      vector may have to allocate memory in response to repeated calls to insert or push_back.
- v.resize(n) ------- Gives v a new size equal to n. If n is smaller than the current size of v, elements
                      beyond n are removed from the vector. If n is greater than the current size, then new
                      elements are added to v and initialized as appropriate to the type in v.

List type: optimized for efficiently inserting and deleting elements at any point in the container.
- l.sort(), l.sort(cmp)

## 6. Using library algorithms

### 6.1 Analyzing strings
A generic algorithm is an algorithm that is not part of any particular kind of container, but instead
takes a cue from it's arguments types about how to access the data it uses. The standard library's 
generic algorithms usually take iterators among their arguments, which they use to manipulate
the elements of the underlying containers.
For example the copy algorithm takes three iterators, which we'll call begin, end and out, and copies
all the elements in the range [begin, end) to a sequence of elements starting at out and extending as
far as necessary.
```cpp
    copy(begin, end, out);
    // has the same effect as
    while (begin != end)
        *out++ = *begin++;
```
We should note that the while loop previously shown depends on the use of the postfix version of the
increment operators. These operators differ from the prefix versions, in that begin++ returns a copy
of the original value of begin, incrementing the stored value of begin as a side effect. In other
words:
```cpp
    it = begin++;
```
is equivalent to
```cpp
    it = begin;
    ++begin;
```
The increment operators have the same precedence as *, and they are both right-associative, which
means that *out++ has the same meaning as *(out++). Thus,
```cpp
    *out++ = *begin++;
```
is equivalent to the more verbose
```cpp
    {*out = *begin; ++out; ++begin;}
```

Iterator adaptors are functions that yield iterators with properties that are related to their
arguments in useful ways. The iterator adaptors are defined in <iterator>. The most common
iterator adaptor is back_inserter, which takes a container as it's argument and yields an
iterator that, when used as a destination, appends values to the container. For example
back_inserter(ret) is an iterator that, when used as a destination, appends elements to ret.

#### 6.1.1 Another way to split
Another function that we can write more directly using the standard algorithms is split. The hard
part of writing that function was dealing with the indices that delimited each word in the input
line. We can replace the indices by iterators, and use the standard library algorithms to do much
of the work for us.
For example:
```cpp
bool space(char c) {
    return isspace(c);
}
bool not_space(char c ) {
    return !isspace(c);
}
vector<string> split(const string& str) {
    typedef string::const_iterator iter;
    vector<string> ret;

    iter i = str.begin();
    while (i != str.end()) {
        // ignore leading blanks
        i = find_if(i, str.end(), not_space);

        // find end of next word
        iter j = find_if(i, str.end(), space);

        // copy the charactes in [i, j) 
        if (i != str.end()) {
            ret.push_back(string(i, j));
        }
        i = j;
    }
    return ret;
}
```
The algortihm that we use in this example is find_if. It's first two arguments are iterators
that denote a sequence; the third is a predicate, which tests it's argument and returns true
or false. The find_if function calls the predicate on each element in the sequence, stopping
when it finds an element for which the predicate yields true.

The std library provides an isspace function to test whether a character is a space. However,
that function is overloaded, so that it will work with languages, such as Japanese, that use
other char types, such as wchar_t. It's not easy to pass an overloaded function directly as
an argument to a template function. The trouble is that the compiler doesn't know which 
version of the overloaded function we mean, because we haven't supplied any arguments that
the compiler might use to select a version. Accordingly, we write our own predicates, called
space and not_space, that make clear which version of isspace we intend.

#### 6.1.2 Palindromes
This chapter introduces equal(begin, end, begin2) that compares a sequence to another and
determines whether they contain equal values. As usual the first two iterators passed to 
equal specify the first sequence. The third argument is the starting point for the second
sequence. The equal function assumes that the second sequence is the same size as the first,
so it doesn't need an ending iterator.

#### 6.1.3 Finding URLs
Introduces the *static* storage class specifier. Local variables that are declared to be 
static are preserved across invocations of the function. Thus, we will create and initialize
the string on the first function. Subsequent call will use the object that the first call 
created.

### 6.2 Comparing grading schemes

#### 6.2.1 Working with students records
Purely practical chapter.

#### 6.2.2 Analyzing the grades
Purely practical chapter.

#### 6.2.3 Grading based on average homework grade
Introduces accumulate from the std numeric library. The accumulate function adds the valuies
in the range denoted by it's first two arguments, starting the summation with the value given
by it's third argument.

#### 6.2.4 Median of the completed homework
This chapter introduces the remove_copy, this function takes three iterators and a value. As
with most algorithms, the first two iterators denote the input sequence. The third denotes
the beginning of the destination for the copy. As with copy, the remove_copy algorithm
assumes that there is enough space in the destination to hold all the elemnts that are copied.

### 6.3 Classifying students, revisited

#### 6.3.1 A two-pass solution
Purely practical explanatory chapter.

#### 6.3.2 A single-pass solution
This chapter introduces partitions and stable_partitions; partitions take a sequence and
rearranges it's elements so that the ones that satisfy a predicate precede the ones that
don't satisy it. The stable_partition differenciates from partition in that it keeps
the elements in the same order aside from the partitioning, for example if you have an
array of names that were already in alphabetical order the stable_partition keeps them
in alphabetical order.

Each of the partition algorithms returns an iterator that represents the first element of
the second section.

### 6.4 Algorithms, containers and iterators
Algorithms act on container elements, they don't act on containers.

### 6.5 Details

Type modifiers:
- static type variable:
  For local declarations, declares variable with *static* storage class. The value of variable
  persists acros executions of this scope and is guaranteed to be initialized before the variable
  is used for the first time. When the program exits from the scope, the variable keeps it's
  value until the next time the program enters that scope.

Types:
- void: 
  The built-in type void can be used in a restricted number of ways, one of which is to
  indicate that a function yields no return value.

Iterator adaptors:
are functions that yield iterators. The most common are the adaptors that generate insert_iterators,
which are iterators that grow the associated container dynamically. Such iterators can be used
safely as the destination of a copying algorithm. They are defined in header <iterator>.
- back_inserter(c):
  Yields an iterator on the container c that appends elements to c. The container must support
  push_back, which the list, vector, and the string types all do.

- front_inserter(c):
  Like back_inserter, but inserts at the front of the container. The container must support push_front,
  which list does, but string and vector do not.

- inserter(c, it):
  Like back_inserter, but inserts elements before the iterator it.

Algorithms: Unless otherwise indicated, <algorithm> defines these algorithms.
- accumulate(b, e, t):
  Creates a local variable and initializes it to a copy and initializes it to a copy of t with the
  same type as t. Adds each element in the range [b, e) to the variable, and returns a copy of the
  variable as it's result. Defined in <numeric>.

- find(b, e, t), find_if(b, e, p), search(b, e, b2, e2)
  Algorithms to look for a given value in the sequence [b, e). The find algorithm looks for the value
  t; the find_if algorithm tests each element against the predicate p; the search algorithm looks for
  the sequence denoted by [b2, e2).

- copy(b, e, d), remove_copy(b, e, d, t), remove_copy_if(b, e, d, p)
  Algorithms to copy the sequence from [b, e) to the destination denoted by d. The copy algorithm
  copies the entire sequence; remove_copy copies all elements not equal to t; and remove_copy_if
  copies all elements for which the predicate p fails.

- remove_if(b, e, p)
  Arranges the container so that the elements in the range [b, e) for which the predicate p is false
  are at the front of the range. Returns an iterator denoting one past the range of these "unremoved"
  elements.

- transform(b, e, d, f)
  Runs the function f on the elements in the range [b, e), storing the result of f in d.

- partition(b, e, p), stable_partition(b, e, p)
  Partitions the elements in the range [b, e), based on the predicate p, so that elements for which
  the predicate is true are at the front of the container. Returns an iterator to the first element
  for which the predicate is false, or e if the predicate is true for all elements. The stable_partition
  function maintains the input order among the elements in each partition. 

## 7 Using associative containers

### 7.1 Containers that support efficient look-up
Instead of storing data in a sequential container, we can use an *associative container*. Such
containers automatically arrange their elements into a sequence that depends on the values
of the elements themselves, rather than the sequence in which we inserted them. Moreover,
associative containers exploit this ordering to let us locate particular elements much more
quickly than do the sequential containers, without our having to keep the container ordered
by ourselves.

Associative containers offer efficient ways to find an element that contains a particular value,
and might contain additional information as well. The part of each container element that we
can use for these efficient searches is called *key*.

The most common kind of associative data structure is one that stores key-value pairs, associating
a value with each key, and that let's us insert and retrieve elements quickly based on their keys.
When we put a particular key-value pair into the data structure, that key will continue to be
associated with the same value until we delete the pair. Such a data structure is called an
*associative array*. The most common kind of associative array in C++ is calles a *map*, and,
analogous with other containers, it is defined in te <map> header.

In many ways, maps behave like vectors. One fundamental difference is that the index of a map need
not be an integer; it can be a string, or any other type with values that we can compare so as to
keep them ordered.

### 7.2 Counting words
What happens when we encounter an element for the first time? In that case, the map will not yet 
contain an element with that key. When we index a map with a key that has not yet been seen,
the map automatically creates a new element with that key. The element is value-initialized,
which, for simple types such as int, is equivalent to setting the value to zero. Thus when
we read a new element for the first time we are guaranted that the value of the map[element]
will be zero.

A *pair* is a simple data structure that holds two elements, which are named first and second.
Each element in a map is really a pair, with a first member that contains the key and a second
member that contains the associated value. When we dereference a map iterator, we obtain a value
that is of the pair type associated with the map.

The pair class can hold values of various types, so when we crate a pair, we say what the types
of the first and second data members should be. For a map that has a key of type K and a value
of type V, the associated pair type is pair<const K, V>.

### 7.3 Generating a cross-reference table
This chapter introduces the concept of a default argument. When we give a parameter a default
argument, we're saying that callers can omit that argument if they wish. If they supply an
argument, the function will use it. If they omit the argument, the compiler will substitute
the default.

### 7.4 Generating senteces
Purely problem explanatory chapter.

#### 7.4.1 Representing the rules
Purely problem explanatory.

#### 7.4.2 Reading the grammar
Purely problem explanatory.

#### 7.4.3 Generating the sentence
Purely problem explanatory.

#### 7.4.4 Selecting a random element
Introduces a nrand auxiliary function, rand() really returns only pseudo-random numbers. Many
C++ implementations pseudo-random-number generators give remainders that aren't very random when
the quotients are small integers. For example, it is not uncommon for successive results of rand()
to be alternately even and odd. In that case, if n is 2, successive results of rand() % n will
alternate between 0 and 1.

To avoid these pitfalls, we use a different strategy, by dividing the range of available random
numbers into buckets of exactly equal size. Then we can compute a random number and return
the number of the corresponding bucket. Because the buckets are of equal size, some random
nmbers may not fall into any bucket at all. In that case, we keep asking for random numbers until
we get one that fits.

### 7.5 A note on performance
Hash tables can be very fast but they have compensating disadvantages:
- For each key type, someone must supply a hash function, which computes an appropiate integer
value from the value of the key.
- A hash table's performance is exquisitely sensitive to the details of the hash function.
- There is usually no easy way to retrieve the elements of a hash table in a useful order.
C++ associative containers are hard to implement in term of hash tables.
- The key type needs only the `<` operator or equivalent comparison function.
- The time to access an associative-container element with a given key is logarithmic in
the total number of elements in that container, regardless of the keys values.
- Associative-container elements are always kept sorted by key.

In other words, although C++ associative containers will typically be slightly slower than the
best hash-table data structures, they perform much better than naive data structures, their
performance doesn't require their users to design good hash functions, and they are more
convenient than hash tables because of their automatic ordering.

### 7.6 Details

The do while statement is similar to the while statement, except that the test is at the end.

Value-initialization: Accessing a map element that doesn't yet exists creates an element with
a value of V(), where V is the type of the values stored in the map. Such an expression is
said to be value-initialized. The most important aspect is that built-in types are initialized
to 0.

rand() is a function that yields a random integer in the range [0, RAND_MAX]. Both rand and
RAND_MAX are defined in <cstdlib>.

pair<K, V> is a simple type whose objects hold pairs of values. Access to these data values
through their names, first and second respectively.

map<K, V> is an associative array with key type K and value type V. The elements of a map are
key-value pairs, which are maintained in key order to allow efficient access of elements by
key. The iterators on maps are bidirectional. Dereferencing a map iterator yields a value of
pair<const K, V>. The map operations include:
- map<K, V> m;
  Creates a new empty map, with keys of type const K and values of type V.

- map<K, V> m(cmp);
  Creates a new empty map with keys of type const K and values of type V, that uses the predicate
  cmp to determine the order of the elements.

- m[k]
  Indexes the map using a key, k, of type K, and returns an lvalue of type V. If there is no entry
  for the given key, a new value-initialized element is created and inserted into the map with
  this key. Because using [] to access a map might create a new element, [] is not allowed on a 
  const map.

- m.begin(), m.end()
  Returns iterators that can be used to access the elements of a map. Note that dereferencing
  one of these iterators yields a key-value pair.

- m.find(k)
  Returns an iterator referring to the element with key k, or m.end() if no such element exists.

## 8 Writing generic functions
This chapter introduces the concept of writing our own abstractions.

These abstractions take several forms. This chapter discusses generic functions, which are functions
with parameter types that we don't know until we call the function.

### 8.1 What is a generic function?
A function is called a *generic function* when the usage implies that we don't know what argument or
result types will be until we use it. The ability to use and create generic functions is a key feature
of the C++ language.

The ways in which a function uses a parameter of unknown type constrain that parameter's type. For
example, if a function has parameters x and y, and computes x + y, then the mere existence of that computation
implicitly requires that x and y have types for which x + y is defined. Whenever you call such a function,
the implementation checks that your argument's types meet the constraints implied by the ways in which the
function uses it's parameters.

The part of the answer to generic functions that lies outside the C++ language is the way in which the std
library organizes the constraints on it's functions parameters. We have already shown one example of this
organization; namely, the notion of an iterator. Some types are iterators; others aren't.

When we say that a particular type is an iterator, we are really saying something about the operations that the
type supports: A type is an iterator if and only if it supports a particular collection of operations in a 
particular way. If we were to set out to write a generic function ourselves, we would do so in a way that relies
only on the operations that every iterator must support. If we were to write our own container then we would have
to supply iterators that support all the appropriate operations.

#### 8.1.1 Medians of unknown type
The language feature that implements generic functions is called *template functoins*.
Templates let us write a signle definition for a family of functions-or types-that behave similarly, except for
differences that we can attribute to the types of their *template parameters*.

The key idea behind templates is that object of different types may nevertheless share common behavior. Template
parameters let us write programs in terms of that common behavior, even though we don't know the specific types
that correspond to the template parameters when we define the template. We do know the types when we use a template,
and that knowledge is available when we compile and link our programs. For generic paramters, the implementation
doesn't need to worry about what to do about objects with types that might vary during execution-only during
compilation.
     
```cpp
  template<class T>
```
The template header tells the implementation that we are defining a template function, and that the function will
take a *type parameter*. Type parameters operate much like function parameters: They define names that can be used
within the scope of the function. However, type parameters refer to types, not to variables. Thus, wherever T appears
in the function, the implementation will assume that T names a type.

#### 8.1.2 Template instantiation
C++ implementations that follow the traditional edit-compile-link model, instantiation often happens not at compile
time, but at link time. It is not until the templates are instantiated that the implementation can verify that
the template code can be used with the types that were specified. Hence, it is possible to get what seem like
compile-time errors at link time.

Most current implementations require that in order to instantiate a template, the definition of the template, not just
the declaration, has to be accessible to the implementation. Generally, this requirement implies access to the source
files that define the template, as well as the header file. How the implementation locates the source file differs
from one implementation to another. Many implementations expect the header file for the template to include the source
file, either directly or via \#include.

#### 8.1.3 Generic functions and types
Subtle type issues arise in the interactions between templates and type conversions. For example, when we call 
accumulate we note that the correctness of our program depends on using the double form of zero, rather than the int.
The reason is that the accumulate function uses the type of it's third argument as the type of it's accumulator.
If that type is int-even if we're adding a sequence of doubles-the addition will be truncated to just the integer
part. In this case, the implementation would let us pass an int, but the sum that we obtained would lack precision.

### 8.2 Data-structure independence
More generally, we would like to write a simple function that deals with values stored in any kind of data structure,
such as a list, a vector, or a string. For that matter, we would like to be able to act on part of a container, rather
than having to use the entire container.

#### 8.2.1 Algorithms and iterators
The easiest way to understand how templates let us write data-structure-independent programs is to look at
implementations of some of the more popular standard-library functions. These functions all include iterators
among their arguments, which identify the container elements on which the functions will act. All standard-library
containers, and some other types, such as string, supply iterators that allow these functions to act on the 
containers elements.

Some containers support operations that others don't. This support, or lack thereof, translates into operations that
some iterators support and others don't. For example, it's possible to access an element with a given index directly
in a vector, but not in a list. Accordingly, if we have an iterator that refers to an element of a vector, the
design of that iterator makes it possible to obtain an iterator that refers to another element of that same vector
by adding the difference between the element's indices to the iterator. Iterators that refer to list elements offer
no analogous facility.

Because different kinds of iterators offer different kinds of operations, it's important to understand the requirements
that various algorithms place on the iterators that they use, and the operations that various kinds of iterators
support.

The library defines five *iterator categories*, each one of which corresponds to a specific collection of iterator
operations. These iterator categories classify the kind of iterator that each of the library containers provides.
Each standard-library algorithm says what category it expects for each iterator argument. Thus, the iterator
categories give us a way to understand which containers can use which algorithms.

Each iterator category corresponds to a strategy for accessing container elements. Because iterator categories
correspond to access strategies, they also correspond to particular kinds of algorithms.

#### 8.2.2 Sequential read-only access
One straightforward way to access a sequence is to read it's elements sequentially. Among the library functions that
does so is find, which we can implement as
```
template<class In, class X>In find(In begin, In end, const X& x)
{
  while(begin != end && *begin != x)
  {
    ++begin;
  }
  return begin;
}
```
We see that this iterator supports the ++ operator, there is one other operator that such an iterator supports and that
is it->member.

If a type provides all of those operations, we call it an *input iterator*. Every container that we've seen supports all
these operations as well, but that additional support doesn't affect the fact that they are input iterators.

When we say that find requires input iterators as it's first and second arguments, we are saying that we can give find
arguments of any type that meets the input-iterator requirements, including iterators that support additional
operations.

#### 8.2.3 Sequential write-only access
Input iterators can be used only for reading elements of a sequence. Obviously, there are contexts in which we would
like to be able to use iterators to write elements of a sequence. For example, consider the copy function
```
template<class In, class Out>
Out copy(In begin, In en, Out dest)
{
  while (begin != end) 
  {
    *dest++ = *begin++;
  }
  return dest;
}
```
Out supports `*out = value`. As with find, logical completeness argues that we should also be able to evaluate
++dest.

There is one other requirement that is less evident. Suppose it's an iterator that we wish to use for output only, and
we execute
```
*it = x;
++it;
++it;
*it = y;
```
By incrementing it twice between assignments to `*it`, we have left a gap in our output sequence. Therefore, if we 
wish to use an iterator exclusively for output, there is an implicit requirement that we not execute ++it more than once
a between assignments to *it, or assign a value to `*it` more than once without incrementing it.

If a function uses a type in a way that meets these requirements, we call that type an *output iterator*. All the
standard containers provide iterators that meet these requirements, as does back_inserter. It's worth noting that
the "write-once" property is a requirement on programs that use iterators, not on iterators themselves.

#### 8.2.4 Sequential read-write access
Suppose we want to be able to read and write the elements of a sequence, but only sequentially: We intend to advance
iterators forward but never backwards. An example of a library function that does is replace, from the <algorithm>
header
```
template<class For, class X>
void replace(For beg, For end, const X& x, const X& y)
{
  while (beg != end)
  {
    if (*beg == x)
    {
      *beg = y;
    }
    ++beg;
  }
}
```
This function examines the elements in the range [beg, end) and replaces every element that is equal to x by y.
It shouls be clear that the type For needs to support all these operations supported by an input iterator, as well
as all the operations supported by an output iterator.

Moreover, it should not need to meet the single-assignment requirement of output iterators, because it now makes sense
to read the element value after assigning it, and perhaps change it. Such a type is a *forward iterator*, and it is
required to support
```
*it
++it and it++ (but not --it or it--)
it == j and it != j
it->member
```
All the standard-library containers meet the forward-iterator requirements

#### 8.2.5 Reversible access
Some functions need to get at a container's elements in reverse order. The mos straightforward example of such a
function is reverse, which the standard library defines in the <algorithm> header
```
template<class Bi> void reverse(Bi begin, Bi end)
{
  while (begin != end)
  {
    --end;
    if (begin != end)
    {
      swap(*begin++, *end);
    }
  }
}
```
In this algorithm, we march end backward from the end of the vector and beg forward from the beginning, exchanging
the elements that they reference as we go.

This function uses the iterator begin and end as if they were forward iterators, except that it also uses --, which
is obviously the key to being able to traverse a sequence bakwards. If a type meets all the requirements of a forward
iterator, and also supports --, we call it a *bidirectional iterator*.

The standar-library container classes all support bidirectional iterators.

#### 8.2.6 Random access
Some functions need to be able to jump around in a container. One good example of such a function is the classical
binary-search algorithm. The standard library implements this algorithm in several forms, the most straightforward
of which is called binady_search. The standard-library actually uses some clever techniques that allow it to do
binary searches on sequences defined by forward iterators. A simpler version, which requires random-access iterators,
looks like
```
template<class Ran, class X>
bool binary_search(Ran begin, Ran end, const X& x)
{
  while (begin < end)
  {
    Ran mid = begin + (end - begin) / 2
    if (x < *mid)
    {
      end = mid;
    } else if (*mid < x)
    {
      begin = mid + 1;
    } else
    {
      return true;
    }
  }
  return false;
}
```
In addition to relying on the other usual iterator properties, this functions relies on the ability to do arithmetic
on iterators. For example, it substracts one iterator from another to obtain an integer, and adds an iterator and an
integer to obtain another iterator. Again, the notion of logical completeness adds requirements to random-access
iterators. If p and q are such iterators, and n is an integer, then the complete list of additional requirements, 
beyond those for bidirectional iterators, is
```
p + n, p - n, and n + p
p - q
p[n] (equivlent to *(p + n))
p < q, p > q, p <= q, and p >= q
```

The vector and string iterators are random-access iterators. However, the list iterator is not; it supports only
bidirectional iterators.

The essential reason that list don't support random-access iterators is that lists are optimized for fast insertion
and deletion. Hence, there is no quick way to navigate to an arbitrary element of the list. The only way to navigate
through a list is to look at each element in sequence.

#### 8.2.7 Iterator ranges and off-the-end values
Simple theory.

### 8.3 Input and output iterators
Introduces istream iterator and the ostream_iterator. We can use them to insert elements into a container or read
elements from a container.

### 8.4 Using iterators for flexibility
Purely practical chapter.

### 8.5 Details
- Template functions that return simple types have the form
```cpp
  template<class type-parameter [, class type-parameter]...>
  ret-type function-name (parameter-list)
```
Each type parameter is a name that may be used inside the function definitio wherever a type is required.
Each of these names should be used in the function parameter-list to name the type of one or more parameters.

If the types do not all appear in the argument list, then the caller must qualify the function-name with the
actual types that cannot be inferred. For example,
```cpp
  template<class T> T zero() { return 0; }
```
defines zero to be a template function with a single type parameter, which is used to name the return type.
In calling this function, we must supply the return type explicitly:
```cpp
  double x = zero<double>();
```

The typename keyword must be used to qualify declarations that use types that are defined by the template
type parameters. For example,
```cpp
  typename T::size_type name;
```
declares name to have type size_type, which must be defined as a type inside T.

The implementation automatically instantiates a separate instance of the template function for each set of
types used in a call to the function.

- Iterators: there are five iterator categories. In general, the later categories subsume the operations in
the earlier ones.
  - Input iterator: Sequential access in one direction, input only.
  - Output iterator: Sequential access in one direction, output only.
  - Forward iterator: Sequential access in one direction, input and output.
  - Bidirectoinal iterator: Sequential access in both directions, input and output.
  - Random-access iterator: Efficient access to any element, input and output.

## 9 Defining new types
C++ has two kinds of types: built-in types and class types. Built-in types, so called because they are defined
as part of the core language, include char, int, and double. The types that we've used from the library, such
as string, vector, and istream, are all class types. Except for some of the low-level, system-specific routines
in the input-output library, the library classes rely only on the same language facilities that any programmer
can use to define application-specific types.

Much of the design of C++ rests on the idea of letting programmers create types that are as easy to use as are
the built-in types.

### 9.1 Student_info revisited
Practical explanation.

### 9.2 Class types
As it's most funcamental level, a class type is a mechanism for combining related data values into a data
structure, so that we can treat that data structure as a single entity.

Rather than letting users access data directly, we would like to hide the implementation details of how
things are stored. In particular, we want to require the type's users to access objects only through functions.
To do so, we first need to provide the users with convenient operations for manipulating our objects. These
operations will form the interface to our class.

#### 9.2.1 Member functions
In order to control access to our objects, we need to define an interface that programmers can use.

Essentially, a member function is a function that is a member of a class object. In order to call a member
function, our users must nominate the object of which the function to be called is a member.

When we call a member function, the object of which it's a member is not an argument. Therefore, there is no
entry in the parameter list in which we might be able to say that the member object is const. Instead
we qualify the function itself, thereby making it a *const member function*. Member functions that are
const may not change the internal state of the object on which they are executing.

#### 9.2.2 Nonmember functions
If a function changes the state of an object, then it ought to be a member of that object.

### 9.3 Protection
We would like to hide the data, and allow users to access the data only through our member functions.

C++ supports data hiding by allowing authors of types to say which members of those types are *public*, and
hence accessible to all users of the type, and which parts are *private*, and inaccessible to users of the type.

There are various *protection labels*. Each protection label defines acceessibility of all the members that follow
the label. Labels can occur in any order within a class, and can occur multiple times.

We can use struct or class to define a new type. The only difference between saying struct and class is the
default protection, which applies to every member defined before the first protection label. If we say class,
then every member between the first bracket and the first protection label is private. If, instead, we write
struct, then every member declared between the first bracket and the first protection label is public. 

There is no difference between what we can do with a struct or a class. In fact, there is no way, short of
reading the code, for our users to distinguish whether we used struct or class to define our class type.
Our choice of struct or class can have a useful documentation role. In general, our programming style
is to reserve struct to denote simple types whose data structure we intend to expose.

#### 9.3.1 Accessor functions
Instead of giving our users access to the data member, we add a member function that will give (read-only) access
to the corresponding data value.

The function is a const member function, which takes no arguments and which returns a value that is a copy of
the member data value. By copying the value, rather than returning a reference to it, we ensure that users 
can read but not change the value of the meber.

#### 9.3.2 Testing for empty
Purely problem explanatory.

### 9.4 The Student_info class
Purely problem explanatory.

### 9.5 Constructors
*Constructors* are special member functions that define how objects are initialized. There is no way to call
a constructor explicitly. Instead, creating an object of class type calls the appropriate constructor automatically
as a side effect.

If we don't define any constructors, the compiler will synthesize one for us. What we need to know is what happens
if we don't define any constructors. In this case our users will be able to define our objects, but will not be
able to initialize them explicitly, except as a copy of other objects.

The synthesized constructor will initialize the data members to a value that depends on how the object is being
created. If the object is a local variable, then the data members will be default-initialized. If the object
is used to initialize a container element, either as a side effect of adding a new element to a map, or as the
elements of a container defined to have a given size, then the members will be value-initialized. The essentials
are:
- If an object is of a class type that defines one or more constructors, then the appropriate constructor
  completely controls initialization of the objects of that class.
- If an object is of built-in type, then value-initializing it sets it to zero, and default-initializing it gives it
  an undefined value.
- Otherwise, the object can be only of a class type that doesn't define any constructors. In that case, value or
  default-initializing the object value-default-initializes each of it's data members. This initialization process
  will be recursive if any of the data members is of a class type with it's own constructor.

It's normally hood practice to ensure that every data member has a sensible value at all times.

Constructors are distinguished from other member functions in two ways: they have the same name as the name of
the class itself, and they have no return type. constructors are similar to other functions in that we can define
multiple versions of constructors that differ in termos of the number or type of their arguments.

#### 9.5.1 The default constructor
The constructor that takes no arguments is known as the *default constructor*. It's job is normally to ensure
that it's object's data members are properly initialized. 

When we create a new class object, several steps happen in sequence:
1. The implementation allocates memory to hold the object.
2. It initializes the object, as directed by the constructor's initializer list.
3. It executes the constructor body.

The need to give members a value is especially critical for members of built-in type. If the constructor
fails to initialize such members, objects declared at local scope will be initialized with garbage, which
is almost never correct.

#### 9.5.2 Constructors with arguments
Purely problem explanatory.

### 9.6 Using the Student_info class
Purely problem explanatory.

### 9.7 Details
- User-defined types: can be defined as either structs or classes. The only difference is in the default protection
  that applies to members defined before the first protection label: Members defined after struct are public;
  those defined after class are private.

- Protection labels: control access to members of a class type. *public* members are generally accessible; *private*
  members are accessible only to members of the class. Protection labels can appear in any order and multiple
  times within a class.

- Member functions: Types may define member functions as well as data. Member functions are implicitly called
  on behalf of a specific object. References to member data or functions from within a member function are implicitly
  bound to that object. 

  Member functions can be defined inside or outside the class definition. Defining a member function inside
  the class asks the implementation to expand calls to it inline, thus avoiding function call overhead. Outside
  the class, the name of the function must be qualified to indicate that it's from the class scope.

  Member functions can be defined as const by inserting the const keyword after the parameter list. Such members
  may not change the state of the object on which they are invoked. Only const member functions may be called
  for const objects.

- Constructors are special member functions that define how objects of the type are initialized. Constructors have
  the same name as the class and have no return value. A class can define multiple constructors as long as they
  differ in the number or types of their arguments. It's good practice for every constructor to ensure that every
  data member has a sensible value on exit from the constructor.

- Constructor initializer list: is a comma-separated list of member-name(value) pairs. Each member-name is
  initialized from the associated value. Data members that are not explicitly initialized are implicitly
  initialized.

  The order in which members are initialized is determined by the order of declaration in the class, so care must be
  taken when using one class member to initialize another. It's safer to practice to avoid such interdependence
  by assigning values to these members inside the constructor body and not initializing them in the constructor
  initializer.

## 10 Managing memory and low-level data structures
We use the therm *low-level* to refer to these ideas because they underline the standard library and because they
correspond closely to the way typical computer hardware works. For these reasons, they tend to be harder to use,
and are more dangerous, but they sometimes can be more efficient-provided that you understand them thoroughly-than
are the related ideas in the standard library.
Because no library can solve all problems, many C++ probrams wind up using low-level techniques form time to time.

### 10.1 Pointers and arrays
An array is a kind of container, similar to a vector but less powerful. A pointer is a kind of random-access
iterator that is essential for accessing elements of arrays, and has other uses as well. Pointers and arrays
are amongst the most primitive data structures in C and C++. They are virtually inseparable from one another,
in the sense that it's impossible to do anything useful with an array without using pointers, and pointers
become much more useful in the presence of arrays.


#### 10.1.1 Pointers
A *pointer* is a value that represents the *address* of an object. Every distinct object has a unique address,
which denotes the part of the computer's memory that contains the object. If you can access an object, you can
obtain it's address, and vice versa. For example, if x is an object, then &x is the address of that object,
and if p is the address of an object, then \*p is the object itself. The & in &x is an *address operator*, and is
distinct from the use of &. The * is a *dereference operator*, which works analogously to the way * works when
it's applied to any other iterator. If p contains the address of x, we also say that p is a *pointer* that *points*
to x.

As with other built-in types, a local variable that is a pointer has no meaningful value until we give it one.
Programmers frequently use the value 0 to initialize pointers, because converting 0 to a pointer yields a value
that is guaranteed to be distinct from a pointer to any object. Moreover, the constant 0 is the only integer value
that can be converted to a pointer type. The resulting value, often called a *null pointer*, is often useful
in comparisons.

As with all C++ values, pointers have types. The address of an object of type T has type "pointer to T", written
as T\* in definitions and similar contexts.

Suppose that x is an object of type int, defined as
```cpp
    int x;
```
and we want to define p to have a type that will allow p to contain the address of x. We do so by saying that the
type of p is "pointer to int", which we say implicitly by defining \*p to have type int:
```cpp
    int *p; // *p has type int
```
here \*p is a *declarator*, which is the part of a definition that defines a single variable. Even though the * and
the p are part of a single declarator, most C++ programmers write this definition as
```cpp
    int* p;
```
to emphasize the notion that p has a particular type. These two usages are equivalent because spaces around the *
are neutral. However, the latter usage conceals a pitfall that is so important that it deserves special attention.
```cpp
    int* p, q; // What does this definition mean?
```
defines p as an object of type "pointer to int" and q as an object of type int. This example is easier to
understand if we view it this way
```cpp
    int *p, q; // *p and q have type int
```
Still better, we can make our intentions crystal clear by writing
```cpp
int* p;
int q;
```

It may be useful to think of a pointer to an object as an iterator that refers to the only element of a "container"
that contains that object and nothing else.

#### 10.1.2 Pointers to functions
Functions aren't objects, and there is no way for a program to create or modify a function-only the compiler can
do that. All that a program can ever do with a function is call it or thake it's address.

Nevertheless, we can call a function with another function as an argument. What happens is that the compiler quietly
translates such calls so as to use pointers to functions instead of using functions directly. Pointers to functions
behave similarly to any other pointers. Once you have dereferenced such a pointer, however, all you can do with
the resulting function is call it-or take the function's address yet again.

```cpp
    int (*fp)(int);
```
with this we are saying that if we dereference fp, and call it with an int argument, the result has type int.
By implication, fp is a pointer to a function that takes an int argument and returns an int result.

Because all that you can do with a function is to take it's address or call it, any use of a function that is not
a call is assumed to be taking it's address, even without an explicit &. Similarly, you can call a pointer to a
function without dereferencing the pointer explicitly. So, for example, if we have a function whose type matches
fp, such as
```cpp
    int next(int n)
    {
        return n + 1;
    }
```
then we can make fp point to next by writing either of the following two statements:
```cpp
    fp = &next;
    fp = next;
```
Similarly, if we have an int variable named i, we can use fp to call next, and thereby increment i, by writing
either
```cpp
    i = (*fp)(i);
    i = fp(i);
```

Finally, if we write a function that looks like it takes another function as a parameter, the compiler quietly
translates the parameter to be a pointer to a function instead.

However, this automatic translation doesn't apply to return values from functions. If we wanted to write a function
pointer then we would have to say explicitly that the function returns a poitner.

Pointers to functions are most commonly used as arguments to other functions. As an example, here is a sample
implementation of the *find_if* library function:
```cpp
    template<class In, class Pref>
    In find_if(In begin, In end, Pred f)
    {
        while (begin != end && !f(*begin))
            ++begin;
        return begin;
    }
```

#### 10.1.3 Arrays
An *array* is a kind of container that is part of the core language rather than part of the standard library.
Every array contains a sequence of one or more objects of the same type. The number of elements in the array
must be known at compile time, which requirement implies that arrays cannot grow or shrink dynamically the way
library containers do.

Because arrays are not class types, they have no members. In particular, they don't have the *size_type* member
to name an appropriate type to deal with the size of an array. Instead, the <cstddef> header defines *size_t*,
which is a more general type. The implementation defines *size_t* as the appropriate unsigned type large enough
to hold the size of any object. Thus, we can (and should) use *size_t* to refer to the size of an array,
similarly to the way we use *size_type* to deal with the size of a container.

For example, a three-dimensional geometry program might represent a point this way:
```cpp
    double coords[3];
```
knowing that the number of dimensions in physical space is unlikely to change any time soon. A more experienced
programmer might represent the point this way.
```cpp
    const size_t NDim = 3;
    double coords[NDim];
```
taking advantage, for documentation purposes, of the fact that the value of NDim is known at compilation time.
Using NDim instead of 3 distinguishes the 3 that represents the number of dimensions from a 3 that represents,
say, the number of sides in a triangle.

No matter how we define an array, there is always a fundamental relationship between arrays and pointers: Whenever
we use the name of an array as a value, that name represents a pointer to the initial element of the array. We
have defined coords as an array, so using coords as a value gives us the address of the array's initial element.
As with any other pointer, we can dereference it with the * operator to get the object to which it points, so
that executing
```cpp
    *coords = 1.5;
```
sets the initial element of coords to 1.5.

#### 10.1.4 Pointer arithmetic
If p points to the mth element of an array, then p + n points to the (m + n)th element of the array and (p - n)
points to the (m - n)th element-assuming that these elements exits.

Continuing the example, we se that coord + 1 is the address of element number 1 of the coords array(the element
after the initial element), and coords + 2 is the address of element number 2, which is also the last element
because we defined coords as an array of 3 elements.

What about coords + 3? That value represents the address of where elment 3 would be in the coords array if the
element existed-but the element doesn't exist.

Nevertheless, coords + 3 is a valid pointer, even though it doesn't point to an element. Analogous with vector
and string iterators, adding n to the address of the initial element of an n-element array yields an address that
is not guaranteed to be the address of any object, but it's one that we can use for comparisons. Moreover, the
rules that relate p, p + n and p - n are valid even if one or more of those expressions yields a value that is one
(but not more than one) past the end of an array.

So, for example, we can copy the contents of coords into a vector by writing
```cpp
    vector<double> v;
    copy(coords, coords + NDim, back_inserter(v));
```

As another example, because we can construct a vector from two iterators, we could have constructed v directly as
a copy of the elements in coords by writing
```cpp
    vector<double> v(coords, coords + NDim);
```

In other words, suppose that a is an n-element array, that v is a vector, and that we want to apply standard-library
algorithms to elements of a. Then, wherever we might use v.begin() and v.end() to give std-library algorithms
access to elements of v, we should use a and a + n as arguments when we wish to apply these algorithms to the
elements of a.

If p and q are pointers to elements of the same array, then p - q is an integer that represents the distance
between p and q. More precisely, p - q is defined so that (p - q) + q is equal to p. Because p - q might be 
negative, it has a signed integer type. Whether that type is int or long depends on the implementation, so the
library provides a synonym, named *ptrdiff_t*, to represent the appropriate type. Like *size_t*, the *ptrdiff_t*
is defined in the <cstddef> header.

#### 10.1.5 Indexing
Pointers are random-access iterators for arrays. Therefore, like all random-access iterators, they support indexing.
Specifically, if p points to the mth element of an array, p[n] is the m + nth elementh of the array-not the address
of th element, but the element itself.

The name of an array is the address of the initial element. This fact, together with the definition of p[n], implies
that if a is an array, a[n] is the nth element of the array. More formally, if p is a pointer and n is an integer,
then p[n] is equivalent to \*(p+n).

#### 10.1.6 Array initialization
Arrays have an important property that the standard-library containers don't share: there is a convenient syntax
for givin an initial value to each element of an array. Moreover, using this syntax often let's us avoid having
to state the size of the array explicitly.

For example, if we were writing a program that deals with dates, we might like to know how many days are in each
month. One way to do so would be the following:
```cpp
    const int month_lengths[] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };
```
Here, we have given an initial value to each element that corresponds to the lenght of a montg, with January
being month 0 and December being month 11. Now, we can use *month_lengths[i]* to refer to the length of month i.

### 10.2 String literals revisited
A string literal is really an array of const char with one more element than the number of characters in the
literal. That extra character is a null character (i.e., '\0') that the compiler automatically appends to the
rest of the characters. in other words, if we define
```cpp
    const char hello[] = {'H', 'e', 'l', 'l', 'o', '\0'};
```
then the variable hello has exactly the same meaning as the string literal "Hello", except, of course, that the
variable and the literal are two distinct objects and, therefore, have different addresses.

The reason that the compiler inserts the null character is to allow the programmer to locate the end of the
literal given only the address of the initial character. There is a library function in <cstring> called strlen,
which tells us how many characters are in a string literal or other null-terminated array of characters, not
counting the null at the end.
```cpp
    size_t strlen(const char* p)
    {
        size_t size = 0;
        while (*p++ != '\0')
        {
            ++size;
        }
        return size;
    }
```

### 10.3 Initializing arrays of character pointers
We can initialize an array of character pointers by giving a sequence of string literals.

sizeof() determines how many elements there are in an array. If e is an expression, then sizeof(e) return a
*size_t* value that tells us how much memory an object of type e consumes. It does so without actually evaluating
the expression, which is possible because it doesn't need to evaluate the expression in order to determine it's
type, and because all objects of a given type occupy the same amount of storage.

The sizeof operator reports it's results in *bytes*, which are storage units whose exact nature varies from one
implementation to another. The only guarantees about bytes are that a byte contains at leas eight bits, every
object occupies at least one byte, and that a char occupies exactly one byte.

### 10.4 Arguments to main
Most operating systems provide a way to pass a sequence of character strings to main as an argument, if the main
function is willing to accept them. The way the author of main signals such willingness is by givin main two
parameters: an int and a pointer to a pointer to char. Like any parameters, these can have arbitrary names, but
programmers often call them argc and argv. The value of argv is a pointer to the initial element of an array of
pointers, one for each argument. The value of argc is the number of pointers in the array of which argv points to
to the initial element. The initial element of that array always represents the name by which the program is called,
so argc is always at least 1. The arguments, if any, occupy subsequent elements of the array.

```cpp
    int main(int argc, char** argv)
    {
        if (argc > 1) {
            int i;
            for (i = 1; i < arc - 1; ++i) {
                cout << argv[i] << " ";
            }
            cout << argv[i] << endl;
        }
        return 0;
    }
```

### 10.5 Reading and writing files
Larger applications often need to work with multiple files, both for input and output. C++ offers a wide variety of
facilities for doing so.

#### 10.5.1 The standard error stream
To make comments easy to distinguish from ordinary output, the C++ library defines a *standard error* stream, in
addition to the standard input and output streams. This stream is often merged with the standard output, but
most system provide a way to separate them.

To write to the standard error stream, C++ programs can use eiter *cerr* or *clog*. These output streams are both
attached to the same destination. The difference between them is how they handle buffering.

The clog stream, as it's name suggests, is intended for logging purposes. Accordingly, it has the same buffering
properties as cout: It saves characters and writes them when the system decides that it's appropriate to do os.
The cerr stream, on the other hand, always writes it's output inmediately. This strategy guarantees that the
output will become visible as soon as possible, but it imposes what might be substantial overhead. Therefore,
to write an urgent, complaint, you should use cer; to produce a running commentary about what the program
is doing, you should use clog.

#### 10.5.2 Dealing with multiple input and output files
The standard input, output and error streams might or might not be associated with files. For example, a 
window system might run C++ programs with these streams connected to a window associated with the program,
and might use completely different facilities to do so than it would to access disk files.

For this reason, the objects that the C++ standard library uses for file input and output have different
types than the objects that it uses to denote the standard input and output streams. If you wish to work
with an input or output file, you must create an object of type *ifstream* or *ofstream* respectively.

It's possible to use an ifstream wherever the library expects an istream and an ofstream wherever the library
expects an ostream. The definitions of both of these classes appear in header <fstream>.

When we define an ifstream or ofstream object, we might expect to have to supply, in the form of a string,
the name of the file that we wish to use. In fact, we are required to supply not a string, but rather a poitner
to the initial element of a null-terminated character array.

### 10.6 Three kinds of memory management
So far, we have seen two distinct kinds of memory management, although we have not discussed them explicitly. The
first kind is usually claled *automatic* memory management, and is associated with local variables: A local variable
occupies memory that the system allocates when it encounters the variable's definition during execution. The system
automatically deallocates that memory at the end of the block that contains the definition.

Once a variable has been deallocated, any pointers to it become invalid. It's the programmer's responsability
to avoid using such invalid pointers. For example:
```cpp
    int* invalid_pointer()
    {
        int x;
        return &x;
    }
```
This function returns the address of the local variabl x. Unfortunately, when the function returns, doing so ends
execution of the block that contains the definition of x, which deallocates x. The pointer that &x created is now
invalid, but the function tries to return it anyway.

If we want to return the address of a variable such as x, one way to do so is to use the other kind of memory
management, by asking x to be *statically allocated*:
```cpp
    int* pointer_to_static()
    {
        static int x;
        return &x;
    }
```
However, static allocation has the potential disadvantage that every call to *pointer_to_static* will return a pointer
to the same object. Suppose we want to define a function such that each time we call it, we get a pointer to a brand
new object, which stays around until we decide that we no longer want ir. To do so, we use *dynamic allocation*, which
we request by using the *new* and *delete* keywords.

#### 10.6.1
If T is the type of an object, new T is an expression that allocates an object of type T, which is
default-initialized, and yields a pointer to this (unnamed) newly allocated object. It's possible to give a
specific value to use when initializing the object by executing new T(args). The object stays around until the
program either ends or executes delete p (whichever happens first), where p is (a copy of) the pointer returned
by new. In order to delete a pointer, the pointer must point to an object that was allocated by new, or be
equal to zero. Deleting a zero pointer has no effect.

We might write a function that allocates an int object, initializes it, and returns a pointer to it:
```cpp
    int* pointer_to_int() {
        return new int(0);
    }
```
which imposes on it's caler the responsability of freeing the object at an appropriate time.

#### 10.6.2 Allocating and deallocating an array
If T is a type and n is a non-negative integral value, new T[n] allocates an array of n objects of type T and returns
a pointer (which has type T\*) to the initial element of the array. Each object is default-initialized, meaning
that if T is a built-in type and the array is allocated at local scope, then the objects are uninitialized. If
T is a class type, then each element is initialized by running it's default constructor.

To deallocate an entire array, rather than a single element, is necssary to use delete[]. An array allocated
by new[] stays around until the program ends or until the program executes delete[] p, where p is (a copy of) 
the pointer that new[] yielded. Before deallocating the array, the system destroys each element, in reverse order.

### 10.7 Details
- Pointers are random-access iterators that hold the addresses of objects.
    - p = &s Makes p point to s.
    - \*p = s2 Dereferences p and assigns a new value to the object to which p points.
    - vector<string> (\*sp)(const string&) = split; Defines sp as a function pointer that points to the split function
    - int nums[100] Defines nums as an array of 100 ints.
    - int\* bn = nums; Defines bn as a pointer to the first element of the array nums.
    - int\* en = nums + 100; Defines en as a pointer to (one past) the last element of the array nums.

- Arrays are fixed-size, built-in containers whose iterators are pointers. Uses some of the name of an array
are automatically converted to a poitner to the initial element of the array. A string literal is a null-terminated
array of characters. Indexing an array is defined in terms of pointer operations.

- The main function may optionally take two arguments. The first argument, an int, says how many character arrays
are stored in the second argument, which is a char\*\*. the second argument to main is sometimes written as
```cpp
    char* argv[]
```
which is equivalent to char\*\*. This syntax is legal only in parameter lists.

- Input-Output
    - cerr: Standard error stream. Output is not buffered.
    - clog: Standard error intended for logging. Output is buffered.
    - ifstream(cp): Input stream bound to the file named by the char\* cp.
    - ofstream(cp): Output stream bound to the file named by the char\* cp.

- Memory management
    - new T allocates and default-initializes a new object of type T and returns a pointer to the object.
    - new T(args) allocates and initializes a new object of type T using args to initialize the object.
    - delete p destroys the object to which p points and frees the memory used to hold \*p.
    - new T[n] allocates and default-initializes an array of n new objects of type T.
    - delete[] p destroys the objects in the array which p points and frees the memory used to hold the array.

## 11. Defining abstract data types
The class author controls all the aspects of how an object is copied, assigned or destroyed.

### 11.1 The Vec class
When we design a class, we normally start by specifying the interface that we want to provide. One way to determine
the right interface is to look at the kind of programs we want our users to be able to write.

### 11.2 Implementing the Vec class
The easiest implementation decision is that we need to define a *template class*. We want to allow users to use
Vecs to hold a variety of types. The template facility for functions also applies to classes. That facility let
us write one definition of a template function, and use that template to create versions that could be run on a
variety of types. Similary, we can define a template class, and then use that class to create a family of types
that differ only with respect to the types used in the template parameter list.

#### 11.2.1 Memory allocation
Because the class will allocate it's array dynamically, we might expect that we should allocate space for our Vec
by using new T[n], where n is the number of elements we want to allocate. However, remember that not only does
new T[n] allocate space, but it also initializes the elements by running the default constructor for T. If we were
to use new T[n], then we would be imposing a requirement on T: users could create a Vec<T> onyl if T has a default
constructor.

It turns out that the library provides a memory allocation class that offers more detailed control over memory
allocation. This class will suit our needs exactly, if we use it instead of new and delete. The class lets us
allocate raw memory, and then-in a separate step-build objects in that memory.

These new utility members will be part of the private implementation of our class. They will be responsible for
allocating and deallocating the memory that we need, and for initializing and destroying the elements stored in
the Vec. Thus, these functions will manage the pointers-data and limit. Only these memory management functions
will give new values to these data members.

When the public members need to do something, such as constructing a new Vec that needs to change the value of data
or limit, they will call an appropriate memory management function to do os.

#### 11.2.2 Constructors
The role of any constructor is to ensure that the object is correctly initialized. For Vec objects, we need to 
initialize data and limit. Doing so involves allocating space to hold the elements of the Vec and initializing
those elements to an appropriate value. In the case of the default constructor, we want to create an empty Vec,
so we need not allocate any space. For the constructors that take a size, we will allocate the given amount of
storage. If the user gives us an initial value as well as size, we'll use that value to initialize all the elements
that we allocated. If the user gives us just a size, then we'll use the default constructor for T to obtain a value
to use in initializing the elements.

The *explicit* keyword makes sense only in the definition of a constructor that takes a single argument. When
we say that a constructor is explicit, we're saying that the compiler will use the constructor only in contexts
in which the user expressly invokes the constructor, and not otherwise.
```cpp
    Vec<int>vi(100); // ok, explicitly construct the Vec from an int
    Vec<int> vi = 100; // error: implicitly construct the Vec and copy it to vi.
```
Use of explicit can be crucial in other contexts in which a constructor might be used.

#### 11.2.3 Type definitions
The library containers also define another type, names *value_type*, that is a synonym for the type of the objects
that the container stores.

The only hard part of defining these types is deciding what types to choose. Iterators are objects that navigate
among the objects in a container and let us examine their values. Often iterators are themselves of class type.
For example, consider a class that implements a linked list. A logical strategy for such a class would be to
model a list as a set of nodes, where each node contains a value and a pointer to the next node in the list.
The iterator for such a class would contain a pointer to one of these nodes and would implement the ++ operator to
follow the pointer to the next node in the list. Such an iterator would have to be implemented as a class type.

Because we used an array to hold the elements of a Vec, we can use plain pointers as our Vec iterator type. Each
pointer will point into the underlying data array.
By using pointers as our underlying iterator type, we will provide full random-access properties, which is consistent
with the standard vector class.

What about the other types? the type of a *value_type* is obvious: it must be T. But, what about the type that
represents the size? We know *size_t* is big enough to hold the number of elements in any array. Because we
are storing Vecs in an array, we can use *size_t* as the underlying type for *Vec::size_type*.

#### 11.2.4 Index and size
We define an overloaded operator much as we define any other function: It has a name, takes arguments, and specifies
a return type.

We form the name of an overloaded operator by appending the operator symbol to the word operator. Thus, the function
we need to define will be called operator[], for an overload of the [] operator.

The kind of operator-whether it's a unary or binary operator-is part of what determines how many parameters the 
corresponding function has. If the operator is a function that is not a member, then the functions has as many
arguments as the operator has operands. The first argument is bound to the left operand; the second is bound to
the right operand. If the operator is defined as a member function, then it's left operand is implicitly bound to
the object on which the operator is invoked. Member operator functions, therefore, take one less argument than
the operator indicates.

In general, operator functions may be member or nonmember functions. However, the index operator is one of a handful
of operations that must be member functions. When our user writes an expression such as vi[i], that expression will
call the member named operator[] of vs, passing i as it's argument.

The index operator finds the corresponding position in the underlying array and returns a reference to the element.
By returning a reference, we allow the user to use th eindex operation to change the values that are stored in 
the Vec. This ability to write to the element implies that we need two verions: one for const Vec objects, the other
for non const objects of type Vec. Note that the const version returns a reference to const. Doing so ensures
that users may use the index only to read the Vec, not to write to it. It's worth noting that we still return a
reference, rather than returning a value. The reason to return a reference is that if the objects stored in the
container are large, it's more efficient to avoid copying them.

Every member function, including operators overloaded, takes an implicit parameter, which is the object on which
it operators.

#### 11.2.5 Operations that return iterators
Easy returning of iterators explanation.

### 11.3 Copy control
Introduction and explanation to why we need copy control

#### 11.3.1 Copy constructor
Passing an object by value to a function, or returning an object by value from a function, implicitly copies the
object.

Similarly, we can explicitly copy an object by using it to initializate another.

Both explicit and implicit copies are controlled by a special constructor called the *copy constructor*. The copy
constructor is a member function with the same name as the name of the class. Because it exists to initialize a new
objects as a copy of an existing object of the same type. Because we are defining what it means to make a copy,
including making copies of function arguments, this is one case when it's essential that the parameter be a reference
type! Furthermore, copying an object shouldn't change the object being copied from, so the constructor takes a const
reference to the object from which to copy.

#### 11.3.2 Assignment
Class definition also controls the behavior of the *assignment operator*. Although a class may define several 
instances of the assignment operator-overloaded, as usual, by differing types for it's argument-the version
that takes a const reference to the class itself is special: it defines what it means to assign one value of
the class type to another. This version is typically called "the assignment operator", even if the class defines
several other versions of the operator= function. The assignment operator like the index operator must be a member
of the class.

Assignment differs from the copy constructor in that assignment always involves obliterating an existing value
and replacing it with a new value. When we make a copy, we are creating a new object for the first time, so there
is no preexisting object to deallocate. Like the copy constructor, assignment usually involves assigning each of
the data values. Data members that are pointers present the same issues for assignment as they did for copying.
We'll want assignment to ensure that each object has it's own copy of the data from the righ hand side.

It's possible that a user might wind up assigning an object to itself. It's crucial that assignment operators
deal correctly with self-assignment.

The *this* keyword is valid only inside a member function, where it denotes a pointer to the object on which
the member function is operating. For example, inside the Vec::operator=, the type of this is Vec\*, because
this is a pointer to the Vec object of which operator= is a member.

Whe use this to determine whether the right and left-hand sides of the assignment refer to the same object. If
they do, then they will have the same address. If the objects are the same, then there's nothing to do in the
assignment operator, and we inmediately fall through to the return statement. If the objects are different, we
need to free the old space and assign new values to each data element, copying the contents from the right-hand
side to the newly allocated array.

It's crucially important that assignment operators correctly handle self-assignment. To see the importance, consider
what would happen if we were to remove this test from our assignment operator. In that case, we would always
uncreate the existing array from the left-hand operand, destroying the elements and returning the space that had
been used. However, if the two operands were the same object, then the right operand would refer to this same space.

The last interesting bit is the return statement, which dereferences this to obtain the object to which it points. We
then return a reference to that object. As usual in returning a reference, it's crucial that the object to which
the reference refers persists after the function has returned. Returning a reference to a local objects
ensures disaster: The referenced object will have gone away when the function returns, resulting in a reference to
garbage.

In the case of the assignment operator, we are returning a reference to the object that is the left-hand side of
the expression. That object exists outside the scope of the assignment operator and hence is guaranteed to be
around even after the function returns.

#### 11.3.3 Assignment is not initialization
When we use = to give an initial value to a variable, we are invoking the copy constructor. When we use it in an
assignment expression, we're calling operator=. Class authors must be attuned to the differnece in order to
implement the right semantics.

The key difference stems from two observations: Assignment(operator=) always obliterates a prevoius value;
initialization never does so. Rather, initialization involves creating a new object and giving it a value at the
same time.

#### 11.3.4 Destructor
An object that is created in a local scope is destroyed as soon as it goes out of scope; a dynamically allocated
object is destroyed when we delete a pointer to the object.

Just as with copy and assignment, it's up to the class to say what happens when objects are destroyed. Like 
constructors which say how to create objects, there is a special member function, called a *destructor*, that
controls what happens when objects of the type are destroyed. Destructors have the same name as the name of
the class prefixed by a tilde(~). Destructors take no arguments and have no return value.

The work of the destructor is to do any cleanup that should be done whenever an object goes away. Typically,
this cleanup involves releasing resources, such as memory, that the constructor has allocated.

#### 11.3.5 Default operations
If the class author doesn't specify the copy constructor, assignment operator or destructor the compiler
synthesizes default versions of the unspecified operations.

The default versions are defined to operate recursively-copying, assigning or destroying each data member according
to the appropriate rules for the type of that element.

There is a default for the default constructor. If the class defines no constructors at all, then the compiler
will synthesize the default constructor, which is the constructor that has no parameters. The synthesized
default constructor recursively initializes each data member in the same way as the object itself is initialized.

#### 11.3.6 The rule of three
Classes that manage resources such as memory require close attention to copy control. In general, the default
operations will not suffice for such cases. Failure to control every copy can confuse users of the class and
often will lead to run-time errors.

Classes that allocate resources in their constructors require that every copy deal correctly with those resources.
Such classes almost surely need to free the resources. If the class needs a destructor, it almos surely needs a copy
constructor, as well as an assignment operator.

Because the copy constructor, destructor and assignment operator are so tightly coupled, the relationship among
them has become known as the *rule of three*: if your class needs a destructor, it probably needs a copy constructor
and an assignment operator too.

### 11.4 Dynamic vecs
There is a classic approach to solving the problem of extending arrays: allocate more storage than we need. Only
when we exhaust the preallocated storage will we go back for more. For simplicity, whenever *push_back* needs to get
more space, we'll allocate twice as much storage as we currently use. So, if we create Vec with 100 elements, and
then call *push_back* for the first time, it will allocate enough space to hold 200 elements. It will copy the
existing 100 elements into the first half of the newly allocated space and construct a new, last element at the
end of that sequence. The next 99 calls to *push_back* will be satisfied without having to go back for more memory.

### 11.5 Flexible memory management
The <memory> header provides a class, called allocator<T>, that allocates a block of uninitialized memory that is
intended to contain objects of type T, and returns a pointer to the initial element of that memory. Such pointers
are dangerous, because their type suggests that they point to objects, but the memory doesn't really contain
those objects yet. The library also provides a way to construct objects in that memory, and to destroy the objects
again-all without deallocating the memory itself. It's up to the programmer using the allocator class to keep track
of which space holds the constructed objects and which space is still uninitialized.

The allocate member allocates typed but uninitialized storage sufficient to hold the requested number of elements.
By typed storage, we mean that it will be used to hold values of type T, and that we will use pointers of type T\*
to address it. By uninitialized storage, we mean that the memory is raw storage, and no objects have yet been
constructed in it. The deallocate member frees this uninitialized storage. It takes a pointer that was allocated
by allocate, and a size that indicates how many elements were allocated. The construct and destroy members construct
or destroy a single object in this unintialized space. We call construct, passing it a pointer into space that was
allocated by allocate, and a value to copy into that space. The destroy function runs the destructor for T on the
element indicated by it's argument.

The two companion functions that we need are named *uninitialized_copy* and *uninitialized_fill*. These functions
initialize elements in space that is allocated by allocate. The *uninitialized_fill* function fills this uninitialized
space with the specified value. When the function completes, each of the elements in the range specified by the first
two arguments will be a newly constructed copy of the value specified in the third argument. The *uninitialized_copy*
function operates like the copy function, in that it copies values from a sequence specified by it's first two 
arguments into a target sequence denoted by it's third argument. Like *uninitialized_fill*, it assumes that the
target range contains raw storage, rather than elements that already hold values, and it constructs new objects in
that memory.

#### 11.5.1 The final Vec class
Purely problem explanatory.

### 11.6 Details
- Template classes can be formed using the template facility
```cpp
    template<class type-parameter [, class type-parameter]...>
    class class-name {...};
```
creates a template class named class-name that depends on the given type parameters. Theset type-parameter names
may be used inside the template wherever a type is required. In th escope of the class, the template class may
be referred to without qualification; outside the class scope, class-name must be qualified with the type parameters
```cpp
    template<class T>
    Vec<T>& Vec<T>::operator=(const Vec&) {...}
```
Users specify the actual types when creating objects of themplate types: Vec<int> causes the implementation
to instantiate a version of Vec binding the type parameter to int.

- Copy control: in general, classes control what happens when objects are created, copied, assigned, or destroyed.
Constructors are invoked as a side effect of creating or copying objects; the assignment operator is invoked in
expressions involving assignment; and the destructor is run automatically when objects are destroyed or go
out of scope.

Classes that allocate resources in a constructor almost invariably must define the copy constructor, the assignment
operator and the destructor. When we write an assignment operator, it's essential for us to check for self-assignment.
For consistency with the built-in assignment operators, it's good practice to return a reference to the left-hand
operand.

- Synthesized operations: if a class defines no constructors, the compiler will synthesize the default constructor,
assignment operator and/or destructor. The synthesized operations are defined recursively: each synthesized operator
recursively applies the appropriate operation for the data members of the class.

- Overloaded operators are defined by defining a function named operator op, where op is the operator beign defined.
At least one parameter must be of class tpye. When an operator function is a member of a class, it's left-hand
operand (if it's a binary operator) or it's only operand (if it's an unary operator) is bound to the object on which
it's invoked. The index operator and the assignment operator must be class members.

## 12 Making class objects act like values
Objects of built-in types generally behave like values: Whenever we copy an object of such a type, the original
and the copy have the same value but are otherwise independent. Subsequent changes to one object do not
affect the other. We can create objects of these types, pass them to and form functions, copy them, or assign
them to other objects.

For most of the built-in types, the language also define a rich set of operators and provides automatic conversion
between logically similar types.

When we define our own classes, we control the extent to which the resulting objects behave like values. By
defining copying and assignment appropriately, the class author can arrange for objects of that class to act like
values. The class author can arrange for each object to have state that is independent of any other object.

The class author can also control conversions and related operations on class objects, thereby providing classes
whose objects behave even more similarly to objects of built-in types.

### 12.1 A simple string class
Problem explanatory.

### 12.2 Automatic conversions
Values of built-in type can often be converted automatically from one type to another.

User-defined conversions say how to transform to and from objects of class type. As with built-in conversions,
the compiler will apply user-defined conversions to convert a value into the type that is needed.

A class can define conversions in two ways: It can convert from other types to it's type, or from it's type
to other types. The more common conversion defines how to convert other types to the type that we are defining.
We do so by defining a constructor with a single argument.

### 12.3 Str operations
Problem explanatory.

#### 12.3.1 Input-output operators
For a binary operation, the left operad is always bound to the first parameter, and the right operand is bound to
the second. In the case of member operator functions, the first parameter (the left operand) is always the one
that is passed implicitly to the member functions. Thus,
```cpp
    cin >> s;
```
is equivalent to
```cpp
    cin.operator>>(s);
```
which calls the overloaded >> operator defined for the object cin. This behavior implies that the >> operator
must be a member of class istream.

Of course, we don't own the definition of istream, so we cannot add this operation to it. If instead we make
operator>> a member of Str, then our users would have to invoke the operation on behalf of a Str:
```cpp
    s.operator>>(cin);
```
or equivalently,
```cpp
    s >> cin;
```
which would flout the conventions used throughout the library. Therefore, we can conclude that the input-and, by
analogy, the output-opretor must be a nonmember.

#### 12.3.2 Friends
The input operator isn't much harder to write than the output iterator. It needs to read and remember characters
from the input stream. Each time we call the input operator, it should read and discard any leading whitespace,
and then read and remember the charactes until it hits whitespace or eof.

The input operator needs to be able to write data, not just read it. The input operator is a part of our general
Str abstraction, so giving it write access to data is fine. On the other hand, we don't want all users to have
write access to data, so we cannot solve the problem by adding a public member that would let operator>>
write to data.

Rather than adding public access function, we can say that the input operator is a *friend* of class Str. A friend
has the same access rights as a member. By making the input operator a friend, we can allow it, along with our
member functions, to access the private members of class Str.
```cpp
    class Str
    {
        friend std::istream& operator>>(std::istream&, Str&);
    }
```

A friend declaration may appear at any point in the class definition: It makes no difference whether it follows
a private or public label. Because a friend function has special access privileges, it's part of the interface
to the class. Therefore, it makes sense to group friend declarations at the beginning of the class definition,
near the public interface for the class.

#### 12.3.3 Other binary operators
Concatenation doesn't change the value of either operand. These facts suggest that there is no particular
reason to decide to make the perator a member function.

We might want to provide our users with operator+= as well. That is, we'd like to let our users assign to s
the value obtained by concatenating s and s1 in either of these forms:
```cpp
    s = s + s1;
    s += s1;
```
It turns out that the most convenient way to implement operator* is to implement operator+= first. Unlike the
simple concatenation operator, the compound version changes it's left operand, so we make it a member of the
Str class.

Recall that concatenation is a nonmember function that will create a new Str. We create this new Str by
initializing a local variable to be a copy of the string passed. That initiialization uses the Str copy constructor.
Next, we invoke the += operator on the new string to concatenate it with the second string passed and then we
return the new Str.

#### 12.3.4 Mixed-type expressions
It's important to understand the implications of conversion operations. For example,
```cpp
    Str greeting = "Hello, " + name + "!";
```
gives greeting the same value as if we had written
```cpp
    Str temp1("Hello, ");  // Str::Str(const char*)
    Str temp2 = temp1 + name; // operator*(const Str&, const Str&)
    Str temp3("!") // Str::Stre(const char*)
    Str greeting = temp2 + temp3; // operator*(const Str&, const Str&)
```
Seeing all these temporaries, we can imagine that this approach might be expensive. In practice, because of the
perceived cost of generating teporaries, commercial string library implementations often take the more tedious
route of defining specific versions of the concatenation operator for every combination of operands, rather
than relying on automatic conversions.

#### 12.3.5 Designing binary operations
If a class supports conversions, then it's usually good practice to define binary operators as nonmember functions.
By doing so, we preserve symmetry between the operands.

If an operator is a member of a class, then that operator's left operand cannot be the result of an automatic
conversion. The reason for this restriction is so that when a programmer writes an expression such as x + y, the
compiler doesn't have to examine every type in the entire program to discover whether it's possible to convert
x to a type that has a member named operator+. Because of the restriction, the compiler has to look only at
nonmember operator+ functions and at operator+ functions that are members of the class x.

The left operand of a nonmember operator, and the right operand of any operator, follow the same rules as any
ordinary function argument: The operand can be of any type that can be converted to the parameter type. If
we make the binary operator a member function, we have introduced an asymmetry with respect to it's operands:
The right operand can be the result of an automatic conversion, but the left operand cannot. Such asymmetries
are fine for intrinsically asymmetric operators such as +=, but in the context of symmetric operands, they
are confusing and error prone.

In the case of the assignment versions of binary operators, we want to constrain the left operand to be of the 
class type. If we allowed conversions for the left operand, then we might convert that operand to the class type and
assign a new value to the resulting temporary. Because that value would be a temporary object, once we completed
the assignment we would have no way to access the object to which we had just assigned! Therefore, like the assignment
operator itself, all of the compound-assignment operators should be members of the class.

### 12.4 Some conversions are hazardous
Now that we know that constructors that take a signle argument define conversions, we can understand what happens
when we make a constructor explicit: doing so tells the compiler to use that constructor only to construct objects
explicitly. The compiler will not use an explicit constructor to create objects implicitly by converting operands
in expressions or function calls.

In general, it's useful to make explicit the constructors that define the structure of the object being constructed,
rather than it's contents. Those constructors whose arguments become part of the object usually shouldn't be explicit.

As an example, the string and Str classes have constructors that take a signle const char* and are not explicit. Each
constructor uses it const char* argument to initialize the value of it's object. Because the argument determines the
value of the resulting object, it's sensible to allow automatic conversions from a const char* in expressions or
function calls.

On the other hand, the vector and Vec constructors that take a signle argument of type Vec::size_type are explicit.
These constructors use their argument value to determine how many elements to allocate. The constructor argument
determines the structure of the object, but not it's value.

### 12.5 Conversion operators
Class authors can also define explicit *conversion operators*, which say how to convert an object from it's type to
a target type. Conversion operators must be defined as members of a class. The name of a conversion operator
is operator followed by the target type name. Thus, if a class has a member called operator double, that member
says how to create a value of type double from a value of the class type.

Conversion operators are most often useful when converting from a class type to a built-in type, but they can also
be useful when converting to another class type for which we don't own the code. In either case, we cannot add
a constructor to the target type, so we can define the conversion operator only as part of the class that we own.

We can now understand what happens in this expression
```cpp
    if (cin >> x) { ... }
```
Using a value of any arithmetic or pointer type automatically converts the value to type bool, so we can use values
of these types as the expression in a condition. Of course, iostream is neither a pointer nor an arithmetic type.
However, the std library defines a conversion from type istream to void\*, which is a pointer to void. It does so
by defining istream::operator void\*, which tests various status flags to determine whether the istream is valid,
and returns either 0 or an implementation-defined nonzero void* value to indicate the state of the stream.

A pointer to void is sometimes called a universal pointer, because it's a pointer that can point to any type of object.
of course, you cannot dereference the pointer, because the type of the object to yield isn't known. But one thing that
can be done with a void* is to convert it to bool, which is exactly how it's used in this context.

### 12.6 Conversions and memory management
The standard string class provides three member functions for getting a char array from a string. The first, *c_str()*,
copies the contents of the string into a null-terminated char array. The string class owns the array, and the user is
expected not to delete the pointer. Data in the array are ephemeral, and will be valid only until the next call of a
member function that might change the string. Users are expected either to use the pointer inmediately or to copy
the data into storage that they will manage. The second function, *data()*, is like *c_str()*, except that it returns
an array that isn't null terminated. Finally, the *copy* function takes a char* and an integer as arguments, and copies
as many characters as indicated by the integer into space pointed to by the char*, which space the user must allocate
and free.

#### 12.7 Details
- Conversions are defined by nonexplicit constructors that take a single argument, or by defining a conversion
operator of the form *operator type-name()*, where *type-name* names the tyoe to which the class type can be converted.
Conversion operators must be members. If two classes define converions to each other's types, ambiguities can result.

- Friend declarations can occur anywhere whithin the class definition, and allow the friend to access private members
of the class granting friendship.
```cpp
    template<class T>
    class Thing 
    {
        friend std::istream& operator>>(std::istream&, Thing&)
    }
```
classes can also be friends.

- Template functions as members: A class may have template functions as members. The clas itself might or might not
be a template. A class that has a template member function effectively has an unbounded family of member functions
with the same name. Template member functions are declared and defined as are any other template functions.

- String operations
    - *s.c_str()*, yields a const char* that points to a null-terminated array. The data in the array are valid until
    the next string operation that might modify s. The user may not delete the pointer and shouldn't hold a copy
    of it because the contents pointed to have a limited lifetime.

    - *s.data()*, similar to *s.c_str()*, but the array is not null-terminated.

    - *s.copy(p, n)*, copies up to an integral number n of characters from s into space pointed to by the character
    pointer p. The user is responsible for ensuring that p points at space that is sufficient to hold n characters.

## 13 Using inheritance and dynamic binding
Chapter explanatory.

### 13.1 Inheritance
Inheritance is one of the cornerstones of OOP. The basic idea is that we can often think of one class as being
just like another, except for some extensions.

We say that a class is derived from another or inherits from another, or equivalently, one class is the base class
of another. Every member of the base clas is also a member of the derived class, except for the constructors, the
assignment operator and destructor. The derived class can add members of it's own and it can redefine members
from the base class. However a derived class cannot delete any of the base class members.

The use of public in a derived class definition says that the fact that the derived class inherits from the base
parts of its interface, rather than part of its implementation. That is the base class inherits the public interface
to the base class which becomes part of the public interface to the derived class. The public members of the base
class are effetively public members of the derived class.

#### 13.1.1 Protection revisited
The protected label gives derived classes access to the protected members of their constituent base-class objects, but
keeps these elements inaccessible to users of the classes.

#### 13.1.2 Operations
We can refer to elements from the base class without any special notation, because these elements are also
members of the derived class. If we wanted to be explicit about the fact that the members were inherited from the
base class we could use the scope operator to do so.

#### 13.1.3 Inheritance and constructors
The fact that the object to construct is of a derived type adds an extra step to the construction process in order
to construct the base-class part of the object. Derived objects are constructed by
- Allocating space for the entire object (base-class members as well as derived class members)
- Calling the base-class constructor to initialize the base-class part(s) of the object
- Initializing the members of the derived class as directed by the constructor initializer
- Executing the body of the derived-class constructor, if any

It's worth noting that there is no requirement that the derived-class constructors take the same arguments as the
constructors for the base class.

### 13.2 Polymorphism and virtual functions
Problem explanatory.

#### 13.2.1 Obtaining a value without knowing the object's type
To run the right function based on the actual type of the objects passed to a function, which is only known only
at run time we provide virtual functions.

We now say that the function now is virtual. When we call the function the implementation will determine the version
of the member to execute by looking at the actual types of the objects to which the references are bound.

The virtual keyword may be used only inside the class definition. The fact that a function is virtual is inherited,
so we need not repeat the virtual designation on the derived classes.

#### 13.2.2 Dynamic binding
This run-time selection of the virtual function to execute is relevant only when the function is called through
a reference or a pointer. If we call a virtual function on behalf of an object, then we know the exact type of
the object at compile time.

We say that calls to a function are *statically bound* if they are bound at compile time, without references or
pointers.

This distinction between *dynamic binding*(calls to functions with references or pointers) and *static binding* is
essential to understanding how C++ supports OOP. The phrase dynamic binding captures the notion that functions
may be bound at run time, as opposed to static bindings that happen at compile time. If we call a virtual function
on behalf of an object, the call is statically bound because there is no possibility that the object will have
a different type during execution than it does during compilation. In contrast, if we call a virtual function
through a pointer or a reference, then the function is dynamically bound. At run time, the version of the virtual
function to use will depend on the type of the object to which the reference or pointer is bound.

C++ supports polymophismo through the dynamic-binding properties of virtual functions. When we call a vritual through
a pointer or reference, we make a polymorphic call. The type of the reference(or pointer) is fixed, but the type
of the object to which it refers(or points) can be the type of the reference(or pointer) or any type derived
from it. Thus, we can potentially call one of many functions through a single type.

#### 13.2.3 Recap
Problem explanatory.

### 13.3 Using inheritance to solve our problem
Problem explanatory

#### 13.3.1 Containers of (virtually) unknown type
To contain objects of unknonw type we use pointers instead of the objects per se, when we do this we pass too much
responsability on the user.

#### 13.3.2 Virtual destructors
When we call delete on a pointer, two things happen: The destructor is run on the object, and the space that held
the object is freed. When the program deletes the pointer in sutudents[i], it could be pointing at either a Core
object or a Grad object. Neither Core nor Grad explicitly defined a destructor, which means that when the delete
runs, it will invoje the synthesized destructor and then return the space that the object consumed. The synthesized
destructor will run the destructor for each data element in the clas. But when the delete is executed, which 
destructor should the system run? Should the destructor destroy the members of Core or a Grad? And when the space
is freed, how much space should be returned-enough to hold a Core or a Grad?

These questions are resolved by the *virtual* mechanism. In order to have a virtual destructor, the class must have
a destructor, which we can make virtual.

### 13.4 A simple handle class
The previous form to resolve the problem of generalizing derived class types has problems: The program adquires
a lot of extra complexity related to managing pointers, and has several added pitfalls that could lead to bugs. Our
users have to remember to allocate space for the records as they read them, and to remember to free that space
when they no longer need the data.

The trouble with the previous soultion is that it imposed error-prone bookkeeping on our users. We can't eliminate
that bookkeeping, but we can hide it from our users by writing a new class that will encapsulate the pointer to Core.

#### 13.4.1 Reading the handle
To create the handle we have various responsabilities first: we need to free the space of the pointer, obtain what
type of object we want to read and then invoke the correct constructor.

#### 13.4.2 Copying handle objects
The way to solve the problem of copying handle objects is to give the base class and it's derived classes a new 
virtual function. That functions creates a new object that holds copies of the values in the original
```cpp
    class Core {
        friend class handle;
        protected:
            virtual Core* clone() const { return new Core(*this); }
    }
```

### 13.5 Using the handle class
Problem explanatory chapter.

### 13.6 Subtleties

#### 13.6.1 Inheritance and containers
At some point the container has to allocate storage for the objects that it contains. When we allocate that storage,
we say which exact type to allocate. There is no virtual-like mechanism that determines what kind of object is needed
and allocates enough space to hold that object.

#### 13.6.2 Which function do you want?
Simple explanation.

### 13.7 Details

- Inheritance allows us to model classes that are similar to one another with exceptions:
```cpp
    class Base {
        public:
            // common interface
        protected:
            // implementation members accessible to derived classes
        private:
            // implementation members accessible only to the base class
    };

    // public interface of Base is part of Derived
    class Derived : public Base { ... };
```

Classes can also inherit privately:
```cpp
    class priv_Derived : private Base { ... };
```
which is rare and only used for implementation purposes.

Dervation chains can be several layers deep:
```cpp
    class Derived2 : public Derived { ... };
```

- Dynamic binding refers to the ability to select at run-time which function to run based on the object type on
which the function was called. Dynamic binding is in effect in calls to virtual functions made with pointers or
references.

Derived classes are not required to redefine their virtual functions. However virtual functions in the base class
are required to be defined. They are many times the source of mysterious error messages.

- Virtual destructors: if a pointer to the base class is used to delete an object that might actually be a 
derived-class object, then the base class needs a virtual destructor. If the class has no other need for a destructor,
then the virtual destructor still must be defined and should be empty.
```cpp
    class Base{
        public:
            virtual ~Base() {}
    }
```

- Constructors and virtual functions: while an object is under construction, its type is the type of the class
being constructed-even if the object is part of a derived-class object. Thus, calls to virtual functions from
inside a constructor are statically bound to the version for the type being constructed.

- Class friendship: A class can designate another as its friend; doing so grants friendship to all the member
functions of the other class. Friendship is neither inherited nor transitive; friends of friends and classes
derived from friends have no special privileges.

- Static members exists as members of the class, rather than as an instance in each object of the class. Therefore,
the this keyword is not available in a static member function. Such functions may access only static data members.
There is a single instance of each static data member for the entire class, which must be initialized, usually
in the source file that implements the class member functions. Because the member is initialized outside the class
definition, you must fully qualify the name when you initialize it.

## 14 Managing memory (almost) automatically
Chapter introduction.

### 14.1 Handles that copy their objects

#### 14.1.1 A generic handle class
- A Handle is a value that refers to an object.
- We can copy a Handle object.
- We can test a Handle object to determine whether it's bound to another object.
- We can use a Handle to trigger polymorphic behavior when it points to an object of a class that belongs to an
inheritance hierarchy. That is, if we call a virtual function through our class, we want the implementation to choose
the function to run dynamically, just as if we'd called the function through a real pointer.

Our Handle will have a restricted interface: Once you attach a Handle to an object, the Handle class will thake over
memory management for that object. Users should attach only one Handle to any object, after which they shouldn't 
access the object directly through a pointer; all access should be through the Handle. When we copy a Handle object,
we'll make a new copy of the object, so that each Handle points to its own copy. When we destroy a Handle, it will
destroy the associated object, doing so will be the only straightforward way to free the object. We'll allow users
crear Handles unbound, but we will throw an exception if the user attemps to access the object to which an unbound
Handle refers(or, more accurately, doesn't refer).

#### 14.1.2 Using a generic handle
Problem explanatory chapter.

### 14.2 Reference-counted handles
A *reference count* is an object that keeps track of how many objects refer to another object. Each target object
will have a reference count associated with it. We will arrange to increment the reference count each time we create
a new handle that refers to our target object, and to decrement the reference count each time a referring object 
goes away. When the last referring object goes away, the reference count will become zero. At that point we'll know
that its safe to destroy the target object.

This technique can save a lot of unneeded memory management and copying of data. We'll first build a new class, called
Ref_handle, which will show how to add reference counts to our Handle class.

Our original Handle class defined provided valuelike behavior because it always copied the associated object by
calling clone. Because Ref_handle never calls clone, handles of this type never copy the objects to which they are 
attached. On the other hand, this version of Ref_handle centainly has the advantage of avoiding needless copying of
data. The trouble is that it does so by avoiding all copying.

### 14.3 Handles that let you decide when to share data
We've seen two possible definitions for the generic handle class. The first version always copies the underlying
object; the second never does so. A more useful kind of handle is one that lets the program that uses it decide when
it wants to copy the target object and when it doesn't. Such a handle class preserves the performance of Ref_handle,
and allows the class author to provide the valuelike behavior of Handles. Such a handle will preserve the useful
properties of built-in pointers, but avoids many of the pitfalls. Thus, we'll call this final handle class Ptr, to
capture the notion that it's a useful substitute for built-in pointers. In general, our Ptr class will copy the object
if we are about to change it's contents, but only if there is another handle attached to the same object.

The only difference with a Ref_handle is that we add a method called make_unique() that, if the reference count is not
1, uses the clone member of the object to which the handle is bound to make a copy of that object, and sets p to point
to the copy.

### 14.4 An improvement on controllable handles

#### 14.4.1 Copying types that we can't control
Unfortunately, the definition of make_unique has a serious problem.

The call to p->clone. This call will try to call the clone function that is a member of the class. Unfortunately, if
no such function exists it will not compile.

Yet the clone function has to be a member of the class to which we are attaching a Ptr, because only in that way
can it be a virtual function. In other words, making clone a member is critically important to making it possible for
Ptr to work across all members of an inheritance hierarchy; yet doing so is impossible, because we can't change
the definition of a class we have no source code for.

The problem is that we are trying to call a member function that doesn't exist, and we have no way to cause the member
function to exist. The solution, then, is not to call the member function directly but to define an intermediary global
function that we can both call and create. We will still call this new function clone.
```cpp
    template<class T> T* clone(const T* tp)
    {
        return tp->clone();
    }
```
and change make_unique() member to call it. It should be clear that introdcing this intermediary function doesn't
change the behavior of make_unique. However, make_unique now works through a level of indirection. This indirection
is exactly what we need, for types that don't support the clone() member function we can define another intermediary
function. Example:
```cpp
    template<>
    vector<char>* clone(const vector<char>* vp)
    {
        return new vector<char>(*vp);
    }
```
The use of template<\> at the beginning of this function indicates that the function is a *template specialization*.
Such specializations define a particular version of a template function for the specific argument type.

What we have done, then, is to moderate our reliance on the clone member by recognizing that the member might not
exist. By introducing the extra indirection, we have made it possible to specialize the clone function template
to do whatever is appropriate to copy an object of a particular class, be it to use a clone member, to call a copy
constructor, or something else entirely.

#### 14.4.2 When is a copy necessary?
Simple explanation.

### 14.5 Details
- Template specializations look like template definitions that they are specializing, but they omit one or more of
the type parameters, replacing them with specific types instead.

## 15 Revisiting character pictures
Chapter introduction.

### 15.1 Design
Problem explanatory chapter.

#### 15.1.1 Using inheritance to model the structure
Problem explanatory chapter.

#### 15.1.2 The Pic_base class
Problem explanatory chapter.

#### 15.1.3 The derived classes
Problem explanatory chapter.

#### 15.1.4 Copy control
Problem explanatory chapter.

### 15.2 Implementation
Problem explanatory chapter.

#### 15.2.1 Implementing the user interface
Problem explanatory chapter.

#### 15.2.2 The String_Pic class
Problem explanatory chapter.

#### 15.2.3 Padding the output
Problem explanatory chapter.

#### 15.2.4 The VCat_Pic class
Problem explanatory chapter.

#### 15.2.5 The HCat_Pic class
Problem explanatory chapter.

#### 15.2.6 The Frame_Pic class
Problem explanatory chapter.

#### 12.5.7 Don't forget friends
Problem explanatory chapter.

### 15.3 Details
- Abstract base classes have one or more pure *virtual* functions:
```cpp
  class Node {
    virtual Node* clone() const = 0;
  };
```
says that clone is a pure virtual function, and, by implication, that Node is an abstract base class. It's not
possible to create objects of an abstract class. A class can be made abstract through inheritance: If the class
fails to redefine even a single inherited pure virtual, then the derived class is also abstract.

- Forward declarations: 
The requirement to define names before using them causes trouble in writing families of classes that refer to
one another. To avoid this trouble, you can declare just the name of the class by writing
```cpp
  class classname;
```
thereby saying that *class-name* names a class, but not describing the class itself.



