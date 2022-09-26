#include <iostream>
#include <cmath>

using namespace std;
enum dataType {undefined, boolType, intType, floatType, doubleType, charType, stringType};

class NativeData{
    public: 
        dataType type;
        void *dataPtr = NULL;
        NativeData(){
            cout << "Blank object created." << endl;
            type = undefined;
        }        
        NativeData(bool val){
            cout << "Bool object created." << endl;
            dataPtr = new bool(val);
            type = boolType;
        }
        NativeData(int val){
            cout << "Integer object created." << endl;
            dataPtr = new int(val);
            type = intType;
        }
        NativeData(float val){
            cout << "Float object created." << endl;
            dataPtr = new float(val);
            type = floatType;
        }
        NativeData(double val){
            cout << "Double object created." << endl;
            dataPtr = new double(val);
            type = doubleType;
        }
        NativeData(char val){
            cout << "Char object created." << endl;
            dataPtr = new char(val);
            type = charType;
        }
        NativeData(string val){
            cout << "String object created." << endl;
            dataPtr = new string(val);
            type = stringType;
        }

        void printData(){
            switch(type){
                case undefined:
                    cout << "undefined" << endl;
                break;
                case boolType:
                    cout << *(bool*)dataPtr << endl;
                break; 
                case intType:
                {
                    cout << *(int*)dataPtr << endl;
                }
                break;
                case floatType:
                {
                    cout << *(float*)dataPtr << endl;
                }
                break;
                case doubleType:
                {
                    cout << *(double*)dataPtr << endl;
                }
                break;
                case charType:
                {
                    cout << *(char*)dataPtr << endl;
                }
                break;
                case stringType:
                    cout << *(string*)dataPtr << endl;
                break;
            }
        }

        operator int() const {
            switch(type){
                case undefined:
                    return 0;
                break;
                case boolType:
                    return bool(*(bool*)dataPtr);
                break; 
                case intType:
                {
                    return *(int*)dataPtr;
                }
                break;
                case floatType:
                {
                    return int(*(float*)dataPtr);
                }
                break;
                case doubleType:
                {
                    return int(*(double*)dataPtr);
                }
                break;
                case charType:
                {
                    int i = int(*(char*)dataPtr) - '0';
                    if(i >=0 && i <= 9){
                        return i;
                    }
                    return 0;
                }
                break;
                case stringType:
                    return stoi(*(string*)dataPtr);
                break;
            }
            return 0;
        }
};


int main(int argc, char const *argv[])
{

    NativeData val(12);

    cout << val << endl;

}
