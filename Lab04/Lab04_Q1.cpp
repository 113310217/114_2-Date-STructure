#include <iostream>
#include <string>
using namespace std;

//定義一個名為 Student 的 Struct 
struct Student {
	
 int id;
 string name;
 int chinese;
 int english;
 int math;
 int social;
 int science;
};

//使用 Call by Address (傳址呼叫)
void updateMath(Student *s) { //將s改成*s，*s代表s是一個指標，用來儲存外部傳入的記憶體位址
 s->math = 100; //因為 s 是指標(位址)，不能直接用點(.)，必須用(->)來存取記憶體位址內部的成員 
}
 
void printStudent(Student s) {
 cout << "學生編號: " << s.id << endl;
 cout << "姓名: " << s.name << endl;
 cout << "數學成績: " << s.math << endl;
}

int main() 
{
 //宣告一個 Student 型態的變數，名稱為one 
 Student one;
 
 //使用[.]存取成員，並賦予變數的初始值 
 one.id = 1; 
 one.name = "張小美";
 one.chinese = 77;
 one.english = 83;
 one.math = 86; //將初始值設為 86 
 one.social = 68;
 one.science = 91;
 
 //呼叫時加上取址符號 (&) 
 updateMath(&one); //把變數 one 在記憶體中的實際位址傳給函數 
 
 //列印出結果，且此時的 one.math已在記憶體位址被修改成 100 
 printStudent(one);
 return 0;
}
