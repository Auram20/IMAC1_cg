#include <stdlib.h>
#include <stdio.h>
#include "geometry.h"
#include "colors.h"
#include "raytracer.h"
#include "shape.h"






int main(int argc, char** argv) 
{	/*
	Vector3D Vector1=vectorXYZ(0,0,0);
	Point3D Point1=vectorXYZ(1,2,0);
	printVector3D(pointPlusVector(Vector1,Point1));
	*/
	
	/*
	Vector3D Vector1=vectorXYZ(0.5,1.0,-2.0);
	Vector3D Vector2=vectorXYZ(0.2,-1.0,0);
	printVector3D(addVectors(Vector1,Vector2));
	*/

	/*
	Vector3D Vector1=vectorXYZ(0.5,1.0,-2.0);
	Vector3D Vector2=vectorXYZ(0.2,-1.0,0);
	printVector3D(subVectors(Vector1,Vector2));
	*/

	/*
	Vector3D Vector1=vectorXYZ(0.5,1.0,-2.0);
	float scalaire1=2.0;
	printVector3D(multVector(Vector1,scalaire1));
	*/

	/*
	Vector3D Vector1=vectorXYZ(0.5,1.0,-2.0);
	float scalaire1=0;
	printVector3D(multVector(Vector1,scalaire1));
	*/

	/*
	Vector3D Vector1=vectorXYZ(0.5,1.0,-2.0);
	float scalaire1=2.0;
	printVector3D(divVector(Vector1,scalaire1));
	*/

	/*
	Vector3D Vector1=vectorXYZ(0.5,1.0,-2.0);
	float scalaire1=0;
	printVector3D(divVector(Vector1,scalaire1));
	*/
	
	/*
	Vector3D Vector1=vectorXYZ(1,0,0);
	Vector3D Vector2=vectorXYZ(2,0,0);
	printf("Le produit scalaire est : %f",dot(Vector1,Vector2));
	*/
	
	/*
	Vector3D Vector1=vectorXYZ(1,0,0);
	Vector3D Vector2=vectorXYZ(0,1,0);
	printf("Le produit scalaire est : %f",dot(Vector1,Vector2));
	*/

	/*	
	Vector3D Vector=vectorXYZ(2,0,0);
	printf("La norme est : %f",norm(Vector));
	*/
	
	/*
	Vector3D Vector=vectorXYZ(1,1,1);
	printf("La norme est : %f",norm(Vector));
	*/

	/*
	Vector3D Vector=vectorXYZ(0,0,0);
	printf("La norme est : %f",norm(Vector));
	*/


	Vector3D Vector=vectorXYZ(1,1,1);
	printVector3D(normalize(Vector));
	

	/*
	Vector3D Vector=vectorXYZ(0,0,0);
	printVector3D(normalize(Vector));
	*/

    return EXIT_SUCCESS;
}
 