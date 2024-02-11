#pragma once

#include "../../../Algs/Hash/Md5/Src/Md5.hpp"
#include "../../Object/Src/Object.hpp"

using Lib::Util::TGuid;

namespace Lib
{
    namespace Util
    {
        class Guid final 
        {
            static TGuid EmptyGuid;

        public:
            static TGuid getNewGuid();
            static TGuid getEmpty();
        };
    }
}