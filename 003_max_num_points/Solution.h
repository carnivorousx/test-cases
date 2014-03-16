#include <vector>
#include <iostream>

struct Point{
	int x;
	int y;
	Point() : x(0), y(0){}
	Point(int a, int b) : x(a), y(b) {}
};
/*
struct Line{
	double x;
	double y;
	std::vector<int> points;
	Line(): x(0), y(0){}
	static Line get(Point a, Point b){
                double y = (b.y*a.x - a.y * b.x)/(a.x - b.x); 
                double x = (a.y*b.x - b.y * a.x)/(a.y - b.y);
                Line line;
                line.x = x;
                line.y = y;
                return line;
        }

};
*/

struct Line{
        double x;
        double y;
        int flag;
        std::vector<int> points;
        Line(): x(0), y(0), flag(0){}
        static Line get(Point a, Point b){
            if(a.x!=b.x && a.y!=b.y){
                double y = (double)(b.y*a.x - a.y * b.x)/(double)(a.x - b.x);
                double x = (double)(a.y*b.x - b.y * a.x)/(double)(a.y - b.y);
                Line line;
                line.x = x;
                line.y = y;
		line.flag = 0;
                return line;
            }else if(a.x==b.x && a.y!=b.y){
                int flag = 1;
                double x = (a.y*b.x - b.y * a.x)/(a.y - b.y);
                Line line;
                line.x = x;
                line.y = -1;
                line.flag = flag;
                return line;
            }else if(a.y==b.y && a.x!=b.x){
                Line line;
                line.flag = 2;
                line.y = a.y;
                line.x = -1;
                return line;
            }else{
                Line line;
                line.flag = 3;
                line.x = a.x;
                line.y = a.y;
                return line;
            }
        }

};

class Solution {
public:
    int maxPoints(std::vector<Point> &points) {
        int max  = 0;
        if(points.size()==0)
            return max;
                std::vector<Line> lines;
                for(int i=0; i<points.size()-1; i++)
                        for(int j=i+1; j<points.size(); j++){
                                Line line = Line::get(points[i], points[j]);
				std::cout<<line.x<<", "<<line.y<<", "<<line.flag<<std::endl;
                                int is_exist = 0;
                                int k;
                                if(line.flag==0){
                                    for(k=0; k<lines.size(); k++){
                                        if(lines[k].x == line.x && lines[k].y == line.y && lines[k].flag==0){
                                                is_exist = 1;
                                                break;
                                        }
                                    }
                                }else if(line.flag==1){
                                    for(k=0; k<lines.size(); k++){
                                        if(lines[k].x == line.x  && lines[k].flag==1){
                                                is_exist = 1;
                                                break;
                                        }
                                    }
                                }else if(line.flag==2){
                                    for(k=0; k<lines.size(); k++){
                                        if(lines[k].y == line.y && lines[k].flag==2){
                                                is_exist = 1;
                                                break;
                                        }
                                    }
                                }else{
                                    for(k=0; k<lines.size(); k++){
                                        if(lines[k].x == line.x && lines[k].y == line.y && lines[k].flag==3){
                                                is_exist = 1;
                                                break;
                                        }
                                    }
                                }
                                if(is_exist==0){
                                    if(line.flag==0){
                                        line.points.push_back(points[i].x);
                                        line.points.push_back(points[j].x);
                                        lines.push_back(line);
                                        if(line.points.size()>max)
                                                max = line.points.size();
                                    }else if(line.flag==1){
                                        line.points.push_back(points[i].y);
                                        line.points.push_back(points[j].y);
                                        lines.push_back(line);
                                        if(line.points.size()>max)
                                            max = line.points.size();
                                    }else if(line.flag==2){
                                        line.points.push_back(points[i].x);
                                        line.points.push_back(points[j].x);
                                        lines.push_back(line);
                                        if(line.points.size()>max)
                                            max = line.points.size();
                                    }else{
                                        line.points.push_back(points[i].x);
                                        line.points.push_back(points[i].y);
                                        lines.push_back(line);
                                        if(line.points.size()-1>max)
                                            max = line.points.size()-1;
                                    }
                                }else{
                                    if(line.flag==0){
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
                                        if(!a_exist){
                                                lines[k].points.push_back(points[i].x);
						std::cout<<points[i].x<<", "<<points[i].y<<std::endl;
					}
                                        if(!b_exist){
                                                lines[k].points.push_back(points[j].x);
						std::cout<<points[j].x<<", "<<points[j].y<<std::endl;
					}
                                        if(lines[k].points.size()>max)
                                                max = lines[k].points.size();
                                    }else if(line.flag==1){
                                        bool a_exist = false;
                                        bool b_exist = false;
                                        for(int n=0; n<lines[k].points.size(); n++){
                                                if(lines[k].points[n]==points[i].y){
                                                        a_exist = true;
                                                }
                                                if(lines[k].points[n]==points[j].y){
                                                        b_exist = true;
                                                }
                                                if(a_exist && b_exist)
                                                        break;
                                        }
                                        if(!a_exist)
                                                lines[k].points.push_back(points[i].y);
                                        if(!b_exist)
                                                lines[k].points.push_back(points[j].y);
                                        if(lines[k].points.size()>max)
                                                max = lines[k].points.size();
                                    }else if(line.flag==2){
                                        bool a_exist = false;
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
                                    }else{
                                        
                                    }
                                }
                        }
                return max;

    }
};
/*
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
				Line line = Line::get(points[i], points[j]);
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
*/
