#pragma once

#include <string>

using namespace std;

class Vector2D{

private:
	double _x;
	double _y;

public:

	Vector2D(); //Constructora
	Vector2D(double x, double y); //Constructora

	double getY() const; //Obtienes _x
	double getX() const;//Obtienes _Y

	void setVector2D(double x, double y);//Cambias el valor de _x e _y del vector

	bool operator==(Vector2D& v);//Comparar vectores
	Vector2D operator+(Vector2D& v);//Sumar vectores entre si (Vector + Vector)
	Vector2D operator*(double d);//Multiplicar un numero y un vector (double * Vector)
	Vector2D operator*(Vector2D& v);//Multiplicar dos vectores (Vector * Vector)

	double Length(); //Obtener el modulo del vector (raiz(x^2 + y^2))
	Vector2D Normalize();//Obtener el vector con modulo 1 (Vector(_x/Length, _y/Length))


	
	~Vector2D();//Destructora
};

