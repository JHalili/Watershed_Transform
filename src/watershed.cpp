#include "watershed.h"
#include <utility>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

bool pairCompare(const pair<int,position>& firstElem, const pair<int, position >& secondElem) {
  return firstElem.first < secondElem.first;
}

vector<vector<int> > watershed(vector<vector<int> > &input){
  // initializing process
  vector<pair<int, position> > helper;
  vector<vector<pair<int, bool> > > output;
  queue<position> myqueue;
  position SE[4];
  uint current_label = 0;
  bool flag = false;

  for(size_t i = 0; i<input.size(); i++){
    vector<pair<int, bool> > a;
    for(size_t j = 0; j< input[i].size(); j++){
      a.push_back(make_pair(init, false));
      position p = {i, j};
      helper.push_back(make_pair(input[i][j], p));
    }
    output.push_back(a);
  }

  // sorting vectors
  sort(helper.begin(), helper.end(), pairCompare);

  vector<pair<int, position> > h_positions;
  for(size_t k=0; k<helper.size(); k++){

    if(h_positions.empty()){
      h_positions.push_back(make_pair(helper[k].first, helper[k].second));
      k++;
      // putting here all the pixels with the value h in the image
      while( k < helper.size() && h_positions[h_positions.size()-1].first == helper[k].first){
        h_positions.push_back(make_pair(helper[k].first, helper[k].second));
        k++;
      }
      k--;

      // go through the same value h_positions
      for(size_t l = 0; l<h_positions.size(); l++){
        //cout << h_positions.back().first << " " << h_positions.back().second.i << "--" << h_positions.back().second.j << " ";
        position current = {h_positions[l].second.i, h_positions[l].second.j};
        output[current.i][current.j].first = mask;
        // finding neighbours
        getNeighbours(current, SE, output);
        for(int m = 0; m<4; m++){
          if(SE[m].i == current.i && SE[m].j == current.j)
            continue;
          if(output[SE[m].i][SE[m].j].first > 0 || output[SE[m].i][SE[m].j].first == wshed){
            output[SE[m].i][SE[m].j].second = true;
            myqueue.push(SE[m]);
          }
        }
      }
    }


    while(!myqueue.empty()){
      position p = myqueue.front();
      myqueue.pop();
      getNeighbours(p, SE, output);
      for(int m=0; m<4; m++){
        if(SE[m].i == p.i && SE[m].j == p.j)
          continue;
        if(output[SE[m].i][SE[m].j].first > 0){
          if(output[SE[m].i][SE[m].j].second || (output[SE[m].i][SE[m].j].first == wshed && flag)){
            output[p.i][p.j].first = output[SE[m].i][SE[m].j].first;
          }
          else if(output[p.i][p.j].first > 0 && output[p.i][p.j] != output[SE[m].i][SE[m].j]){
            output[p.i][p.j].first  =wshed;
            flag = false;
          }
        }
        else if(output[SE[m].i][SE[m].j].first == wshed){
          if(output[p.i][p.j].second){
            output[p.i][p.j].first  =wshed;
            flag = true;
          }else if(output[SE[m].i][SE[m].j].first == mask){
            output[SE[m].i][SE[m].j].second = true;
            myqueue.push(SE[m]);
          }
        }
      }
    }

    // go through the same value h_positions
    while(!h_positions.empty()){

      position p = {h_positions.back().second.i, h_positions.back().second.j};
      h_positions.pop_back();
      if( output[p.i][p.j].first == mask){
        current_label++;
        myqueue.push(p);
        output[p.i][p.j].first = current_label;
        while(!myqueue.empty()){
          position q = myqueue.front();
          myqueue.pop();
          getNeighbours(q, SE, output);
          for(int m=0; m<4; m++){
            if(SE[m].i == q.i && SE[m].j == q.j)
              continue;
            if(output[SE[m].i][SE[m].j].first == mask){
              myqueue.push(SE[m]);
              output[SE[m].i][SE[m].j].first = current_label;
            }
          }
        }
      }
    }
  }

  vector<vector<int> > result;
  for(int i=0; i< output.size(); i++){
    vector<int> a;
    for(int j=0; j< output[i].size(); j++){
      a.push_back(output[i][j].first);
    }
    result.push_back(a);
    a.clear();
  }
  return result;
}

void getNeighbours(position current, position SE[], vector<vector<pair<int, bool> > > &output){
  if (current.i == 0) {
    SE[0] = {current.i, current.j};
  } else {
    SE[0] = {current.i - 1, current.j};
  }
  if (current.j == 0) {
    SE[1] = {current.i, current.j};
  } else {
    SE[1] = {current.i, current.j - 1};
  }
  if (current.i == output.size() - 1) {
    SE[2] = {current.i, current.j};
  } else {
    SE[2] = {current.i + 1, current.j};
  }
  if (current.j == output[current.i].size() - 1) {
    SE[3] = {current.i, current.j};
  } else {
    SE[3] = {current.i, current.j + 1};
  }
}
