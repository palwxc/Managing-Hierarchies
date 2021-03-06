/**
.h
==

These are your function and class declarations.
Do not edit this file at all!
If you change it, and your program does not run as a result,
you will receive a grade of %10.
**/

#ifndef MANAGING_HIERARCHIES
#define MANAGING_HIERARCHIES

#include <iostream>
#include <exception>
#include <string> // optional with modern GCC installs
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::exception;

/*
Writes to a string array containing the your (the student author’s) Campus Username (at index 0) and Student ID# (at index 1). Takes as input a pre-existing length-2 string array.
*/
void get_identity(string my_id[]);


/*
Contrete class
Implement (via overriding) a custom exception function here which follows the standard std exception class style for including an error message.
We need to be able to catch this exception, and call it's standard message function.
When we call that standard message function, it should return an error message:
    "Custom error has occured"
If you read the std exception documentation and examples I gave for the std expection, you will know *what* we are asking for ;)
*/
class MyException: public exception
{
    public:
        virtual const char * what() const throw();
};


/*
virtual class
get_function should cout and return the variable my_function
*/
class Machine
{
    protected:
        string my_function = "Compute computable things";

    public:
        string get_function();
};


/*
virtual class
my_function should default contstructed to be: "Backward compatibile"
Default constructor should set numcores to point to a 2 big array.
A parameterized constructor should allow the user to make an array numCores large at runtime and set my_function
Destructor should do what it does best!
If numCores value is not even at construction, then throw your custom exception.
*/
class X86: public Machine
{
    private:
        bool *num_cores;

    public:
        X86();
        X86(string init_function, int init_cores);
        virtual ~X86();

        // allows you to set one of the indices
        void set_core_pos(int position, bool value);

        // returns an element of the array
        bool get_core_pos(int index);
};


/*
virtual class
my_function should default construct to be "Reduced Instruction Set"
num_bits should be default constructed to 64
A parameterized constructor should allow the user to set num_bits at runtime and set my_function
If num_bits is not 32 or 64, then throw your custom exception.
*/
class ARM: public Machine
{
    private:
        short num_bits;

    public:
        ARM();
        ARM(string init_function, short init_bits);

        // sets numbits
        void set_num_bits(short set_bits);

        // returns and couts numbits
        short get_num_bits();
};


/*
Pure virtual class
get_puprose should return and cout the purpose.
*/
class Operating_system
{
    protected:
        string purpose = "Running a machine";
        int version_number;

    public:
        string get_purpose();
        virtual void set_version_number(int set_ver_num) = 0;
        virtual int get_version_number() = 0;
};


/*
Pure virtual class
purpose should default construct to "Anything you want"
pupose should be able to be set by the parameterized constructor.
*/
class Linux: public Operating_system
{
    public:
        Linux();
        Linux(string init_purpose);
};


// not stylistically ideal, but needed so you can't edit this file
#include "Android.h"


/*
Concrete class
get_func_purpose should return and cout:
Your cluster architecture is "my_function", its purpose is "purpose", and lots of it!
where each is replaced with the value of the named variable.

set_version_number must set the version_number variable to the inputted value.
get_version_number returns and cout the version number
*/
class Cluster: public X86, public Linux
{
    public:
        string get_func_purpose();
        void set_version_number(int set_ver_num);
        int get_version_number();
};


/*
Concrete class
get_phone_number should return and cout your phone number formatted as below.
set_phone_number should set your phone number if it is formatted like this:
+1(573)-465-1111
otherwise, it should throw your custom exception

set_version_number must set the version_number variable to the inputted value.

my_IMEI should default construct to a value of 0000 being stored, and the parameterized constructor should both allocate memory for it, and set it.

Implement the default constructor, the parameterized constructor, the copy constructor, the operator=, and the destructor, while making sure to use a deep copy!

get_func_purpose should return:
Your phone architecture is "my_function", its purpose is "purpose", and I follows you around!

set_version_number must set the version_number variable to the inputted value.
get_version_number returns and cout the version number
*/

class Personal_surveillance_device: public ARM, public Android
{
    private:
        string my_phone_number;

    public:
        long *my_IMEI;
        Personal_surveillance_device();
        Personal_surveillance_device(long input_my_IEMI);
        ~Personal_surveillance_device();
        Personal_surveillance_device(const Personal_surveillance_device &source);
        Personal_surveillance_device & operator=(const Personal_surveillance_device &rhs);
        void set_phone_number(string init_phone);
        string get_phone_number();
        void set_version_number(int set_ver_num);
        int get_version_number();
        string get_func_purpose();
};

#endif
