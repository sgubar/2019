#ifndef DZ2_H_INCLUDED
#define DZ2_H_INCLUDED



typedef struct tagPoint
{
	int x;
	int y;
}Point;

typedef  struct tagCircle
{
     Point *A;
     double radius;
     double area;
}Circle;

float circleRadius(Circle *aCircle);
float circleArea(Circle *aCircle);
Point *copyPointWithPoint(Point *aPoint);
Circle *createCircleWithPoint(Point *aPoint);
Circle *createCircleWithCenter(Point *aCenter, double radius);
void printCircle(Circle *aCircle);
void destroyCircle(Circle *aCircle);

#endif

