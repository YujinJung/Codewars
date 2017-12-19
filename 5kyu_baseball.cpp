#include <deque>
#include <string>

using namespace std;

class ScoreCard 
{
private:
  int bats; // Home : True / Away : False
  int outs;
  int score[2];
  deque<int> playerPosition;
public:
  ScoreCard() : bats(1), outs(0), playerPosition(4, 0), score{0,0}
  {  }
  /*
  * A public method accepting the result of an at-bat
  * @param {string} entry - The result of an at-bat 
  * Acceptable values: ('single', 'double', 'triple', 'homerun' or 'out') 
  */
  void addEntry(string entry);
  /*
  * A public method returning the current score
  * Format: "Home: [HOME_SCORE] Away: [AWAY_SCORE]"
  */
  string getScore();
};

void ScoreCard::addEntry(string entry)
{
  int run = 0;
  
  cout<<entry<<endl;
  cout<<playerPosition.at(0)<<playerPosition.at(1)<<playerPosition.at(2)<<playerPosition.at(3)<<endl;
  if(entry.compare("out") == 0)
  {
    outs++;
    if(outs == 3)
    {
      outs = 0;
      bats = -1 * (bats - 1);
      playerPosition.clear();
      playerPosition.push_back(0);
      playerPosition.push_back(0);
      playerPosition.push_back(0);
      playerPosition.push_back(0);
    }
    return;
  }
  else if(entry.compare("single") == 0)
    run = 1;
  else if(entry.compare("double") == 0)
    run = 2;
  else if(entry.compare("triple") == 0)
    run = 3;
  else if(entry.compare("homerun") == 0)
  {
    for(int i = 0; i < 4; i++)
      if(playerPosition.at(i) == 1)
        score[bats]++;
    score[bats]++;
    playerPosition.clear();
    playerPosition.push_back(0);
    playerPosition.push_back(0);
    playerPosition.push_back(0);
    playerPosition.push_back(0);
    return;
  }
  
  playerPosition.push_back(1);
  playerPosition.pop_front();
  score[bats] += playerPosition.front();
  playerPosition.front() = 0;
  
  for(int i = 1; i < run; i++)
  {
    playerPosition.push_back(0);
    playerPosition.pop_front();
    score[bats] += playerPosition.front();
    playerPosition.front() = 0;
  }
  cout<<endl;
}

string ScoreCard::getScore()
{
  string result;
  result = "Home: " + to_string(score[0]) + " Away: " + to_string(score[1]);
  cout<<result<<endl;
  return result;
}