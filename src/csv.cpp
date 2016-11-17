#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>

#include "csv.h"

using namespace std;

vector<vector<int> > read_csv(const char* file_name) {
	vector<vector<int> > parsed_values;
	ifstream input_file(file_name, ios::in);
	if (!input_file.good()) {
		cout << "Could not open input file!" << endl;
		exit(EXIT_FAILURE);
	}

	string line;
	while (getline(input_file, line)) {
		stringstream lineStream(line);
		string number_string;
		vector<int> lineVector;
		while (getline(lineStream, number_string, ',')) {
			int number = atoi(number_string.c_str());
			lineVector.push_back(number);
		}
		parsed_values.push_back(lineVector);
	}

	input_file.close();

	return parsed_values;
}

void write_csv(vector<vector<int> > image, const char* file_name) {
	ofstream output_file(file_name, ios::out);
	if (!output_file.good()) {
		cout << "Could not open output_file file!" << endl;
		exit(EXIT_FAILURE);
	}

	for (size_t i = 0; i <  image.size(); i++) {
		for (size_t j = 0; j < image[i].size(); j++) {
			if(image[i][j] < 10){
				output_file << image[i][j] << "  ";
			}
			else if(image[i][j] < 100){
				output_file << image[i][j] << " ";
			}else{
				output_file << image[i][j];
			}
			if (!(j == image.size() - 1) && !(j == image[i].size() - 1) )
				output_file << ",";

		}
		output_file << endl;
	}

	output_file.close();
}
