#include <iostream>
#include <string>
#include <vector>

class Solution{
public:
	void reverseWords(std::string &s){
		std::vector<std::string>words;
		int st=-1;					// this place, I declare the var name as "s" first, and I didn't notice this super stupid mistake
		int e = -1;					// orgininally, defined inside the for loop
		for(int i=0; i<s.length();i++ ){
			if(s[i]==' '&&st==-1){
			}
			else if(s[i]!=' '&&st==-1){
				st = i;
			}else if(s[i]==' ' && st!=-1){
				e = i-1;
				char* str = new char[e-st+2];
				for(int j=st; j!=e+1; j++)
					str[j-st] = s[j];	// this place, I made some mistakes about the index of the string( new string use the same index as the old one);
				str[e-st+1] = '\0';
				std::string word = std::string(str);
				words.push_back(word);
				st = -1;
			}else if (s[i]!=' '&&st!=-1){
			}
		}

/*
		for(int i=0; i<words.size(); i++){
			std::cout<<i<<words[i]<<" ";
		}
		std::cout<<std::endl;
*/
		std::string ret;
		std::vector<std::string>rwords;
		for(int i = words.size()-1; i>=0; i--){		// this place, the i = words.size(); i>=0; i--
			rwords.push_back(words[i]);
		}
		for(int i=0; i<rwords.size(); i++){
			ret+=" ";
			ret+=rwords[i];
		}
		ret+=" ";
		s = ret;	


	}
};
