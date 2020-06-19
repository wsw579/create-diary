#ifndef LOGIN_H   //조건부 컴파일 
#define LOGIN_H

class Login{  //클래스 선언부 
public:
	static string id;
	static int pw;
	static bool comfirm; //가입 여부 확인
	static void signup(string name, int date); //회원가입 -> (이름 , 생년월일) 
	static int login(string name,int date); //로그인 id:이름 password: 생년월일
	static void pwModity(int pw); //비밀번호수정
	static void withDraw(); //회원탈퇴
};
#endif