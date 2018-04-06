
#include "geometry.h"
#include "colors.h"
#include "raytracer.h"
#include "shape.h"
#include "math.h"

Sphere createSphere(Point3D origine, float rayon, Color3f couleur)
{
	Sphere temp;
	temp.o=origine;
	temp.r=rayon;
	temp.c=couleur;

	return temp;

}

Cube createCube(Point3D MIN, Point3D MAX, Color3f couleur)
{

	Cube temp;
	temp.min=MIN;
	temp.max=MAX;
	temp.c=couleur;
	return temp;
}




int intersectsSphere(Ray r, Sphere s, Intersection* i)
{
	float a=norm(r.d); //Norme de la direction du rayon
	float b= 2*dot(r.o,pointPlusVector(multVector((s.o),-1.0),(r.d)));
	float c=norm(r.o)+norm(s.o)-2*norm(r.o)*norm(s.o)-s.r;
	float delta= pow(b,2)-(4*pow(a,2)*pow(c,2));


	if (delta<0)
		printf ("Il n'y a pas de solutions réelles");
		return 0;

	if (delta=0)
		float x=(-b/(2*a));
		printf("Le delta est nul et la solution double est %d",x)


	if (delta>0)
		float x1= (-b-sqrt(delta)/2);
		float x2= (-b+sqrt(delta)/2);
		printf("Le delta est positif et les solution sont %d et %d", x1,x2);
		if (x1<x2 && x1>0)
			x=x1;
		else if (x2<x1 && x2>0)
			x=x2;


	if (x<0)
		return 0;

	else 

		return 1;

}


int intersectsCube(Ray r, Cube s, Intersection* i)
{






}



