
#include<iostream>
#include<string>
using std::istream;
using std::string;
istream& read(istream& in)
{
    string str;
    while(!in.eof())
    {
        in >> str;
        std::cout <<str << std::endl;
        str="";
    }
    in.clear();
    return in;
}

int main(int argc, char** argv)
{
    read(std::cin);
    return 0;
}
