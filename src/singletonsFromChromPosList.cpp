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
#include <boost/algorithm/string.hpp>
#include <stdlib.h>



namespace po = boost::program_options;


void poslistreducetosingletons(std::vector<int> &poslist){
  std::vector<int>::iterator iter;

  if(poslist.size() <= 1)
    return;

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
        poslist.erase(iter - (lensequential + 1), iter - 1);

        //reset sequential length tracker
        lensequential = 1;
      }

    }//end if/else over sequential check

    lastval = currval;
  }//end loop

  if(lensequential > 1){ //did we end on a sequence?
    poslist.erase(iter - (lensequential + 1), iter); //iter should be poslist.end() here
  }
}


std::map<std::string,std::vector<int> > read_file(std::ifstream chromSizes){
  std::map<std::string,std::vector<int> > data = new std::map<std::string,std::vector<int> >();
  std::string line;

  while(std::getline(chromSizes,line)){
    if(line.length() <= 1 || line[0] == '#')
      continue; //skip comments or blank lines
    std::stringstream ss(line);
    std::string chrom;
    int pos;

    ss >> chrom >> pos;

    std::vector<int> poslst = data.find(chrom);
    //see if it exists, or isn't in the map yet
    if(poslst == data.end()){
      poslst = new std::vector<int>();
      data.insert(std::make_pair(chrom, poslst));
    }
    poslst.push_back(pos);
  }
  return(data);
}

int main(int ac, char* av[]){
  /**
   * Set defaults and process arguments
   */
  int edge_len;
  std::stringstream usage;

  usage << "Options (some required)";

  po::options_description desc(usage.str());


  desc.add_options()
      ("help", "produce help message")
      ("chrom_pos_lst", po::value<std::string>(),"File of 'chrom pos' one per line, (REQUIRED).")
  ;


  po::variables_map vm;
  po::store(po::parse_command_line(ac, av, desc), vm);
  po::notify(vm);

  if (vm.count("help") || !vm.count("chrom_pos_lst")) {
      std::cerr << desc << std::endl;
      return(1);
  }



  /**
   * Loop over input file, and write out
   */

  std::ifstream chromSizes(vm["chrom_sizes"].as<std::string>().c_str());
  std::map<std::string,std::vector<int> > chrom_to_poslst = read_file(chromSizes);

  std::map<std::string,std::vector<int> >::iterator iter;

  for(iter=chrom_to_poslst.begin(); iter != chrom_to_poslst.end(); ++iter){
    std::vector<int>poslst = iter->second; //the value in this key->val pair
    std::string chrom = iter->first;
    //get rid of everything sequential in place
    poslistreducetosingletons(poslst);

    std::vector<int>::iterator positer;
    //write out the remaining singleton positions
    for(positer = poslst.begin(); positer != poslst.end(); ++positer){
      std::cout << chrom << *positer << std::endl;
    }



  }

  //free up the map
  delete chrom_to_poslst;


}
