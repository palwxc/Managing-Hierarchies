/**
.cpp
====

This is the .cpp you should define and implement the functions and classes that are declared in the .h file.
Add any non-required functions here.
**/

#include "managing_hierarchies.h"


void get_identity(string my_id[])
{
    my_id[0]="palwxc";
    my_id[1]="12398940";
}


const char* MyException::what() const throw(){return "Custom error has occured";}

string Machine::get_function()
{
    cout << my_function;
    return my_function;
}

//Default Constructor
X86::X86()
{
    my_function = "Backward compatibile";
    num_cores = new bool[2];
}

//Parameterized Constructor
X86::X86(string init_function, int init_cores)
{
    try
    {
        if (init_cores%2 == 0)
            throw MyException();
        if (init_cores <= 0)
            cout << "Value for init_cores was not positive.";
        else
        {
            num_cores = new bool[init_cores];
            my_function = init_function;
        }
    }

    catch(MyException& e)
    {
        cout << e.what() << '\n';
        cout << "X86::parameterized constructor: init_cores must be even" << endl;
    }
    catch (...) {cout << "Exception occurred" << endl;}
}

//Destructor
X86::~X86()
{
    delete [] num_cores;
}

//set a value in the num_core array at a given position
void X86::set_core_pos(int position, bool value)
{
    try
    {
        if (position < 0 || position >= sizeof(num_cores))
            throw MyException();
        *(num_cores+position) = value;
    }
    catch (MyException &e)
    {
        cout << e.what() << '\n';
        cout << "X86::set_core_pos: position must be within range of array" << endl;
    }
    catch (...) {cout << "Exception occurred" << endl;}
}

//get a value from the num_core array at a give index
bool X86::get_core_pos(int index)
{
    try
    {
        if (index < 0 || index >= sizeof(num_cores))
            throw MyException();
        return *(num_cores+index);
    }
    catch (MyException &e)
    {
        cout << e.what() << '\n';
        cout << "X86::get_core_pos: index must be within range of array" << endl;
    }
    catch (...) {cout << "Exception occurred" << endl;}
}

//Default Constructor
ARM::ARM()
{
    my_function = "Reduced Instruction Set";
    num_bits = 64;
}

//Parameterized Constructor
ARM::ARM(string init_function, short init_bits)
{
    try
    {
        if (init_bits!=32 && init_bits!=64)
            throw MyException();
        num_bits = init_bits;
        my_function = init_function;
    }
    catch (MyException& e)
    {
        cout << e.what() << '\n';
        cout << "ARM::parameterized constructor: init_bits must be either 32 or 64" << endl;
    }
    catch (...) {cout << "Exception occurred" << endl;}
}

//sets the value for num_bits
void ARM::set_num_bits(short set_bits)
{
    try
    {
        if (set_bits!=32 && set_bits!=64)
            throw MyException();
        num_bits = set_bits;
    }
    catch (MyException& e)
    {
        cout << e.what() << '\n';
        cout << "ARM::parameterized constructor: set_bits must be either 32 or 64" << endl;
    }
    catch (...) {cout << "Exception occurred" << endl;}
}

//returns and couts the value of num_bits
short ARM::get_num_bits()
{
    cout << num_bits;
    return num_bits;
}

void Operating_system::set_version_number(int set_ver_num) {version_number=set_ver_num;}
int Operating_system::get_version_number() {return version_number;}

//returns and couts the purpose
string Operating_system::get_purpose()
{
    cout << purpose;
    return purpose;
}

//Default Constructor (from Operating_system class)
Linux::Linux(){purpose = "Anything you want";}

//Parameterized Constructor
Linux::Linux(string init_purpose){purpose = init_purpose;}

//returns and couts the purpose (from Operating_system class; the parent of Linux)
string Cluster::get_func_purpose()
{
    cout << "Your cluster architecture is " << my_function
    << ", its purpose is " << purpose << ", and lots of it!" << endl;
    return purpose;
}

//returns and couts the version number
int Cluster::get_version_number()
{
    cout << "Your OS version number is: " << version_number << endl;
    return version_number;
}

//sets the version_number variable (from Operating_system)
void Cluster::set_version_number(int set_ver_num)
{
    try
    {
        if(set_ver_num<=0)
            throw MyException();
        version_number=set_ver_num;
    }
    catch(MyException &e)
    {
        cout << e.what() << '\n';
        cout << "Cluster::set_version_number: set_ver_num is invalid" << endl;
    }
    catch (...) {cout << "Exception occurred" << endl;}
}

//accepts and checks phone number
void Personal_surveillance_device::set_phone_number(string init_phone)
{
    try
    {
        if(init_phone.at(0)!= '+' || init_phone.length()!=16)
            throw MyException();
        else if(init_phone.at(2)!='(' || init_phone.at(6)!=')')
            throw MyException();
        else if(init_phone.at(7)!='-' || init_phone.at(11)!='-')
            throw MyException();
        else if(init_phone.at(1)<48 || init_phone.at(1)>57)
            throw MyException();
        else if(init_phone.at(3)<48 || init_phone.at(3)>57)
            throw MyException();
        else if(init_phone.at(4)<48 || init_phone.at(4)>57)
            throw MyException();
        else if(init_phone.at(5)<48 || init_phone.at(5)>57)
            throw MyException();
        else if(init_phone.at(8)<48 || init_phone.at(8)>57)
            throw MyException();
        else if(init_phone.at(9)<48 || init_phone.at(9)>57)
            throw MyException();
        else if(init_phone.at(10)<48 || init_phone.at(10)>57)
            throw MyException();
        else if(init_phone.at(12)<48 || init_phone.at(12)>57)
            throw MyException();
        else if(init_phone.at(13)<48 || init_phone.at(13)>57)
            throw MyException();
        else if(init_phone.at(14)<48 || init_phone.at(14)>57)
            throw MyException();
        else if(init_phone.at(15)<48 || init_phone.at(15)>57)
            throw MyException();
        else
            my_phone_number = init_phone;
    }
    catch(MyException &e)
    {
        cout << "That was not a valid phone number, please try again." << endl;
        my_phone_number="n";
    }
}

//prints phone number
string Personal_surveillance_device::get_phone_number()
{
    if (my_phone_number=="n")
        return my_phone_number;
    cout << "Your phone number is " << my_phone_number << endl;
    return my_phone_number;
}

//
void Personal_surveillance_device::set_version_number(int set_ver_num)
{
    try
    {
        if(set_ver_num<=0)
            throw MyException();
        version_number=set_ver_num;
    }
    catch(MyException &e)
    {
        cout << e.what() << '\n';
        cout << "Personal_surveillance_device::set_version_number: set_ver_num is invalid" << endl;
    }
    catch (...) {cout << "Exception occurred" << endl;}
}

//
int Personal_surveillance_device::get_version_number()
{
    cout << "Your OS version number is: " << version_number << endl;
    return version_number;
}

//
string Personal_surveillance_device::get_func_purpose()
{
    cout << "Your phone architecture is " << my_function
    << ", its purpose is " << purpose << ", and it follows you around!" << endl;
    return purpose;
}

//Default Constructor
Personal_surveillance_device::Personal_surveillance_device()
{
    my_IMEI = new long;
    *my_IMEI = 0000;
}


//Parameterized Constructor
Personal_surveillance_device::Personal_surveillance_device(long input_my_IEMI)
{
    my_IMEI = new long;
    *my_IMEI = input_my_IEMI;
}

//Destructor
Personal_surveillance_device::~Personal_surveillance_device(){delete my_IMEI;}

//Deep Copy Constructor
Personal_surveillance_device::Personal_surveillance_device(const Personal_surveillance_device &source)
{
    my_phone_number = source.my_phone_number;
    purpose = source.purpose;
    version_number = source.version_number;
    short tmp = get_num_bits();
    set_num_bits(tmp);
    my_function = source.my_function;
    my_IMEI = new long;
    *my_IMEI = *source.my_IMEI;
}



//Copy Constructor
Personal_surveillance_device& Personal_surveillance_device::operator=(const Personal_surveillance_device &rhs)
{
    if (this == &rhs)
        return *this;

    my_phone_number = rhs.my_phone_number;                      //PSD
    purpose = rhs.purpose;                                      //OS
    version_number = rhs.version_number;                        //OS
    short tmp = get_num_bits();                                 //ARM
    set_num_bits(tmp);                                          //ARM
    my_function = rhs.my_function;                              //Machine
    *my_IMEI = *rhs.my_IMEI;                                     //PSD
    return *this;
}
