#ifndef RAYTRACER_H
#define RAYTRACER_H

#include "colors.h"


typedef struct Ray
{
	Point3D o; //Origine
	Vector3D d; //Direction

}Ray;


typedef struct Intersection
{
	Point3D pos; //Position
	Color3f c; 	 //Couleur

}Intersection;

	
Ray createRay(Point3D origine, Vector3D direction);



#endif