
#include <math.h>
#include <stdio.h>
#include "geometry.h"

 Point3D pointXYZ(float x, float y, float z)
 {
 	Point3D temp;
 	temp.x=x;
 	temp.y=y;
 	temp.z=z;

 	return temp;
 }


Vector3D vectorXYZ(float x, float y, float z)
{	
	Vector3D temp;
 	temp.x=x;
 	temp.y=y;
 	temp.z=z;

 	return temp;
 }


Vector3D vector(Point3D A, Point3D B)
{	
	Vector3D temp;
 	temp.x=(B.x-A.x);
 	temp.y=(B.y-A.y);
 	temp.z=(B.z-A.z);

 	return temp;
 }



Point3D pointPlusVector(Point3D P, Vector3D V)
{
	Point3D temp;
	temp.x=(P.x+V.x);
	temp.y=(P.y+V.y);
	temp.z=(P.z+V.z);

	return temp;
}


Vector3D addVectors(Vector3D A, Vector3D B)
{
	Vector3D temp;
	temp.x=(A.x+B.x);
	temp.y=(A.y+B.y);
	temp.z=(A.z+B.z);

	return temp;
}


Vector3D subVectors(Vector3D A, Vector3D B)
{
	Vector3D temp;
	temp.x=(A.x-B.x);
	temp.y=(A.y-B.y);
	temp.z=(A.z-B.z);

	return temp;


}


Vector3D multVector(Vector3D V, float a)
{
	Vector3D temp;
	temp.x=(a*(V.x));
	temp.y=(a*(V.y));
	temp.z=(a*(V.z));

	return temp;

}



Vector3D divVector(Vector3D V, float a)
{
	Vector3D temp;
	temp.x=((V.x)/a);
	temp.y=((V.y)/a);
	temp.z=((V.z)/a);

	return temp;

}


float dot(Vector3D A, Vector3D B)
{
	float temp;
	temp=((A.x*B.x)+(A.y*B.y)+(A.z*B.z));

	return temp;

}


float norm(Vector3D A)
{
	float temp;
	temp=sqrt(pow(A.x,2)+pow(A.y,2)+pow(A.z,2));

	return temp;

}
// Le produit scalaire représente la projection 


Vector3D normalize(Vector3D A)
{	
	Vector3D temp=divVector(A,norm(A));

 	return temp;
 }


void printVector3D(Vector3D v)
{
	printf("Le vecteur a pour coordonnées : \n ");
	printf("%f \n %f \n %f ", v.x,v.y,v.z);
}




void printPoint3D(Point3D p)
{
	printf("Le point a pour coordonnées : \n ");
	printf("%f \n %f \n %f ", p.x,p.y,p.z);
}




