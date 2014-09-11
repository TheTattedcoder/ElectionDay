#ifndef CANDIDATE_H
#define CANDIDATE_H

#include "../../Utilities/Utils.h"

class Candidate
{
public:
  Candidate();
  virtual ~Candidate();

  string toString() const;

  bool isAWinner;
  bool isInContention;
  int weightedVotes;
  string name;

private:
};

#endif // CANDIDATE_H
