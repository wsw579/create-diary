#include <iostream>
#include <string>
#include<map>

using namespace std;

#include "Diary.h"    // 헤더파일과 cpp파일 분리 

//클래스 구현부  
Diary::Diary() {
 it=diaryMap.begin();
 iter=like.begin();
}

void Diary::MakeDiary(int date, string text) {          
	if (diaryMap.find(date) == diaryMap.end()) { //diary는 날짜 중복되지않아야한다.
		diaryMap.insert(make_pair(date, text)); 
		cout << date << "diary 생성합니다. " << text << endl;
	}
	else {
		cout << date << "의 날짜는 이미 diary에 내용이 존재합니다." << endl;
	}
}

void Diary::ShowAllDiary() {    
	cout << "diary 전체 개수 : " << diaryMap.size() << endl;
	cout << "diary 생성된 내용이 없습니다 ~! " << endl;
	if (diaryMap.size() != 0) {
		for (auto it = diaryMap.begin(); it != diaryMap.end(); it++) {
			cout << "날짜 : " << it->first << " " << "diary내용 : " << it->second << '\n';
		}
	}
}

int Diary::SearchDiary(int date) {               
	if (diaryMap.find(date) == diaryMap.end()) {
		cout << date << " 날짜의 diary는 존재하지 않습니다. " << endl;
		date = -1;
		return date;
	}
	else {
		cout << date << " 날짜의 내용은 [" << diaryMap[date] << "] 입니다 " << endl;
		return 1;
	}
}

int Diary::ModifyDiary(int date, string text) {
	if (diaryMap.find(date) == diaryMap.end()) {
		cout << date << " 날짜의 diary는 존재하지 않습니다. " << endl;
		return -1;
	}
	else {
		it->second = text;
		SearchDiary(date);
		return 0;
	}
}
int Diary::DeleteDiary(int date) {
	if (diaryMap.find(date) == diaryMap.end()) {
		cout << date << " 날짜의 diary는 존재하지 않습니다. " << endl;
		return -1;
	}
	else {
		cout << date << " 날짜의 diary를 삭제합니다" << endl;
		diaryMap.erase(date);
		return 0;
	}
}
	

