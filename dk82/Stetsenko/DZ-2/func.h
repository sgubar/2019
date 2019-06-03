#ifndef dk_line_h
#define dk_line_h

typedef struct tagPoint
{
	int x;
	int y;
	
}Point;

typedef struct tagRectangle
{
	Point *A;
	Point *B;
	Point *C;
	Point *D;
}Rectangle;


Rectangle *createRectangle(Point *A, Point *B, Point *C, Point *D);
void destroyRectangle(Rectangle *aRectangle);
float squareRectangle(Rectangle *aRectangle);
void printRectangle(Rectangle *aRectangle);


#endif
