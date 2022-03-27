#include "Direction.hpp"

#include <err.h>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <stdexcept>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;
namespace ariel
{

    
    class Notebook
    {

            struct line
    {
        string data = string(100, '_');
    };
    
    private:
        unordered_map<int, map<int, line>> notebook_data;

    public:

        void write(int page, int row, int col, Direction dir, const std::string &str);

        std::string read(int page, int row, int col, Direction dir, int len);

        void erase(int page, int row, int col, Direction dir, int len);

        void show(int page);

        bool can_write(int page, int row, int col, Direction dir, const string &str);

        bool static check_str(const std::string &str);

    };


};