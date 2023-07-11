#include <ostream>

struct Location
{
    int _col; // Column coordinate of the location
    int _row; // Row coordinate of the location

    // Overloaded << operator to print the location in the format (col, row)
    friend std::ostream& operator<<(std::ostream& os, const Location& loc) {
        os << "(" << loc._col << ", " << loc._row << ")";
        return os;
    }

    // Overloaded += operator to add the coordinates of another location to the current location
    Location& operator+=(const Location& other) {
        _col += other._col;
        _row += other._row;
        return *this;
    }

    // Overloaded == operator to compare two locations for equality
    bool operator==(const Location& other) const {
        return (_col == other._col) && (_row == other._row);
    }

    // Overloaded = operator to assign the values of another location to the current location
    Location& operator=(const Location& other) {
        if (this != &other) {
            _row = other._row;
            _col = other._col;
        }
        return *this;
    }

    // Overloaded != operator to compare two locations for inequality
    bool operator!=(const Location& other) const {
        return !(*this == other);
    }
};
