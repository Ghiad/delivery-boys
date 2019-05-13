#include "point.h" 
#include "tools.h" 
#include <cstdio> 
#include <iostream>

void point::clear(){
	setCursorPosition(x,y);
	std::cout<<" "; 
};

void point::PrintRider(){
	setCursorPosition(x,y);
	std::cout<<"*";
};

void point::PrintCanteen(){
	setCursorPosition(x,y);
	std::cout<<"------"<<endl;
	std::cout<<"|²ÍÌü|"<<endl;
	srd::cout<<"------";
	setCurSorPosition(x,y);
}

void point::PrintResidence(){
	setCursorPosition(x,y);
	std::cout<<"------"<<endl;
	std::cout<<"|×¡Ëù|"<<endl;
	srd::cout<<"------";
	setCurSorPosition(x,y);
}
