/**
main
====

Solve the main input and output here.
Within the main loop of your program, you must use the same polymorphic pointer to
an Operating_system to manage multiple objects of type Cluster and Personal_surveillance_device.
Do not reference the objects directly.
Note: only a small fraction of your cpp implementations are tested in main.
**/

#include "managing_hierarchies.h"

int main()
{
    string answer;
    int tmp;
    long tmp_long;
    string tmp_string;
    Operating_system *ptr;
    do{
        ptr = NULL;
        cout << "What devices do you need to manage (choose one or enter 0 to exit): phone, cluster" << endl;
        getline(cin, answer);
        if(answer!="0")
        {
            if(answer=="cluster")
            {
                ptr = new Cluster();
                cout << "Your cluster architecture is ";
                ((Cluster*)ptr)->get_function();
                cout << ", its purpose is ";
                ptr->get_purpose();
                cout << ", and lots of it!" << endl;
                cout << "What is the version number of your operating system?" << endl;
                cin >> tmp;
                ptr->set_version_number(tmp);
                ptr->get_version_number();
                getline(cin, tmp_string);
                cout << endl;
                //((X86*)ptr)->~X86();
                delete ((Cluster*)ptr);
            }
            else if(answer=="phone")
            {
                ptr = new Personal_surveillance_device();
                cout << "What is your IMEI?" << endl;
                cin >> tmp_long;
                *((Personal_surveillance_device*)ptr)->my_IMEI=tmp_long;
                ((Personal_surveillance_device*)ptr)->get_func_purpose();
                do{
                    cout << "What is the version number of your operating system?" << endl;
                    cin >> tmp;
                    ptr->set_version_number(tmp);
                }while(tmp<=0);
                ptr->get_version_number();
                getline(cin, tmp_string);
                cout << "What is your phone number?" << endl;
                do{
                    getline(cin, tmp_string);
                    ((Personal_surveillance_device*)ptr)->set_phone_number(tmp_string);
                }while(((Personal_surveillance_device*)ptr)->get_phone_number()=="n");
                //
                do{
                    cout << "Would you like to encrypt your phone (type yes or no)?" << endl;
                    getline(cin, tmp_string);
                    if(tmp_string == "yes")
                        ((Personal_surveillance_device*)ptr)->set_pretend_encryption();
                    else if (tmp_string == "no")
                        cout << "Your device will remain unchanged." << endl << endl;
                    else
                        cout << "Please enter a valid choice." << endl;
                }while(tmp_string != "yes" && tmp_string != "no");
                //((Personal_surveillance_device*)ptr)->~Personal_surveillance_device();
                delete ((Personal_surveillance_device*)ptr);
            }
            else
                cout << "Please enter a valid choice." << endl;
        }
        getline(cin,tmp_string);
        //delete ptr;
    }while(answer!="0");
    cout << "Exiting now" << endl;
    delete ptr;
    return 0;
}
