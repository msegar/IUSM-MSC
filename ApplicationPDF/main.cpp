#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <sstream>

using namespace std;

int main(int argc, const char* argv[])
{
	if (argc < 2){
		cout << "usage: [exe] [applicant csv]" << endl;
		exit(1);
	}
	
	ifstream input;
	input.open(argv[1]);
	
	vector<string> curr;
	bool first = true;
	
	for (string row; getline(input, row);){
		istringstream ss(row);
		curr.clear();
		if (first){
			first = false;
			continue;
		}
		for (string word; getline(ss, word, ',');){
			curr.push_back(word);
		}
		
		cout << "size: " << curr.size() << endl;
		
		string command = "php ";
				
		if (curr.size() == 17)
			command += "createPDF.php";
		else if (curr.size() == 21)
			command += "createPDF_2";	
		else if (curr.size() == 21)
			command += "createPDF_3";
		else if (curr.size() == 21)
			command += "createPDF_4";
		else if (curr.size() == 21)
			command += "createPDF_5";
		
		for (int i = 0; i < curr.size(); ++i){
			command += " ";
			command += "\"";
			command += curr[i];
			command += "\"";
		}
		
		string name = curr[0];
		replace(name.begin(), name.end(), ' ', '_');
		
		command += " > Applicant_";
		command += name;
		command += ".pdf";
		
		//cout << "command: " << command << endl;
		
		system(command.c_str());
	}
}