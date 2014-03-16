#include <vector>
#include <iostream>

struct Point{
	int x;
	int y;
	Point() : x(0), y(0){}
	Point(int a, int b) : x(a), y(b) {}
};

struct Line{
	double x;
	double y;
	std::vector<int> points;
	Line(): x(0), y(0){}
};

class Solution{
public:
	static Line getLine(Point a, Point b){
		double y = (b.y*a.x - a.y * b.x)/(a.x - b.x); 
		double x = (a.y*b.x - b.y * a.x)/(a.y - b.y);
		Line line;
		line.x = x;
		line.y = y;
		return line;
	}

	int maxPoints(std::vector<Point> &points){
		int max  = 0;
		std::vector<Line> lines;
		for(int i=0; i<points.size()-1; i++)
			for(int j=i+1; j<points.size(); j++){
				Line line = getline(points[i], points[j]);
				int is_exist = 0;
				int k;
				for(k=0; k<lines.size(); k++){
					if(lines[k].x == line.x && lines[k].y == line.y){
						is_exist = 1;
						break;
					}
				}
				if(is_exist==0){
					line.points.push_back(points[i].x);
					line.points.push_back(points[j].x);
					lines.push_back(line);
					if(line.points.size()>max)
						max = line.points.size();
				}else{
					bool a_exist  = false;
					bool b_exist = false;
					for(int n=0; n<lines[k].points.size(); n++){
						if(lines[k].points[n]==points[i].x){
							a_exist = true;
						}
						if(lines[k].points[n]==points[j].x){
							b_exist = true;
						}
						if(a_exist && b_exist)
							break;
					}
					if(!a_exist)
						lines[k].points.push_back(points[i].x);
					if(!b_exist)
						lines[k].points.push_back(points[j].x);
					if(lines[k].points.size()>max)
						max = lines[k].points.size();
				}
			}
		return max;
	}
					
				


	
	
};
