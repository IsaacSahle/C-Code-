/*
 ============================================================================
 Name        : V00816592A3P1.c
 Author      : Isaac Sahle
 Date        : 09/30/14
 Description : Calculate different volumes and areas of shapes.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>

/*
 **********************************************
 * Function Name : areaCirc
 * Description   : Calculates area of a circle
 * ********************************************
 */
float areaCirc(float r) {
	return M_PI*r*r;
}

/*
 ***************************************************
 * Function Name : periCirc
 * Description   : Calculates perimeter of a circle
 ***************************************************
 */
float periCirc (float r){
	return 2*M_PI*r;
}

/*
 ***************************************************
 * Function Name : volCyl
 * Description   : Calculates volume of a cylinder
 **************************************************
 */
float volCyl(float r, float h) {
	float areaCi = areaCirc(r);
	float volCyl = h*areaCi;
	return volCyl;
}

/*
 ************************************************
 * Function Name : volSph
 * Description   : Calculates volume of a sphere
 ************************************************
 */
float volSph(float r) {
	float p1 = (float)pow(r, 3.0);
	float p2 = (4*M_PI)/3;
	float p3 = p1*p2;
	return p3;
}

/*
 *****************************************************
 * Function Name : areaSph
 * Description   : Calculates surface area of sphere
 *****************************************************
 */
float areaSph(float r) 	{
	return 4*M_PI*(r*r);
}

/*
 **********************************************
 * Function Name : areaCyl
 * Description   : Calculates surface area
 *               : of a cylinder
 **********************************************
 */
float areaCyl(float r, float h) {
	return ((2*areaCirc(r)) + (h*periCirc(r)));
}

/*
 **********************************************
 * Function Name : volCone
 * Description   : Calculates volume of a cone
 **********************************************
 */
float volCone(float r, float h) {
	//
	return (areaCirc(r)*(h/3));
}

/*
 **********************************************
 * Function Name : areaCon
 * Description   : Calculates surface area
 *               : of a cone
 **********************************************
 */
float areaCon(float r, float h) {
	float p1 = areaCirc(r);
	float p2 = (float)sqrt((r*r)+(h*h));
	return (p1 + (M_PI*r*p2));
}

int main(void) {
	float radius = 6.2;
	float area1 = areaCirc(radius);
	float height = 8.1;
	float vol1 = volCyl(radius, height);
	float vol2 = volSph (radius);
	float vol3 = volCone (radius,height);
	float area2 = areaSph (radius);
	float area3 = areaCyl (radius, height);
	float area4 = areaCon (radius, height);

	printf("Circle:\t\tRadius = %.1f\t\t\t\t\t\tArea = %.1f\n",radius, area1);
	printf("Sphere:\t\tRadius = %.1f\t\t\tVolume = %.1f\t\tArea = %.1f\n",radius, vol2, area2);
	printf("Cylinder:\tRadius = %.1f\tHeight = %.1f\tVolume = %.1f\t\tArea = %.1f\n", radius, height, vol1, area3);
	printf("Cone:\t\tRadius =%.1f\tHeight = %.1f\tVolume = %.1f\t\tArea = %.1f\n", radius, height, vol3, area4);
	printf("Sum:\t\t\t\t\t\tVolumes = %.1f\tAreas = %.1f", (vol1+vol2+vol3), (area1+area2+area3+area4) );

	return EXIT_SUCCESS;
}
