#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <random>

using namespace std;



int main(int argc, char** argv)
{
	// Read options and declare files
	
	if (argc<1) throw runtime_error("You must give one argument (the palette number)");
	
	string palette_id = argv[1];
	ofstream fct_file("build"+palette_id+".mcfunction");
	string struct_dir = "../structures/palette"+palette_id+"/";
	
	// List of possible units (base + offset)
	
	vector<string> units_base = {"400", "330", "320", "310", "300", "230", "220", "210", "200", "110", "100", "40", "30", "20", "10", "0"};
	vector<string> units;
	
	for (int i=0; i<10; i++)
	for (string unit_base : units_base)
	{
		int len = unit_base.size();
		string unit = unit_base.substr(0,len-1) + to_string(i);
		units.push_back(unit);
	}
	
	// Generate commands in the buildX.mcfunction
	// First the setblock command for the structure blocks
	
	string cmd1 = "execute at @e[type=armor_stand,name=unit";
	string cmd2 = "] run setblock ~ ~ ~ structure_block[mode=load]{mode:\"LOAD\",ignoreEntities:0b,posX:0,posY:0,posZ:0,name:\"laby:palette"+palette_id+"/unit";
	string cmd3 = "\"}";
	
	for (string unit : units)
	{
		// check that there is a structure for this unit
		// otherwise use unit with default offset of 0
		
		ifstream struct_file(struct_dir+"unit"+unit+".nbt");
		
		if (struct_file.good()) 
		{
			string cmd = cmd1 + unit + cmd2 + unit + cmd3;
			fct_file << cmd << endl;
		}
		else
		{
			int len = unit.size();
			string default_unit = unit.substr(0,len-1) + "0";
			
			string cmd = cmd1 + unit + cmd2 + default_unit + cmd3;
			fct_file << cmd << endl;
		}
	}
	
	/* uncomment to generate the code that is now moved
	 * in functions "activatestruct" and 'killarmorstands"
	
	// Second the restone block to activate
	
	cmd1 = "execute at @e[type=armor_stand,name=unit";
	cmd2 = "] run setblock ~ ~1 ~ redstone_block";
	
	fct_file << endl;
	for (string unit : units)
	{
		string cmd = cmd1 + unit + cmd2;
		fct_file << cmd << endl;
	}
	
	// Third the clearing of armor_stands
	
	cmd1 = "kill @e[type=armor_stand,name=unit";
	cmd2 = "]";
	
	fct_file << endl;
	for (string unit : units)
	{
		string cmd = cmd1 + unit + cmd2;
		fct_file << cmd << endl;
	}
	*/
}





