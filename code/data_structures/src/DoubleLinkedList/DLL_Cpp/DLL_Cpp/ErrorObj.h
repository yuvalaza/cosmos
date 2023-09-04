#pragma once
#include<iostream>
#include<string>
using namespace std;

#define INVALID_INDEX "Invalid index. Must be between 0 and (size-1)"
#define INVALID_INDEX_NUM 1

class ErrorObject
{
private:
	string _errorDesc;
	int _errorNumber;
public:
	ErrorObject(int en = 0, string ed = "generic error") :_errorNumber(en), _errorDesc(ed) {}
	void printError() const {
		cout << "********************* ERROR DETAILS **************************" << endl;
		cout << "Error number : " << this->_errorNumber << endl;
		cout << "Error description : " << this->_errorDesc << endl;
		cout << "************************* ERROR **************************" << endl;
	}

};

