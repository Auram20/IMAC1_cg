#ifndef GEOMETRY_H
#define GEOMETRY_H



typedef struct Vec3
{
	float x;
	float y;
	float z;

}Point3D, Vector3D;


 Point3D pointXYZ(float x, float y, float z);
/*→ Construit le point (x, y, z)*/


Vector3D vectorXYZ(float x, float y, float z);
/*→ Construit le vecteur (x, y, z)*/


Vector3D vector(Point3D A, Point3D B);
/*→ Construit le vecteur AB = B − A*/


Point3D pointPlusVector(Point3D P, Vector3D V);
// → Construit le point P + V


Vector3D addVectors(Vector3D A, Vector3D B);
Vector3D subVectors(Vector3D A, Vector3D B); 
//→ fonctions d’addition et soustraction de vecteurs


Vector3D multVector(Vector3D V, float a);
Vector3D divVector(Vector3D V, float a);
//→ fonctions de multiplication et division d’un vecteur par un scalaire 


float dot(Vector3D A, Vector3D B);
// → Fonction calculant le produit scalaire de deux vecteurs


float norm(Vector3D A);
//→ fonction calculant la norme d’un vecteur


Vector3D normalize(Vector3D A);
//→ fonction retournant le vecteur normalisé passé en paramètre


void printVector3D(Vector3D v);
void printPoint3D(Point3D p);

/*
// PSEUDO-CODE // 


On a : 
L'équation d'un rayon (droite) : y=ax+b 
L'équation d'une sphère : x^2 + y^2 + z^2 = r^2
L'équation d'un cube : 




*/ 



#endif
