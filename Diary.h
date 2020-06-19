#ifndef DIARY_H   //조건부 컴파일 
#define DIARY_H

#include<map>

class Diary {  //클래스 선언부 
public:
	Diary();
	map<int, string> diaryMap; //int -> 날짜 string -> 날씨와 다이어리내용 입력
	map<int, string>::iterator it;
	map<int, int> like; 
	map<int, int>::iterator iter;
	void MakeDiary(int date,string text);
	void ShowAllDiary();
	int SearchDiary(int date);
	int ModifyDiary(int date,string text);
	int DeleteDiary(int date);
};
#endif