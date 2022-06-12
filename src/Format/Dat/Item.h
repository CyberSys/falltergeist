#pragma once

// Project includes
#include "../../Format/Enums.h"

// Third-party includes

// stdlib
#include <fstream>
#include <string>
#include <memory>

namespace Falltergeist
{
    namespace Format
    {
        namespace Dat
        {
            // A base class for all game resource files
            class Item
            {
                public:
                    virtual ~Item() {}

                    Item& setFilename(const std::string& filename);

                    const std::string& filename() const;

                private:
                    std::string _filename;
            };
        }
    }
}
