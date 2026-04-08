#include <iostream>
#include <vector> //用於動態陣列 
#include <algorithm> //用於 std shuffle
#include <random> //用於產生隨機數種子 
#include <string> //用於處理字串

using namespace std;

// 表示單張撲克牌的類別
class Card {
 public:
 string colors; //儲存撲克牌的花色
 string rank; //儲存撲克牌的數值
 Card(string s, string r) : colors(s), rank(r) {} //建立 constructor來初始化物件,當 Card 物件建立時,它會自動執行這個函式,並把 s 和 r 的值存入 colors 和 rank
 void display() const { //顯示撲克牌的資訊
  cout << rank << " of " << colors << endl;
 }
};

// 實作 Stack
class Stack {
 private:
 //使用 vector 作為存放 card 的底層容器 
 vector<Card> stack; //表示 stack 是一個能存放 Card 類別物件的 vector

 public: 
 //push:將一張牌壓入堆疊的最上方 
 void push(const Card& card) {
  stack.push_back(card); //在 vector 的最後面加入元素，模擬元素在堆疊的最頂端 
 }
 
 //pop:從堆疊的最上方取出一張牌 
 Card pop() {
  Card topCard = stack.back(); //取得 vector 最後一個元素(堆疊頂端的牌) 
  stack.pop_back(); //從 vector 中移除該元素 
  return topCard; //回傳被取出的這張牌 
 }
 
 //isEmpty:檢查堆疊是否為空 
 bool isEmpty() const {  
  return stack.empty(); //若 vector 的長度為0，代表堆疊是空的
 }
};

// 代表一副撲克牌的類別
class Deck {
 private:
 vector<Card> cards; // 存放未洗牌的撲克牌
 Stack shuffledDeck; // 存放洗過的牌,用實作的 stack 來管理
 
 public:
 Deck() { //建立 constructor 來初始化物件
  string colors[] = { "Hearts", "Diamonds", "Clubs", "Spades" };
  //儲存撲克牌的花色
  string ranks[] = { "2", "3", "4", "5", "6", "7", "8", "9","10", "J", "Q", "K", "A" }; //儲存撲克牌的數值
 
  //利用迴圈將 52 張牌加入 cards 這個 vector 裡面
  for (int i = 0; i < 4; i++) { // 四種花色
   for (int j = 0; j < 13; j++) { // 13 種點數
    cards.push_back(Card(colors[i], ranks[j]));
   }
  } 
 } 
 
 //洗牌(Hint:使用 shuffle 函數)
 void shuffleDeck() {
  random_device rd; //取得硬體的隨機數種子 
  mt19937 g(rd()); //使用演算法產生隨機數 
  shuffle(cards.begin(), cards.end(), g); //使用 shuffle 函式打亂 cards vector 的順序 

  for(int i = 0; i < cards.size(); i++) { //將洗亂的牌送進 Stack 裡面 
   shuffledDeck.push(cards[i]);
  }
 }
 //發牌，從 Stack 取出所有牌 
 void drawAllCards() {
  while(!shuffledDeck.isEmpty()){ //一直抽牌直到 Stack 裡面沒有牌 
   Card c=shuffledDeck.pop();
   c.display(); //將抽到的牌顯示出來 
  }
 }
};


int main() {
 Deck deck; //建立 deck 產生 52 張撲克牌
 deck.shuffleDeck(); //進行洗牌並放入堆疊
 cout << "Shuffled deck:" << endl;
 deck.drawAllCards(); //依序取出堆疊內的牌並顯示
 return 0;
}
