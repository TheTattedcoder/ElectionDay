ElectionDay
This program is to tally votes based on a ranked choice voting
system. This is used in Australia and has been experimented with in thd
United States.
RCV works as follows. If there are ve candidates for an election, then
each voter has to rank all ve candidates in order, similar to basketball or
football rankings. Candidates ranked rst then get a weighted vote of 1,
candidates ranked second get a weighted vote of 1, and so forth. This is the
way that the college sports rankings are done, but the sports rankings quit
there.
Read RCV is somewhat dierent, as mentioned below.
Your code should run through the votes and compute a weighted vote.
The candidate (or candidates) with the least number of weighted votes is 
then eliminated from contention. All candidates receiving rankings below
the removed candidates are shifted up in the ranking, and the weighted total
is recomputed. This process continues until there is one candidate left, who
is the winner, or until all candidates remaining in contention have the same
number of weighted votes. (In real RCV, there would then be some sort of
tiebreaking decision.)
The heart of this program is not the computation or the actual data
structure that is used. The heart of this program is the logic of how to do
this eciently and cleanly without too much repeated code.
You might also note that this isn't just a voting scheme for elections.
There's a great book by Langville and Meyer, Who's Number One?, that
goes through the math and the computation for ranking. Any sport without
a playo system is the obvious example of when ranking takes place, but this
kind of logic is applicable in any situation in which there are more than two
\candidates". In a ranking
A B C
B C A
C A B
each of the three candidates gets six weighted votes, and we have a tie.
===========

C++ Programming
