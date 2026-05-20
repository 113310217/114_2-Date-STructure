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

class MaxHeap {
public:
    vector<int> heap; // 儲存Max Heap的元素

    // 建立Max Heap
    void buildMaxHeap(vector<int>& arr) {  //建立Max Heap
        heap = arr;

        for (int i = (heap.size() / 2) - 1; i >= 0; i--) { // 從最後一個非葉子節點開始向上執行Max Heap
            heapify(i);
        }
    }

    void heapify(int i) {// 堆化函式（確保以 i 為根的子樹符合Max Heap性質）
        int largest = i;          // 假設當前節點是最大的
        int left = 2 * i + 1;     // 左子節點索引
        int right = 2 * i + 2;    // 右子節點索引

        // if判斷式，檢查左子節點是否為有效範圍且比當前節點(父節點)大
        // 如果判斷式成立，把largest設為left
        if (left < heap.size() && heap[left] > heap[largest]) {
            largest = left;
        }

        // if判斷式，檢查右子節點是否為有效範圍且比當前節點(父節點)大
        // 如果判斷式成立，把largest設為right
        if (right < heap.size() && heap[right] > heap[largest]) {
            largest = right;
        }

        // if判斷式，如果最大的不是父節點，交換並繼續堆化                   
        // 遞迴處理受影響的子樹
        if (largest != i) {
            swap(heap[i], heap[largest]); // 交換父節點與最大的子節點
            heapify(largest);             // 遞迴向下檢查受影響的子樹
        }
    }
    
    // 顯示Heap的內容(使用BFS)
    void printHeap() {
        for (int val : heap) {// 遍歷 Max Heap中的每個元素
            cout << val << " ";// 輸出元素
        }
        cout << endl;
    }
};

int main() {
    // 1. 將三個 input 檔案名稱存入向量中
    vector<string> files = {"input1.txt", "input2.txt", "input3.txt"};

    // 2. 設定隨機數生成器
    // 使用 random_device 與 mt19937 引擎，並用目前時間 (time(0)) 當作隨機種子
    mt19937 gen(static_cast<unsigned int>(time(0))); 
    uniform_int_distribution<> dis(0, files.size() - 1); // 產生 0 到 2 的均勻分佈隨機數

    // 3. 隨機選擇一個索引並選出檔案
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

    MaxHeap maxHeap;// 創建Max Heap對象
    maxHeap.buildMaxHeap(arr); // 建立Max Heap

    // 輸出Max Heap的內容
    cout << "Max Heap: ";
    maxHeap.printHeap();
    cout << endl;

    system("pause");
    return 0;
}
