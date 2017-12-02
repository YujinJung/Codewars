/*
 * A famous casino is suddenly faced with a sharp decline of their revenues. They decide to offer Texas hold'em also online. Can you help them by writing an algorithm that can rank poker hands?
 * 
 * Task:
 * 
 * Create a poker hand that has a method to compare itself to another poker hand:
 *     Result compare (const PokerHand &player, const PokerHand &opponent);
 * A poker hand has a constructor that accepts a string containing 5 cards:
 *     PokerHand hand ("KS 2H 5C JD TD");
 * The characteristics of the string of cards are:
 * A space is used as card seperator
 * Each card consists of two characters
 * The first character is the value of the card, valid characters are: 
 * 2, 3, 4, 5, 6, 7, 8, 9, T(en), J(ack), Q(ueen), K(ing), A(ce)
 * The second character represents the suit, valid characters are: 
 * S(pades), H(earts), D(iamonds), C(lubs)
 * 
 * The result of your poker hand compare can be one of these 3 options:
 *     enum class Result { Win, Loss, Tie };
 * Apply the Texas Hold'em rules for ranking the cards.
 * There is no ranking for the suits.
 * 
 * Notes:
 * If you finished this kata, you might want to continue with Sortable Poker Hands.
 */

#include <vector>
#include <algorithm>
#include <string>

class ResultScore 
{ 
public:
  const int none = 0;
  const int one = 1; 
  const int two = 2;
  const int triple = 3; 
  const int straight = 4;
  const int flush = 5;
  const int full_house = 6;
  const int four = 7;
  const int straight_flush = 8;
  const int royal_flush = 9;
  
  const int club = 0;
  const int diamond = 1;
  const int heart = 2;
  const int spade = 3;
  
  const int hand = 100 * 100 * 10;
};
// 9 royal flush - AKQJT 같은 무늬
// 8 straight flush - 5개 이어진 같은 무늬 
// 7 four card - 4개 같은 숫자
// 6 full house - 3개 2개 같은 숫자
// 5 flush - 5개 같은 무늬
// 4 straight - 5개 이어지는 숫자
// 3 triple
// 2 two pair
// 1 one pair
// 0 none

class PokerHand {
private:
  std::string pokerString;
  std::vector<std::pair<int, int>> vec;
  ResultScore r;
  int score = 0;
  
public:
  PokerHand (const char* pokerhand) 
  {
    pokerString = pokerhand;
  }
  void calculateScore();
  void vecInit();
  bool isSameSuit();
  int isRoyalFlushStraight();
  int isFlushStraight();
  int isFour();
  int isFullHouse();
  int isFlush();
  int isStraight();
  bool isTripleCalculate(int& ret, int a, int b);
  int isTriple();
  bool isTwoCalculate(int& ret, int a, int b);
  int isTwo();
  int isOne();
  
  const int& getScore () const { return score; }
  const std::vector<std::pair<int, int>>& getVector () const { return vec; }
};

enum class Result { Win, Loss, Tie };

void PokerHand::vecInit()
{
  for(int i = 0; i < 5; i++)
  {
    int suits = 0;
    if(pokerString.at(3*i + 1) == 'S') 
      suits = r.spade;
    else if(pokerString.at(3*i + 1) == 'H') 
      suits = r.heart;
    else if(pokerString.at(3*i + 1) == 'D') 
      suits = r.diamond;
    else 
      suits = r.club;
    
    if(pokerString.at(3*i) >= 48 && pokerString.at(3*i) <= 57)
      vec.push_back(std::make_pair(pokerString.at(3*i) - 48, suits));
    else if(pokerString.at(3*i) == 'T')
      vec.push_back(std::make_pair(10, suits));
    else if(pokerString.at(3*i) == 'J')
      vec.push_back(std::make_pair(11, suits));
    else if(pokerString.at(3*i) == 'Q')
      vec.push_back(std::make_pair(12, suits));
    else if(pokerString.at(3*i) == 'K')
      vec.push_back(std::make_pair(13, suits));
    else if(pokerString.at(3*i) == 'A')
      vec.push_back(std::make_pair(14, suits));
  }
}

bool PokerHand::isSameSuit()
{
  // same the suit
  int init = vec.at(0).second;
  int i = 0;
  for(i = 1; i < 5; i++)
    if(vec.at(i).second != init) break;
  
  if(i == 5) return true;
  return false;
}

int PokerHand::isRoyalFlushStraight()
{
  if(isSameSuit())
  {
    if(vec.at(4).first - vec.at(0).first == 4)
    {
      if(vec.at(0).first == 10)
        return r.royal_flush * r.hand;
      return r.straight_flush * r.hand + vec.at(0).first * 10;
    }
  }
  return 0;
}

int PokerHand::isFlushStraight()
{
  if(isSameSuit())
  {
    if(vec.at(4).first - vec.at(0).first == 4)
      return r.straight_flush * r.hand + vec.at(0).first * 10;
    
    if(vec.at(0).first == 2 && vec.at(4).first == 14)
      if(vec.at(1).first == 3 && vec.at(2).first == 4 && vec.at(3).first == 5)
        return r.straight_flush * r.hand + 1 * 10;
  }
  return 0;
}

int PokerHand::isFour()
{
  int ret = 0;
  
  if(vec.at(0).first == vec.at(3).first)
    return r.four * r.hand + vec.at(2).first * 1000 + vec.at(4).first * 10;
  else if(vec.at(1).first == vec.at(4).first)
    return r.four * r.hand + vec.at(2).first * 1000 + vec.at(0).first * 10;
    
  return 0;
}

int PokerHand::isFullHouse()
{
  if((vec.at(0).first == vec.at(2).first) && (vec.at(3).first == vec.at(4).first))
    return r.full_house * r.hand + vec.at(0).first * 1000 + vec.at(4).first * 10;
  if((vec.at(0).first == vec.at(1).first) && (vec.at(2).first == vec.at(4).first))
    return r.full_house * r.hand + vec.at(4).first * 1000 + vec.at(0).first * 10;
  return 0;
}

int PokerHand::isFlush()
{
  if(isSameSuit())
    return r.flush * r.hand; 
  return 0;
}

int PokerHand::isStraight()
{
  // tjqka
  // jqka2 / qka23 / ka234 / a2345  
  // 2jqka / 23qka / 234ka / 2345a
  if(vec.at(0).first == 2 && vec.at(4).first == 14)
    if(vec.at(1).first == 3 && vec.at(2).first == 4 && vec.at(3).first == 5)
      return r.straight * r.hand + 1 * 10;
      
  int i = 1;
  while(i < 5)
  {
    if(vec.at(i).first - vec.at(i - 1).first != 1) return 0;
    i++;
  }
  return r.straight * r.hand + vec.at(0).first * 10;
}

bool PokerHand::isTripleCalculate(int& ret, int a, int b)
{
  if(vec.at(a).first == vec.at(b).first)
  {
    ret = r.triple * r.hand + vec.at(b).first * 10; 
    vec.erase(vec.begin() + a, vec.begin() + b);
    return true;
  }
  return false;
}
int PokerHand::isTriple()
{
  int ret = 0;
  
  // no while for readability
  // aaabc abbbc abccc
  if(isTripleCalculate(ret, 0, 2)) 
      return ret;
  if(isTripleCalculate(ret, 1, 3)) 
      return ret;
  if(isTripleCalculate(ret, 2, 4)) 
      return ret;
    
  return 0;
}

bool PokerHand::isTwoCalculate(int& ret, int a, int b)
{
  if((vec.at(a).first == vec.at(a + 1).first) && (vec.at(b).first == vec.at(b + 1).first))
  {
    if(vec.at(a).first > vec.at(b).first)
      ret = r.two * r.hand + vec.at(a).first * 1000 + vec.at(b).first * 10;
    else
      ret = r.two * r.hand + vec.at(b).first * 1000 + vec.at(a).first * 10;
      
    vec.erase(vec.begin() + a, vec.begin() + a + 1);
    vec.erase(vec.begin() + b, vec.begin() + b + 1);
    return true;
  }
  return false;
}
int PokerHand::isTwo()
{
  int ret = 0;
  
  // no while for readability
  // aabbc / aabcc / abbcc
  if(isTwoCalculate(ret, 0, 2))
    return ret;
  if(isTwoCalculate(ret, 0, 3))
    return ret;
  if(isTwoCalculate(ret, 1, 3))
    return ret;
  
  return 0;
}

int PokerHand::isOne()
{
  int ret = 0;
  
  for(int i = 0; i < 5; i++)
  {
    for(int j = i + 1; j < 5; j++)
    {
      if(vec.at(i).first == vec.at(j).first)
      {
        ret = r.one * r.hand + vec.at(i).first * 10;
        vec.erase(vec.begin() + i, vec.begin() + j);
        return ret;
      }
    }
  }
  
  return 0;
}

void PokerHand::calculateScore()
{
  // 01 34 67 90 23
  vecInit();
  std::sort(vec.begin(), vec.end());
  
  // royal_flush_straight
  score = isRoyalFlushStraight();
  if(score > 0) return;
  
  // flush_straight
  score = isFlushStraight();
  if(score > 0) return;
  
  // four card
  score = isFour();
  if(score > 0) return;
  
  // full house
  // aaabb aabbb
  score = isFullHouse();
  if(score > 0) return;
    
  // flush
  score = isFlush();
  if(score > 0) return;
  
  // straight
  score = isStraight();
  if(score > 0) return;
      
  // 11 12 13 14 -> -2 -1 0 
  // triple
  score = isTriple();
  if(score > 0) return;
  
  // two pair
  score = isTwo();
  if(score > 0) return;
  
  // one pair
  score = isOne();
  if(score > 0) return;
}

Result compare (const PokerHand &playerInput, const PokerHand &opponentInput) 
{
  PokerHand player = playerInput;
  PokerHand opponent = opponentInput;
  player.calculateScore();
  opponent.calculateScore();
  
  if(player.getScore() != opponent.getScore())
    return player.getScore() > opponent.getScore() ? Result::Win : Result::Loss;
 
  for(int i = player.getVector().size() - 1; i >= 0; i--)
  {
    if(player.getVector().at(i).first != opponent.getVector().at(i).first)
      return player.getVector().at(i).first > opponent.getVector().at(i).first ? Result::Win : Result::Loss;
  }
  
  return Result::Tie;
}