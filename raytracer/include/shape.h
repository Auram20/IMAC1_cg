#ifndef SHAPE_H
#define SHAPE_H

#include "colors.h"


typedef struct Sphere
{
	Point3D o; //Origine
	float r; //Rayon
	Color3f c; //Couleur

}Sphere;


typedef struct Cube
{
	Point3D min;
	Point3D max;
	Color3f c;

}Cube;

Sphere createSphere(Point3D origine, float rayon, Color3f couleur);

Cube createCube(Point3D MIN, Point3D MAX, Color3f couleur);

int intersectsSphere(Ray r, Sphere s, Intersection* i);

int intersectsCube(Ray r, Cube s, Intersection* i);	



#endif