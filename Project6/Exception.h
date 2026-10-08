#pragma once
class DivideException : public Exception
{
public:
    DivideException(string s) : Exception(s) {}
    void Print() const
    {
        cout << "Divide is Errror... " << str << endl;
    }
};

class IndexException : public Exception
{
public:
    IndexException(string s) : Exception(s) {}
    void Print() const
    {
        cout << "Index Error... " << str << endl;
    }
};