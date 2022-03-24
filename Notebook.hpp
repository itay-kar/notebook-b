#include "Direction.hpp"

#include <err.h>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <stdexcept>

namespace ariel
{

    struct Notebook
    {

        static void write(unsigned int page, unsigned int row, unsigned int col, Direction dir,const std::string &str);

        static std::string read(unsigned int page, unsigned int row, unsigned int col, Direction dir, unsigned int len);

        static void erase(unsigned int page, unsigned int row, unsigned int col, Direction dir, unsigned int len);

        void show(unsigned int page);
    };
};