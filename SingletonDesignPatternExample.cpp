#include<iostream>
using namespace std;

class singleton
{
private:
	static singleton *pSingletonObj;
	singleton()
	{
		cout << "singleton class constructor called" << endl;  /*construcor will call only one time*/
	}
public :
	static singleton* fnGetInstance();
	void method();
};

singleton* singleton::pSingletonObj = nullptr;
singleton* singleton::fnGetInstance()
{
	if (pSingletonObj == nullptr)
	{
		pSingletonObj = new singleton;
	}
	return pSingletonObj;
}
void singleton::method()
{
	cout << "singleton design pattern" << endl;
}

int main()
{
	singleton *pobj1,*pobj2;
	pobj1 = singleton::fnGetInstance();
	pobj1->method();
	pobj2 = singleton::fnGetInstance();
	pobj2->method();
	return 0;
}