#include "Notebook.hpp"
using namespace ariel;
#include <string>

const int MAX_LINE_SIZE = 100;
const int number_of_lines = 20;
void Notebook::write(int page, int row, int col, Direction dir, const std::string &str)
{
    if (!check_str(str))
    {
        throw std::invalid_argument("string contains invalid char.\n");
    }
    if (str.find('~') != std::string::npos)
    {
        throw std::invalid_argument("sstring Cant containg char \\`~\\`.\n");
    }

    if (col < 0 || row < 0 || page < 0)
    {
        throw std::invalid_argument("page row and col must be positive integers.\n");
    }
    if (col >= MAX_LINE_SIZE)
    {
        throw std::invalid_argument("Col index must be lower than 100.\n");
    }

    if ((int)str.length() + col >= MAX_LINE_SIZE && dir == Direction::Horizontal)
    {
        throw std::invalid_argument("trying to write line from col index exceed line size.\n");
    }

    if (!can_write(page, row, col, dir, str))
    {
        throw std::invalid_argument("Cannot write on erased or written place.\n");
    }

    if (dir == Direction::Horizontal)
    {
        notebook_data[page][row].data.replace((size_t)col, str.length(), str);
    }

    else
    {
        for (int i = row; i < row + (int)str.length(); i++)
        {
            notebook_data[page][i].data[(size_t)col] = str[(size_t)i];
        }
    }
}

std::string Notebook::read(int page, int row, int col, Direction dir, int len)
{
    if (col >= MAX_LINE_SIZE)
    {
        throw std::invalid_argument("Col index must be lower than 100.\n");
    }

    if (col < 0 || row < 0 || page < 0 || len < 0)
    {
        throw std::invalid_argument("page row and col must be positive integers.\n");
    }
    if (len + col > MAX_LINE_SIZE && dir == Direction::Horizontal)
    {
        throw std::invalid_argument("trying to read line from col index exceed line size.\n");
    }

    if (dir == Direction::Horizontal)
    {
        return notebook_data[page][row].data.substr((size_t)col, (size_t)len);
    }

    string str;
    for (int i = row; i < row + len; i++)
    {
        str += notebook_data[page][i].data[(size_t)col];
    }

    return str;
}

void Notebook::erase(int page, int row, int col, Direction dir, int len)
{
    if (col < 0 || row < 0 || page < 0 || len < 0)
    {
        throw std::invalid_argument("page row and col must be positive integers.\n");
    }
    if (col >= MAX_LINE_SIZE)
    {
        throw std::invalid_argument("Col index must be lower than 100.\n");
    }

    if (len + col > MAX_LINE_SIZE && dir == Direction::Horizontal)
    {
        throw std::invalid_argument("trying to erase line from col index exceed line size.\n");
    }

    if (dir == Direction::Horizontal)
    {
        notebook_data[page][row].data.replace((size_t)col, (size_t)len, string((size_t)len, '~'));
    }

    else if (dir == Direction::Vertical)
    {
        for (int i = row; i < row + len; i++)
        {
            notebook_data[page][i].data[(size_t)col] = '~';
        }
    }
};

void Notebook::show(int page)
{
    if (page < 0)
    {
        throw std::invalid_argument("Page must be a positive integer.\n");
    }

    cout << "\n\t\t\t\t\tPage " << page << "." << endl;
    int last_row = 0;
    for (auto const &row : notebook_data[page])
    {
        while (last_row < row.first)
        {
            cout << notebook_data[page][last_row].data << endl;
            last_row += 1;
        }
        cout << row.second.data << endl;
        last_row += 1;
    }

    while (last_row < number_of_lines)
    {
        cout << notebook_data[page][last_row].data << endl;
        last_row += 1;
    }
};

bool Notebook::can_write(int page, int row, int col, Direction dir, const string &str)
{
    if (dir == Direction::Horizontal)
    {
        for (int i = col; i < col + (int)str.length(); i++)
        {
            if (notebook_data[page][row].data[(size_t)i] != '_')
            {
                // cout << endl
                //      << notebook_data[page][row].data[(size_t)i] << ",------Horizontal------";

                // cout << "Cant write" << endl;
                return false;
            }
        }
    }

    else
    {
        for (size_t i = (size_t)row; i < row + (int)str.length(); i++)
        {
            if (notebook_data[page][i].data[(size_t)col] != '_')
            {
                // cout << endl
                //      << notebook_data[page][i].data[(size_t)col] << ",------Vertical------";

                // cout << "Cant write" << endl;
                return false;
            }
        }
    }
    return true;
};

bool Notebook::check_str(const std::string &str)
{
    for (char c : str)
    {
        if (isprint(c) == 0)
        {
            return false;
        }
    }
    return true;
};

// int main(int argc, char const *argv[])
// {
//     for ( int i=100; i<200;i++){
//         Notebook note;
//         try
//         {
//             note.show(1);
//             note.write(1,i-100,0,Direction::Vertical,"Look at me");
//             note.write(1,i-100,2,Direction::Horizontal,"I'm Mr. meeseeks");
//         }
//         catch(const std::exception& e)
//         {
//             cout << e.what() << endl;
//         }
//     return 0;
// }
// }
// int main(int argc, char const *argv[])
// {
//     ariel::Notebook notebook;
//     notebook.write(1, 1, 1, Direction::Horizontal, "Tryout");
//     notebook.write(1, 3, 14, Direction::Horizontal, "Tryout");
//     notebook.write(1, 5, 17, Direction::Horizontal, "Tryout");
//     notebook.write(1, 9, 84, Direction::Horizontal, "Tryout");

//     notebook.write(12, 2, 12, Direction::Horizontal, "Tryout");

//     notebook.write(1, 1, 90, Direction::Horizontal, "Tryout");
//     cout << "All good" <<endl;

//     // notebook.write(1, 5, 26, Direction::Horizontal, "Tryout");
//     // notebook.erase(1, 5, 26, Direction::Horizontal, 5);

//     cout << notebook.read(1, 1, 1, Direction::Horizontal, 6) << endl;
//     notebook.show(1);

//     for (size_t i = 0; i < 100000000; i++)
//     {
//             notebook.write(i, 5, 26, Direction::Horizontal, "Tryout");
//     }

//     notebook.show(4294967295);

//     return 0;
// }
