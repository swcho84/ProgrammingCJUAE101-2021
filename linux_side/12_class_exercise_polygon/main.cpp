#include "triangle.h"
#include "rectangle.h"
#include "circle.h"

using namespace std;

// main function
int main(void)
{
	// assigning the arbitrary circle(center point, radius)
	Circle circleA(0.0, 0.0, 5.0);
	printf("2D::circleA(area,perimeter)=(%.4lf[m^2],%.4lf[m])\n\n", 
					circleA.GetCircleArea(), circleA.GetCirclePerimeter());

	// assigning the arbitrary rectangle(top-left point, bottom-right point)
	Rectangle rectA(-5.0, 5.0, 5.0, -5.0);
	printf("2D::rectA(area,perimeter)=(%.4lf[m^2],%.4lf[m])\n\n", 
					rectA.GetRectangleArea(), rectA.GetRectanglePerimeter());			

	// assigning the arbitrary triangle(point A, point B, point C)
	Triangle triangleA(0.0, 0.0, 5.0, 0.0, 5.0, 5.0);
	printf("2D::triangleA(area,perimeter)=(%.4lf[m^2],%.4lf[m])\n\n", 
					triangleA.GetTriangleArea(), triangleA.GetTrianglePerimeter());										

	// pause function (windows: system("pause");)
	getchar();
  return 0;
}
