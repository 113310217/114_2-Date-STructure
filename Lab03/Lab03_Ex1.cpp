class Solution {
public:
    int findLucky(vector<int>& arr) {
     int count[501] = {0};  //宣告一個大小為501(1+500)的陣列，初始化為0  
    
      for(int x : arr){  //統計每個數字出現的次數 
       count[x]++; //若x是2，就將陣列的數值+1 
      }

        // 3. 從最大值 500 開始往回（遞減）檢查
        // 題目要求回傳「最大的」幸運數字，所以從大到小找，第一個符合的就是答案。
      for(int i = 500; i >= 1; i--){ //從500開始遞減檢查  
            // 幸運數字的定義：數值 (i) 等於 出現次數 (count[i])
       if(count[i] == i) { //若數值i等於出現次數count[i]，回傳數值i 
        return i; 
       }
      }
     return -1; //若迴圈執行完都沒觸發return i，表示無幸運數字，回傳-1    
    }
};
