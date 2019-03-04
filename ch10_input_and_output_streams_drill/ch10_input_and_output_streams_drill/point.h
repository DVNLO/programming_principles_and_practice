#ifndef POINT_H
#define POINT_H

#include <algorithm>
#include <iostream>

template<typename X_t, typename Y_t>
class Point
{
	X_t X;
	Y_t Y;
public:
	Point() = default;

	Point(X_t x_val, Y_t y_val) : X{ x_val }, Y{ y_val } {};

	Point(Point const & const source) noexcept : X{ source.X }, Y{ source.Y } {};

	Point& operator=(Point source) noexcept
	{
		std::swap(X, source.X);
		std::swap(Y, source.Y);
		return *this;
	};

	void x(X_t x_val) { X = x_val; };
	X_t x() const { return X; };

	void y(X_t y_val) { Y = y_val; };
	Y_t y() const { return Y; };

	template<typename X_t, typename Y_t>
	friend std::ostream& operator<<(std::ostream & os, Point<X_t, Y_t> const & const p);

	template<typename X_t, typename Y_t>
	friend std::istream& operator>>(std::istream & is, Point<X_t, Y_t> & const p);

	~Point() = default;
};

template<typename X_t, typename Y_t>
std::ostream& operator<<(std::ostream& os, Point<X_t, Y_t> const & const p)
{
	return os << p.X << ' ' << p.Y;
}

template<typename X_t, typename Y_t>
std::istream& operator>>(std::istream& is, Point<X_t, Y_t> & const p)
{
	Point<X_t, Y_t> tmp;
	is >> tmp.X;
	if (is.bad() || is.fail())
		return is;
	is >> tmp.Y;
	if (is.bad() || is.fail())
		return is;
	p = tmp;
	return is;
}

#endif // !POINT_H