// Min Heap 程式 
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <random> // 引入隨機數標頭檔
#include <ctime>  // 引入時間標頭檔以便初始化隨機種子
using namespace std;

// 從文件中讀取數據並存入向量
vector<int> readFromFile(const string& filename) {
 vector<int> arr;
 ifstream file(filename);

 if (!file) {
  cerr << "Error opening file: " << filename << endl;
  return arr;
 }

 string line;
 while (getline(file, line)) { // 持續讀取整行內容
  stringstream ss(line);    // 創建字符串流
  string value;
  while (getline(ss, value, ',')) { // 用逗號分隔值
   try {
    arr.push_back(stoi(value)); // 將字符串轉換為整數並存入向量
   }
   catch (exception& e) {
    cerr << "Invalid number format in file: " << value << endl;
   }
  }
 }

 file.close();
 return arr;
}

class MinHeap {
public:
 vector<int> heap; // 儲存Min Heap的元素

 // 建立Min Heap
 void buildMinHeap(vector<int>& arr) {  //建立Min Heap
  heap = arr;

  for (int i = (heap.size() / 2) - 1; i >= 0; i--) { // 從最後一個非葉子節點開始向上執行Min Heap
   heapify(i);
  }
 }

 void heapify(int i) {// 堆化函式（確保以 i 為根的子樹符合Min Heap性質）
  int smallest = i;          // 假設當前節點是最小的
  int left = 2 * i + 1;     // 左子節點索引
  int right = 2 * i + 2;    // 右子節點索引

  // if判斷式，檢查左子節點是否為有效範圍且比當前節點(父節點)小
  // 如果判斷式成立，把smallest設為left
  // 第一步，檢查左子節點
  // left < heap.size()，透過邊界檢查，來確保計算出來的左子節點索引沒有超出陣列的有效範圍
  // heap[left] < heap[smallest]，比較左子節點的值是否小於目前記錄的最小值(父節點) 
  // 若兩者皆成立，代表左子節點小於父節點，違反 Min Heap 性質 
  if (left < heap.size() && heap[left] < heap[smallest]) {
   smallest = left; // 將最小值指標 smallest 轉向左子節點的索引位置
  }

  // if判斷式，檢查右子節點是否為有效範圍且比當前節點(父節點)小
  // 如果判斷式成立，把smallest設為right
  // 第二步，檢查右子節點
  // right < heap.size()，透過邊界檢查，來確保計算出來的右子節點索引沒有超出陣列的有效範圍 
  // heap[right] < heap[smallest]，比較右子節點的值是否小於目前為止的最小值
  // 若兩者皆成立，代表右子節點是三者之中的最小值 
  if (right < heap.size() && heap[right] < heap[smallest]) {
   smallest = right; // 將最小值指標 smallest 更新為右子節點的索引位置
  }

  // if判斷式，如果最小的不是父節點，交換並繼續堆化                   
  // 遞迴處理受影響的子樹
  // 第三步：若最小值不是父節點，執行交換與遞迴調整
  // 若 smallest 不等於 i，則代表經過上面兩個 if 的比較後，左子或右子節點的值比父節點還要小 
  if (smallest != i) {
   swap(heap[i], heap[smallest]); // 為了維持 Min Heap 原則，將父節點的值與最小子節點的值進行實體位置對調
   heapify(smallest);             // 因為原本較大的父節點被換下去，可能會導致該位置以下的子樹結構被破壞
                                 // 因此，必須以剛才被換下去的新位置（即 smallest 索引）作為新的根節點
							     //再次遞迴呼叫 heapify，像漣漪一樣持續向下修正，直到整棵子樹都安全地符合 Min Heap 為止
  }
 }
    
 // 顯示Heap的內容(使用BFS)
 void printHeap() {
  vector<int> backup = heap; 

  while (!heap.empty()) {
   cout << heap[0] << " ";  // 列印出樹頂 heap[0] (當前最小值) 
   
   if (heap.size() == 1) {
    heap.pop_back();
    break;
   }
   
   heap[0] = heap.back();
   heap.pop_back();
   
   heapify(0);
  }
  
  heap = backup; 
  cout << endl;
 }
};

int main() {
// 將三個 input.txt 檔案名稱存入向量中
 vector<string> files = {"input1.txt", "input2.txt", "input3.txt"};

 // 設定隨機數生成器
 // 使用 random_device 與 mt19937 虛擬隨機數生成引擎，並用目前時間 (time(0)) 當作隨機種子
 mt19937 gen(static_cast<unsigned int>(time(0))); 
 uniform_int_distribution<> dis(0, files.size() - 1); // 產生 0 到 2 的均勻分佈隨機數

 // 隨機選擇一個索引並選出檔案
 int randomIndex = dis(gen);
 string filename = files[randomIndex]; // 隨機挑選出的檔案名稱
    
 vector<int> arr = readFromFile(filename);//讀取數據
    
 if (arr.empty()) {// 如果數據為空
  cerr << "No valid data found in file." << endl;//輸出錯誤信息
  return -1;
 }
 cout << "Input Array: ";//輸出讀取的數據
 for (int val : arr) {
  cout << val << " ";//輸出每個元素
 }
 cout << endl;

 MinHeap minHeap;// 創建Min Heap對象
 minHeap.buildMinHeap(arr); // 建立Min Heap

 // 輸出Min Heap的內容
 cout << "Min Heap: ";
 minHeap.printHeap();
 cout << endl;

 system("pause");
 return 0;
}
