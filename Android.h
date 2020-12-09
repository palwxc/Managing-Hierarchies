/*
Pure virtual class
Make the Android class immediately below here.
It should inherit Operating_system.
It's purpose should be default-constructed to: "Uploading your converstations to google"
It should have no parameterized consructor.
It should have one private variable, a boolean, named pretend_encryption
It should have one function called set_pretend_encryption(), with void return type. It should swap the value of pretend_ercryption, and print out either:
If the bool is switched to 1, then cout: "Your device is now securely encrypted"
If the bool is switched to 0, then cout: "Encryption is now off"
*/

#ifndef ANDROID
#define ANDROID

class Android : public Operating_system{

    private:
        bool pretend_encryption=0;

    public:
        //Default Constructor
        Android(){purpose = "Uploading your converstations to google";}

        void set_pretend_encryption()
        {
            if (pretend_encryption==0)
            {
                pretend_encryption=1;
                cout << "Your device is now securely encrypted" << endl << endl;
            }
            else
            {
                pretend_encryption=0;
                cout << "Encryption is now off" << endl << endl;
            }
        }
};

#endif
