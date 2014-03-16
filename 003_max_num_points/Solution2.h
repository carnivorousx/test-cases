#include <iostream>
#include <vector>

struct Point{
	int x;
	int y;
	Point():x(0),y(0){}
	Point(int a,int b):x(a),y(b){}
};

class Line{
	int a;
	int b;
	int c;
	std::vector<int> points;
	Line():a(0), b(0), c(0) {}

	static Line cal(Point p1, Point p2){
		a = p2.y - p1.y; 
		b = p1.x - p2.x;
		c = p1.y * p2.x - p2.y * p1.x;
		Line line;
		line.a = a;
		line.b = b;
		line.c = c;
	}
	bool isIn(Point p){
		if(a*p.x + b* p.y + c==0)
			return true;
		else
			return false;
	}
};

class Solution{
public:
	int maxPoints(std::vector<Point> &points){
		std::vector<std::vector<int> >whichLine(points.size());
		std::vector<Line> lines;
		int max = 0;
		for(int i=0; i<points.size()-1; ++i){
			bool existed = false;
			for(int j=i+1; j<points.size(); ++j){
				if(points[i].x==points[j].x && points[i].y == points[j].y){
					if(max<1)
						max = 1;
				}else if(!existed){
					Line newline = Line::cal(points[i], points[j]);
					newline.points.push_back(i);
					newline.points.push_back(j);
					lines.push_back(newline);
					whichline[i].push_back(lines.size()-1);
					whichline[j].push_back(lines.size()-1);
					
					for(int k = j+1; k<points.size(); ++k){
						if(newline.isIn(points[k]){
							lines[lines.size()-1].points.push_back(k);
							whichline[k].push_back(lines.size()-1);
						}
					}
					if(lines[lines.size()-1].points.size()>max)
						max = lines[lines.size()-1].points.size();	
				}		






	}
};
			
