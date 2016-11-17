#ifndef WATERSHED_H
#define WATERSHED_H

#include <vector>
#include <utility>
#include <algorithm>

const int mask = -2;
const int wshed = 0;
const int init = -1;
const int inqueue = -3;

typedef struct pos{
  size_t i;
  size_t j;
}position;

extern std::vector< std::vector<int> > watershed(std::vector< std::vector<int> > &f_i);
extern void getNeighbours(position current, position SE[], std::vector<std::vector<std::pair<int, bool> > > &output);
#endif  /// WATERSHED_H
