#include <iostream>
#include <string>
#include <map>
using namespace std;

#include "Login.h" 
#include "Diary.h" 

int main() {
	Diary d;
	while (true) { // login하는 부분  
		cout << endl;
		cout << "┌────── L O G I N ──────┐" << endl;
		cout << "│ (1) Sign up           │" << endl;
		cout << "│ (2) Login             │" << endl;
		cout << "│ (3) Modify Password   │" << endl;
		cout << "│ (4) End               │" << endl;
		cout << "└───────────────────────┘" << endl;
		cout << endl;

		int nLogin;
		cout << "사용하실 기능을 골라주세요 : ";
		cin >> nLogin;

		switch (nLogin) {									// 입력한 nLogin값에따라서 switch문 수행
		case 1: {											//회원가입  
			string name;
			int birth;
			cout << "회원가입하려는 사용자 이름 > ";
			cin >> name;
			cout << "회원가입하려는 사용자 생년월일 >";
			cin >> birth;
			Login::signup(name, birth);
			break;
		}
		case 2: {											//로그인 -> 로그인 성공 시 다이어리 작성가능
			string id;
			int pw,c;
			cout << " id > ";
			cin >> id;
			cout << " password > ";
			cin >> pw;
			c=Login::login(id, pw);
			if (c != -1) {
				while (true) {
					cout << " ======== ★ " << Login::id << " 's  D I A R Y ★ ========" << endl;
					cout << endl;
					cout << "          (1)  Diary 쓰기 " << endl;
					cout << "          (2)  Diary 검색 " << endl;
					cout << "          (3)  Diary 수정" << endl;
					cout << "          (4)  Diary 삭제" << endl;
					cout << "          (5)  Diary 전체내용" << endl;
					cout << "          (6)  Diary 종료" << endl;
					cout << endl;
					cout << " ======== ★ ============== ★ ========" << endl;

					int nDiary;
					cout << "사용하실 기능을 골라주세요 : ";
					cin >> nDiary;

					switch (nDiary) {							 //입력한 nDiary값 에따라 switch문 수행
					case 1: {									 //다이어리 생성
						int date;
						cout << "생성하고 싶은 diary 날짜를 입력하세요 > ";
						cin >> date;
						string text;
						cout << date << "날짜의 diary 내용을 입력하세요." << date << "날짜의 날씨와 기록하고 싶은 내용 > ";
						cin >> text;
						d.MakeDiary(date, text);
						break;
					}
					case 2: {									  //다이어리 검색
						int date;
						cout << "어떤 내용을 검색할까요? 날짜를 입력하세요 > ";
						cin >> date;
						d.SearchDiary(date);
						break;
					}
					case 3: {									  //다이어리 수정
						int date, t;
						string text;
						cout << "어떤 내용을 수정할까요? 날짜를 입력하세요 > ";
						cin >> date;
						t = d.SearchDiary(date);
						if (t != -1) {
							d.DeleteDiary(date);
							cout << "날짜" ;
							cin >> date;
							cout << "내용";
							cin >> text;
							d.MakeDiary(date, text);
						}
						break;
					}
					case 4: {									  //다이어리 삭제
						int date, t;
						char check;
						cout << "어떤 내용을 삭제할까요? 날짜를 입력하세요 > ";
						cin >> date;
						t = d.SearchDiary(date);
						if (t != -1) {
							cout << "정말로 삭제할까요 ? (Y/N) > ";
							cin >> check;
							if (check == 'Y') {
								d.DeleteDiary(date);
							}
						}
						break;
					}
					case 5: {									 //다이어리내용 전체보기		
						d.ShowAllDiary();
						break;
					}
					case 6: {									//다이어리쓰기 종료	
						cout << "diary 종료합니다." << endl;
						return 0;
					}
					default: {
						cout << " ※※※ (1)~(6)번 만 입력해주세요 ※※※ " << endl;
						break;
					}
					}
				}
			}
			return 0;
		}
		case 3: {										//비밀번호 수정 
			int newPassword;
			cout << "새로운 password를 입력하세요 > ";
			cin >> newPassword;
			Login::pwModity(newPassword);
			break;
		}

		case 4: {										//종료				
			cout << "프로그램을 종료합니다." << endl;
			return 0;
		}
		
		default: {
			cout << " ※※※ (1)~(4)번 만 입력해주세요 ※※※ " << endl;
			break;
		}
		}
	}
	
}

