#include <ostream>
struct Loction
{
	int col;
	int row;
	
	friend std::ostream& operator<<(std::ostream& os, const Loction& loc) {
		os << "(" << loc.col << ", " << loc.row << ")";
		return os;
	}
	Loction& operator+=(const Loction& other) {
		col += other.col;
		row += other.row;
		return *this;
	}
	bool operator==(const Loction& other) const {
		return (col == other.col) && (row == other.row);
	}

	Loction& operator=(const Loction& other) {
		if (this != &other) {
			row = other.row;
			col = other.col;
		}
		return *this;
	}

	bool operator!=(const Loction& other) const {
		return !(*this == other);
	}
	
};