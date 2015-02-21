#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <sstream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

using namespace std;

string getCommittee(string com){
	string committee = "";
	
	int first = com.find('(');
	int second = com.find(')');
	committee = com.substr(first+1, second - first - 1);
	
	return committee;
}

int main(int argc, const char* argv[])
{
	if (argc < 2){
		cout << "usage: [exe] [applicant txt]" << endl;
		exit(1);
	}
	
	ifstream input;
	input.open(argv[1]);
	
	vector< vector<string> > db;
	vector<string> curr;
	bool first = true;
	string longWord = "";
	bool lw = false;
	
	for (string row; getline(input, row);){
		if (first){
			first = false;
			continue;
		}
		istringstream ss(row);
		if (lw == false)
			curr.clear();
		for (string word; getline(ss, word, '\t');){
			cout << "word: " << word << endl;
			if (count(word.begin(), word.end(), '"') == 2)
				curr.push_back(word);
			else if (word[0] == '"'){
				cout << "case1" << endl;
				longWord = word;
				longWord += "\n";
				lw = true;
			} else if ((lw == true) && (word.find("\"") == string::npos)){
				cout << "case2" << endl;
				longWord += word;
				longWord += "\n";
			} else if ((lw == true) && (word.find("\"") != string::npos)){
				cout << "case3" << endl;
				longWord += word;
				curr.push_back(longWord);
				cout << "size: " << curr.size() << endl;
				longWord = "";
				lw = false;
			} else if (lw == false){
				cout << "case4" << endl;
				curr.push_back(word);
				cout << "size: " << curr.size() << endl;
			}
		}
		if (lw == false){
			//if ((curr.size() < 40) && (curr.size() < 2)){
			if (curr.size() != 42){
				cout << "**ERROR: less than 42" << endl;
				cout << "size: " << curr.size() << endl;
				cout << "Line/applicant " << db.size()+1 << endl;
				cout << curr[0] << endl;
				exit(1);
			}
			db.push_back(curr);
		}

	}
	
	cout << "# of applicants: " << db.size() << endl;
	
	// loop through database removing quotation marks
	for (int i = 0; i < db.size(); ++i){
		for (int j = 0; j < db[i].size(); ++j){
			string q = db[i].at(j);
			//cout << q << endl;
			q.erase(remove(q.begin(), q.end(), '"'), q.end());
			db[i].at(j) = q;
			//cout << q << endl;
			//cout << endl;
		}
	}
	
	cout << "cleaned quotations" << endl;
	
	bool repeat = true;
	
	// main loop
	for (int i = 0; i < db.size(); ++i){
		repeat = true;
		while (repeat){
			curr.clear();
			cout << "copy size: " << db[i].size() << endl;
			for (int j = 0; j < 20; ++j){
				cout << j << ": " << db[i].at(j) << endl;
				curr.push_back(db[i].at(j));
			}
		
			// add last 2 elements to vector
			curr.push_back(db[i].at(db[i].size()-2)); // phone?
			curr.push_back(db[i].at(db[i].size()-1)); // skype username

			string committee = getCommittee(curr[15]);
			cout << committee << endl;
	
			string name = curr[0];
			name += " ";
			name += curr[1];
	
			string command = "php ";
				
			command += "createPDF.php";
		
			command += " ";
			command += "\"";
			command += name;
			command += "\"";
			
			// loop through adding cells to command
			for (int j = 2; j < 20; ++j){
				command += " ";
				command += "\"";
				command += curr[j];
				command += "\"";
			}
	
			//cout << command << endl;
		
			cout << "20: " << curr[curr.size()-2] << endl;
			command += " ";
			command += "\"";
			command += curr[curr.size()-2]; // phone interview?
			command += "\"";

			cout << "21: " << curr[curr.size()-1] << endl;			
			command += " ";
			command += "\"";
			command += curr[curr.size()-1]; // skype username
			command += "\"";
	
			cout << count(command.begin(), command.end(), '"') << endl;
			//exit(1);
		
			// get output filename
			name += "_";
			name += committee;
			replace(name.begin(), name.end(), ' ', '_');
		
			command += " > ";
			//command += committee;
			//command += "/";
			command += name;
			command += ".pdf";
		
			cout << "command: " << command << endl;
			system(command.c_str());
			
			int t;
			//cin >> t;
			
			// apply to another?
			if (curr[curr.size()-3].compare("Yes") == 0){
				db[i].erase(db[i].begin()+15);
				db[i].erase(db[i].begin()+15);
				db[i].erase(db[i].begin()+15);
				db[i].erase(db[i].begin()+15);
				db[i].erase(db[i].begin()+15);
				repeat = true;
			} else
				repeat = false;
		}
	}
}