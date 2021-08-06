#include <QCoreApplication>
#include <iostream>
using namespace std;

template <typename T>
class VectorClass
{
private:
    T *arr;
    int capacity,current;
public:
    VectorClass()
    {
        capacity = 1;
        current = 0;
        arr = new T[capacity];
    }

    void push_back(T ele)
    {
        if(current == capacity)
        {
            capacity = capacity * 2;
            T *temp = new T[capacity];

            for(int i=0;i<capacity;i++)
                temp[i]=arr[i];

            delete [] arr;
            arr = temp;
        }

        arr[current++] = ele;
    }

    void pop_front()
    {
        if(current == 0)
            cout << "There is no elements in vector" << endl;

        current = current -1;

    }

    void print_element()
    {
        cout << "Elements : ";
        for(int i=0;i<current;i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int size()
    {
        return current;
    }

    int get_capacity()
    {
        return capacity;
    }

    void insert_at(T ele,int index)
    {
        int i=0;
        if(index == current+1)
            push_back(ele);
        else if(index <= current)
        {
            for(i=current-1;i>=index-1;i--)
            {
                arr[i+1]=arr[i];
            }
            arr[index-1]=ele;
            current+=1;
        }
        else
        {
            cout << "Insert element out of scope for insering element" << endl;
        }
    }

    T get_at(int index)
    {
        if(index>current)
        cout << "Index is out of scope tp get element" << endl;
        else
        {
            return arr[index];
        }
    }

    void erase_at(int index)
    {
        if(index == current)
            pop_front();
        else if(index < current)
        {
            for(int i=index-1;i<current;i++)
            {
                arr[i]=arr[i+1];
            }
            current-=1;
        }
        else
        {
            cout << "Index is out of scope for erasing element" << endl;
        }

    }
};


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    VectorClass<int> vobj;
    vobj.push_back(10);
    vobj.push_back(20);
    vobj.push_back(30);
    vobj.push_back(23);
    vobj.push_back(234);
    vobj.push_back(34);

    vobj.print_element();
    cout << "Size of the vector : " << vobj.size() << endl;
    cout << "Capacity of the vector : " << vobj.get_capacity() << endl;
    vobj.pop_front();
     vobj.pop_front();

    vobj.print_element();
    cout << "Size of the vector : " << vobj.size() << endl;
    cout << "Capacity of the vector : " << vobj.get_capacity() << endl;

    vobj.insert_at(90,1);
    vobj.print_element();

    vobj.insert_at(100,5);
    vobj.print_element();

    vobj.erase_at(1);
    vobj.print_element();

    cout << "Elements at : " << vobj.get_at(1) << endl;


    return a.exec();
}
