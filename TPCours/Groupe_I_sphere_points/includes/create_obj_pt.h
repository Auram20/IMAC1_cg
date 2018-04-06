#ifndef __CREATE_OBJECT_H
#define __CREATE_OBJECT_H

extern unsigned int vertex_number;
extern float* vertex_coord;
extern float* normal_coord;

void createCoordinates(unsigned int* sz_pt);

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

#endif
