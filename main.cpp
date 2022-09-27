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

        operator bool() const {
            switch(type){
                case undefined:
                    return false;
                break;
                case boolType:
                    return bool(*(bool*)dataPtr);
                break; 
                case intType:
                {
                    if(*(int*)dataPtr != 0){
                        return true;
                    }
                    else{
                        return false;
                    }
                }
                break;
                case floatType:
                {
                    if(*(float*)dataPtr != 0){
                        return true;
                    }
                    else{
                        return false;
                    }
                }
                break;
                case doubleType:
                {
                    if(*(double*)dataPtr != 0){
                        return true;
                    }
                    else{
                        return false;
                    }
                }
                break;
                case charType:
                {
                    return true;
                }
                break;
                case stringType:
                    if(*(string*)dataPtr != ""){
                        return true;
                    }
                    else{
                        return false;
                    }
                break;
            }
            return 0;
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

        NativeData& operator = (bool val){
            free(dataPtr);
            this->type = boolType;
            this->dataPtr = new bool(val);
            return *this;
        }
        NativeData& operator = (int val){
            free(dataPtr);
            this->type = intType;
            this->dataPtr = new int(val);
            return *this;
        }
        NativeData& operator = (float val){
            free(dataPtr);
            this->type = floatType;
            this->dataPtr = new float(val);
            return *this;
        }
        NativeData& operator = (double val){
            free(dataPtr);
            this->type = doubleType;
            this->dataPtr = new double(val);
            return *this;
        }
        NativeData& operator = (char val){
            free(dataPtr);
            this->type = charType;
            this->dataPtr = new char(val);
            return *this;
        }
        NativeData& operator = (string val){
            free(dataPtr);
            this->type = stringType;
            this->dataPtr = new string(val);
            return *this;
        }

};


int main(int argc, char const *argv[])
{

    NativeData val(12);

    cout << val << endl;

}
