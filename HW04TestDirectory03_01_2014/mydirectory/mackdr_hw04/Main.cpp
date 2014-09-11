#include "Main.h"

/****************************************************************
 * Main program for doing ranked choice voting.
 *
 * Author/copyright:  Duncan Buell. All rights reserved.
 * Date: 21 February 2014
 *
**/

static const string TAG = "Main: ";

int main(int argc, char *argv[])
{
  string timeCallOutput = "";
  string inStreamName = "";
  string logStreamName = "";
  string outStreamName = "";
  ofstream outStream;
  Scanner inStream;
  TallyVotes tallyVotes;

  // check arguments and create the filenames
  Utils::CheckArgs(3, argc, argv, "infilename outfilename logfilename");
  inStreamName = static_cast<string>(argv[1]);
  outStreamName = static_cast<string>(argv[2]);
  logStreamName = static_cast<string>(argv[3]);

  // open the output file and the log file
  Utils::FileOpen(outStream, outStreamName);
  Utils::LogFileOpen(logStreamName);

  // announce our presence and start the timer
  timeCallOutput = Utils::timecall("beginning");
  Utils::logStream << timeCallOutput;
  Utils::logStream << TAG << "Beginning execution" << endl;
  Utils::logStream.flush();

  Utils::logStream << TAG << "infile  '" << inStreamName << "'" << endl;
  Utils::logStream << TAG << "outfile '" << outStreamName << "'" << endl;
  Utils::logStream << TAG << "logfile '" << logStreamName << "'" << endl;

  // open the input file
  inStream.openFile(inStreamName);

  // initialize the tally and read the votes
  tallyVotes.initialize(inStream);
  outStream << TAG << "RAW DATA" << endl << tallyVotes.toString() << endl;

  // now do the actual tally
  outStream << TAG << "TALLY THE VOTES " << endl;
  tallyVotes.tallyVotes(outStream);

  // and report the result
  outStream << TAG << "THE WINNER IS:\n" << tallyVotes.getWinner() << endl;

  // let the world know we're done, close files, stop timer, finish
  outStream.close();
  Utils::logStream << TAG << "Ending execution" << endl;
  timeCallOutput = Utils::timecall("ending");
  Utils::logStream << timeCallOutput;
  Utils::logStream.flush();

  Utils::FileClose(Utils::logStream);

  return 0;
}
