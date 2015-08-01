/*
 ============================================================================
 Name        : V00816592A3P2.c
 Author      : Isaac Sahle
 Date        : 09/30/14
 Description : Calculates volume, radius, and height of a cone.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

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
 **********************************************
 * Function Name : volCone
 * Description   : Calculates volume of a cone
 **********************************************
 */
float volCone(float r, float h) {
	return (areaCirc(r)*(h/3));
}
/*
 **********************************************
 * Function Name : radi
 * Description   : Calculates radius of a cone
 **********************************************
 */
float radi(float v, float h) {
	return (sqrt((3*(v))/(M_PI*h)));
}
/*
 *********************************************
 * Function Name : tall
 * Description   : Calculates height of a cone
 *********************************************
 */
float tall(float v, float r ) {
	return ((3*(v))/areaCirc(r));
}

int main(void) {

	float radius;
	float height;
	float vol1;
	radius = 97.73271;
	height = 17.61;
	vol1 = 176144.0;
	float volume = volCone(radius, height);
	float rad = radi(vol1, height);
	float xx = tall(vol1, radius);
	printf("A cone with height %.1f and volume %.1f has radius %.1f\n", height, volume, rad);
	printf("A cone with radius %.1f and height %.1f has volume %.1f\n", radius, height, volume);
	printf("A cone with radius %.1f and volume %.1f has height %.1f\n", radius, volume, xx);

	return EXIT_SUCCESS;
}
