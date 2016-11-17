#include <iostream>
#include <unistd.h>

#include "csv.h"
#include "watershed.h"

using namespace std;

static const char *usage
    = "Usage: ./main marker mask out_file [-c | -r xsize ysize] [-h]";

int main(int argc, char** argv) {
	int parse_var;
	while ((parse_var = getopt(argc, argv, "crh")) >= 0) {
		switch (parse_var) {

		case 'h':
			cout << usage << endl;
			return EXIT_SUCCESS;
		}
	}

	char *in_file, *out_file;
	if (!argv[optind]) {
		cout << "Marker image not provided!" << endl;
		cout << usage << endl;
		return EXIT_FAILURE;
	} else {
		in_file= argv[optind++];
	}

	if (!argv[optind]) {
		cout << "Output file not provided!" << endl;
		cout << usage << endl;
		return EXIT_FAILURE;
	} else {
		out_file = argv[optind++];
	}
	// File processing
	vector< vector< int> > input = read_csv(in_file);
  vector< vector< int> > output = watershed(input);
	// Marker vector is modified to accordingly


	write_csv(output, out_file);

	return EXIT_SUCCESS;
}
