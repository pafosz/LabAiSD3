#include <iostream>
#include <string>
#include <vector>
class Car {
private:
	std::string _brand;
	int _year_release;
public:
	Car() : _brand(""), _year_release(0) { }
	Car(std::string brand, int year_release) : _brand(brand), _year_release(year_release){ }
	Car(const Car& other) {
		_brand = other._brand;
		_year_release = other._year_release;
	}
	Car& operator=(const Car& other) {
		_brand = other._brand;
		_year_release = other._year_release;
		return *this;
	}

	std::string get_brand() const {
		return _brand;
	}
	int get_year_release() const {
		return _year_release;
	}
	

	bool operator==(const Car& other) const {
		return ((_brand == other._brand) && (_year_release == other._year_release));
	}
	bool operator<(const Car& other) const {
		return ((_brand < other._brand) || ((_brand == other._brand) && (_year_release < other._year_release)));
	}
	bool operator>(const Car& other) const {
		return ((_brand > other._brand) || ((_brand == other._brand) && (_year_release > other._year_release)));
	}
	bool operator<=(const Car& other) const {
		return ((_brand <= other._brand) || ((_brand == other._brand) && (_year_release <= other._year_release)));
	}
	bool operator>=(const Car& other) const {
		return ((_brand >= other._brand) || ((_brand == other._brand) && (_year_release >= other._year_release)));
	}

	
};

std::ostream& operator<<(std::ostream& os, const Car& car) {
	os << car.get_brand() << ", " << car.get_year_release();
	return os;
}

std::ostream& operator<<(std::ostream& os, std::vector<Car>& list) {
	for (const Car& car : list) {
		os << car << std::endl;
	}
	os << std::endl;
	return os;
}

