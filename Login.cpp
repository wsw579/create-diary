#include <iostream>
#include <string>

using namespace std;

#include "Login.h"    

string Login::id=" ";  //static멤버변수 초기화 
int Login::pw =0;
bool Login::comfirm=false; 

void Login::signup(string name, int date) {   
	if (comfirm == true) {
		cout << "이미 회원가입이 되어있습니다. 탈퇴하기 전까지 회원가입 불가능 합니다." << endl;
	}
	comfirm = true;
	id = name;
	pw = date;
	cout << id <<  "회원가입 완료~!" << endl;
	cout << endl;
}

int Login::login(string name, int date) {
	if (id == name && pw == date) {
		cout << "login 성공 ~! " << endl;
		return 0;
	}
	else {
		cout << "login 실패 ! login하지않으면 diary를 사용할수없습니다. " << endl;
		return -1;
	}
}
void Login::pwModity(int newpassword){
	if (pw == newpassword) {
		cout << "기존 password와 같습니다. 새로운 password를 입력해주세요 !! " << endl;
	}
	else {
		pw = newpassword;
		cout << "비밀번호 수정 완료~! " << endl;
	}
}
void Login::withDraw() {
	cout << "탈퇴되었습니다. 이용해주셔서 감사합니다. " << endl;
}