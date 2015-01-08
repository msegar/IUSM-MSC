#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <sstream>
#include <algorithm>

using namespace std;

#define ALTERNATES 1
#define COMMITTEE_WEIGHT 0.90

struct committee {
	string name;
	int quota;
	vector<string> choices;
};
struct applicant {
	string name;
	vector<string> choices;
};
struct weight {
	string applicantName;
	double weight;
};
// ----------------------------------------------------
// global variables
vector<committee> committees;
vector<applicant> applicants;
// ----------------------------------------------------
// functions
void readInCommittees(const char* argv[]);
void readInApplicants(const char* argv[]);
// ----------------------------------------------------

bool compareStart(const weight &a, const weight &b){
	if (a.weight < b.weight) return true;
	return false; 
}

double getApplicantPref(string a, string c){
	double pref = 10.0; // **** ARBITRARY VALUE - MAY WANT TO MAKE A VARIABLE
	int i = 0;
	while (i < applicants.size()){
		if (applicants[i].name.compare(a) == 0)
			break;
		++i;
	}
	
	applicant ap = applicants[i];
	
	for (int j = 0; j < ap.choices.size(); ++j){
		if (ap.choices[j].compare(c) == 0){
			if (j <= 1)
				pref = ((j+1) * 1.0);
			else
				pref = ((j+1) * 1.0) + 1.0;
			
			return pref;
		}	
	}
	
	return pref;
}

double getCommitteePref(int i){
	double pref = 10.0;
	
	if (i < 1)
		pref = (i+1) * 1.0;
	else
		pref = ((i+1) * 1.0) + 1.0;
	
	pref*=COMMITTEE_WEIGHT; // SHOULD COMMITTEE HAVE GREATER WEIGHT?????
	
	return pref;
}

void algorithm(){
	for (int i = 0; i < committees.size(); ++i){
		committee c = committees[i];
		vector<weight> weights;
		double applicantPref = 0.0;
		double committeePref = 0.0;
		
		for (int j = 0; j < c.choices.size(); ++j){
			weight w;
			applicantPref = getApplicantPref(c.choices[j], c.name);
			w.applicantName = c.choices[j];
			w.weight = applicantPref;
			committeePref = getCommitteePref(j);
			w.weight += committeePref;
			
			weights.push_back(w);
		}
		
		// sort weights
		sort(weights.begin(), weights.end(), compareStart);

		// print out final
		int quota = c.quota;
		int applicantSize = weights.size();
		
		cout << "\n--- " << c.name << " ---" << endl;
		cout << "quota = " << quota << ", applicantSize = " << applicantSize << endl;
		if (quota < applicantSize){
			for (int j = 0; j < quota; ++j)
				cout << weights[j].applicantName << endl;
			cout << "------------" << endl;
			cout << "alternate: " << weights[quota].applicantName << endl;
		} else {
			for (int j = 0; j < applicantSize; ++j)
				cout << weights[j].applicantName << endl;
			int diff = quota - applicantSize;
			for (int j = 0; j < diff; ++j)
				cout << "N/A" << endl;
			cout << "------------" << endl;
			cout << "alternate: N/A" << endl;
		}
	}
}


int main(int argc, const char* argv[])
{
	if (argc < 3){
		cout << "Usage: [exe] [committee csv] [applicant csv]" << endl;
		exit(1);
	}
	
	readInCommittees(argv);
	readInApplicants(argv);
	
	algorithm();
}

void readInCommittees(const char* argv[]){
	ifstream input;
	vector<string> curr;
	string name = "";
	bool first = true;
	int index = 0;
	int quota = 0;
	
	// read in committee choices
	input.open(argv[1]);
	
	for (string row; getline(input, row); ){
		istringstream ss(row);
		name = "";
		curr.clear();
		index = 0;
		quota = 0;
		if (first){
			first = false;
			continue;
		}
		
		for (string word; getline(ss, word, ',');){
			++index;
			if (index == 1){
				name = word;}
			else if (index == 2){
				quota = atoi(word.c_str());}
			else
				curr.push_back(word);
		}
		
		committee c;
		c.name = name;
		c.quota = quota;
		c.choices = curr;
		
		committees.push_back(c);
	}
	input.close();

	cout << "# committees: " << committees.size() << endl;
}

void readInApplicants(const char* argv[]){
	ifstream input;
	vector<string> curr;
	string name = "";
	bool first = true;
	int index = 0;
	
	// read in applicant choices
	input.open(argv[2]);
	
	for (string row; getline(input, row); ){
		istringstream ss(row);
		name = "";
		curr.clear();
		index = 0;
		if (first){
			first = false;
			continue;
		}
		
		for (string word; getline(ss, word, ',');){
			++index;
			if (index == 1)
				name = word;
			else
				curr.push_back(word);
		}
		
		applicant a;
		a.name = name;
		a.choices = curr;
		
		applicants.push_back(a);
	}
	input.close();
	
	cout << "# applicants: " << applicants.size() << endl;
}