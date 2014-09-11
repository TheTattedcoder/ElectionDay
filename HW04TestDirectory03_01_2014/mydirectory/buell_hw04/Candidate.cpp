#include "Candidate.h"

Candidate::Candidate()
{
	  isAWinner = false;
	  isInContention = false;
	  weightedVotes = 0;
	  
}

Candidate::~Candidate()
{
}

string Candidate::toString() const
{
  string s = "";
  if( isInContention == true)
  {
  	s += "isInContention = true";
  }
  else
  {
  	s += "isInContention = false";
  }
  if(isAWinner == true)
  {
  	s += "isAWinner = true";
  }
  else
  {
  	s += "isAWinner = false";
  }
  return s;
} // string Candidate::toString() const
