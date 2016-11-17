#ifndef CSV_H
#define CSV_H

#include <vector>

extern std::vector<std::vector<int> > read_csv(const char* file_name);
extern void write_csv(std::vector<std::vector<int> > image, const char* file_name);

#endif
