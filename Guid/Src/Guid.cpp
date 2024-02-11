#include <cstdlib>
#include <chrono>
#include <ctime> 
#include <algorithm>
#include <string>
#include <cstring>
#include <iterator>


using std::string;
using std::chrono::system_clock;
using std::chrono::time_point;
using std::back_inserter;
using std::ctime;
using std::to_string;
using std::copy_n;
using std::copy_if;

#include "Guid.hpp"

using Lib::Algs::Hash::Md5;

namespace Lib
{
    namespace Util                
    {
        static void InitRandomizer();

        void getHashableString(string& hashableString);
        string getCurrentTime();
        int getRandomNumber(int maxNumber);
        
        TGuid Guid::EmptyGuid = { "00000000-0000-0000-0000-000000000000" };

        TGuid Guid::getNewGuid()
        {
            InitRandomizer();

            string hashableString;
            getHashableString(hashableString);

            string hash = Md5::hash(hashableString);
            hash.shrink_to_fit();

            TGuid guid = EmptyGuid;

            // a27a8668 e3ee 6680 cec8 49cb5e0f37029
            // 00000000-0000-0000-0000-000000000000

            copy_n(hash.begin(),       8, guid.begin());
            copy_n(hash.begin() +  8,  4, guid.begin() + 9);
            copy_n(hash.begin() + 12,  4, guid.begin() + 14);
            copy_n(hash.begin() + 16,  4, guid.begin() + 19);
            copy_n(hash.begin() + 20, 12, guid.begin() + 24);

            return guid;
        }

        TGuid Guid::getEmpty()
        {
            return EmptyGuid;
        }

        static void InitRandomizer()
        {
            static bool isInit = false;

            if (isInit) {
                return;
            }

            srand((unsigned)time(0));
            isInit = true;
        }

        void getHashableString(string& hashableString)
        {
            int const firstMaxRandomNumber  = 10001;
            int const secondMaxRandomNumber = 1000000002;
            int const lastMaxRandomNumber   = 777;

            hashableString += to_string(getRandomNumber(firstMaxRandomNumber));
            hashableString += to_string(getRandomNumber(secondMaxRandomNumber));
            hashableString += getCurrentTime();
            hashableString += to_string(getRandomNumber(secondMaxRandomNumber));
            hashableString += to_string(getRandomNumber(lastMaxRandomNumber));
        }

        string getCurrentTime()
        {
            time_t currentTime = system_clock::to_time_t(system_clock::now());
            char* time = ctime(&currentTime);

            string timeWithoutSpaces;
            timeWithoutSpaces.reserve(20);

            copy_if(time, time + strlen(time), back_inserter(timeWithoutSpaces), 
                [](char ch) {
                    return !isspace(ch);
                });

            return timeWithoutSpaces;
        }

        int getRandomNumber(int maxNumber)
        {
            return rand() % maxNumber + 1;
        }
    }
}