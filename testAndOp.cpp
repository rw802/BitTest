//============================================================================
// Name        : testAndOp.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <bitset>
#include "glm/glm.hpp"

using namespace std;
using glm::uint32;

void setBit(uint32 & input, int bit, bool value)
{
	input ^= (-value ^ input) & (1 << bit);;
}

void printInBit(uint32 number)
{
	std::bitset<32> output(number);
	cout<<output<<endl;
}

int main() {
	cout << "!!!Int-Bit test!!!" << endl; // prints !!!Hello World!!!

	uint32 number = 8;

	cout <<"input: "<< number << endl;
	setBit(number, 30, 1);
	setBit(number, 31, 1);
	cout<<"set first two bits to 1 ";
	printInBit(number);

	uint32 bitAnd = number & 0x3FFFFFFFU;
	cout<<"And op ";
	printInBit(bitAnd);

	uint32 x = 8,y = 16,z = 64;
	number = (x << 20U) | (y<<10U) | z ;
	cout<<"brick index ";
	printInBit(number);

	x = (number & 0x3FF00000U ) >> 20U;
	y = ( number & 0x000FFC00U ) >> 10U;
	z = number & 0x000003FFU;

	cout<<"xyz "<<x<<" "<<y<<" "<<z<<endl;

	return 0;
}
