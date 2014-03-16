#include "Solution.h"

int main(int argc, char** argv){

	std::string test = " hello my name is Yiming Xiao ";
	
	Solution sol;
	sol.reverseWords(test);
	std::cout<<test<<std::endl;

	return 0;
}
