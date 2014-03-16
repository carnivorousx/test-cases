#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

struct InfoNode{
	int value;
	int prev;
/*
	InfoNode(){
		value = 0;
		prev = -1;
	}
*/
};

class Solution{
public:
	int evalRPN(std::vector<std::string> &tokens){
		int num = tokens.size();
		std::vector<InfoNode> info(num);
		for(int i=0; i<num; i++){
			info[i].value = 0;
			info[i].prev = -1;
		}

		int i=0;
		while(i<num){
			while(tokens[i]!="+" && 
				tokens[i]!="-" && 
				tokens[i]!="*" && 
				tokens[i]!="/" && 
			     )
				i++;
			if(tokens[i]=="+"){
				if(info[i-1].prev==-1 && info[i-2].prev==-1){
					info[i].value = atoi(tokens[i-1].c_str()) + atoi(tokens[i-2].c_str());
					info[i].prev = i-3;
				}else if(info[i-1].prev!=-1){
					if(info[info[i-1].prev].prev==-1){
							
