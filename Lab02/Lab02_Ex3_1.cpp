void copyArray(const vector<int>& source, vector<int>& dest) {
 
 int stepCount = 0; //假設步數
  
 stepCount++; //for迴圈初始化(i=0)，1步 

 for (int i = 0; i < source.size(); i++) {
  stepCount++; //比較 i<source.size()，1步
 
  dest[i] = source[i];
  stepCount = stepCount + 2; //讀取source[i]並賦值給dest[i]，2步 
 
  stepCount++; //迴圈遞增(i++)，1步 
 }
 
 stepCount++; //for迴圈結束時最後一次失敗的比較，1步 
 
 cout << "Step count: " << stepCount << endl;
}
// Total operations (總運算次數):
// 1 (初始化) + 4 * n (for迴圈內運算) + 1 (跳出迴圈)
// = 4n + 2 operations
// Therefore, O(n) complexity
