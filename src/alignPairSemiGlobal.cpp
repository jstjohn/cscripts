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

#include <seqan/basic.h>
#include <seqan/sequence.h>
#include <seqan/stream.h>
#include <seqan/consensus.h>

using namespace std;
using namespace seqan;

namespace po = boost::program_options;

map<CharString,Dna5String> readFastaStream(fstream &stream){
  RecordReader<fstream, SinglePass<> > reader(stream);
  CharString id;
  Dna5String seq;
  map<CharString,Dna5String> seqHash;
  // Read FASTA file and output "$id\t$seq".
  while (!atEnd(reader))
  {
    if (readRecord(id, seq, reader, Fasta()) != 0)
    {
      cerr << "ERROR reading FASTA." << endl;
    }

    seqHash[id] = seq;
  }
  return(seqHash);
}

pair<Dna5String,Dna5String> getPairFromFasta(fstream &stream, string id1, string id2){
  RecordReader<fstream, SinglePass<> > reader(stream);
  CharString id;
  Dna5String seq;
  Dna5String seq1;
  Dna5String seq2;
  while(!atEnd(reader))
  {
    if (readRecord(id, seq, reader, Fasta()) != 0)
    {
      cerr << "ERROR reading FASTA." << endl;
    }
    if(id == id1){
      seq1 = seq;
    }
    if(id == id2){
      seq2 = seq;
    }
  }
  return(pair<Dna5String,Dna5String>(seq1,seq2));
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
      ("fasta", po::value<string>(),"Fasta file with at least the two records, (REQUIRED).")
      ("sid1", po::value<string>(),"Id of the first record to align in file, (REQUIRED).")
      ("sid2", po::value<string>(),"Id of the second record to align in file, (REQUIRED).")
      ("reverse", "Search on the reverse string?")
      //("outAln", po::value<string>(),"Outfile name to write optional alignment.")
      //("out", po::value<string>(),"Outfile name to write consensus, (REQUIRED).")
      ;


  po::variables_map vm;
  po::store(po::parse_command_line(ac, av, desc), vm);
  po::notify(vm);

  if (vm.count("help") || !vm.count("fasta") || /*!vm.count("out") ||*/ !vm.count("sid1") || !vm.count("sid2")) {
      cerr << desc << endl;
      return(1);
  }


  fstream fastaStream(vm["fasta"].as<string>().c_str(), ios::binary | ios::in);

  if(!fastaStream.good()){
    cerr << "Fasta file cannot be read." << endl;
    cerr << desc << endl;
    return(1);
  }

  //map<CharString,Dna5String> records = readFastaStream(fastaStream);

  pair<Dna5String,Dna5String> seq1_2 = getPairFromFasta(fastaStream, vm["sid1"].as<string>(), vm["sid2"].as<string>());


  typedef StringSet<Dna5String,Dependent<> > TDepStringSet;
  typedef Graph<Alignment<TDepStringSet> > TAlignGraph;

  StringSet<Dna5String> seqs;
  appendValue(seqs, seq1_2.first);

  if(vm.count("reverse")){
    reverseComplement(seq1_2.second);
  }

  appendValue(seqs, seq1_2.second);

  TAlignGraph alignG(seqs);
  AlignConfig<true,true,true,true> aconfig; //no end-gap penalties
  // Score(TValue _match, TValue _mismatch, TValue _gap_extend, TValue _gap_open)
  int score = globalAlignment(alignG, Score<int>(1,-2,-1,-2), aconfig, BandedGotoh());

  cout << alignG << endl;





}
