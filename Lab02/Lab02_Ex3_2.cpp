int countElement(const vector<int>& arr, int target) { 
 int stepCount = 0; //假設步數 
 int count = 0;
 
 stepCount++; //初始化count=0，1步 
 stepCount++; //for迴圈初始化(i=0)，1步 
 
 for (int i = 0; i < arr.size(); i++) {
 	
  stepCount++; //比較 i<arr.size()，1步
  stepCount++; //比較if判斷式(arr[i] == target)，1步 
  if (arr[i] == target) {
   count++;
   stepCount++; //count遞增，1步 
  }
  stepCount++; //迴圈遞增(i++)，1步 
 }
 
 stepCount++; //for迴圈結束時最後一次失敗的比較，1步
 stepCount++; //return動作，1步
 
 cout << "Step count: " << stepCount << endl;
 return count;
}
// Total operations (總運算次數):
// 2 (初始化) + 4 * n (for迴圈內運算) + 1 (跳出迴圈) + 1 (return回傳結果)
// = 4n + 4 operations
// Therefore, O(n) complexity
