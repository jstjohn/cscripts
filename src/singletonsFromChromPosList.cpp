/**
 * singletonsFromChromPosList
 *  Created on: Mar 30, 2012
 *    Author: jstjohn
 */

#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <boost/program_options.hpp>
#include <stdlib.h>

using namespace std;

namespace po = boost::program_options;


vector<int> poslistreducetosingletons(vector<int> &poslist){
  vector<int>::iterator iter;
  vector<int> result;
  if(poslist.size() == 1){
    result.push_back(poslist[0]);
    return(result);
  }else if(poslist.size() == 0){
    return(result);
  }
  int lensequential = 1;
  int lastval = poslist[0];
  //start at the second position and go to the end
  for(iter=poslist.begin()+1; iter != poslist.end(); ++iter){
    int currval = *iter; //dereference this pointer
    if( abs(currval-lastval) == 1){
      lensequential++;
    }else{
      // we just saw a sequential list of some length
      // ending at the previous position
      if(lensequential > 1){
        //reset sequential length tracker
        lensequential = 1;
      }else{
        //the previous position was a singleton
        result.push_back(lastval);
      }

    }//end if/else over sequential check

    lastval = currval;
  }//end loop

  if(lensequential == 1){ //did we end on a sequence?
    result.push_back(lastval);
  }

  return(result);
}


void read_file_print_singles(ifstream &chromSizes){
  string line;
  string lastChrom = "nOtA_Ch*roM";
  vector<int> last_chrom_poslst;
  while(getline(chromSizes,line)){
    if(line.length() <= 1 || line[0] == '#')
      continue; //skip comments or blank lines
    stringstream ss(line);
    string chrom;
    int pos;

    ss >> chrom >> pos;


    if(chrom != lastChrom){
      if(last_chrom_poslst.size() > 0 ){
        vector<int>reduceposlist = poslistreducetosingletons(last_chrom_poslst);
        vector<int>::iterator positer;

        //write out the remaining singleton positions
        for(positer = reduceposlist.begin(); positer != reduceposlist.end(); ++positer){
          cout << lastChrom << "\t" << *positer << endl;
        }
      }
      //clear it up and set the last chrom to this one
      last_chrom_poslst.clear();
      lastChrom = chrom;
    }

    last_chrom_poslst.push_back(pos);
  }


  //one last time if there was anything else
  if(last_chrom_poslst.size() > 0){
    vector<int>reduceposlist = poslistreducetosingletons(last_chrom_poslst);
    vector<int>::iterator positer;

    //write out the remaining singleton positions
    for(positer = reduceposlist.begin(); positer != reduceposlist.end(); ++positer){
      cout << lastChrom << "\t" << *positer << endl;
    }
  }
}


int main(int ac, char* av[]){
  /**
   * Set defaults and process arguments
   */
  int edge_len;
  stringstream usage;

  usage << "Options (some required)";

  po::options_description desc(usage.str());


  desc.add_options()
      ("help", "produce help message")
      ("chrom_pos_lst", po::value<string>(),"File of 'chrom pos' one per line, (REQUIRED).")
  ;


  po::variables_map vm;
  po::store(po::parse_command_line(ac, av, desc), vm);
  po::notify(vm);

  if (vm.count("help") || !vm.count("chrom_pos_lst")) {
      cerr << desc << endl;
      return(1);
  }


  ifstream chromSizes(vm["chrom_pos_lst"].as<string>().c_str());

  read_file_print_singles(chromSizes);



}
