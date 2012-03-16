#include <iostream>
#include <sstream>
#include <fstream>
#include <boost/program_options.hpp>
#include <boost/algorithm/string.hpp>
#include <stdlib.h>



namespace po = boost::program_options;



int main(int ac, char* av[]){
  /**
   * Set defaults and process arguments
   */
  int edge_len = 4000;
  std::stringstream usage;

  usage << "Usage: " << av[0] << " chromSizes.lst (a file of 'chrom size' one per line)" << std::endl;
  usage << "Options";

  po::options_description desc(usage.str());
  std::stringstream edge_len_desc;
  edge_len_desc << "Length from edges to include in bed file (default: " << edge_len << ")";
  desc.add_options()
      ("help", "produce help message")
      ("edge_len", po::value<int>(), edge_len_desc.str().c_str())
  ;


  po::variables_map vm;
  po::store(po::parse_command_line(ac, av, desc), vm);
  po::notify(vm);

  if (vm.count("help") || ac < 2) {
      std::cerr << desc << std::endl;
      return 1;
  }

  if (vm.count("edge_len")) {
      edge_len = vm["edge_len"].as<int>();
  } else {
      std::cerr << "edge_len not set, using default value of "<< edge_len <<" ." << std::endl;
  }


  /**
   * Loop over input file, and write out
   */

  std::ifstream chromSizes(av[1]);
  std::string line;

  while(std::getline(chromSizes,line)){
    if(line.length() == 0 || line[0] == '#')
      continue; //skip comments or blank lines
    std::vector<std::string> strs;
    boost::split(strs, line, boost::is_any_of("\t "));

    std::string chrom = strs[0];
    int len = atoi(strs[1].c_str());

    if(len <= edge_len * 2){
      std::cout << chrom << '\t' << 0 << '\t' << len << std::endl;
    }else{
      std::cout << chrom << '\t' << 0 << '\t' << edge_len << std::endl;
      std::cout << chrom << '\t' << len - edge_len << '\t' << edge_len << std::endl;
    }
  }

}
