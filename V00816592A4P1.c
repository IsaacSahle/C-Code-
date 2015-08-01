/*
 ============================================================================
 Name        : V00816592A4P1.c
 Author      : Isaac Sahle
 Date        : 10/14/14
 Description : Print out four shapes of different colours and dimensions
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define FILENAME   ("A4P1.html")

/*
 ****************************************************
 * Function Name : writeHTMLHeader
 * Description   : Write HTML header to file
 * **************************************************
 */
void writeHTMLHeader(FILE* ofp) {
    //Write HTML header to file passed in as argument
	fprintf(ofp, "<!DOCTYPE html>\n");
	fprintf(ofp, "<html>\n");
	fprintf(ofp, "\t<head>\n");
	fprintf(ofp, "\t\t<title>A4P1.html</title>\n");
	fprintf(ofp, "\t</head>\n");
	fprintf(ofp, "\t<body>\n");
	fprintf(ofp, "\t\t<p>MY SWEET SHAPES!</p>\n");
}

/*
 ****************************************************
 * Function Name : Frame
 * Description   : Sets dimensions of shape placement
 * **************************************************
 */
void Frame(FILE* ofp, int w, int e, int x, int y, int width, int height, int st, int r, int g, int b, float op) {
	fprintf(ofp, "\t\t<svg width=\"%d\" height=\"%d\">\n", w, e);
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
 * Function Name : Rectangle
 * Description   : Outputs rectangles of various color, opacity, and dimensions
 * ***************************************************************************
 */
void Rectangle(FILE * ofp, int x, int y, int width, int height, int r, int g, int b, float op) {
	fprintf(ofp, "\t\t\t<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" style=\"fill:rgb(%d,%d,%d); fill-opacity:%.1f;\"/>\n", x, y, width, height, r, g, b, op);
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
 * Function Name : Square
 * Description   : Outputs squares of various color, opacity, and dimensions
 * **************************************************************************
 */
void Square(FILE * ofp, int x, int y, int width, int height, int r, int g, int b, float op) {
	fprintf(ofp," \t\t\t<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" style=\"fill:rgb(%d,%d,%d); fill-opacity:%.1f\"/>\n", x, y, width, height, r, g, b, op);
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
	printf("We are about to create a file called %s for writing into it\n", FILENAME);
	ofp = fopen(FILENAME, "w");
	if (ofp == NULL) {
		printf("Cannot open output file %s\n", FILENAME);
		exit(EXIT_FAILURE);  // exit() is defined in <stdlib.h>
	} /* if */
	printf("We created the file %s successfully for writing\n", FILENAME);
	writeHTMLHeader(ofp);
	Frame(ofp, 700, 400, 0, 0, 700, 350, 4, 0, 50, 250, 0.8);
	Circle(ofp, 250, 100, 99, 0, 50, 50, 0.2);
	Rectangle(ofp, 300, 50, 400, 100, 0, 150, 225, 0.5);
	Ellipse(ofp, 300, 300, 200, 50, 250, 0, 0, 0.4);
	Square(ofp, 50, 50, 200, 200, 250, 0, 250, 0.6);
	writeHTMLTail(ofp);
	printf("We wrote HTML5 code into the file %s successfully\n", FILENAME);
	fclose(ofp);
	printf("We closed the file %s successfully\n", FILENAME);
	return EXIT_SUCCESS;
} /*main*/
