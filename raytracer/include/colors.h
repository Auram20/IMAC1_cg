#ifndef COLORS_H
#define COLORS_H



// r,g,b entre 0 et 1 
typedef struct Color3f
{
	float r;
	float g;
	float b;

}Color3f;



Color3f addColors(Color3f c1, Color3f c2);
//→ Fonction qui calcule la somme de deux couleurs

Color3f subColors(Color3f c1, Color3f c2);
Color3f multColors (Color3f c1, Color3f c2);
//→ L’équivalent pour la soustraction et la multiplication.



Color3f multColor(Color3f c, float a); 
Color3f divColor(Color3f c1, float a); 

//→ fonctions de multiplication et division d’une couleur par un scalaire


#endif