void printPairs(const vector<int>& arr) {
// TODO: Add counts for outer loop initialization
 int stepCount = 0; //假設步數
 
 stepCount++; //for迴圈初始化(i=0)，1步 
 for (int i = 0; i < arr.size(); i++) {
  // TODO: Add counts for inner loop
  stepCount++; //外層for迴圈比較 (i<arr.size())，1步
 
  stepCount++; //內層for迴圈初始化(j=i+1)，1步 
  for (int j = i + 1; j < arr.size(); j++) {
   // TODO: Add counts for printing operation
   stepCount++; //內層for迴圈比較 (j<arr.size())
  
   cout << arr[i] << "," << arr[j] << endl;
   stepCount=stepCount+3; //使用arr[i]+使用arr[j]+列印出來，共三步
   
   stepCount++; //內層迴圈遞增(j++)，1步 
   
  }
  stepCount++; //j退出時，內層迴圈最後一次失敗的比較，1步 
  
  stepCount++; //外層迴圈遞增(i++)，1步 
 }
 stepCount++; //i退出時，外層迴圈最後一次失敗的比較，1步 
 
 cout << "Step count: " << stepCount << endl;
}
