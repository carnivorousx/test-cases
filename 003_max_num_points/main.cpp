#include "Solution.h"

int main(){

	std::vector<Point> p;
	Point p1;
	Point p2;
	Point p3;
	Point p4;
	Point p5;
	Point p6;
	
	p1.x = 1;
	p1.y = 1;
	
	p2.x = 2;
	p2.y = 2;

	p3.x = 3;
	p3.y = 3;

	p4.x = 4;
	p4.y = 9;

	p5.x = 6;
	p5.y = 11;

	p6.x = 8;
	p6.y = 2;

	p.push_back(p1);
	p.push_back(p2);
	p.push_back(p3);
	p.push_back(p4);
	p.push_back(p5);
	p.push_back(p6);

	Solution sl;
	std::cout<<sl.maxPoints(p)<<std::endl;

	return 0;
}
