

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/create_object.h"

unsigned int vertex_number;
float* vertex_coord;
float* normal_coord;
unsigned int triangle_number;
unsigned int* triangle_index;

void createCoordinates() {
	// Vous devez fixer :
	// - le nombre de sommets (vertex_number)
	// - le tableau des coordonnees des sommets (vertex_coord)
	// - le tableau des coordonnees des normales (normal_coord)
	// - le nombre de triangles (triangle_number)
	// - le tableau des indices des sommets constituant les triangles (triangle_index)
	// CUBE
	vertex_number = 24; // A CHANGER
	triangle_number = 12; // A CHANGER
	
	vertex_coord = (float*) calloc(sizeof(float),3*vertex_number);
	normal_coord = (float*) calloc(sizeof(float),3*vertex_number);
	triangle_index = (unsigned int*) calloc(sizeof(unsigned int),3*triangle_number);

// COORDONNEES DES SOMMETS 
	// Sommet 1 
	vertex_coord[0]=0.0;
	vertex_coord[1]=1.0;
	vertex_coord[2]=0.0;
	// Sommet 2 
	vertex_coord[3]=1.0;
	vertex_coord[4]=1.0;
	vertex_coord[5]=0.0;
	// Sommet 3 
	vertex_coord[6]=1.0;
	vertex_coord[7]=0.0;
	vertex_coord[8]=0.0;
	// Sommet 4 
	vertex_coord[9]=0.0;
	vertex_coord[10]=0.0;
	vertex_coord[11]=0.0;
 	// Sommet 5
	vertex_coord[12]=0.0;
	vertex_coord[13]=1.0;
	vertex_coord[14]=1.0;
	// Sommet 6 
	vertex_coord[15]=1.0;
	vertex_coord[16]=1.0;
	vertex_coord[17]=1.0;
	// Sommet 7
	vertex_coord[18]=1.0;
	vertex_coord[19]=0.0;
	vertex_coord[20]=1.0;

	// Sommet 8
	vertex_coord[21]=0.0;
	vertex_coord[22]=0.0;
	vertex_coord[23]=1.0;

	// Triangle 1 - FACE DEVANT
	triangle_index[0]=1;
	triangle_index[1]=2;
	triangle_index[2]=3;

	// Triangle 2 - FACE DEVANT
	triangle_index[3]=3;
	triangle_index[4]=4;
	triangle_index[5]=1;

	// Triangle 3 - FACE GAUCHE
	triangle_index[6]=4;
	triangle_index[7]=8;
	triangle_index[8]=1;

	// Triangle 4 - FACE GAUCHE
	triangle_index[9]=1;
	triangle_index[10]=5;
	triangle_index[11]=8;
	
	// Triangle 5 - FACE ARRIERE 
	triangle_index[12]=8;
	triangle_index[13]=5;
	triangle_index[14]=6;

	// Triangle 6 - FACE ARRIERE 
	triangle_index[15]=6;
	triangle_index[16]=7;
	triangle_index[17]=8;


	// Triangle 7 - FACE DROITE 
	triangle_index[18]=6;
	triangle_index[19]=2;
	triangle_index[20]=3;


	// Triangle 8 - FACE DROITE 
	triangle_index[21]=6;
	triangle_index[22]=3;
	triangle_index[23]=7;

	// Triangle 9 - FACE HAUT 
	triangle_index[24]=6;
	triangle_index[25]=5;
	triangle_index[26]=2;

	// Triangle 10 - FACE HAUT 
	triangle_index[27]=5;
	triangle_index[28]=2;
	triangle_index[29]=1;

	// Triangle 11 - FACE BAS 
	triangle_index[30]=7;
	triangle_index[31]=8;
	triangle_index[32]=3;

	// Triangle 12 - FACE BAS 
	triangle_index[33]=8;
	triangle_index[34]=3;
	triangle_index[35]=4;












	// CONSTRUIRE LES TABLEAUX
}