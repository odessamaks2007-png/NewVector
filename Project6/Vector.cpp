#include<iostream>
using namespace std;

class Exception
{
protected:
    string str;
public:
    virtual void Print() const = 0;
    Exception(string s) : str(s) {}
};
class IndexException : public Exception
{
public:
    IndexException(string s) : Exception(s) {}
    void Print() const
    {
        cout << "Index/Size error... " << endl;
    }
};

class Myvector
{
    int* ptr;
    int size;
public:
    Myvector()
    {
        ptr = nullptr;
        size = 0;
    }
    Myvector(int s)
    {
        if (s <= 0)
        {
            throw IndexException("Error: Invalid vector size!Size must be greater than 0...");
        }
        size = s;
        ptr = new int[size];
    }
    int& operator[](int index)
    {
        if (index < 0 || index >= size)
        {
            throw IndexException("Error: Index out of range");
        }
        return ptr[index];
    }
    void Init()
    {
        for (int i = 0; i < size; i++)
        {
            ptr[i] = rand() % 100;
        }
    }
    void Print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << ptr[i] << "\t";
        }
        cout << endl;

    }
    ~Myvector()
    {
        delete[]ptr;
    }
    void AddBack(int a)
    {
        int* temp = new int[size + 1];
        for (int i = 0; i < size; i++)
        {
            temp[i] = ptr[i];
        }
        temp[size] = a;

    }
    void AddFirst(int a)
    {

    }
    Myvector(const Myvector& rez)
    {
        size = rez.size;
        if (rez.ptr != nullptr)
        {
            ptr = new int[size];
            for (int i = 0; i < size; i++)
            {
                ptr[i] = rez.ptr[i];
            }
        }
        else
        {
            ptr = nullptr;
        }
        cout << "Constructor coopy...";
    }
    Myvector& operator=(const Myvector& rez)
    {
        if (this == &rez)
        {
            return *this;
        }
        delete[] ptr;
        size = rez.size;
        if (rez.ptr != nullptr)
        {
            ptr = new int[size];
            for (int i = 0; i < size; i++)
            {
                ptr[i] = rez.ptr[i];
            }
        }
        else
        {
            ptr = nullptr;
        }
        cout << "Operator '='";
        return *this;
    }
};

template<typename Kit = int, int SIZE = 10>
class StaticArray
{
    Kit arr[SIZE];
public:
    StaticArray() : arr() {}
    void FillArray(void);
    void PrintArray(void);
    int getSize(void) const
    {
        return SIZE;
    }
    Kit& operator[] (int index)
    {
        return index >= 0 && index < SIZE ? arr[index] : arr[0];
    }
    const Kit& operator[] (int index) const
    {
        return index >= 0 && index < SIZE ? arr[index] : arr[0]
    }

};
template<typename Kit, int SIZE>
void StaticArray<Kit, SIZE>::FillArray(void)
{

}
template<typename Kit, int SIZE>
void StaticArray<Kit, SIZE>::PrintArray(void)
{

}

int main()
{
    srand(time(0));
    /*Myvector num(5);
    num.Init();
    num.Print();
    cout << "___________________________________________";
    cout << "Here is Copy Constructor...";
    Myvector num1 = num;
    cout << endl;
    cout << "___________________________________________";
    cout << "Here is Operator '='...";
    Myvector num2(9);
    num2.Init();
    num2.Print();*/

    try
    {
        Myvector num(5);
        num.Init();
        num.Print();
        cout << "Trying to access element at 10 index..." << endl;
    }
    catch (const Exception& ex)
    {
        ex.Print();
    }

}