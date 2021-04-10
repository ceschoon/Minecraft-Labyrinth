#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <random>

using namespace std;



int random_offset(double random_number)
{
	double cumul = 0;
	double proba;
	
	proba = 1.0/4;
	if (random_number-cumul<proba) return 1;
	else cumul += proba;
	
	proba = 1.0/8;
	if (random_number-cumul<proba) return 2;
	else cumul += proba;
	
	proba = 1.0/16;
	if (random_number-cumul<proba) return 3;
	else cumul += proba;
	
	proba = 1.0/32;
	if (random_number-cumul<proba) return 4;
	else cumul += proba;
	
	proba = 1.0/64;
	if (random_number-cumul<proba) return 5;
	else cumul += proba;
	
	proba = 1.0/128;
	if (random_number-cumul<proba) return 6;
	else cumul += proba;
	
	proba = 1.0/256;
	if (random_number-cumul<proba) return 7;
	else cumul += proba;
	
	proba = 1.0/512;
	if (random_number-cumul<proba) return 8;
	else cumul += proba;
	
	proba = 1.0/1024;
	if (random_number-cumul<proba) return 9;
	else cumul += proba;
	
	return 0; // proba = 1-cumul = 0.5 (approx)
}



void dimensions(string maze_in, int &nx, int &ny)
{
	ifstream file_in(maze_in);
	string line;
	
	ny = 0;
	while (getline(file_in,line)) 
	{
		nx = line.size();
		ny++;
	}
}



void identify_topology(int array_in[], int array_out[], int nx, int ny)
{
	for (int i=0; i<nx; i++)
	for (int j=0; j<ny; j++)
	{
		int c = array_in[i+nx*j];     // center
		int t = array_in[i+nx*(j-1)]; // top
		int b = array_in[i+nx*(j+1)]; // bottom
		int l = array_in[i-1+nx*j];   // left
		int r = array_in[i+1+nx*j];   // right
		
		int topo = 0; // default is 0 for filled room (wall)
		
		if (c==0 && t==0 && b==1 && l==1 && r==1) topo = 10; // top opening
		if (c==0 && t==1 && b==0 && l==1 && r==1) topo = 20; // bottom opening
		if (c==0 && t==1 && b==1 && l==0 && r==1) topo = 30; // left opening
		if (c==0 && t==1 && b==1 && l==1 && r==0) topo = 40; // right opening
		
		if (c==0 && t==0 && b==0 && l==1 && r==1) topo = 100; // top-bottom corridor
		if (c==0 && t==1 && b==1 && l==0 && r==0) topo = 110; // left-right corridor
		
		if (c==0 && t==0 && b==1 && l==0 && r==1) topo = 200; // top-left corner
		if (c==0 && t==0 && b==1 && l==1 && r==0) topo = 210; // top-right corner
		if (c==0 && t==1 && b==0 && l==0 && r==1) topo = 220; // bottom-left corner
		if (c==0 && t==1 && b==0 && l==1 && r==0) topo = 230; // bottom-right corner
		
		if (c==0 && t==0 && b==0 && l==0 && r==1) topo = 300; // T-intersection
		if (c==0 && t==0 && b==0 && l==1 && r==0) topo = 310; // T-intersection
		if (c==0 && t==0 && b==1 && l==0 && r==0) topo = 320; // T-intersection
		if (c==0 && t==1 && b==0 && l==0 && r==0) topo = 330; // T-intersection
		
		if (c==0 && t==0 && b==0 && l==0 && r==0) topo = 400; // fully open
		
		array_out[i+nx*j] = topo;
	}
}



int main(int argc, char** argv)
{
	// Read options and declare files
	
	if (argc<4) throw runtime_error("You must give three arguments (1. the maze .dat file, 2. an integer for the size of the rooms in the maze 3. The name of the mc function)");
	
	string maze_in = argv[1];
	string maze_out = "maze_topo.dat";
	
	int room_size = stoi(argv[2]);
	
	string fct_name = argv[3];
	ofstream fct_file(fct_name+".mcfunction");
	
	
	// First, read maze and store in an array
	
	int nx,ny; dimensions(maze_in,nx,ny);
	int array_in[nx*ny];
	
	ifstream file_in(maze_in);
	ofstream file_out(maze_out);
	
	string line;
	int j=0;
	
	while (getline(file_in,line))
	{
		for (int i=0; i<line.size(); i++)
		{
			if (line[i]==' ' || line[i]=='0') array_in[i+nx*j]=0;
			else if (line[i]=='1') array_in[i+nx*j]=1;
		}
		
		j++;
	}
	
	
	// Second, use the array to identify the topology
	
	int array_out[nx*ny];
	identify_topology(array_in, array_out, nx, ny);
	
	
	// Print topology to file
	
	ofstream topo_file("maze_topo.dat");
	
	for (int j=0; j<ny; j++)
	{
		for (int i=0; i<nx; i++) topo_file << setw(4) << array_out[i+nx*j];
		topo_file << endl;
	}
	
	
	// Add randomness to the maze
	
	random_device true_gen;
	int seed = true_gen();
	default_random_engine gen(seed);
	uniform_real_distribution<double> dist01(0,1);
	
	for (int i=0; i<nx; i++)
	for (int j=0; j<ny; j++)
	{
		array_out[i+nx*j] += random_offset(dist01(gen));
	}
	
	
	// Generate commands to place an armor stand
	// on each north-west corner of a maze unit
	
	for (int i=0; i<nx; i++)
	for (int j=0; j<ny; j++)
	{
		string cmd_str = "summon armor_stand ";
		
		int x = (i+1)*room_size; // add 1 to generate the maze a bit further from player
		int y = (j+1)*room_size;
		
		cmd_str += ("~" + to_string(x) + " ");
		cmd_str += "~ ";
		cmd_str += ("~" + to_string(y) + " ");
		
		int id = array_out[i+nx*j];
		string name = "unit" + to_string(id);
		
		cmd_str += "{Invisible:1,Marker:1,CustomName:\"\\\""+name+"\\\"\",CustomNameVisible:0}";
		
		fct_file << cmd_str << endl;
	}
}





