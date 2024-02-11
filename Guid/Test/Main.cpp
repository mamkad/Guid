#include <iostream>

using std::cout;

#include "../Src/Guid.hpp"

using Lib::Util::Guid;

int main()
{
    
    cout << Guid::getEmpty().data() << '\n';
    cout << Guid::getNewGuid().data() << '\n';
    cout << Guid::getNewGuid().data() << '\n';
    cout << Guid::getNewGuid().data() << '\n';
}