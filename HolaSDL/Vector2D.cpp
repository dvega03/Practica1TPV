#include "Vector2D.h"
#include <math.h>
#include <string>



Vector2D::Vector2D() //Constructora
{
	_x = 0;
	_y = 0;
}

Vector2D::Vector2D(double x, double y) //Constructora
{
	_x = x;
	_y = y;
}

double Vector2D::getX() const { return _x; }

double Vector2D::getY() const { return _y; }

void Vector2D::setVector2D(double x, double y)
{
	_x = x;
	_y = y;
}


bool Vector2D::operator==(Vector2D& v)
{
	if (_x != v.getX() || _y != v.getY())
	{
		return false;
	}
	else
	{
		return true;
	}
}

Vector2D Vector2D::operator+(Vector2D& v)
{
	double newX, newY;

	newX = _x + v.getX();
	newY = _y + v.getY();

	return Vector2D{ newX, newY };
}

Vector2D Vector2D::operator*(double d)
{
	return Vector2D{ _x * d,_y * d };
}

Vector2D Vector2D::operator*(Vector2D& v)
{
	return Vector2D{_x * v.getX() , _y * v.getY()};
}


double Vector2D::Length()
{
	return sqrt(_x *_x + _y * _y);
}

Vector2D Vector2D::Normalize() 
{
	if (this->Length() != 0)
	{
		return Vector2D{ _x / this->Length(), _y / this->Length() };
	}
}


Vector2D::~Vector2D()//Destructora
{
}
