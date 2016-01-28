#include <iostream>     // cout, endl
#include <fstream>      // fstream
#include <vector>
#include <string>
#include <algorithm>    // copy
#include <iterator>     // ostream_operator
#include <stdlib.h>

#include <boost/tokenizer.hpp>

using namespace std;
using namespace boost;

string getCommittee(string com){
	string committee = "";
	
	int first = com.find('(');
	int second = com.find(')');
	committee = com.substr(first+1, second - first - 1);
	
	return committee;
}

int main(int argc, const char* argv[]){   
    if (argc < 2){
		cout << "usage: [exe] [applicant txt]" << endl;
		exit(1);
	}

    ifstream in;
	in.open(argv[1]);
	
    if (!in.is_open()) return 1;

    typedef tokenizer< escaped_list_separator<char> > Tokenizer;

	bool first = true;
    vector< string > vec;
    string line;
    vector< vector<string> > db;
    vector<string> curr;
    int t;

    while (getline(in,line))
    {
        Tokenizer tok(line);
        vec.assign(tok.begin(),tok.end());

        if (vec.size() < 48) continue;
        if (first){
        	first = false;
        	continue;
        }
		db.push_back(vec);
		vec.clear();
    }
    cout << "# of applicants: " << db.size() << endl;
	
	//cin >> t;
	
	bool repeat = true;
	
	// main loop
	for (int i = 0; i < db.size(); ++i){
		repeat = true;
		while (repeat){
			curr.clear();
			cout << "copy size: " << db[i].size() << endl;
			for (int j = 1; j < 26; ++j){
				cout << j << ": " << db[i].at(j) << endl;
				curr.push_back(db[i].at(j));
			}
		
			// manually add these 2 columns to the end of the spreadsheet
			// add last 2 elements to vector
			curr.push_back(db[i].at(db[i].size()-2)); // phone?
			curr.push_back(db[i].at(db[i].size()-1)); // skype username

			string committee = getCommittee(curr[20]);
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
			for (int j = 2; j < 25; ++j){
				command += " ";
				command += "\"";
				command += curr[j];
				command += "\"";
			}
	
			cout << command << endl;
			//cin >> t;
		
			cout << "26: " << curr[curr.size()-2] << endl;
			command += " ";
			command += "\"";
			command += curr[curr.size()-2]; // phone interview?
			command += "\"";

			cout << "27: " << curr[curr.size()-1] << endl;			
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
			//cin>>t;
			// apply to another?
			if (curr[curr.size()-3].compare("Yes") == 0){
				db[i].erase(db[i].begin()+21);
				db[i].erase(db[i].begin()+21);
				db[i].erase(db[i].begin()+21);
				db[i].erase(db[i].begin()+21);
				db[i].erase(db[i].begin()+21);
				repeat = true;
			} else
				repeat = false;
		}
	}
}