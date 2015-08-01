/*
 ============================================================================
 Name        : V00816592A4P1.c
 Author      : Isaac Sahle
 Date        : 10/14/14
 Description : Generates random shape card
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define FILENAME ("mycsc111art.html")
#define NO_SHAPES 1000
#define X_RANGE 700
#define Y_RANGE 400
#define SHAPE_RANGE 4
#define WIDTH_RANGE 50
#define HEIGHT_RANGE 50
#define RED_RANGE 256
#define GREEN_RANGE 256
#define BLUE_RANGE 256
#define OPACITY_RANGE 100

/*
 ****************************************************
 * Function Name : writeHTMLHeader
 * Description   : Write HTML header to file
 * **************************************************
 */
void writeHTMLHeader(FILE* ofp, int w, int e) {
    //Write HTML header to file passed in as argument
	fprintf(ofp, "<!DOCTYPE html>\n");
	fprintf(ofp, "<html>\n");
	fprintf(ofp, "\t<head>\n");
	fprintf(ofp, "\t\t<title>A4P1.html</title>\n");
	fprintf(ofp, "\t</head>\n");
	fprintf(ofp, "\t<body>\n");
	fprintf(ofp, "\t\t<p>MY Merry Christmas!</p>\n");
	fprintf(ofp, "\t\t<svg width=\"%d\" height=\"%d\">\n", w, e);
}

/*
 ****************************************************
 * Function Name : Frame
 * Description   : Sets dimensions of shape placement
 * **************************************************
 */
void Frame(FILE* ofp, int x, int y, int width, int height, int st, int r, int g, int b, float op) {
	fprintf(ofp, "\t\t\t<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" style=\"fill: none; stroke-width: %d; stroke:rgb(%d,%d,%d); stroke-opacity:%.1f;\"/>\n ", x, y, width, height, st, r, g, b, op);
}

/*
 ****************************************************************************
 * Function Name : Circle
 * Description   : Outputs circles of various color, opacity, and dimensions
 * **************************************************************************
 */

void Circle(FILE * ofp, int cx, int cy, int rad, int r, int g, int b, float op) {
	fprintf(ofp," \t\t\t<circle cx=\"%d\" cy=\"%d\" r=\"%d\" style=\"fill:rgb(%d,%d,%d); fill-opacity:%.1f\"/>\n", cx, cy, rad, r, g, b, op);
}


/*
 ****************************************************************************
 * Function Name : Square
 * Description   : Outputs squares of various color, opacity, and dimensions
 * **************************************************************************
 */
void Square(FILE * ofp, int x, int y, int width, int height, int r, int g, int b, float op) {
	fprintf(ofp," \t\t\t<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" style=\"fill:rgb(%d,%d,%d); fill-opacity:%.1f\"/>\n", x, y, width, height, r, g, b, op);
}


/*
 ***************************************************************************
 * Function Name : Ellipse
 * Description   : Outputs ellipses of various color, opacity, and dimensions
 * *************************************************************************
 */
void Ellipse(FILE * ofp, int cx, int cy, int rx, int ry, int r, int g, int b, float op){
	fprintf(ofp," \t\t\t<ellipse cx=\"%d\" cy=\"%d\" rx=\"%d\" ry=\"%d\" style=\"fill:rgb(%d,%d,%d); fill-opacity:%.1f\"/>\n", cx, cy, rx, ry, r, g, b, op);
}

/*
 ****************************************************************************
 * Function Name : Rectangle
 * Description   : Outputs rectangles of various color, opacity, and dimensions
 * ***************************************************************************
 */
void Rectangle(FILE * ofp, int x, int y, int width, int height, int r, int g, int b, float op) {
	fprintf(ofp, "\t\t\t<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" style=\"fill:rgb(%d,%d,%d); fill-opacity:%.1f;\"/>\n", x, y, width, height, r, g, b, op);
}


/*
 *****************************************************************************************
 * Function Name : Random
 * Description   : Generates random numbers corresponding to different features of shapes
 * ***************************************************************************************
 */
void DrawRandomArt(FILE *ofp, int w) {

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
	printf("%7s%7s%7s%7s%7s%7s%7s%7s%7s%8s\n", "Shape#", "RSCE", "x", "y", "width", "height", "red", "green", "blue", "opacity");

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
		if (s <= 9)
			printf("%7d%7d%7d%7d%7d%7d%7d%7d%7d%8.2f\n", s, sr, x, y, wr, hr, red, green, blue, op);
		Circle(ofp, y, wr, hr, red, green, blue, op);
		Rectangle(ofp, x, y, wr, hr, red, green, blue, op);
		Ellipse(ofp, x, y, wr, hr, red, green, blue, op);
		Square(ofp, x, y, wr, wr, red, green, blue, op);
	}
}

/*
 ****************************************************
 * Function Name : writeHTMLTail
 * Description   : Write HTML tail to file
 * **************************************************
 */
void writeHTMLTail(FILE* ofp) {
    //Write HTML tail to file passed in as argument
	fprintf(ofp, "\t\t</svg>\n");
	fprintf(ofp, "\t</body>\n");
	fprintf(ofp, "</html>\n");
}

int main(void) {
	FILE* ofp = NULL;
		ofp = fopen(FILENAME, "w");
		if (ofp == NULL) {
			printf("Cannot open output file %s\n", FILENAME);
			exit(EXIT_FAILURE);  // exit() is defined in <stdlib.h>
		} /* if */
		writeHTMLHeader(ofp, 700, 400);
		DrawRandomArt(ofp, NO_SHAPES);
		Frame(ofp, 0, 0, 700, 400, 4, 0, 50, 250, 0.8);
		writeHTMLTail(ofp);
		fclose(ofp);

	return EXIT_SUCCESS;
}
