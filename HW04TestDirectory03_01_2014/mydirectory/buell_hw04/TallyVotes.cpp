#include "TallyVotes.h"

TallyVotes::TallyVotes()
{
}

TallyVotes::~TallyVotes()
{
}
/******************************************************************************
Within this function the Candidates who receive the biggest rank is to be 
eliminated from the voting pole. Here we find the maximum and minimum values
by assigning who ever has the lowest ranking, that would be the maximum value,
and whoever has the highest ranking, that would be the minimum value. The first
two for loops iterate through the map to find the minimum and maximum values
(i.e. the best and worst value). The last for loop assigns whoever the loser(s)
are and eliminates them from the poles.
******************************************************************************/
string TallyVotes::eliminateLosers()
{
 int minValue = 0;
 int maxValue = 0;
 string nameOfLoser = "";
  map<string,Candidate>::iterator iter;
 for(iter = theCandidates.begin(); iter != theCandidates.end(); iter++)
 {
 	if(iter->second.weightedVotes > maxValue)
	{
		maxValue = iter->second.weightedVotes;
	}
 }
 minValue = maxValue;
 for(iter = theCandidates.begin(); iter != theCandidates.end(); iter++)
 {
 	if(iter->second.weightedVotes < minValue)
	{
		minValue = iter->second.weightedVotes;
	}
 }
 for(iter = theCandidates.begin(); iter != theCandidates.end(); iter++)
 {
 	if(iter->second.weightedVotes ==  minValue)
	{
		iter->second.isInContention = false;
	}
	if(iter->second.weightedVotes == maxValue)
	{
		iter->second.isInContention = true;
		iter->second.isAWinner = true;
	}
 }
 nameOfLoser += "Loser(s)" + iter->second.toString() + "\n";
  return nameOfLoser;
} // string TallyVotes::eliminateLosers()
/******************************************************************************
  In the getWinner function we are basically iterating through the map of
  candidates to see if we have any winners. If we have any winners then we
  will set the boolean isWAWinner in the Candidate Class and set it to true.
 Finally the result will be printed to the toString function within the
 Candidate Class.
******************************************************************************/
string TallyVotes::getWinner()
{
  string s = "";
  map<string,Candidate>::iterator iter;
  for(iter = theCandidates.begin(); iter != theCandidates.end(); iter++)
  {
  	if(iter->second.isAWinner == true)
	{
		s += iter->second.toString();
	}
  }

  return s;
} // string TallyVotes::getWinner() const
/******************************************************************************
  In this function we use a scanner to read in the votes within the text file.
  As usual we use an outer for loop to get the rows and a nested for loop to
  get the columns. As the function goes through the nested for loop, we call an
  instance of the class to read the name of the candidates and no more are left.
  then we push it back within the inner vector and assign the iterator from the
  map to find the temp string(i.e. name of the candidates). Still within the
  inner for loop an if statement is being started saying that if the iterator
  is equal to the end of the map then the accessing of the temp string out of
  the map is assigned to the instance of the Candidate class and the weighted
 vote integer variable is concatenated and increments the column positon of the
 vector by one.-
******************************************************************************/
void TallyVotes::initialize(Scanner& inStream)
{

  
   string temp;
   Candidate tempName;
   map<string, Candidate>::iterator ron;
   numberOfCandidates = inStream.nextInt();
   numberOfVotes = inStream.nextInt();
   for(int i = 0; i < numberOfVotes; i++)
   {
   		vector<string> tempVec;
   		for(int j = 0; j < numberOfCandidates; j++)
		{
			temp = inStream.next();
			tempVec.push_back(temp);
			ron = theCandidates.find(temp);
			
			if(ron == theCandidates.end())
			{
                theCandidates[temp] = tempName; 
               tempName.weightedVotes += (j+1);
			   
		    } 
			else
			{
				ron->second.weightedVotes += (j+1);
			}
   	 theVotes.push_back(tempVec);
    }
   }
} // void TallyVotes::initialize(Scanner& inStream)
void TallyVotes::tallyVotes(ofstream& outStream)
{

 // while(!weHaveAWinner())
  
  	for(int i = 0; i < numberOfVotes; i++)
	{
		vector<string> newVoteResult = newVoteA(theVotes[i]); 
		for(int j = 0; j <= newVoteResult.size(); j++)
		{
			 string name = theVotes[i][j];
			 theCandidates[name].weightedVotes += (j+1);
			 
		}
	}
	eliminateLosers();
  
} // void TallyVotes::tallyVotes(ofstream& outStream)
 vector<string> TallyVotes::newVoteA(vector<string> recentVotes)
 {
  	vector<string> tempVect;
	string n = "";
	for(int i = 0; i < numberOfVotes; i++)
	{
		string n = tempVect[i];
		if(theCandidates[n].isInContention == true)
		{
			tempVect.push_back(n);
		}
	}
	return tempVect;
 }
bool TallyVotes::weHaveAWinner()
{
  int maxValue = 0;
  int minValue = 0;
  bool thereIsAWinner = false;
  map<string,Candidate>::iterator iter;
  for(iter = theCandidates.begin(); iter != theCandidates.end(); iter++)
 {
 	if(iter->second.weightedVotes > maxValue)
	{
		maxValue = iter->second.weightedVotes;
	}
 }
 minValue = maxValue;
 for(iter = theCandidates.begin(); iter !=theCandidates.end(); iter++)
 {
 	if(iter->second.weightedVotes < minValue)
	{
		minValue = iter->second.weightedVotes;
	}
 }
 if(minValue == maxValue)
 {
 	thereIsAWinner = true;
 }
 else
 {
 	thereIsAWinner = false;
 }
  

  return thereIsAWinner;
} // string TallyVotes::weHaveAWinner()

string TallyVotes::toString() const
{
  string s = "";
  
  s += toStringCandidates() + "\n" + toStringVotes();
  
  return s;
} // string TallyVotes::toString() const

string TallyVotes::toStringCandidates() const
{
  string s = "";
  Candidate cand;
   map<string,Candidate>::const_iterator it;
  for(it = theCandidates.begin(); 
       it != theCandidates.end(); it++)
  {
	cand = it->second;
 	if(cand.isAWinner == true)
	{
            s += cand.name;
	    s += cand.toString();
        }
  }
  return s;
} // string TallyVotes::toStringCandidates()

string TallyVotes::toStringVotes() const
{
  string s = "";
  for(int i = 0; i < numberOfVotes; i++ )
  {
  	for(int j = 0; j < numberOfCandidates; j++)
	{
		s += theVotes[i][j] + " ";
		s += "\n";
	}
	
  }
  return s;
} // string TallyVotes::toStringCandidates()
