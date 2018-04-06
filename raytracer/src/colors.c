
#include <math.h>
#include "colors.h"


int valmax(float valeur)
{
	
	if (valeur>1)
	{
		return 1;
	}
	else if (valeur<0)
	{
		return 0;
	}

return valeur; 
}


Color3f addColors(Color3f c1, Color3f c2)
{
	Color3f temp;
	temp.r= valmax(c1.r+c2.r);
	temp.g= valmax(c1.g+c2.g);
	temp.b= valmax(c1.b+c2.b);


	return temp;
}

Color3f subColors(Color3f c1, Color3f c2)
{
	Color3f temp;
	temp.r= valmax(c1.r-c2.r);
	temp.g= valmax(c1.g-c2.g);
	temp.b= valmax(c1.b-c2.b);


	return temp;
}


Color3f multColors (Color3f c1, Color3f c2)
{
	Color3f temp;
	temp.r= valmax(c1.r*c2.r);
	temp.g= valmax(c1.g*c2.g);
	temp.b= valmax(c1.b*c2.b);


	return temp;
}



Color3f multColor(Color3f c, float a)
{
	Color3f temp;
	temp.r= valmax((c.r)*a);
	temp.g= valmax((c.g)*a);
	temp.b= valmax((c.b)*a);


	return temp;
}




Color3f divColor(Color3f c, float a)
{	
	Color3f temp;
	temp.r= valmax((c.r)/a);
	temp.g= valmax((c.g)/a);
	temp.b= valmax((c.b)/a);


	return temp;
}

