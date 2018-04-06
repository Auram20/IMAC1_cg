/* *******************************************************/
/* 			Sphère 3D - modélisation de points 			 */
/* 					IMAC 1 - groupe I 					 */
/* *******************************************************/

#include "../includes/create_obj_pt.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

unsigned int vertex_number;
float* vertex_coord;
float* normal_coord;

	

void createCoordinates(unsigned int* sz_pt) {
	// Vous devez fixer :
	// - le nombre de sommets (vertex_number)
	// - le tableau des coordonnees des sommets (vertex_coord)
	// - le tableau des coordonnees des normales (normal_coord)
	// Vous pouvez changer :
	// - la taille des points GL affichés à l'écran (sz_pt)



	*sz_pt = 4; //TAILLE DES POINTS DU CERCLE 
	vertex_number = 10*1000000; 
	
	vertex_coord = (float*) calloc(sizeof(float),3*vertex_number);
	normal_coord = (float*) calloc(sizeof(float),3*vertex_number);

int i=-1;
// rayon de la sphère
float R = 0.5;
	// sphere
	for(int phi=0 ; phi<360 ; phi++){
		for(int teta=-90 ; teta<90 ; teta++){
			i++;
			// coordonnées x
			vertex_coord[i] = cos(teta)*cos(phi)*R;
			i++;
			// coordonnées y
			vertex_coord[i] = cos(teta)*sin(phi)*R;
			i++;
			// coordonnées z
			vertex_coord[i] = sin(teta)*R;
		}
	}


}


// DEFINITION D'UN POINT
Point3D pointXYZ(float x, float y, float z)
 {
 	Point3D temp;
 	temp.x=x;
 	temp.y=y;
 	temp.z=z;

 	return temp;
 }

//DEFINITION D'UN VECTEUR
Vector3D vectorXYZ(float x, float y, float z)
{	
	Vector3D temp;
 	temp.x=x;
 	temp.y=y;
 	temp.z=z;

 	return temp;
 }

 // PRODUIT VECTORIEL
 Vector3D prodVector(Vector3D v1, Vector3D v2){
 	Vector3D produit;
 	produit.x = (v1.y)*(v2.z)-(v1.z)*(v2.y);
 	produit.y = (v1.z)*(v2.x)-(v1.x)*(v2.z);
 	produit.z = (v1.x)*(v2.y)-(v1.y)*(v2.x);
 	return produit;
 }
