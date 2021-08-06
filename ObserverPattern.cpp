#include <iostream>
#include <QCoreApplication>
#include <vector>
using namespace std;

class InterfaceObeserver
{
private:

public:
    virtual ~InterfaceObeserver(){}
    virtual void update()=0;
};

class InterfaceObservable
{
public:
    virtual ~InterfaceObservable(){}
    virtual void AddObserver(InterfaceObeserver*)=0;
    virtual bool RemoveObserver(InterfaceObeserver*)=0;
    virtual void NotifyToObserver()=0;
};

class ConcreteObservable: public InterfaceObservable
{
private:
     vector<InterfaceObeserver*> ListOfObserver;
     int StateOfObservable;
public:
    void AddObserver(InterfaceObeserver* Observer)
    {
        ListOfObserver.push_back(Observer);
    }

   bool RemoveObserver(InterfaceObeserver* Observer)
   {
      for(auto it=ListOfObserver.begin();it!=ListOfObserver.end();it++)
      {
          if((*it)==Observer)
          {
              ListOfObserver.erase(it);
              return true;

          }
      }
      return false;
   }

   void NotifyToObserver()
   {
       for(auto it=ListOfObserver.begin();it!=ListOfObserver.end();it++)
       {
          (*it)->update();
       }
   }

   int getState()
   {
       return StateOfObservable;
   }

   void setState(const int state)
   {
       StateOfObservable = state;
       NotifyToObserver();
   }

};


class ConcreteObserver1 : public InterfaceObeserver
{
private:
    ConcreteObservable *localobservableobj;
public:
    ConcreteObserver1(ConcreteObservable *Observable)
    {
        this->localobservableobj = Observable;
        localobservableobj->AddObserver(this);
    }
    void update()
    {
       cout << "Observer : 1 "    << this->localobservableobj->getState() << endl;
    }
};

class ConcreteObserver2 : public InterfaceObeserver
{
private:
    ConcreteObservable *localobservableobj;
public:
    ConcreteObserver2(ConcreteObservable *Observable)
    {
        this->localobservableobj = Observable;
        localobservableobj->AddObserver(this);
    }
    void update()
    {
       cout << "Observer : 2 "    << this->localobservableobj->getState() << endl;
    }
};

class ConcreteObserver3 : public InterfaceObeserver
{
private:
    ConcreteObservable *localobservableobj;
public:
    ConcreteObserver3(ConcreteObservable *Observable)
    {
        this->localobservableobj = Observable;
        localobservableobj->AddObserver(this);
    }
    void update()
    {
       cout << "Observer : 3 "    << this->localobservableobj->getState() << endl;
    }
};






int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    ConcreteObservable *observable = new ConcreteObservable();
    ConcreteObserver1 *observer1 = new ConcreteObserver1(observable);
    ConcreteObserver2 *observer2 = new ConcreteObserver2(observable);
    ConcreteObserver3 *observer3 = new ConcreteObserver3(observable);
    observable->setState(10);
    observable->RemoveObserver(observer1);
    observable->setState(20);


    return a.exec();
}
