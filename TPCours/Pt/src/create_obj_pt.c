#include "../includes/create_obj_pt.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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



	*sz_pt = 4; //TAILLE DES POINTS DU CUBE 
	vertex_number = 10*1000000; 
	
	vertex_coord = (float*) calloc(sizeof(float),3*vertex_number);
	normal_coord = (float*) calloc(sizeof(float),3*vertex_number);

int i=-1;

// PLAN XY ARRIERE
	for(int x=0;x<=100;x++)
	{	
		for(int y=0;y<=100;y++)
		{			
				i++;
				vertex_coord[i]=(x/100.0)-0.5;
				normal_coord[i]=0;
				i++;
				vertex_coord[i]=(y/100.0)-0.5;	
				normal_coord[i]=0;
				i++;
				vertex_coord[i]=0.5;
				normal_coord[i]=1;
		}
	}



// PLAN XY FACE
	for(int x=0;x<=100;x++)
	{	
		for(int y=0;y<=100;y++)
		{			
				i++;
				vertex_coord[i]=(x/100.0)-0.5;
				normal_coord[i]=0;
				i++;
				vertex_coord[i]=(y/100.0)-0.5;	
				normal_coord[i]=0;
				i++;
				vertex_coord[i]=-0.5;
				normal_coord[i]=-1;
		}
	}

// PLAN XZ BAS 
	for(int x=0;x<=100;x++)
	{	
		for(int z=0;z<=100;z++)
		{			
				i++;
				vertex_coord[i]=(x/100.0)-0.5;
				normal_coord[i]=0;
				i++;
				vertex_coord[i]=0.5;
				normal_coord[i]=1;
				i++;
				vertex_coord[i]=(z/100.0)-0.5;
				normal_coord[i]=0;
		}
	}

// PLAN XZ HAUT 
	for(int x=0;x<=100;x++)
	{	
		for(int z=0;z<=100;z++)
		{			
				i++;
				vertex_coord[i]=(x/100.0)-0.5;
				normal_coord[i]=0;
				i++;
				vertex_coord[i]=-0.5;
				normal_coord[i]=-1;
				i++;
				vertex_coord[i]=(z/100.0)-0.5;
				normal_coord[i]=0;	
		}
	}


// PLAN YZ GAUCHE
	for(int z=0;z<=100;z++)
	{	
		for(int y=0;y<=100;y++)
		{		

				i++;
				vertex_coord[i]=0.5;
				normal_coord[i]=1;
				i++;
				vertex_coord[i]=(y/100.0)-0.5;	
				normal_coord[i]=0;
				i++;
				vertex_coord[i]=(z/100.0)-0.5;
				normal_coord[i]=0;
		}
	}

// PLAN YZ DROITE
	for(int z=0;z<=100;z++)
	{	
		for(int y=0;y<=100;y++)
		{		

				i++;
				vertex_coord[i]=-0.5;
				normal_coord[i]=-1;
				i++;
				vertex_coord[i]=(y/100.0)-0.5;	
				normal_coord[i]=0;
				i++;
				vertex_coord[i]=(z/100.0)-0.5;
				normal_coord[i]=0;
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


// FONCTION PRODUIT VECTORIEL 


 Vector3D produitVect(Vector3D VecA, Vector3D VecB)
 {
 	Vector3D temp;
 	temp.x=((VecA.y*VecB.z)-(VecA.z*VecB.y));
 	temp.y=((VecA.z*VecB.x)-(VecA.x*VecB.z));
 	temp.z=((VecA.x*VecB.y)-(VecA.y*VecB.x));

 	return temp;

 }


