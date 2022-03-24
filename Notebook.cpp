#include "Notebook.hpp"
using namespace ariel;
#include <string>

const int MAX_LINE_SIZE = 100;

void Notebook::write(unsigned int page, unsigned int row, unsigned int col, Direction dir, const std::string &str)
{
    if (col >= MAX_LINE_SIZE)
    {
        throw std::invalid_argument("Col index must be lower than 100.\n");
    }

    if (str.length()>MAX_LINE_SIZE){
                throw std::invalid_argument("Line size cannot be bigger than 100 chars.\n");
    }
    
    if (str.size() + col >= MAX_LINE_SIZE && dir == Direction::Horizontal)
    {
        throw std::invalid_argument("trying to write line from col index exceed line size.\n");
    }
}

std::string Notebook::read(unsigned int page, unsigned int row, unsigned int col, Direction dir, unsigned int len) {
    if (col >= MAX_LINE_SIZE)
    {
        throw std::invalid_argument("Col index must be lower than 100.\n");
    }
    
    if (len + col >= MAX_LINE_SIZE && dir == Direction::Horizontal)
    {
        throw std::invalid_argument("trying to write line from col index exceed line size.\n");
    }

     return ""; }

void Notebook::erase(unsigned int page, unsigned int row, unsigned int col, Direction dir, unsigned int len)
{

     if (col > MAX_LINE_SIZE)
    {
        throw std::invalid_argument("Col index must be lower than 100.\n");
    }
    
    if (len + col > MAX_LINE_SIZE && dir == Direction::Horizontal)
    {
        throw std::invalid_argument("trying to write line from col index exceed line size.\n");
    }
};


void Notebook::show(unsigned int page) {};