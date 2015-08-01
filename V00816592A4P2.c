/*
 ============================================================================
 Name        : V00816592A4P1.c
 Author      : Isaac Sahle
 Date        : 10/14/14
 Description : Generates random numbers in a table
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define RANDOM_NUM ("myrandom.txt")
#define NO_SHAPES 10
#define X_RANGE 800
#define Y_RANGE 500
#define SHAPE_RANGE 4
#define WIDTH_RANGE 100
#define HEIGHT_RANGE 100
#define RED_RANGE 255
#define GREEN_RANGE 255
#define BLUE_RANGE 255
#define OPACITY_RANGE 100

/*
 *****************************************************************************************
 * Function Name : Random
 * Description   : Generates random numbers corresponding to different features of shapes
 * ***************************************************************************************
 */
void Random(FILE * ofp, int w) {

	int s;
	int x = 0;
	int y = 0;
	int sr = 0;
	int wr = 0;
	int hr = 0;
	int red = 0;
	int green = 0;
	int blue = 0;
	int fop = 0;
	float op = 1.0;
	srand(time(NULL));

	printf("Table for drawing random geometric shapes in different colours, sizes, and opacities\n");
	fprintf(ofp, "Table for drawing random geometric shapes in different colours, sizes, and opacities\n");
	printf("%7s%7s%7s%7s%7s%7s%7s%7s%7s%8s\n", "Shape#", "RSCE", "x", "y", "width", "height", "red", "green", "blue", "opacity");
	fprintf(ofp, "%7s%7s%7s%7s%7s%7s%7s%7s%7s%8s\n", "Shape#", "RSCE", "x", "y", "width", "height", "red", "green", "blue", "opacity");

	for (s = 0; s < w; s++) {

		x = rand() %X_RANGE;
		y = rand() %Y_RANGE;
		sr = rand() %SHAPE_RANGE;
		wr = rand() %WIDTH_RANGE;
		hr = rand() %HEIGHT_RANGE;
		red = rand() %RED_RANGE;
		green = rand() %GREEN_RANGE;
		blue = rand() %BLUE_RANGE;
		fop = rand() %OPACITY_RANGE;
		op = (float) fop/100.0;



		printf("%7d%7d%7d%7d%7d%7d%7d%7d%7d%8.2f\n", s, sr, x, y, wr, hr, red, green, blue, op);
		fprintf(ofp,"%7d%7d%7d%7d%7d%7d%7d%7d%7d%8.2f\n",s, sr, x, y, wr, hr, red, green, blue, op);
	}
}

int main(void) {

	FILE* ofp = NULL;
		ofp = fopen(RANDOM_NUM, "w");
		if (ofp == NULL) {
			printf("Cannot open output file %s\n", RANDOM_NUM);
			exit(EXIT_FAILURE);  // exit() is defined in <stdlib.h>
		} /* if */
		Random(ofp, NO_SHAPES);

		return EXIT_SUCCESS;
}
