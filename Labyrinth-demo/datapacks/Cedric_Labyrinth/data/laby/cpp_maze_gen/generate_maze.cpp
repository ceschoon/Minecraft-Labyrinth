#include "Map.h"
#include <fstream>
#include <string>
#include <random>
#include <stdexcept>

using namespace std;

int main(int argc, char** argv)
{
	if (argc<3) throw runtime_error("You must give two arguments (sizeX and sizeY) which must be odd integers.");
	
	int mapSizeX = stoi(argv[1]);
	int mapSizeY = stoi(argv[2]);
	
	if (mapSizeX%2==0 || mapSizeY%2==0) throw runtime_error("The maze dimensions must be odd integers.");
	
	random_device true_gen;
	int seed = true_gen();
	
	Map map(mapSizeY,mapSizeX,seed);
	map.recursiveDivision();
	
	ofstream outFile("maze.dat");
	
	// top wall
	for (int i=0; i<map.GetmapWidth()+2; i++) outFile << 1;
	outFile << endl;
	
	// generated maze
	for (int i=0; i<map.GetmapWidth(); i++)
	{
		outFile << 1; // left wall
		
		for (int j=0; j<map.GetmapHeight(); j++)
		{
			int value = map.GetgridAt(i,j);
			outFile << value;
		}
		
		outFile << 1; // right wall
		outFile << endl;
	}
	
	// bottom wall
	for (int i=0; i<map.GetmapWidth()+2; i++) outFile << 1;
	outFile << endl;
	
	cout << "Info: The generated maze has been written in file \"maze.dat\"" << endl;
	
	return 0;
}