#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <ctime>
#include <string>
#include <cmath>

#define BLACK 0 
#define BLUE 1 
#define GREEN 2 
#define CYAN 3 
#define RED 4 
#define MAGENTA 5 
#define BROWN 6 
#define LIGHTGRAY 7 
#define DARKGRAY 8 
#define LIGHTBLUE 9 
#define LIGHTGREEN 10 
#define LIGHTCYAN 11 
#define LIGHTRED 12 
#define LIGHTMAGENTA 13 
#define YELLOW 14 
#define WHITE 15 


int outputx=66,outputmaxx=73,inputy=100;   

using namespace std;

char command[1000][1000];// 35()66-3이 기본  
int com_height=0;
///////////////////////////////
char text[10000],text1[10000],oper_text[10000],oper_text1[10000],oper_text2[10000];
/////////////////////텍스트  
char ineq_text[10000],ineq_text1[10000],ineq_text2[10000];
int ineq_length=0;
/////////////////////////조건문 연산  

int i,i1,i2,j,j1,j2;
int p,q,r,k, a,b,c,d, a1,b1,c1,d1;
//////////////////////////////////////다용도 변수  
int length,length1,strlength;
/////////////////문자열, commander 길이  
char but;
int chaint,chaint1;
char intcha[100];
///////////////////////////char숫자 -> int 

int xpos, ypos, xpos1, ypos1;///////////////문자열, 도형  위치  
int xfrom, yfrom,xto, yto;//////////////범위  
int delaying,line;
int colorf, colorb,colorf1, colorb1;
/////////////////////////배경색 attribute 
int scale;

int randto,randfrom;
////////////////////랜덤  
int func_am[100];
string func_na[100];
int func_pos,func_len,f_amount=0,func_length;
char func_putting[100];
/////////////////////////////////////변수 연산  
int suc_y=0;
int suc_count=-1;
int exe_check[1000];//35가 기본  
////////////////////////////////command성공 여부  

int det_func_y[1000];
int det_y[1000];
int det_rep[1000],det_amount;
int condition,conplus;
/////////////////////////////////////while, if ,test ...전용 } 감지 

int vc_C;////////////////////변수 연산  
char test_cha;/////////////////test 문자  

///////////////////////////////////switch 창 전용  변수  
int switch_num=0,switch_x=0,switch_y=0;
int switch_array[2][6]={{1,0,0,0,0,0},{0,0,0,0,0,0}};
int set_x=0,set_y=0,set_page=0;
int check=0;

int wordlength=0,wordline=0,enterline=0;
//////////////////////////cursor 
int cursor_color=0,cursor_color_pos=15,cursor_shape_pos=0;
char cursor_shape[8]={'|','_','/','?','1','!','}',';'};
////////////////////////////info version  
char version[5]={'1','.','5','.','2'};
int set_height=0;
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
void CursorView()             //커서 삭제 
{
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.dwSize = 1; //커서 굵기 (1 ~ 100)
    cursorInfo.bVisible = FALSE; //커서 Visible TRUE(보임) FALSE(숨김)
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void textcolor(int foreground, int background) //글자색 
{ 
int color=foreground+background*16; 
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); 
}

///////////////////////////////////////////////////////////////////////////////
void Gotoxy(int x, int y)          //gotxy
{
	COORD Pos={static_cast<SHORT>(x),static_cast<SHORT>(y)};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);	
}
///////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
void Write(int x, int y, int foreground, int background, const char text[10000]){
	Gotoxy(x,y);
	textcolor(foreground, background);
	cout<<text;	
	
}
void Write_char(int x, int y, int foreground, int background, char *text){
	Gotoxy(x,y);
	textcolor(foreground, background);
	cout<<*text;		
}
void Write_int(int x, int y, int foreground, int background, int *text){
	Gotoxy(x,y);
	textcolor(foreground, background);
	cout<<*text;		
}
void Write_array(int x, int y, int foreground, int background, char *text[10000]){
	Gotoxy(x,y);
	textcolor(foreground, background);
	cout<<*text;		
}
//////////////////////////////////////////////
int oper_Number_detect(int x){
	chaint=0;
	chaint=atoi(&oper_text[x]); 
	return chaint;
}
//////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
void func_detect(int x1 ,int y1){//commad array에서 함수만 감지하는 용  
	c=0;
	while(c<=99){
		func_putting[c]=' ';
		c+=1;
	}
	
	c=0;
	if(command[y1][x1]=='['){
		c=0;
		func_putting[0]='[';
		while(c<=98&&command[y1][x1+c+1]!=']'){
		func_putting[c+1]=command[y1][x1+c+1];	
		c+=1;
		}
		func_putting[c+1]=']';

	func_putting[0]='[';//버그 
	string puts;
	puts="";
//Gotoxy(0,0);
//textcolor(12,0);
//cout<<func_putting;
	c=0;
	func_length=0;
	while(c<=99&&func_putting[c]!=' '){
		puts+=func_putting[c];
		c+=1;
	}
	func_length=c;
	
	d=0;
	while(d<=99){
		if(puts==func_na[d]){
		func_pos=d;
		break;
		}
		d+=1;
	}
	
	}
	if(d==100||command[y1][x1]!='[')
	func_pos=100;
}
//////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
void oper_func_detect(int x1){
	c=0;
	while(c<=99){
		func_putting[c]=' ';
		c+=1;
	}
	
	c=0;
	if(oper_text[x1]=='['){
		c=0;
		func_putting[0]='[';
		while(c<=98&&oper_text[x1+c+1]!=']'){
		func_putting[c+1]=oper_text[x1+c+1];	
		c+=1;
		}
		func_putting[c+1]=']';

	func_putting[0]='[';//버그 
	string puts;
	puts="";
//Gotoxy(0,0);
//textcolor(12,0);
//cout<<func_putting;
	c=0;
	func_length=0;
	while(c<=99&&func_putting[c]!=' '){
		puts+=func_putting[c];
		c+=1;
	}
	func_length=c;
	
	d=0;
	while(d<=99){
		if(puts==func_na[d]){
		func_pos=d;
		break;
		}
		d+=1;
	}
	
	}
	if(d==100||oper_text[x1]!='[')
	func_pos=100;
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////
void oper_Com_num_detect(int x, int* n){
	if(oper_text[x]!=' '){
		oper_Number_detect(x);
		*n=chaint;
	}
	else if(oper_text[x]!=' '&&oper_text[x+1]!=' '){
			oper_Number_detect(x);
			*n=chaint;						
	}
	else if(oper_text[x]!=' '&&oper_text[x+1]!=' '&&oper_text[x+2]!=' '){
		oper_Number_detect(x);
		*n=chaint;
	}	
}
void oper_func_num_com(int x, int* n){
	oper_func_detect(x);
	if(func_pos==100)
	oper_Com_num_detect(x,n);
	else{
	*n=func_am[func_pos];
	}
	
}
//////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
void func_text_com(int x, int y){//say, tell 
	func_detect(x,y);
	if(func_pos==100){
		text[a1]=command[y][x];
		a+=1;
		a1+=1;
	}		
	else{
		string intstr=to_string(func_am[func_pos]);
		strcpy(intcha, intstr.c_str());
		b=0;
		while(b<strlen(intcha)&&intcha[b]!=' '){
			text[a1]=intcha[b];
			b+=1;
			a1+=1;
		}
		a+=func_length;
	}
}
////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void operating_detect(int s, int f ,int y, int *n){
	int start,last;
	int oppos=0;
	int num1,num2,result;
	int lsize;		
	//////////////////////제곱  
	while(oppos!=-1){
		a1=f-s;
		while(a1>=0){
			if(oper_text[a1]=='^'){//지수는 뒤에서 부터 연산  
			oppos=a1;
			break;	
			}
			oppos=-1;//감지 안됨 
			a1-=1;
		}
		
		if(oppos!=-1){//감지가 됐다면  
		a1=0;
		while(a1<=9999){//초기화  
			oper_text1[a1]=' ';
			if(a1<=99)
			intcha[a1]=' ';
			a1+=1;
		}
		
		a1=0;
		while(oper_text[a1]!=' '){//문자열 사이즈 구함 
		a1+=1;
		}
		lsize=a1-1;
		
		b1=1;
		while((oper_text[oppos-b1]!='+'&&oper_text[oppos-b1]!='-'&&oper_text[oppos-b1]!='*'&&oper_text[oppos-b1]!='/'&&oper_text[oppos-b1]!='^'&&oper_text[oppos-b1]!='%')&&oppos-b1>=0){
		b1+=1;
		}
		start=oppos-b1+1;//시작 지점  
		b1=1;
		while((oper_text[oppos+b1]!='+'&&oper_text[oppos+b1]!='-'&&oper_text[oppos+b1]!='*'&&oper_text[oppos+b1]!='/'&&oper_text[oppos+b1]!='^'&&oper_text[oppos-b1]!='%')&&oppos+b1<=lsize){
		b1+=1;
		}
		last=oppos+b1-1;//끝 지점  
		
		oper_func_num_com(start,&num1);
		oper_func_num_com(oppos+1,&num2);
		result=pow(num1,num2);
		string intstr=to_string(result);
		strcpy(intcha, intstr.c_str());//결과값을 문자열로 변환  
		
		a1=0;
		while(a1+last+1<=lsize&&oper_text[a1+last+1]!=' '){// 끝지점 이후 문자들을 oper_text1에 저장  
			oper_text1[a1]=oper_text[a1+last+1];
			oper_text[a1+last+1]=' ';
			a1+=1;
		}
		
			a1=start;//시작 지점부터 끝 지점 까지 문자열 없앰  
			while(a1<=last){
			oper_text[a1]=' ';
			a1+=1;
			}
			b1=0;
			while(b1<strlen(intcha)&&intcha[b1]!=' '){//없앤 부분에 문자열로 변환한 result 대입  
				oper_text[start+b1]=intcha[b1];
				b1+=1;
			}
			
			a1=0;
			while(oper_text1[a1]!=' '){//oper_text1에서 result 문자열 크기 만큼 이후에 다시 대입  
			oper_text[start+strlen(intcha)+a1]=oper_text1[a1];
			a1+=1;
			}
		}
	}
	oppos=0;
	//////////////////////나머지  
	while(oppos!=-1){
		a1=0;
		while(a1<=f-s){
			if(oper_text[a1]=='%'){
			oppos=a1;
			break;	
			}
			oppos=-1;//감지 안됨 
			a1+=1;
		}
		
		if(oppos!=-1){//감지가 됐다면  
		a1=0;
		while(a1<=9999){//초기화  
			oper_text1[a1]=' ';
			if(a1<=99)
			intcha[a1]=' ';
			a1+=1;
		}
		
		a1=0;
		while(oper_text[a1]!=' '){//문자열 사이즈 구함 
		a1+=1;
		}
		lsize=a1-1;
		
		b1=1;
		while((oper_text[oppos-b1]!='+'&&oper_text[oppos-b1]!='-'&&oper_text[oppos-b1]!='*'&&oper_text[oppos-b1]!='/'&&oper_text[oppos-b1]!='^'&&oper_text[oppos-b1]!='%')&&oppos-b1>=0){
		b1+=1;
		}
		start=oppos-b1+1;//시작 지점  
		b1=1;
		while((oper_text[oppos+b1]!='+'&&oper_text[oppos+b1]!='-'&&oper_text[oppos+b1]!='*'&&oper_text[oppos+b1]!='/'&&oper_text[oppos+b1]!='^'&&oper_text[oppos-b1]!='%')&&oppos+b1<=lsize){
		b1+=1;
		}
		last=oppos+b1-1;//끝 지점  
		
		oper_func_num_com(start,&num1);
		oper_func_num_com(oppos+1,&num2);
		if(num1*num2>=1)
		result=num1%num2;
		else
		result=1;
		
		string intstr=to_string(result);
		strcpy(intcha, intstr.c_str());//결과값을 문자열로 변환  
		
		a1=0;
		while(a1+last+1<=lsize&&oper_text[a1+last+1]!=' '){// 끝지점 이후 문자들을 oper_text1에 저장  
			oper_text1[a1]=oper_text[a1+last+1];
			oper_text[a1+last+1]=' ';
			a1+=1;
		}
			a1=start;//시작 지점부터 끝 지점 까지 문자열 없앰  
			while(a1<=last){
			oper_text[a1]=' ';
			a1+=1;
			}
			b1=0;
			while(b1<strlen(intcha)&&intcha[b1]!=' '){//없앤 부분에 문자열로 변환한 result 대입  
				oper_text[start+b1]=intcha[b1];
				b1+=1;
			}
			
			a1=0;
			while(oper_text1[a1]!=' '){//oper_text1에서 result 문자열 크기 만큼 이후에 다시 대입  
			oper_text[start+strlen(intcha)+a1]=oper_text1[a1];
			a1+=1;
			}
			
		}
	}
	oppos=0;
	//////////////////////곱셈  
	while(oppos!=-1){
		a1=0;
		while(a1<=f-s){
			if(oper_text[a1]=='*'||oper_text[a1]=='/'){
			oppos=a1;
			break;	
			}
			oppos=-1;//감지 안됨 
			a1+=1;
		}
		
		if(oppos!=-1){//감지가 됐다면  
		a1=0;
		while(a1<=9999){//초기화  
			oper_text1[a1]=' ';
			if(a1<=99)
			intcha[a1]=' ';
			a1+=1;
		}
		
		a1=0;
		while(oper_text[a1]!=' '){//문자열 사이즈 구함 
		a1+=1;
		}
		lsize=a1-1;
		
		b1=1;
		while((oper_text[oppos-b1]!='+'&&oper_text[oppos-b1]!='-'&&oper_text[oppos-b1]!='*'&&oper_text[oppos-b1]!='/'&&oper_text[oppos-b1]!='^'&&oper_text[oppos-b1]!='%')&&oppos-b1>=0){
		b1+=1;
		}
		start=oppos-b1+1;//시작 지점  
		b1=1;
		while((oper_text[oppos+b1]!='+'&&oper_text[oppos+b1]!='-'&&oper_text[oppos+b1]!='*'&&oper_text[oppos+b1]!='/'&&oper_text[oppos+b1]!='^'&&oper_text[oppos-b1]!='%')&&oppos+b1<=lsize){
		b1+=1;
		}
		last=oppos+b1-1;//끝 지점  
		
		oper_func_num_com(start,&num1);
		oper_func_num_com(oppos+1,&num2);
		if(oper_text[oppos]=='*')
		result=num1*num2;
		else if(oper_text[oppos]=='/'){
		if(num2==0)
		num2=1;
		result=num1/num2;
		}
		
		string intstr=to_string(result);
		strcpy(intcha, intstr.c_str());//결과값을 문자열로 변환  
		
		a1=0;
		while(a1+last+1<=lsize&&oper_text[a1+last+1]!=' '){// 끝지점 이후 문자들을 oper_text1에 저장  
			oper_text1[a1]=oper_text[a1+last+1];
			oper_text[a1+last+1]=' ';
			a1+=1;
		}
			a1=start;//시작 지점부터 끝 지점 까지 문자열 없앰  
			while(a1<=last){
			oper_text[a1]=' ';
			a1+=1;
			}
			b1=0;
			while(b1<strlen(intcha)&&intcha[b1]!=' '){//없앤 부분에 문자열로 변환한 result 대입  
				oper_text[start+b1]=intcha[b1];
				b1+=1;
			}
			
			a1=0;
			while(oper_text1[a1]!=' '){//oper_text1에서 result 문자열 크기 만큼 이후에 다시 대입  
			oper_text[start+strlen(intcha)+a1]=oper_text1[a1];
			a1+=1;
			}
			
		}
	}
	//////////////////////덧셈  
	oppos=0;
	while(oppos!=-1){
		a1=0;
		while(a1<=f-s){
			if(oper_text[a1]=='+'||oper_text[a1]=='-'){
			oppos=a1;
			break;	
			}
			oppos=-1;//감지 안됨 
			a1+=1;
		}
		
		if(oppos!=-1){//감지가 됐다면  
		a1=0;
		while(a1<=9999){//초기화  
			oper_text1[a1]=' ';
			if(a1<=99)
			intcha[a1]=' ';
			a1+=1;
		}
		
		a1=0;
		while(oper_text[a1]!=' '){//문자열 사이즈 구함 
		a1+=1;
		}
		lsize=a1-1;
		
		b1=1;
		while((oper_text[oppos-b1]!='+'&&oper_text[oppos-b1]!='-'&&oper_text[oppos-b1]!='*'&&oper_text[oppos-b1]!='/'&&oper_text[oppos-b1]!='^'&&oper_text[oppos-b1]!='%')&&oppos-b1>=0){
		b1+=1;
		}
		start=oppos-b1+1;//시작 지점  
		b1=1;
		while((oper_text[oppos+b1]!='+'&&oper_text[oppos+b1]!='-'&&oper_text[oppos+b1]!='*'&&oper_text[oppos+b1]!='/'&&oper_text[oppos+b1]!='^'&&oper_text[oppos-b1]!='%')&&oppos+b1<=lsize){
		b1+=1;
		}
		last=oppos+b1-1;//끝 지점  
		
		oper_func_num_com(start,&num1);
		oper_func_num_com(oppos+1,&num2);
		if(oper_text[oppos]=='+')
			result=num1+num2;
		else if(oper_text[oppos]=='-')
			result=num1-num2;
		string intstr=to_string(result);
		strcpy(intcha, intstr.c_str());//결과값을 문자열로 변환  
		
		a1=0;
		while(a1+last+1<=lsize&&oper_text[a1+last+1]!=' '){// 끝지점 이후 문자들을 oper_text1에 저장  
			oper_text1[a1]=oper_text[a1+last+1];
			oper_text[a1+last+1]=' ';
			a1+=1;
		}
			a1=start;//시작 지점부터 끝 지점 까지 문자열 없앰  
			while(a1<=last){
			oper_text[a1]=' ';
			a1+=1;
			}
			b1=0;
			while(b1<strlen(intcha)&&intcha[b1]!=' '){//없앤 부분에 문자열로 변환한 result 대입  
				oper_text[start+b1]=intcha[b1];
				b1+=1;
			}
			
			a1=0;
			while(oper_text1[a1]!=' '){//oper_text1에서 result 문자열 크기 만큼 이후에 다시 대입  
			oper_text[start+strlen(intcha)+a1]=oper_text1[a1];
			a1+=1;
			}
			
		}
	}
	
	if(oper_text[0]!='[')
	*n=atoi(oper_text);//정수형으로 변환 후 출력  
	else 
	oper_func_num_com(0,n);
}
//////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void formula_detect(int x, int y, int *n, int mode){
	int bracket1=0,bracket2=0,finale;	
	int number;
	if(mode==0){//수 대입  
	a1=0;
	while(command[y][x+a1]!=' '){
	a1+=1;
	length+=1;
	}
	length-=1;
	finale=x+a1-1;	
	}
	else if(mode==1){//조건문  
	ineq_length=0;
	a1=0;
	while(ineq_text[x+a1]!=' '&&ineq_text[x+a1]!='<'&&ineq_text[x+a1]!='>'&&ineq_text[x+a1]!='='&&ineq_text[x+a1]!='&'&&ineq_text[x+a1]!='#'&&ineq_text[x+a1]!=')'){
	a1+=1;
	ineq_length+=1;
	}
	ineq_length-=1;
	finale=x+a1-1;	
	}
	
	
	a1=0;
	while(a1<=9999){
		oper_text[a1]=' ';
		oper_text1[a1]=' ';
		oper_text2[a1]=' ';
		if(a1<=99)
		intcha[a1]=' ';
		a1+=1;
	}
	if(mode==0){//수 대입  
	a1=x;
	while(a1<=finale){
		oper_text2[a1-x]=command[y][a1];
		a1+=1;
	}	
	}
	else if(mode==1){//조건문  
	a1=x;
	while(a1<=finale){
		oper_text2[a1-x]=ineq_text[a1];
		a1+=1;
	}	
	}
	
	while(bracket2!=-1){
		b1=0;
		while(b1<=finale-x){
			if(oper_text2[b1]=='(')
			bracket1=b1;
			else if(oper_text2[b1]==')'){
			bracket2=b1;
			break;
			}
			bracket2=-1;//괄호 감지  
			b1+=1;	
		}
		if(bracket2!=-1){
		a1=0;
		while(a1<=9999){
			oper_text[a1]=' ';
			oper_text1[a1]=' ';
			if(a1<=99)
			intcha[a1]=' ';
			a1+=1;
		}
		a1=bracket1+1;
		while(a1<=bracket2-1){
			oper_text[a1-bracket1-1]=oper_text2[a1];
			a1+=1;
		}
		operating_detect(0,bracket2-bracket1-2,y,&number);//넣을 때가 없어 임시로 number에 넣어둠  
		
		a1=0;
		while(a1<=9999){
			oper_text1[a1]=' ';
			a1+=1;
		}
		a1=0;
		while(oper_text2[a1+bracket2+1]!=' '){// 끝지점 이후 문자들을 oper_text1에 저장  
			oper_text1[a1]=oper_text2[a1+bracket2+1];
			oper_text2[a1+bracket2+1]=' ';
			a1+=1;
		}
			a1=bracket1;//시작 지점부터 끝 지점 까지 문자열 없앰  
			while(a1<=bracket2){
			oper_text2[a1]=' ';
			a1+=1;
			}
			b1=0;
			while(oper_text[b1]!=' '){//없앤 부분에 문자열로 변환한 result 대입  
				oper_text2[bracket1+b1]=oper_text[b1];
				b1+=1;
			}
			
			a1=0;
			while(oper_text1[a1]!=' '){//oper_text1에서 result 문자열 크기 만큼 이후에 다시 대입  
			oper_text2[bracket1+b1+a1]=oper_text1[a1];//b1-1은 바로 위에서 구한  oper_text 크기 
			a1+=1;
			}
			
			bracket1=0;
			bracket2=0;
		}
	}
	a1=0;
	while(oper_text2[a1]!=' '){
		oper_text[a1]=oper_text2[a1];
		a1+=1;
	}
	operating_detect(x,finale,y,n);
}
////////////////////////////////////////////////////////
void ineqsign_detect(int x, int y, int *n){
	int left=0,right=0;
	int ineq_sign=-1;
	formula_detect(x, y, &left,1);
	if(ineq_text[x+ineq_length+1]=='<'&&ineq_text[x+ineq_length+2]!='='){
		ineq_sign=0;
		formula_detect(x+ineq_length+2, y, &right,1);
	}
	else if(ineq_text[x+ineq_length+1]=='>'&&ineq_text[x+ineq_length+2]!='='){
		ineq_sign=1;
		formula_detect(x+ineq_length+2, y, &right,1);
	}
	else if(ineq_text[x+ineq_length+1]=='='&&ineq_text[x+ineq_length+2]=='='){
		ineq_sign=2;
		formula_detect(x+ineq_length+3, y, &right,1);
	}
	else if(ineq_text[x+ineq_length+1]=='!'&&ineq_text[x+ineq_length+2]=='='){
		ineq_sign=3;
		formula_detect(x+ineq_length+3, y, &right,1);
	}
	else if(ineq_text[x+ineq_length+1]=='>'&&ineq_text[x+ineq_length+2]=='='){
		ineq_sign=4;
		formula_detect(x+ineq_length+3, y, &right,1);		
	}
	else if(ineq_text[x+ineq_length+1]=='<'&&ineq_text[x+ineq_length+2]=='='){
		ineq_sign=5;
		formula_detect(x+ineq_length+3, y, &right,1);
	}

	
	if(ineq_sign==-1){
	if(left==0)
	*n=0;
	else
	*n=1;
	}
	else if(ineq_sign==0&&left<right)
	*n=1;
	else if(ineq_sign==0&&left>=right)
	*n=0;
	else if(ineq_sign==1&&left>right)
	*n=1;
	else if(ineq_sign==1&&left<=right)
	*n=0;
	else if(ineq_sign==2&&left==right)
	*n=1;
	else if(ineq_sign==2&&left!=right)
	*n=0;
	else if(ineq_sign==3&&left!=right)
	*n=1;
	else if(ineq_sign==3&&left==right)
	*n=0;
	else if(ineq_sign==4&&left>=right)
	*n=1;
	else if(ineq_sign==4&&left<right)
	*n=0;
	else if(ineq_sign==5&&left<right)
	*n=1;
	else if(ineq_sign==5&&left>=right)
	*n=0;
} 
////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void andor_detect(int s, int f ,int y, int *n){
	int start,last;
	int ineqpos=0;
	int num1,num2,result;
	int lsize;		
	
	//////////////////////제곱  
	while(ineqpos!=-1){
		a1=0;
		while(a1<=f-s){
			if(ineq_text[a1]=='&'&&ineq_text[a1+1]=='&'){//지수는 뒤에서 부터 연산  
			ineqpos=a1;
			break;	
			}
			ineqpos=-1;//감지 안됨 
			a1+=1;
		}
		
		if(ineqpos!=-1){//감지가 됐다면  
			a1=0;
			while(a1<=9999){//초기화  
				ineq_text1[a1]=' ';
				if(a1<=99)
				intcha[a1]=' ';
				a1+=1;
			}
			
			a1=0;
			while(ineq_text[a1]!=' '){//문자열 사이즈 구함 
			a1+=1;
			}
			lsize=a1-1;
			
			b1=1;
			while(ineq_text[ineqpos-b1]!='&'&&ineq_text[ineqpos-b1]!='#'&&ineqpos-b1>=0){
			b1+=1;
			}
			start=ineqpos-b1+1;//시작 지점  
			b1=2;
			while(ineq_text[ineqpos+b1]!='&'&&ineq_text[ineqpos+b1]!='#'&&ineqpos+b1<=lsize){
			b1+=1;
			}
			last=ineqpos+b1-1;//끝 지점  
			
			ineqsign_detect(start,y,&num1);
			ineqsign_detect(ineqpos+2,y,&num2);
			
			result=num1*num2;
			string intstr=to_string(result);
			strcpy(intcha, intstr.c_str());//결과값을 문자열로 변환  
			
			a1=0;
			while(a1+last+1<=lsize&&ineq_text[a1+last+1]!=' '){// 끝지점 이후 문자들을 ineq_text1에 저장  
				ineq_text1[a1]=ineq_text[a1+last+1];
				ineq_text[a1+last+1]=' ';
				a1+=1;
			}
		
			a1=start;//시작 지점부터 끝 지점 까지 문자열 없앰  
			while(a1<=last){
			ineq_text[a1]=' ';
			a1+=1;
			}
			b1=0;
			while(b1<strlen(intcha)&&intcha[b1]!=' '){//없앤 부분에 문자열로 변환한 result 대입  
				ineq_text[start+b1]=intcha[b1];
				b1+=1;
			}
			
			a1=0;
			while(ineq_text1[a1]!=' '){//ineq_text1에서 result 문자열 크기 만큼 이후에 다시 대입  
			ineq_text[start+strlen(intcha)+a1]=ineq_text1[a1];
			a1+=1;
			}
		}
	}
	ineqpos=0;
	//////////////////////나머지  
	while(ineqpos!=-1){
		a1=0;
		while(a1<=f-s){
			if(ineq_text[a1]=='#'&&ineq_text[a1+1]=='#'){
			ineqpos=a1;
			break;	
			}
			ineqpos=-1;//감지 안됨 
			a1+=1;
		}
		
		if(ineqpos!=-1){//감지가 됐다면  
			a1=0;
			while(a1<=9999){//초기화  
				ineq_text1[a1]=' ';
				if(a1<=99)
				intcha[a1]=' ';
				a1+=1;
			}
			
			a1=0;
			while(ineq_text[a1]!=' '){//문자열 사이즈 구함 
			a1+=1;
			}
			lsize=a1-1;
			
			b1=1;
			while(ineq_text[ineqpos-b1]!='&'&&ineq_text[ineqpos-b1]!='#'&&ineqpos-b1>=0){
			b1+=1;
			}
			start=ineqpos-b1+1;//시작 지점  
			b1=2;
			while(ineq_text[ineqpos+b1]!='&'&&ineq_text[ineqpos+b1]!='#'&&ineqpos+b1<=lsize){
			b1+=1;
			}
			last=ineqpos+b1-1;//끝 지점  
			
			ineqsign_detect(start,y,&num1);
			ineqsign_detect(ineqpos+2,y,&num2);
			result=num1+num2;
			
			string intstr=to_string(result);
			strcpy(intcha, intstr.c_str());//결과값을 문자열로 변환  
			
			a1=0;
			while(a1+last+1<=lsize&&ineq_text[a1+last+1]!=' '){// 끝지점 이후 문자들을 ineq_text1에 저장  
				ineq_text1[a1]=ineq_text[a1+last+1];
				ineq_text[a1+last+1]=' ';
				a1+=1;
			}
			a1=start;//시작 지점부터 끝 지점 까지 문자열 없앰  
			while(a1<=last){
			ineq_text[a1]=' ';
			a1+=1;
			}
			b1=0;
			while(b1<strlen(intcha)&&intcha[b1]!=' '){//없앤 부분에 문자열로 변환한 result 대입  
				ineq_text[start+b1]=intcha[b1];
				b1+=1;
			}
			
			a1=0;
			while(ineq_text1[a1]!=' '){//ineq_text1에서 result 문자열 크기 만큼 이후에 다시 대입  
			ineq_text[start+strlen(intcha)+a1]=ineq_text1[a1];
			a1+=1;
			}
		}
	}
	ineqsign_detect(0,y,n);
}
//////////////////////////////////////////////
////////////////////////////////////////////
void condition_detect(int x, int y, int *n){
int bracket1=0,bracket2=0,finale;	
int number;
int length_false=0;
a1=0;
while((command[y][x+a1]!=')'||command[y][x+a1+1]!=' ')&&a1<=100){
a1+=1;
length_false+=1;
}
length_false-=1;
finale=x+a1-1;
a1=0;
while(a1<=9999){
	ineq_text[a1]=' ';
	ineq_text1[a1]=' ';
	ineq_text2[a1]=' ';
	if(a1<=99)
	intcha[a1]=' ';
	a1+=1;
}
a1=x;
while(a1<=finale){
	ineq_text2[a1-x]=command[y][a1];
	a1+=1;
}

while(bracket2!=-1){
b1=0;
while(b1<=finale-x){
	if(ineq_text2[b1]=='(')
	bracket1=b1;
	else if(ineq_text2[b1]==')'){
	bracket2=b1;
	break;
	}
	bracket2=-1;//괄호 감지  
	b1+=1;	
}
if(bracket2!=-1){
a1=0;
while(a1<=9999){
	ineq_text[a1]=' ';
	ineq_text1[a1]=' ';
	if(a1<=99)
	intcha[a1]=' ';
	a1+=1;
}
a1=bracket1+1;
while(a1<=bracket2-1){
	ineq_text[a1-bracket1-1]=ineq_text2[a1];
	a1+=1;
}
andor_detect(0,bracket2-bracket1-2,y,&number);//넣을 때가 없어 임시로 number에 넣어둠  

a1=0;
while(a1<=9999){
	ineq_text1[a1]=' ';
	a1+=1;
}
a1=0;
while(ineq_text2[a1+bracket2+1]!=' '){// 끝지점 이후 문자들을 ineq_text1에 저장  
	ineq_text1[a1]=ineq_text2[a1+bracket2+1];
	ineq_text2[a1+bracket2+1]=' ';
	a1+=1;
}
	a1=bracket1;//시작 지점부터 끝 지점 까지 문자열 없앰  
	while(a1<=bracket2){
	ineq_text2[a1]=' ';
	a1+=1;
	}
	b1=0;
	while(ineq_text[b1]!=' '){//없앤 부분에 문자열로 변환한 result 대입  
		ineq_text2[bracket1+b1]=ineq_text[b1];
		b1+=1;
	}
	
	a1=0;
	while(ineq_text1[a1]!=' '){//ineq_text1에서 result 문자열 크기 만큼 이후에 다시 대입  
	ineq_text2[bracket1+b1+a1]=ineq_text1[a1];//b1-1은 바로 위에서 구한  ineq_text 크기 
	a1+=1;
	}
	
	bracket1=0;
	bracket2=0;
}
}
a1=0;
while(ineq_text2[a1]!=' '){
	ineq_text[a1]=ineq_text2[a1];
	a1+=1;
}

andor_detect(x,finale,y,n);
length+=length_false;
}
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
int output_line(){
	if(((yfrom-yto)/(xfrom-xto))>=1||((yfrom-yto)/(xfrom-xto))<=-1){
		a=xfrom;
		while((a<=xto&&xfrom<xto)||(a>=xto&&xfrom>=xto)){
				b=0;
				while(b<(yfrom-yto)/(xfrom-xto)){
				if((a==xfrom&&b==0)||(a!=xfrom)||(a==xto&&b==0))
				Write(a+outputx,((yfrom-yto)/(xfrom-xto))*(a-xfrom)+yfrom-b+3,BLACK,colorb," ");
				b+=1;
				}
				
			if(xfrom<xto)
			a+=1;
			else if(xfrom>=xto)
			a-=1;
	 	}	
	}						
 	else if(((xfrom-xto)/(yfrom-yto))>=1||((xfrom-xto)/(yfrom-yto))<=-1){
	 	b=yfrom;
		while((b<=yto&&yfrom<yto)||(b>=yto&&yfrom>=yto)){
				a=0;
				while(a<(xfrom-xto)/(yfrom-yto)){
					if((b==yfrom&&a==0)||(b!=yfrom)||(b==yto&&a==0))
					Write(((xfrom-xto)/(yfrom-yto))*(b-yfrom)+xfrom-a+outputx,b+3,BLACK,colorb," ");
					a+=1;
				}
				
			if(yfrom<yto)
			b+=1;
			else if(yfrom>=yto)
			b-=1;
		}	
	}	
	 return 1;
}
int output_say(int y){
	b=0;
	while(b<=99){
		intcha[b]=' ';
		b+=1;
	}
	
	a=0;//command
	a1=0;//text
	while(command[y][6+a]!='"'&&a<=outputx-3-8){
		func_text_com(6+a,y);
	}
	strlength=a1;
	Gotoxy(outputx+xpos, 3+ypos);
	textcolor(colorf,colorb);
	cout<<text;
	return 1;
}
int output_tell(int y,int l){		
	b=0;
	while(b<=99){
		intcha[b]=' ';
		b+=1;
	}
	a=0;
	while(((command[y][15+l+a]!='"'&&command[y][10+l]!='"')||(command[y][11+l+a]!='"'&&command[y][10+l]=='"'))&&a<=outputx-18-l){
		if(command[y][10+l]!='"'){
		a=0;//command
	a1=0;//text
	while(command[y][15+l+a]!='"'&&a<=outputx-3-8){
		func_text_com(15+l+a, y);	
	}	
		}
		else {
		a=0;//command
	a1=0;//text
	while(command[y][11+l+a]!='"'&&a<=outputx-3-8){
		func_text_com(11+l+a, y);	
		}
	}
	}
	strlength=a1;
	Gotoxy(outputx+xpos, 3+ypos);
	textcolor(colorf,colorb);
	cout<<text;
	length1=l;
	return 1;
}
int output_fill(int y,int l){
	if((strncmp(&command[y][16+l],"line(false)",strlen("line(false)"))==0)||command[y][17+l]==' '){
	a=xfrom;
	b=yfrom;
	while(a<=xto){
		while(b<=yto){
			Write(a+outputx,b+3,BLACK,colorb," ");
			b+=1;
		}
		b=yfrom;
		a+=1;
	}
	}
	else if(strncmp(&command[y][16+l],"line(true) empty(true)",strlen("line(true) empty(true)"))==0){
	a=xfrom;
	while(a<=xto){
			Write(a+outputx,3+yfrom,BLACK,colorb," ");
			Write(a+outputx,3+yto,BLACK,colorb," ");
		a+=1;
	}
	b=yfrom;
	while(b<=yto){
			Write(outputx+xfrom,b+3,BLACK,colorb," ");
			Write(outputx+xto,b+3,BLACK,colorb," ");
		b+=1;
	}
	}
	else if((strncmp(&command[y][16+l],"line(true) empty(false)",strlen("line(true) empty(false)"))==0)||(strncmp(&command[y][16+l],"line(true)  ",strlen("line(true)  "))==0)){
	a=xfrom;
	b=yfrom;
	while(a<=xto){
		while(b<=yto){
			Write(a+outputx,b+3,BLACK,colorb," ");
			b+=1;
		}
		b=yfrom;
		a+=1;
	}
	a=xfrom+1;
	b=yfrom+1;
	while(a<=xto-1){
		while(b<=yto-1){
			Write(a+outputx,b+3,BLACK,BLACK," ");
			b+=1;
		}
		b=yfrom+1;
		a+=1;
	}
	}
	length1=l;							
	return 1;
}
int output_shape(int y,int l){
	if(strncmp(&command[y][7],"triangle ",strlen("triangle "))==0){
		if((strncmp(&command[y][15+l],"line(false)",strlen("line(false)"))==0)||command[y][16+l]==' '){
		a=xpos;
		b=ypos;
		while(a<=2*scale+xpos){
			while(b<=scale+ypos){
				if((b-ypos>=-(1.7/2)*(a-xpos)+scale&&a<=scale+xpos)||(b-ypos>=(1.7/2)*(a-xpos)-(1.4/2)*scale&&a>scale+xpos))
				Write(a+outputx,b+3,BLACK,colorb," ");
				b+=1;
			}
			b=ypos;
			a+=1;
		}
		}
		else if(strncmp(&command[y][15+l],"line(true) empty(true)",strlen("line(true) empty(true)"))==0){
		a=xpos;
		b=ypos;
		while(a<=2*scale+xpos){
			while(b<=scale+ypos){
				if(((b-ypos>=-(1.7/2)*(a-xpos)+scale&&a<=scale+xpos)&&(b-ypos<=1.7-(1.7/2)*(a-xpos)+scale&&a<=scale+xpos))||((b-ypos>=(1.7/2)*(a-xpos)-(1.4/2)*scale&&a>scale+xpos)&&(b-ypos<=1.7+(1.7/2)*(a-xpos)-(1.4/2)*scale&&a>scale+xpos)))
				Write(a+outputx,b+3,BLACK,colorb," ");
				b+=1;
			}
			b=ypos;
			a+=1;
		}
		a=xpos;
		while(a<=2*scale+xpos){
			Write(a+outputx,ypos+scale+3,BLACK,colorb," ");
			a+=1;
		}
		}
		else if((strncmp(&command[y][15+l],"line(true) empty(false)",strlen("line(true) empty(false)"))==0)||(strncmp(&command[y][15+l],"line(true)  ",strlen("line(true)  "))==0)){
		a=xpos;
		b=ypos;
		while(a<=2*scale+xpos){
			while(b<=scale+ypos){
				if((b-ypos>=-(1.7/2)*(a-xpos)+scale&&a<=scale+xpos)||(b-ypos>=(1.7/2)*(a-xpos)-(1.4/2)*scale&&a>scale+xpos))
				Write(a+outputx,b+3,BLACK,BLACK," ");
				b+=1;
			}
			b=ypos;
			a+=1;
		}
		a=xpos;
		b=ypos;
		while(a<=2*scale+xpos){
			while(b<=scale+ypos){
				if(((b-ypos>=-(1.7/2)*(a-xpos)+scale&&a<=scale+xpos)&&(b-ypos<=1.7-(1.7/2)*(a-xpos)+scale&&a<=scale+xpos))||((b-ypos>=(1.7/2)*(a-xpos)-(1.4/2)*scale&&a>scale+xpos)&&(b-ypos<=1.7+(1.7/2)*(a-xpos)-(1.4/2)*scale&&a>scale+xpos)))
				Write(a+outputx,b+3,BLACK,colorb," ");
				b+=1;
			}
			b=ypos;
			a+=1;
		}
		a=xpos;
		while(a<=2*scale+xpos){
			Write(a+outputx,ypos+scale+3,BLACK,colorb," ");
			a+=1;
		}
		}
	}
	else if(strncmp(&command[y][7],"square ",strlen("square "))==0){
		if((strncmp(&command[y][15+l],"line(false)",strlen("line(false)"))==0)||command[y][16+l]==' '){
		a=xpos;
		b=ypos;
		while(a<=2*scale+xpos){
			while(b<=scale+ypos){
				Write(a+outputx,b+3,BLACK,colorb," ");
				b+=1;
			}
			b=ypos;
			a+=1;
		}	
		}
		else if(strncmp(&command[y][15+l],"line(true) empty(true)",strlen("line(true) empty(true)"))==0){
		a=xpos;
		while(a<=2*scale+xpos){
			Write(a+outputx,3+ypos,BLACK,colorb," ");
			Write(a+outputx,3+ypos+scale,BLACK,colorb," ");
		a+=1;
		}
		b=ypos;
		while(b<=scale+ypos){
			Write(outputx+xpos,b+3,BLACK,colorb," ");
			Write(outputx+xpos+2*scale,b+3,BLACK,colorb," ");
		b+=1;
		}	
		}
		else if((strncmp(&command[y][15+l],"line(true) empty(false)",strlen("line(true) empty(false)"))==0)||(strncmp(&command[y][15+l],"line(true)  ",strlen("line(true)  "))==0)){
		a=xpos;
		b=ypos;
		while(a<=2*scale+xpos){
			while(b<=scale+ypos){
				Write(a+outputx,b+3,BLACK,colorb," ");
				b+=1;
			}
			b=ypos;
			a+=1;
		}	
		a=xpos+1;
		b=ypos+1;
		while(a<=2*scale+xpos-1){
			while(b<=scale+ypos-1){
				Write(a+outputx,b+3,BLACK,BLACK," ");
				b+=1;
			}
			b=ypos+1;
			a+=1;
		}	
		}		
	}
	else if(strncmp(&command[y][7],"circle ",strlen("circle "))==0){
		if((strncmp(&command[y][15+l],"line(false)",strlen("line(false)"))==0)||command[y][16+l]==' '){
		a=xpos;
		b=ypos;
		while(a<=2*scale+xpos){
			while(b<=scale+ypos){
				if(scale*scale/4>=(a-xpos-scale)*(a-xpos-scale)/4+(b-ypos-scale/2)*(b-ypos-scale/2))
				Write(a+outputx,b+3,BLACK,colorb," ");
				b+=1;
			}
			b=ypos;
			a+=1;
		}
		}
		else if(strncmp(&command[y][15+l],"line(true) empty(true)",strlen("line(true) empty(true)"))==0){
		a=xpos;
		b=ypos;
		while(a<=2*scale+xpos){
			while(b<=scale+ypos){
				if(scale*scale/4>=(a-xpos-scale)*(a-xpos-scale)/4+(b-ypos-scale/2)*(b-ypos-scale/2)&&scale*scale/4-9<=(a-xpos-scale)*(a-xpos-scale)/4+(b-ypos-scale/2)*(b-ypos-scale/2))
				Write(a+outputx,b+3,BLACK,colorb," ");
				b+=1;
			}
			b=ypos;
			a+=1;
		}
		}
	else if((strncmp(&command[y][15+l],"line(true) empty(false)",strlen("line(true) empty(false)"))==0)||(strncmp(&command[y][15+l],"line(true)  ",strlen("line(true)  "))==0)){
		a=xpos;
		b=ypos;
		while(a<=2*scale+xpos){
			while(b<=scale+ypos){
				if(scale*scale/4>=(a-xpos-scale)*(a-xpos-scale)/4+(b-ypos-scale/2)*(b-ypos-scale/2)&&scale*scale/4-9<=(a-xpos-scale)*(a-xpos-scale)/4+(b-ypos-scale/2)*(b-ypos-scale/2))
				Write(a+outputx,b+3,BLACK,colorb," ");
				b+=1;
			}
			b=ypos;
			a+=1;
		}
		a=xpos;
		b=ypos;
		while(a<=2*scale+xpos){
			while(b<=scale+ypos){
				if(scale*scale/4-9>(a-xpos-scale)*(a-xpos-scale)/4+(b-ypos-scale/2)*(b-ypos-scale/2))
				Write(a+outputx,b+3,BLACK,BLACK," ");
				b+=1;
			}
			b=ypos;
			a+=1;
		}
		}
	}
	length1=l;	
	return 1;
}

////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
void posx_detect(int *p){
	if(*p>outputmaxx)
	*p=outputmaxx;
	else if(*p<0)
	*p=0;
}
void posy_detect(int *p){
	if(*p>35-1)
	*p=35-1;
	else if(*p<0)
	*p=0;
}
//////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
void Success_text(int h){
	if(exe_check[h]==0){
	if(4*suc_count<outputmaxx-3)
	suc_y=0;
	else if(4*suc_count>=outputmaxx-3)
	suc_y=1;
	else if(4*suc_count>=2*(outputmaxx-3))
	suc_y=2;
	
	Gotoxy(4*suc_count+outputx-(outputmaxx-3)*suc_y,4+35+suc_y);
	textcolor(10,0);
	cout<<"*"<<h+1<<"* ";	
	}
	
}
void Fail_text(int h){
	if(exe_check[h]==0){
		suc_count+=1;
	if(4*suc_count<outputmaxx-3)
		suc_y=0;
	else if(4*suc_count>=outputmaxx-3)
		suc_y=1;
	else if(4*suc_count>=2*(outputmaxx-3))
		suc_y=2;
	
	Gotoxy(4*suc_count+outputx-(outputmaxx-3)*suc_y,4+35+suc_y);
	textcolor(12,0);
	cout<<"*"<<h+1<<"* ";	
	}
	
}
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
void line_change_color(int y){
	j1=y;
	i1=0;
	while(j1<=com_height+34){
		while(i1<=outputx-3-2){
			textcolor(BLACK,WHITE);
			if(command[j1][0]=='?'||command[j1][0]=='/'){
				textcolor(LIGHTRED,WHITE);
				if(command[j1][i1]=='0'||command[j1][i1]=='1'||command[j1][i1]=='2'||command[j1][i1]=='3'||command[j1][i1]=='4'||command[j1][i1]=='5'||command[j1][i1]=='6'||command[j1][i1]=='7'||command[j1][i1]=='8'||command[j1][i1]=='9'||command[j1][i1]=='['||command[j1][i1]==']')
					textcolor(LIGHTMAGENTA,WHITE);
				else if(command[j1][i1]=='~'||command[j1][i1]=='('||command[j1][i1]==')'||command[j1][i1]=='{'||command[j1][i1]=='}'||command[j1][i1]=='"'||command[j1][i1]=='\'')
					textcolor(BROWN,WHITE);
				else if(i1!=0&&(command[j1][i1]=='+'||command[j1][i1]=='-'||command[j1][i1]=='*'||command[j1][i1]=='/'||command[j1][i1]=='&'||command[j1][i1]=='#'||command[j1][i1]=='='||command[j1][i1]=='%'||command[j1][i1]=='^'||command[j1][i1]=='<'||command[j1][i1]=='>'||command[j1][i1]=='!'))
					textcolor(LIGHTGREEN,WHITE);
		a=0;
		k=0;//"감지 상수  
		while(a<=outputx-3&&i1>=a){
			if(command[j1][i1-a]=='\''){
				k+=1;//"감지 상수
			}
			a+=1;
		}
		if((command[j1][0]=='?'||command[j1][0]=='/')&&k%2==1&&command[j1][i1]!=']') 
		textcolor(BROWN,WHITE);
		
		a=0;
		k=0;//"감지 상수  
		while(a<=outputx-3&&i1>=a){
			if(command[j1][i1-a]=='"'){
				k+=1;//"감지 상수
			}
			a+=1;
		}
		if((command[j1][0]=='?'||command[j1][0]=='/')&&k%2==1&&command[j1][i1]!=']') 
		textcolor(BROWN,WHITE);
		
		k=0;
		a=0;//"감지 상수 
		b=0; //"감지 상수 
		while(k<=outputx-3&&i1>=k){
			if(command[j1][i1-k]=='['){
				a+=1;//"감지 상수
			}
			else if(command[j1][i1-k]==']'){
				b+=1;//"감지 상수
			}
			k+=1;
		}
		if(a%2!=b%2)				
		textcolor(LIGHTMAGENTA,WHITE);
			}
			else if(command[j1][0]=='}')
			textcolor(BROWN,WHITE);
			///////////////////////
		if(command[j1][i1]=='\\')
			textcolor(WHITE,WHITE);
			
		Gotoxy(2+i1,3+j1-com_height);
		cout<<command[j1][i1];  	
			
			i1+=1;
		}
		i1=0;
		j1+=1;
	}
}
////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
void version_text(int y,const char tt[100]){
		if(set_height+y>=12&&set_height+y<=23){
		Gotoxy(outputx+10,y+set_height);
		
		if(strncmp(&tt[1],version,strlen(version))==0)//현제  버전 감지  
		textcolor(LIGHTRED,WHITE);
		else if((tt[1]=='1'||tt[1]=='2'||tt[1]=='3')&&tt[2]=='.')
		textcolor(BLACK,WHITE);
		else
		textcolor(DARKGRAY,WHITE);
		
		cout<<tt;
		}
		}
//////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
int main(){
	string puts;
	srand((unsigned int)time(NULL));
	
	
	j=3;
	while(j<=35+3-1+5){
		Write(outputx-2,j,WHITE,DARKGRAY," ");
		Write(outputx-1,j,WHITE,DARKGRAY," ");
		j+=1;
	}
	
	i=0;
	while(i<=outputx+outputmaxx){
		Write(i,2,WHITE,DARKGRAY," ");
		Write(i,3+35,WHITE,DARKGRAY," ");
		i+=1;
	}
	Write(0,2,WHITE,DARKGRAY,"  Commander");//메세지  
	Write(outputx,2,WHITE,DARKGRAY,"Running display");
	Write(0,3+35,WHITE,DARKGRAY,"  Help message");
	Write(outputx,3+inputy,WHITE,DARKGRAY,"Running check");
	Write(0,4+35,BLACK,DARKGRAY,"  ");
	Write(0,5+35,BLACK,DARKGRAY,"  ");
	Write(0,6+35,BLACK,DARKGRAY,"  ");
	Write(0,7+35,BLACK,DARKGRAY,"  ");
	Write(0,7+35,BLACK,DARKGRAY,"                                                                 ");//맨 아래 바  
	Write(outputx,7+35,BLACK,DARKGRAY,"                                                                          ");//맨 아래 바 
////////   	////////   	////////   	////////   	////////   	////////   	////////   	////////   	
	i1=2;
	j1=0;
	while(i1<=outputx-3){
		while(j1<=35-1){
			Write(i1,j1+3,BLACK,WHITE," ");
			j1+=1;
		}
		j1=0;
		i1+=1;
	}
	j1=1;
		while(j1<=35){
			if(j1+com_height<=enterline+1){
			Gotoxy(0,j1+3-1);
			if(j1%2==1)
			textcolor(LIGHTGRAY,BLACK);
			else if(j1%2==0)
			textcolor(WHITE,DARKGRAY);
			if(j1<=9)
			cout<<"0"<<j1;   
			else
			cout<<j1;  
			}
			else
			Write(0,j1+3-1,LIGHTGRAY,LIGHTGRAY,"  ");
			
			j1+=1;
		}
	i1=0;
		while(i1<=outputmaxx){
			Gotoxy(i1+outputx,0);
			if(i1%10==0)
			textcolor(LIGHTRED,BLACK);
			else
			textcolor(BLACK,BLACK);		 
			cout<<i1/10;  
			
			Gotoxy(i1+outputx,1);
			if(i1%2==1)
			textcolor(BLACK,LIGHTGRAY);
			else if(i1%2==0)
			textcolor(DARKGRAY,WHITE);
			cout<<i1%10;  

			i1+=1;
		}
////////   	////////   	////////   	////////   	////////   	////////   	////////   	////////   	////////   	////////   	////////   			
	i1=0;
	j1=0;
	while(i1<=outputx-3-1){
		while(j1<=inputy-1){
			command[j1][i1]=' ';
			j1+=1;
		}
		j1=0;
		i1+=1;
	}
//////////////////////////////////////////////////////////	
	i=0;
	j=0;
	p=0;
	q=0;
	//////////////////////////////////////////////////////////////////////////////////	
	//////////////////////////////////////////////////////////////////////////////////	
	//////////////////////////////////////////////////////////////////////////////////	
	//////////////////////////////////////////////////////////////////////////////////	
	//////////////////////////////////////////////////////////////////////////////////	
	//////////////////////////////////////////////////////////////////////////////////	
	//////////////////////////////////////////////////////////////////////////////////	
	
	while(true){//기록 완료 상수 
	CursorView();//
//////////////////////////////////////////////////////////////////////////////////	
		char com_name[30];
		string command_name[100]={"/say","/tell","/remove","/fill","/shape","/attr","/color","/delay","/stop","/goto","/line","/random","/vc","/textlen","/usef","/deff","/int","?test","?for","?if","?unless"};
		if(switch_num==0){
		if(command[j][0]==' '){//(command[q][0]=='/'&&strncmp(&command[q][1],"remove ",strlen("remove "))==0)
		Write(2,4+35,LIGHTRED,BLACK,"*Write  '/','?'... to start the commander*                    ");
		Write(2,5+35,LIGHTRED,BLACK,"*Write 'Helping!' to get informations*                        ");	
		Write(2,6+35,LIGHTRED,BLACK,"*'Tab' : Switching Mode    '\\' : Down    '|' : Up*           ");
		}
		else if(command[j][0]=='/'&&command[j][1]==' '){
		Write(2,4+35,LIGHTRED,BLACK,"*'/' is the excution commander*                               ");
		Write(2,5+35,LIGHTRED,BLACK,"                                                              ");	
		Write(2,6+35,LIGHTRED,BLACK,"                                                              ");	
		}
		else if(command[j][0]=='?'&&command[j][1]==' '){
		Write(2,4+35,LIGHTRED,BLACK,"*'?' is the detection commander*                              ");
		Write(2,5+35,LIGHTRED,BLACK,"                                                              ");	
		Write(2,6+35,LIGHTRED,BLACK,"                                                              ");	
		}
		else if(strncmp(&command[q][0],"Helping!",strlen("Helping!"))==0){
		Write(2,4+35,LIGHTRED,BLACK,"*You can write in Condition with this way ...                 ");
		Write(2,5+35,LIGHTRED,BLACK,"  ... ex) ?if((2*[a]<=10&&12==[b])##[c]^2>1) {*               ");	
		Write(2,6+35,LIGHTRED,BLACK,"*Don't use Spacebar '&&' is And , '##' is Or*                 ");
		}
		else if(strncmp(&command[q][0],"Helping",strlen("Helping"))==0){
		Write(2,4+35,LIGHTRED,BLACK,"*You can use only English or number in variable names ...     ");
		Write(2,5+35,LIGHTRED,BLACK,"   ...  if you use others, it is replaced with '_'*           ");	
		Write(2,6+35,LIGHTRED,BLACK,"*ex) \"as+(name  )\" -> \"as__name___\"*                          ");	
	    }
	    else if(strncmp(&command[q][0],"Helpin",strlen("Helpin"))==0){
	    Write(2,4+35,LIGHTRED,BLACK,"*When you use print-commanders, consider max x and y ...      ");
		Write(2,5+35,LIGHTRED,BLACK," ... position. Present Max positions are 73 and 35 ...        ");	
		Write(2,6+35,LIGHTRED,BLACK," ... if Number goes beyond it , An Error occur*               ");
	    }
	    else if(strncmp(&command[q][0],"Helpi",strlen("Helpi"))==0){
	    Write(2,4+35,LIGHTRED,BLACK,"*When you write numbers, you can only the integer number*     ");
		Write(2,5+35,LIGHTRED,BLACK,"                                                              ");	
		Write(2,6+35,LIGHTRED,BLACK,"                                                              ");
	    }
	    else if(strncmp(&command[q][0],"Help",strlen("Help"))==0){
	    Write(2,4+35,LIGHTRED,BLACK,"*If you don't use '{}', '\"' or '[]', An error occured         ");
		Write(2,5+35,LIGHTRED,BLACK,"                                                              ");	
		Write(2,6+35,LIGHTRED,BLACK,"                                                              ");
	    }
	    else if(strncmp(&command[q][0],"Hel",strlen("Hel"))==0){
	    Write(2,4+35,LIGHTRED,BLACK,"*You can use only Variable and letter between ' \" '*          ");
		Write(2,5+35,LIGHTRED,BLACK,"*ex) /say \"a = [a]\"*                                          ");	
		Write(2,6+35,LIGHTRED,BLACK,"                                                              ");
	    }
	    else if(command[j][0]=='H'&&command[j][1]=='e'){
	    Write(2,4+35,LIGHTRED,BLACK,"*You can also use Variables including arithmetics there*      ");
		Write(2,5+35,LIGHTRED,BLACK,"*ex) /tell ([a]+1)^3 2 3+7 [b]*2+3 \"text\"*                  ");	
		Write(2,6+35,LIGHTRED,BLACK,"                                                              ");
	    }
	    else if(command[j][0]=='H'){
	    Write(2,4+35,LIGHTRED,BLACK,"*The capital letters in Helping massage are the text ...      ");
		Write(2,5+35,LIGHTRED,BLACK," ... that you must write numbers or letters there*            ");	
		Write(2,6+35,LIGHTRED,BLACK,"                                                              ");
	    }
////////////////////////////////////////////////////////////////////////////////////////////////		
		else if(command[j][0]=='/'&&strncmp(&command[j][1],"say",strlen("say"))==0){
		Write(2,4+35,LIGHTRED,BLACK,"/say \"TEXT\"                                                   ");
		Write(2,5+35,LIGHTRED,BLACK,"                                                              ");	
		Write(2,6+35,LIGHTRED,BLACK,"                                                              ");	
		}
		else if(command[j][0]=='/'&&strncmp(&command[j][1],"tell",strlen("tell"))==0){
		Write(2,4+35,LIGHTRED,BLACK,"/tell XPOS YPOS \"TEXT\"                                        ");
		Write(2,5+35,LIGHTRED,BLACK,"      ...       F-COLOR B-COLOR \"TEXT\"                        ");	
		Write(2,6+35,LIGHTRED,BLACK,"                                                              ");	
		}
		else if(command[j][0]=='/'&&strncmp(&command[j][1],"remove",strlen("remove"))==0){
		Write(2,4+35,LIGHTRED,BLACK,"/remove all                                                   ");
		Write(2,5+35,LIGHTRED,BLACK,"  ...   part X-FROM Y-FROM X-TO Y-TO                          ");	
		Write(2,6+35,LIGHTRED,BLACK,"                                                              ");	
		}
		else if(command[j][0]=='/'&&strncmp(&command[j][1],"fill",strlen("fill"))==0){
		Write(2,4+35,LIGHTRED,BLACK,"/fill X-FROM Y-FROM X-TO Y-TO B-COLOR *line(false)*           ");
		Write(2,5+35,LIGHTRED,BLACK,"                               ...   line(true) *empty(false)*");	
		Write(2,6+35,LIGHTRED,BLACK,"                                         ...    empty(true)   ");	
		}
		else if(command[j][0]=='/'&&strncmp(&command[j][1],"line",strlen("line"))==0){
		Write(2,4+35,LIGHTRED,BLACK,"/line X-FROM Y-FROM X-TO Y-TO B-COLOR                         ");
		Write(2,5+35,LIGHTRED,BLACK,"                                                              ");	
		Write(2,6+35,LIGHTRED,BLACK,"                                                              ");	
		}
		else if(command[j][0]=='/'&&strncmp(&command[j][1],"shape",strlen("shape"))==0){
		Write(2,4+35,LIGHTRED,BLACK,"/shape square SCALE XPOS YPOS B-COLOR *line(false)*           ");
		Write(2,5+35,LIGHTRED,BLACK," ...   triangle   ...          ...   line(true) *empty(false)*");	
		Write(2,6+35,LIGHTRED,BLACK," ...   circle     ...                     ...    empty(true)  ");	
		}
		else if(command[j][0]=='/'&&strncmp(&command[j][1],"attr",strlen("attr"))==0){
		Write(2,4+35,LIGHTRED,BLACK,"/attr move XPOS YPOS                                          ");
		Write(2,5+35,LIGHTRED,BLACK," ...  copy      ...                                           ");	
		Write(2,6+35,LIGHTRED,BLACK," ...  color F-COLOR BCOLOR                                    ");	
		}
		else if(command[j][0]=='/'&&strncmp(&command[j][1],"color",strlen("color"))==0){
		Write(2,4+35,LIGHTRED,BLACK,"/color F-COLOR BCOLOR                                         ");
		Write(2,5+35,LIGHTRED,BLACK,"                                                              ");	
		Write(2,6+35,LIGHTRED,BLACK,"                                                              ");	
		}
		else if(command[j][0]=='/'&&strncmp(&command[j][1],"random",strlen("random"))==0){
		Write(2,4+35,LIGHTRED,BLACK,"/random RAND-TO RAND-FROM [VARIABLE]                          ");
		Write(2,5+35,LIGHTRED,BLACK,"                                                              ");	
		Write(2,6+35,LIGHTRED,BLACK,"                                                              ");	
		}
		else if(command[j][0]=='/'&&strncmp(&command[j][1],"textlen",strlen("textlen"))==0){
		Write(2,4+35,LIGHTRED,BLACK,"/textlen \"TEXT\" [VARIABLE]                                    ");
		Write(2,5+35,LIGHTRED,BLACK,"  ...    [VARIABLE]                                           ");	
		Write(2,6+35,LIGHTRED,BLACK,"                                                              ");	
		}
		else if(command[j][0]=='/'&&strncmp(&command[j][1],"int",strlen("int"))==0){
		Write(2,4+35,LIGHTRED,BLACK,"/int \"VARIABLE\"                                             ");
		Write(2,5+35,LIGHTRED,BLACK,"      ...         = NUMBER                                    ");	
		Write(2,6+35,LIGHTRED,BLACK,"                                                              ");	
		}
		else if(command[j][0]=='/'&&strncmp(&command[j][1],"stop",strlen("stop"))==0){
		Write(2,4+35,LIGHTRED,BLACK,"/stop                                                         ");
		Write(2,5+35,LIGHTRED,BLACK,"                                                              ");	
		Write(2,6+35,LIGHTRED,BLACK,"                                                              ");	
		}
		else if(command[j][0]=='/'&&strncmp(&command[j][1],"delay",strlen("delay"))==0){
		Write(2,4+35,LIGHTRED,BLACK,"/delay TIME                                                   ");
		Write(2,5+35,LIGHTRED,BLACK,"                                                              ");	
		Write(2,6+35,LIGHTRED,BLACK,"                                                              ");	
		}
		else if(command[j][0]=='/'&&strncmp(&command[j][1],"goto",strlen("goto"))==0){
		Write(2,4+35,LIGHTRED,BLACK,"/goto LINE-POS                                                ");
		Write(2,5+35,LIGHTRED,BLACK,"                                                              ");	
		Write(2,6+35,LIGHTRED,BLACK,"                                                              ");	
		}
		else if(command[j][0]=='/'&&strncmp(&command[j][1],"vc",strlen("vc"))==0){
		Write(2,4+35,LIGHTRED,BLACK,"/vc [VARIABLE] = NUMBER                                       ");
		Write(2,5+35,LIGHTRED,BLACK,"           ... += ...                                         ");	
		Write(2,6+35,LIGHTRED,BLACK,"              .                                               ");
		}
		else if(command[j][0]=='/'&&strncmp(&command[j][1],"usef",strlen("usef"))==0){
		Write(2,4+35,LIGHTRED,BLACK,"/usef \"FUNC_NAME\" (VARIABLES)                                 ");
		Write(2,5+35,LIGHTRED,BLACK,"                                                              ");	
		Write(2,6+35,LIGHTRED,BLACK,"                                                              ");	
		}
		else if(command[j][0]=='/'&&strncmp(&command[j][1],"deff",strlen("deff"))==0){
		Write(2,4+35,LIGHTRED,BLACK,"/deff \"FUNC_NAME\" (VARIABLES) {                               ");
		Write(2,5+35,LIGHTRED,BLACK,"                                                              ");	
		Write(2,6+35,LIGHTRED,BLACK,"                                                              ");	
		}
		else if(command[j][0]=='?'&&strncmp(&command[j][1],"for",strlen("for"))==0){
		Write(2,4+35,LIGHTRED,BLACK,"?for(CONDITONS) REPEATION {                                   ");
		Write(2,5+35,LIGHTRED,BLACK,"           ...     i      ...                                 ");	
		Write(2,6+35,LIGHTRED,BLACK,"                                                              ");
		}
		else if(command[j][0]=='?'&&strncmp(&command[j][1],"test",strlen("test"))==0){
		Write(2,4+35,LIGHTRED,BLACK,"?test('CHARACTER') {                                          ");
		Write(2,5+35,LIGHTRED,BLACK," ...      key      ...                                        ");	
		Write(2,6+35,LIGHTRED,BLACK,"                                                              ");
		}
		else if(command[j][0]=='?'&&strncmp(&command[j][1],"if",strlen("if"))==0){
		Write(2,4+35,LIGHTRED,BLACK,"?if(CONDITONS) {                                              ");
		Write(2,5+35,LIGHTRED,BLACK,"                                                              ");	
		Write(2,6+35,LIGHTRED,BLACK,"                                                              ");
		}
		else if(command[j][0]=='?'&&strncmp(&command[j][1],"unless",strlen("unless"))==0){
		Write(2,4+35,LIGHTRED,BLACK,"?unless(CONDITONS) {                                          ");
		Write(2,5+35,LIGHTRED,BLACK,"                                                              ");	
		Write(2,6+35,LIGHTRED,BLACK,"                                                              ");
		}
		else if(command[j][0]=='}'){
		Write(2,4+35,LIGHTRED,BLACK,"*'}' is the finish of the detection commander*                ");
		Write(2,5+35,LIGHTRED,BLACK,"                                                              ");	
		Write(2,6+35,LIGHTRED,BLACK,"                                                              ");
		}
		else if((command[j][0]=='/'||command[j][0]=='?')&&command[j][0]!=' '){//함수 이름 검색  
		
		Write(2,4+35,LIGHTRED,BLACK,"                                                              ");
		Write(2,5+35,LIGHTRED,BLACK,"                                                              ");	
		Write(2,6+35,LIGHTRED,BLACK,"                                                              ");
			a=0;
			d=0;
			while(a<=99){
			strcpy(com_name, command_name[a].c_str());//결과값을 문자열로 변환  
			b=0;
			c=0;
			while(b<=29&&command[j][b]!=' '){
			if(command[j][b]==com_name[b]&&command[j][b]!=' ')
			c+=1;
			b+=1;
			}
			
			if(c==b&&c!=0&&c!=1){
			Gotoxy(2,4+35+d);
			textcolor(12,0);
			cout<<"*"<<command_name[a]<<"*";
			if(d!=2)
			d+=1;
			}		

			a+=1;
			}
		}//////////////////////////////////////////////////
		}
		else if(switch_num==1){
		if(switch_array[0][0]==1)
		Write(2,4+35,YELLOW,BLACK,"Present positon : Code Runnning                               ");
		else if(switch_array[0][1]==1)
		Write(2,4+35,YELLOW,BLACK,"Present positon : Code Clear                                  ");
		else if(switch_array[0][2]==1)
		Write(2,4+35,YELLOW,BLACK,"Present positon : Display Clear                               ");
		else if(switch_array[0][3]==1) 
		Write(2,4+35,YELLOW,BLACK,"Present positon : File System Open                            ");
		else if(switch_array[0][4]==1) 
		Write(2,4+35,YELLOW,BLACK,"Present positon : Length                                      ");
		else if(switch_array[1][0]==1) 
		Write(2,4+35,YELLOW,BLACK,"Present positon : Compile                                     ");
		else if(switch_array[1][1]==1) 
		Write(2,4+35,YELLOW,BLACK,"Present positon : void                                        ");
		else if(switch_array[1][2]==1) 
		Write(2,4+35,YELLOW,BLACK,"Present positon : void                                        ");
		else if(switch_array[1][3]==1) 
		Write(2,4+35,YELLOW,BLACK,"Present positon : void                                        ");
		else if(switch_array[1][4]==1) 
		Write(2,4+35,YELLOW,BLACK,"Present positon : Lines                                       ");
		else if(switch_array[0][5]==1) 
		Write(2,4+35,YELLOW,BLACK,"Present positon : Commander Setting                           ");
		else if(switch_array[1][5]==1) 
		Write(2,4+35,YELLOW,BLACK,"Present positon : Information about this program              ");
		
		Write(2,5+35,LIGHTRED,BLACK,"                                                              ");	
		Write(2,6+35,LIGHTRED,BLACK,"*'Tab' : Switching Mode    'w/a/s/d' : Move    'q' : Select*  ");
		}
	
	
	
//////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////	
//////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////	
//////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////	
////////////////////////////////////////////////////////////////////////////////
		if(switch_num==0){
		Write(46,1,LIGHTRED,LIGHTGRAY,"       ");//////////line,length 숫자 칸  
		Write(46,0,BLACK,WHITE,"       ");		
		} 
		
		
		if(switch_array[0][0]==1&&switch_num==1)
			Write(0,0,LIGHTRED,WHITE,"  Run▶  ");//2+5+2가 기본  
		else if(switch_array[0][0]==0||switch_num==0)
			Write(0,0,BLACK,WHITE,"  Run▶  ");
		if(switch_array[0][1]==1&&switch_num==1)
			Write(9,0,LIGHTRED,LIGHTGRAY," Clear☜ ");
		else if(switch_array[0][1]==0||switch_num==0)
			Write(9,0,BLACK,LIGHTGRAY," Clear☜ ");
		if(switch_array[0][2]==1&&switch_num==1)
			Write(18,0,LIGHTRED,WHITE," Clear☞ ");
		else if(switch_array[0][2]==0||switch_num==0)
			Write(18,0,BLACK,WHITE," Clear☞ ");
		if(switch_array[0][3]==1&&switch_num==1)
			Write(27,0,LIGHTRED,LIGHTGRAY," File ↓ ");
		else if(switch_array[0][3]==0||switch_num==0)
			Write(27,0,BLACK,LIGHTGRAY," File ↓ ");
		if(switch_array[0][4]==1&&switch_num==1){
			Write(36,0,BLACK,DARKGRAY,"  ");	
		Write(38,0,LIGHTRED,WHITE," Length:");	
		Gotoxy(46,0);
		textcolor(LIGHTRED,WHITE);
		cout<<wordlength;
		}
		else if(switch_array[0][4]==0||switch_num==0){
		Write(36,0,BLACK,DARKGRAY,"  ");	
		Write(38,0,BLACK,WHITE," Length:");	
		Gotoxy(46,0);
		textcolor(BLACK,WHITE);
		cout<<wordlength;
		}
		if(switch_array[0][5]==1&&switch_num==1){
		Write(55,0,LIGHTRED,LIGHTGRAY," setting ");	
		}		
		else if(switch_array[0][5]==0||switch_num==0){
		Write(55,0,BLACK,LIGHTGRAY," setting ");	
		}
		Write(53,0,BLACK,DARKGRAY,"  ");
		Write(53,1,BLACK,DARKGRAY,"  ");
		Write(64,0,BLACK,DARKGRAY,"  ");
		Write(64,1,BLACK,DARKGRAY,"  ");
		
		
		if(switch_array[1][0]==1&&switch_num==1)
			Write(0,1,LIGHTRED,LIGHTGRAY," Comp.▣ ");
		else if(switch_array[1][0]==0||switch_num==0)
			Write(0,1,BLACK,LIGHTGRAY," Comp.▣ ");
		if(switch_array[1][1]==1&&switch_num==1)
			Write(9,1,LIGHTRED,WHITE," void_## ");
		else if(switch_array[1][1]==0||switch_num==0)
			Write(9,1,BLACK,WHITE," void_## ");
		if(switch_array[1][2]==1&&switch_num==1)
			Write(18,1,LIGHTRED,LIGHTGRAY," void_## ");
		else if(switch_array[1][2]==0||switch_num==0)
			Write(18,1,BLACK,LIGHTGRAY," void_## ");
		if(switch_array[1][3]==1&&switch_num==1)
			Write(27,1,LIGHTRED,WHITE," void_## ");
		else if(switch_array[1][3]==0||switch_num==0)
			Write(27,1,BLACK,WHITE," void_## ");
		if(switch_array[1][4]==1&&switch_num==1){
			Write(36,1,BLACK,DARKGRAY,"  ");	
		Write(38,1,LIGHTRED,LIGHTGRAY," Lines: ");	
		Gotoxy(46,1);
		textcolor(LIGHTRED,LIGHTGRAY);
		cout<<wordline;
		}
		else if(switch_array[1][4]==0||switch_num==0){
			Write(36,1,BLACK,DARKGRAY,"  ");	
			Write(38,1,BLACK,LIGHTGRAY," Lines: ");	
			Gotoxy(46,1);
			textcolor(BLACK,LIGHTGRAY);
			cout<<wordline;
		}
		if(switch_array[1][5]==1&&switch_num==1){
			Write(55,1,LIGHTRED,WHITE," version ");	
		}		
		else if(switch_array[1][5]==0||switch_num==0){
			Write(55,1,BLACK,WHITE," version ");	
		}
////////////////////////////////////////////////////////	
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
		if(kbhit()&&switch_num==1){  
			but=_getch();
			if(but==0x09){//TAB
				switch_num=0;
			}
			else if(but=='w'&&switch_y>0){
				switch_array[switch_y][switch_x]=0;
				switch_y-=1;
			}	
			else if(but=='a'&&switch_x>0){
				switch_array[switch_y][switch_x]=0;
				switch_x-=1;	
			}
			else if(but=='s'&&switch_y<1){
				switch_array[switch_y][switch_x]=0;
				switch_y+=1;	
			}		
			else if(but=='d'&&switch_x<5){
				switch_array[switch_y][switch_x]=0;
				switch_x+=1;
			}
////////////////////////////////////////////////////////
		else if(but=='q'&&switch_array[0][1]==1){//클리어 커맨더  
			check=0;
			Write(2,4+35,YELLOW,BLACK,"CLEARING |   'y' : Yes   'n' : No                             ");
			while(check==0){
				if(kbhit()){
				but=_getch();
					if(but=='y')
					check=1;
					else if(but=='n')
					check=2;
				}
			}
			////////////
			if(check==1){
			a=0;
			b=0;
			while(a<=outputx-3-2){
				while(b<=35-1){
					Write(a+2,b+3,BLACK,WHITE," ");	
					b+=1;
				}
				b=0;
				a+=1;
			}
			a=0;
			b=0;
			while(a<=outputx-3-2){
				while(b<=inputy-1){
					command[b][a]=' ';
					b+=1;
				}
				b=0;
				a+=1;
			}
	////////////////////////		
			i=0;
			j=0;	
			com_height=0;
			wordlength=0;
			wordline=0;
			enterline=0;
			////////////////// 
			
			j1=1;
			while(j1<=35){
				Gotoxy(0,j1+3-1);
				if((j1+com_height)%2==1)
				textcolor(LIGHTGRAY,BLACK);
				else if((j1+com_height)%2==0)
				textcolor(WHITE,DARKGRAY);
				
				if(j1+com_height<=9)
				cout<<"0"<<j1+com_height;   
				else
				cout<<j1+com_height;  
	
				j1+=1;
			}
			////////////
			Write(2,4+35,YELLOW,BLACK,"                                                              ");
			}
		}
////////////////////////////////////////////////////////
		else if(but=='q'&&switch_array[0][2]==1){//클리어 디스플래이  
			check=0;
			Write(2,4+35,YELLOW,BLACK,"CLEARING |   'y' : Yes   'n' : No                             ");
			while(check==0){
				if(kbhit()){
				but=_getch();
					if(but=='y')
					check=1;
					else if(but=='n')
					check=2;
				}
			}
			if(check==1){
				a=0;
				b=0;
				while(a<=outputmaxx){
					while(b<=35-1){
						Write(a+outputx,b+3,BLACK,BLACK," ");
						b+=1;
					}
					b=0;
					a+=1;
				}
			}
		}
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////		
		else if(but=='q'&&switch_array[0][5]==1){//설정   
			a=0;
			while(a<=15){
				Write(outputx+10,8+a,YELLOW,WHITE,"                                     ");
				a+=1;
			}
			check=0;
			set_page=0;
			set_x=0;
			set_y=0;
			while(check==0){//////////////////////////////////////////////////////////////////////////////////
				
				if(set_y==0&&set_x==0)
				Write(outputx+10,8,LIGHTRED,LIGHTGRAY," out ");
				else if(set_y!=0||set_x!=0)
				Write(outputx+10,8,BLACK,LIGHTGRAY," out ");
				if(set_y==0&&set_x==1)
				Write(outputx+43,8,LIGHTRED,LIGHTGRAY," <");
				else if(set_y!=0||set_x!=1)
				Write(outputx+43,8,BLACK,LIGHTGRAY," <");
				if(set_y==0&&set_x==2)
				Write(outputx+45,8,LIGHTRED,LIGHTGRAY,"> ");
				else if(set_y!=0||set_x!=2)
				Write(outputx+45,8,BLACK,LIGHTGRAY,"> ");
				
				Gotoxy(outputx+26,23);
				textcolor(DARKGRAY,WHITE);
				cout<<set_page+1;
				Write(outputx+27,23,DARKGRAY,WHITE,"/5");
				
				if(set_page==0){//////////////////////////////page 1
					
				if(set_y==1){
				Write(outputx+11,11,LIGHTRED,WHITE,"cursor color ");
				Write(outputx+11,14,DARKGRAY,WHITE,"                ");
				Write(outputx+11+set_x,14,LIGHTRED,WHITE,"^");	
				cursor_color_pos=set_x;
				
				if(set_x==0)
				cursor_color=RED;
				else if(set_x==1)
				cursor_color=LIGHTRED;
				else if(set_x==2)
				cursor_color=BROWN;
				else if(set_x==3)
				cursor_color=YELLOW;
				else if(set_x==4)
				cursor_color=LIGHTGREEN;
				else if(set_x==5)
				cursor_color=GREEN;
				else if(set_x==6)
				cursor_color=LIGHTCYAN;
				else if(set_x==7)
				cursor_color=CYAN;
				else if(set_x==8)
				cursor_color=LIGHTBLUE;
				else if(set_x==9)
				cursor_color=BLUE;
				else if(set_x==10)
				cursor_color=LIGHTMAGENTA;
				else if(set_x==11)
				cursor_color=MAGENTA;
				else if(set_x==12)
				cursor_color=WHITE;
				else if(set_x==13)
				cursor_color=LIGHTGRAY;
				else if(set_x==14)
				cursor_color=DARKGRAY;
				else if(set_x==15)
				cursor_color=BLACK;
				}
				else{
				Write(outputx+11,11,DARKGRAY,WHITE,"cursor color ");
				Write(outputx+11+cursor_color_pos,14,BLACK,WHITE,"^");
				}
				
				if(set_y==2){
				Write(outputx+11,16,LIGHTRED,WHITE,"cursor shape ");
				Write(outputx+11,19,DARKGRAY,WHITE,"                ");
				Write(outputx+11+2*set_x,19,LIGHTRED,WHITE,"^");	
				cursor_shape_pos=set_x;
				}
				else{
				Write(outputx+11,16,DARKGRAY,WHITE,"cursor shape ");
				Write(outputx+11+2*cursor_shape_pos,19,BLACK,WHITE,"^");
				}
	
				Write(outputx+11,13,0,RED," ");
				Write(outputx+12,13,0,LIGHTRED," ");
				Write(outputx+13,13,0,BROWN," ");
				Write(outputx+14,13,0,YELLOW," ");
				Write(outputx+15,13,0,LIGHTGREEN," ");
				Write(outputx+16,13,0,GREEN," ");
				Write(outputx+17,13,0,LIGHTCYAN," ");
				Write(outputx+18,13,0,CYAN," ");
				Write(outputx+19,13,0,LIGHTBLUE," ");
				Write(outputx+20,13,0,BLUE," ");
				Write(outputx+21,13,0,LIGHTMAGENTA," ");
				Write(outputx+22,13,0,MAGENTA," ");
				Write(outputx+23,13,0,WHITE," ");
				Write(outputx+24,13,0,LIGHTGRAY," ");
				Write(outputx+25,13,0,DARKGRAY," ");
				Write(outputx+26,13,0,BLACK," ");
				
				Write(outputx+11,18,BLACK,LIGHTGRAY,"|");
				Write(outputx+13,18,BLACK,LIGHTGRAY,"_");
				Write(outputx+15,18,BLACK,LIGHTGRAY,"/");
				Write(outputx+17,18,BLACK,LIGHTGRAY,"?");
				Write(outputx+19,18,BLACK,LIGHTGRAY,"1");
				Write(outputx+21,18,BLACK,LIGHTGRAY,"!");
				Write(outputx+23,18,BLACK,LIGHTGRAY,"}");
				Write(outputx+25,18,BLACK,LIGHTGRAY,";");
				}//////////////////////////////page 1
	////////////////////////////////////////////////////////			
				if(kbhit()){
					but=_getch();	
					if(but=='w'&&set_y>0){//위  
						set_y-=1;
					if(set_y==0)
						set_x=0;
					else if(set_y==1)
						set_x=cursor_color_pos;
					else if(set_y==2)
						set_x=cursor_shape_pos;
					}//위  
					else if(but=='a'&&set_x>0){//왼  
						set_x-=1;	
					}
					else if(but=='s'&&set_y<2){//아래  
						set_y+=1;	
					if(set_y==1)
						set_x=cursor_color_pos;
					else if(set_y==2)
						set_x=cursor_shape_pos;
					}		
					else if(but=='d'&&((set_x<15&&set_y==1)||(set_x<7&&set_y==2)||(set_x<2&&set_y==0))){//오  
						set_x+=1;
					}	
					else if(but=='q'){
						if(set_y==0&&set_x==0){
							check=1;//나가기 	
							a=0;
							b=0;
							while(a<=outputmaxx){
								while(b<=35-1){
									Write(a+outputx,b+3,BLACK,BLACK," ");
									b+=1;
								}
								b=0;
								a+=1;
							}
						}			
						else if(set_y==0&&set_x==1&&set_page>0)
						set_page-=1;
						else if(set_y==0&&set_x==2&&set_page<4)
						set_page+=1;
						 
					}
				}
			}
		}
		////////////////////////////////////////////////////////
////////////////////////////////////////////////////////		
		else if(but=='q'&&switch_array[1][5]==1){//업데이트 내역    
			
			
			Write(outputx+10,8,DARKGRAY,WHITE,"                                     ");
			Write(outputx+10,8,LIGHTRED,LIGHTGRAY," out ");
			Write(outputx+10,9,DARKGRAY,WHITE,"                                     ");
			Write(outputx+10,10,BLACK,WHITE," version ");
			Gotoxy(outputx+19,10);
			textcolor(LIGHTRED,WHITE);
			cout<<"("<<version<<")                     ";
			Write(outputx+10,11,DARKGRAY,WHITE,"                                     ");
			Write(outputx+10,24,DARKGRAY,WHITE,"                                     ");
			
			check=0;
			while(check==0){//////////////////////////////////////////////////////////////////////////////////			
			version_text(12," 1.0.0                               ");
			version_text(13," /say,/remove                        ");
			version_text(14," the beginning of Commander          ");
			version_text(15,"                                     ");
			version_text(16," 1.1.0                               ");
			version_text(17," Character number detection          ");
			version_text(18," /tell,/remove part                  ");
			version_text(19," bug fixed                           ");
			version_text(20,"                                     ");
			version_text(21," 1.1.1                               ");
			version_text(22," /color,/fill,/shape square ...      ");
			version_text(23,"                                     ");
			version_text(24," 1.1.2                               ");
			version_text(25," /shape triangle, circle             ");
			version_text(26," /fill ... line() ... empty()        ");
			version_text(27,"                                     ");
			version_text(28," 1.1.3                               ");
			version_text(29," commander line number               ");
			version_text(30," /line                               ");
			version_text(31,"                                     ");
			version_text(32," 1.1.4                               ");
			version_text(33," /attribute,/delay,/stop             ");
			version_text(34," bug fixed                           ");
			version_text(35,"                                     ");
			version_text(36," 1.2.0                               ");
			version_text(37," can use variable in text            ");
			version_text(38," /int (variable added)               ");
			version_text(39,"                                     ");
			version_text(40," 1.2.1                               ");
			version_text(41," running check and helping ...       ");
			version_text(42," message added                       ");
			version_text(43," /vc,/while                          ");
			version_text(44," bug fixed                           ");
			version_text(45,"                                     ");
			version_text(46," 1.3.0                               ");
			version_text(47," can use mathematics and brackets    ");
			version_text(48," bug fixed                           ");
			version_text(49,"                                     ");
			version_text(50," 1.3.1                               ");
			version_text(51," /while -> /for                      ");
			version_text(52," infinite repeatition added          ");
			version_text(53," /test                               ");
			version_text(54,"                                     ");
			version_text(55," 1.3.2                               ");
			version_text(56," switching mode window added         ");
			version_text(57,"                                     ");
			version_text(58," 1.4.0                               ");
			version_text(59," command searching, conditions added ");
			version_text(60," display position                    ");
			version_text(61," /if,/goto                           ");
			version_text(62," bug fixed                           ");
			version_text(63,"                                     ");
			version_text(64," 1.4.1                               ");
			version_text(65," setting, info added                 ");
			version_text(66," Customizing cursor                  ");
			version_text(67," /attribute -> /attr                 ");
			version_text(68," /unless                             ");
			version_text(69,"                                     ");
			version_text(70," 1.4.2                               ");
			version_text(71," info update                         ");
			version_text(72,"                                     ");
			version_text(73," 1.5.0                               ");
			version_text(74," commander update                    ");
			version_text(75," (commander expansion ...            ");
			version_text(76," ... enter,backspace update)         ");
			version_text(77,"                                     ");
			version_text(78," 1.5.1                               ");
			version_text(79," /textlen                            ");
			version_text(80," Switching Mode update ...           ");
			version_text(81," (setting, commander size ...)       ");
			version_text(82,"                                     ");
			version_text(83," 1.5.2                               ");
			version_text(84," /break                              ");
			version_text(85," Length,Lines system ...             ");
			version_text(86," bug fixed                           ");
			version_text(87,"                                     ");
	
				if(kbhit()){
				but=_getch();	
					if(but=='q'){
						check=1;//나가기 	
			a=0;
			b=0;
			while(a<=outputmaxx){
				while(b<=35-1){
					Write(a+outputx,b+3,BLACK,BLACK," ");
					b+=1;
				}
			b=0;
			a+=1;
			}
					}
					else if(but=='w'){
					if(set_height<0)
					set_height+=1;				
					}
					else if(but=='s'){
					if(set_height>-64)//위에서 줄을 추가한 만클 빼야됨 (-30 -> -34 ) 
					set_height-=1;
					}
				}
			}
		}
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////	
//////////////////////////////////////////////////////////		실행  
			else if(but=='q'&&switch_array[0][0]==1){ 
				Write(2,4+35,YELLOW,BLACK,"--------------------------------------------------------------");
				Write(2,5+35,YELLOW,BLACK,"                  *Current Code Running*                      ");
				Write(2,6+35,YELLOW,BLACK,"--------------------------------------------------------------");
				colorf=15;
				colorb=0;
				f_amount=0;
				det_amount=0;
				test_cha=' ';
				
				a=0;
				while(a<=99){
					func_na[a]="";
					func_am[a]=0;
					det_func_y[a]=-1;
					det_y[a]=0;
					det_rep[a]=0;
					a+=1;
				}
				a=0;
				while(a<=inputy-1){
					exe_check[a]=0;
					a+=1;
				}
				
				suc_count=-1;
				suc_y=0;
				Write(outputx,4+35,LIGHTRED,BLACK,"                                                                        ");
				Write(outputx,5+35,LIGHTRED,BLACK,"                                                                        ");
				Write(outputx,6+35,LIGHTRED,BLACK,"                                                                        ");
				
				q=0; 
				while(q<=enterline){//max : inputy-2
//////////////////////////////////say					
					if(command[q][0]=='/'&&strncmp(&command[q][1],"say ",strlen("say "))==0){
						Fail_text(q);
						xpos=0;
						ypos=0;
						if(command[q][5]=='"'){
							a=0;
							while(a<=9999){
								text[a]=0;
								a+=1;
							}
						output_say(q);
						if(output_say(q))
							Success_text(q);
						}
						exe_check[q]=1;
					}
//////////////////////////////////remove						
					else if(command[q][0]=='/'&&strncmp(&command[q][1],"remove ",strlen("remove "))==0){
						Fail_text(q);
						length=0;
						xfrom=0;
						yfrom=0;
						xto=0;
						yto=0;
						if(strncmp(&command[q][8],"all",strlen("all"))==0){
						a=0;
						b=0;
						while(a<=outputmaxx){
							while(b<=35-1){
								Write(a+outputx,b+3,BLACK,BLACK," ");
								b+=1;
							}
							b=0;
							a+=1;
						}	
						Success_text(q);
						}
						else if(strncmp(&command[q][8],"part ",strlen("part "))==0){//
							formula_detect(13,q,&xfrom,0);
							posx_detect(&xfrom);
							formula_detect(15+length,q,&yfrom,0);
							posy_detect(&yfrom);
							formula_detect(17+length,q,&xto,0);
							posx_detect(&xto);
							formula_detect(19+length,q,&yto,0);	
							posy_detect(&yto);
							a=xfrom;
							b=yfrom;
							while(a<=xto){
								while(b<=yto){
									Write(a+outputx,b+3,BLACK,BLACK," ");
									b+=1;
								}
								b=yfrom;
								a+=1;
							}
							if(xfrom<=xto&&yfrom<=yto)
								Success_text(q);
						}//
						exe_check[q]=1;
					}
//////////////////////////////////tell			
					else if(command[q][0]=='/'&&strncmp(&command[q][1],"tell ",strlen("tell "))==0){
						Fail_text(q);
						length=0;
						colorf=15;
						colorb=0;
						xpos=0;
						ypos=0;

						formula_detect(6,q,&xpos,0);
						posx_detect(&xpos);
						formula_detect(8+length,q,&ypos,0);
						posy_detect(&ypos);
						
						if(command[q][10+length]!='"'){
						formula_detect(10+length,q,&colorf,0);
						formula_detect(12+length,q,&colorb,0);
						}				
//////////					
						if((command[q][14+length]=='"'&&command[q][10+length]!='"')||command[q][10+length]=='"'){
							a=0;
							while(a<=9999){
								text[a]=0;
								a+=1;
							}	
						output_tell(q,length);
						if(output_tell(q,length))
						Success_text(q);
						}
						exe_check[q]=1;
					}
////////////////////////////////color 					
					else if(command[q][0]=='/'&&strncmp(&command[q][1],"color ",strlen("color "))==0){
						Fail_text(q);
						length=0;
						formula_detect(7+length,q,&colorf,0);
						formula_detect(9+length,q,&colorb,0);
						
						if(colorf>=0&&colorb>=0)
						Success_text(q);
						exe_check[q]=1;
					}
//////////////////////////////////////////////////////delay
					else if(command[q][0]=='/'&&strncmp(&command[q][1],"delay ",strlen("delay "))==0){
						Fail_text(q);
						delaying=0;
						if(command[q][7]!=' '){
							formula_detect(7,q,&delaying,0);
						}
						Sleep(delaying);
						if(delaying!=0)
						Success_text(q);
						exe_check[q]=1;
					}
////////////////////////////////////////////fill
					else if(command[q][0]=='/'&&strncmp(&command[q][1],"fill ",strlen("fill "))==0){
						Fail_text(q);
						length=0;
						xfrom=0;
						yfrom=0;
						xto=0;
						yto=0;
						colorb=0;

						formula_detect(6,q,&xfrom,0);
						posx_detect(&xfrom);
						formula_detect(8+length,q,&yfrom,0);
						posy_detect(&yfrom);
						formula_detect(10+length,q,&xto,0);
						posx_detect(&xto);
						formula_detect(12+length,q,&yto,0);
						posy_detect(&yto);
						formula_detect(14+length,q,&colorb,0);
						output_fill(q,length);
						if(output_fill(q,length))
						Success_text(q);
						exe_check[q]=1;
					} 
///////////////////////////////////////line 
					else if(command[q][0]=='/'&&strncmp(&command[q][1],"line ",strlen("line "))==0){
						Fail_text(q);
						length=0;
						xfrom=0;
						yfrom=0;
						xto=0;
						yto=0;
						colorb=0;

						formula_detect(6,q,&xfrom,0);
						posx_detect(&xfrom);
						formula_detect(8+length,q,&yfrom,0);
						posy_detect(&yfrom);
						formula_detect(10+length,q,&xto,0);
						posx_detect(&xto);
						formula_detect(12+length,q,&yto,0);
						posy_detect(&yto);
						formula_detect(14+length,q,&colorb,0);
						if(xfrom!=xto&&yfrom!=yto){
						output_line();	
						if(output_line())
						Success_text(q);
						}
						exe_check[q]=1;
						
					} 
//////////////////////////////////////stop
					else if(command[q][0]=='/'&&strncmp(&command[q][1],"stop",strlen("stop"))==0){
						q=100;
					}	
					else if(command[q][0]=='/'&&strncmp(&command[q][1],"goto ",strlen("goto "))==0){
						line=0;
						formula_detect(6,q,&line,0);
						if(line-2<=enterline&&line-2>=0){
						q=line-2;
						}
						
					}	
//////////////////////////////////////////////////attribute
					else if(command[q][0]=='/'&&strncmp(&command[q][1],"attr ",strlen("attr "))==0){
						Fail_text(q);
						length=0;
						xpos1=0;
						ypos1=0;
						if(strncmp(&command[q][6],"move ",strlen("move "))==0||strncmp(&command[q][6],"copy ",strlen("copy "))==0){
						formula_detect(11+length,q,&xpos1,0);
						posx_detect(&xpos1);
						formula_detect(13+length,q,&ypos1,0);
						posx_detect(&ypos1);
						k=0;
						while(q-k!=-1&&q!=0){
						if(command[q-k][0]=='/'&&strncmp(&command[q-k][1],"say ",strlen("say "))==0){	
						break;	
						}
						else if(command[q-k][0]=='/'&&strncmp(&command[q-k][1],"tell ",strlen("tell "))==0){
						break;	
						}
						else if(command[q-k][0]=='/'&&strncmp(&command[q-k][1],"fill ",strlen("fill "))==0){
						break;	
						}
						else if(command[q-k][0]=='/'&&strncmp(&command[q-k][1],"line ",strlen("line "))==0){	
						break;							
						}
						else if(command[q-k][0]=='/'&&strncmp(&command[q-k][1],"shape ",strlen("shape "))==0){
						break;	
						}
						k+=1;	
						}
						if(command[q-k][0]=='/'&&strncmp(&command[q-k][1],"say ",strlen("say "))==0){		
							if(strncmp(&command[q][6],"move ",strlen("move "))==0){
								colorf1=colorf;
								colorb1=colorb;
								colorf=BLACK;
								colorb=BLACK;
								output_say(q-k);
								colorf=colorf1;
								colorb=colorb1;
							}
							xpos=xpos1;
							ypos=ypos1;
							output_say(q-k);
							if(output_say(q-k))
							Success_text(q);
						}
						else if(command[q-k][0]=='/'&&strncmp(&command[q-k][1],"tell ",strlen("tell "))==0){
							if(strncmp(&command[q][6],"move ",strlen("move "))==0){
								colorf1=colorf;
								colorb1=colorb;
								colorf=BLACK;
								colorb=BLACK;
								output_tell(q-1,length1);
								colorf=colorf1;
								colorb=colorb1;
							}
							xpos=xpos1;
							ypos=ypos1;
							output_tell(q-k,length1);
							if(output_tell(q-k,length1))
							Success_text(q);
						}
						else if(command[q-k][0]=='/'&&strncmp(&command[q-k][1],"fill ",strlen("fill "))==0){
							if(strncmp(&command[q][6],"move ",strlen("move "))==0){
								colorf1=colorf;
								colorb1=colorb;
								colorf=BLACK;
								colorb=BLACK;
								output_fill(q-k,length1);
								colorf=colorf1;
								colorb=colorb1;
							}
							xto=xpos1-xfrom+xto;
							xfrom=xpos1;
							yto=ypos1-yfrom+yto;
							yfrom=ypos1;
							
							output_fill(q-k,length1);
							if(output_fill(q-k,length1))
							Success_text(q);
						}
						else if(command[q-k][0]=='/'&&strncmp(&command[q-k][1],"line ",strlen("line "))==0){
							if(strncmp(&command[q][6],"move ",strlen("move "))==0){
								colorf1=colorf;
								colorb1=colorb;
								colorf=BLACK;
								colorb=BLACK;
								output_line();
								colorf=colorf1;
								colorb=colorb1;
							}
							xto=xpos1-xfrom+xto;
							xfrom=xpos1;
							yto=ypos1-yfrom+yto;
							yfrom=ypos1;
							
							output_line();			
							if(output_line())
							Success_text(q);				
						}
						else if(command[q-k][0]=='/'&&strncmp(&command[q-k][1],"shape ",strlen("shape "))==0){
							if(strncmp(&command[q][6],"move ",strlen("move "))==0){
								colorf1=colorf;
								colorb1=colorb;
								colorf=BLACK;
								colorb=BLACK;
								output_shape(q-k,length1);
								colorf=colorf1;
								colorb=colorb1;
							}
							xpos=xpos1;
							ypos=ypos1;
							
							output_shape(q-k,length1);	
							if(output_shape(q-k,length1))
							Success_text(q);						
						}
						}
						else if(strncmp(&command[q][11],"color ",strlen("color "))==0){
						formula_detect(12,q,&colorf,0);
						formula_detect(14+length,q,&colorb,0);
						k=0;
						while(q-k!=-1&&q!=0){
						if(command[q-k][0]=='/'&&strncmp(&command[q-k][1],"say ",strlen("say "))==0){	
						break;	
						}
						else if(command[q-k][0]=='/'&&strncmp(&command[q-k][1],"tell ",strlen("tell "))==0){
						break;	
						}
						else if(command[q-k][0]=='/'&&strncmp(&command[q-k][1],"fill ",strlen("fill "))==0){
						break;	
						}
						else if(command[q-k][0]=='/'&&strncmp(&command[q-k][1],"line ",strlen("line "))==0){	
						break;							
						}
						else if(command[q-k][0]=='/'&&strncmp(&command[q-k][1],"shape ",strlen("shape "))==0){
						break;	
						}
						k+=1;	
						}
						if(command[q-k][0]=='/'&&strncmp(&command[q-k][1],"say ",strlen("say "))==0){
							output_say(q-k);
							if(output_say(q-k))
							Success_text(q);
						}
						else if(command[q-k][0]=='/'&&strncmp(&command[q-k][1],"tell ",strlen("tell "))==0){
							output_tell(q-k,length1);
							if(output_tell(q-k,length1))
							Success_text(q);
						}
						else if(command[q-k][0]=='/'&&strncmp(&command[q-k][1],"fill ",strlen("fill "))==0){
							output_fill(q-k,length1);
							if(output_fill(q-k,length1))
							Success_text(q);
						}
						else if(command[q-k][0]=='/'&&strncmp(&command[q-k][1],"line ",strlen("line "))==0){
							output_line();				
							if(output_line())
							Success_text(q);			
						}
						else if(command[q-k][0]=='/'&&strncmp(&command[q-k][1],"shape ",strlen("shape "))==0){
							output_shape(q-k,length1);	
							if(output_shape(q-k,length1))
							Success_text(q);						
						}
						}
						else if(strncmp(&command[q][11],"scale ",strlen("scale "))==0){
						formula_detect(12+length,q,&scale,0);
						k=0;
						while(q-k!=-1&&q!=0){
						if(command[q-k][0]=='/'&&strncmp(&command[q-k][1],"shape ",strlen("shape "))==0){
						break;	
						}
						k+=1;	
						}
						if(command[q-k][0]=='/'&&strncmp(&command[q-k][1],"shape ",strlen("shape "))==0){
							output_shape(q-k,length1);	
							if(output_shape(q-k,length1))
							Success_text(q);						
						}
						}
						exe_check[q]=1;
					}
//////////////////////////////////////////////////shape 
					else if(command[q][0]=='/'&&strncmp(&command[q][1],"shape ",strlen("shape "))==0){
						Fail_text(q);
						length=0;
						scale=0;
						xpos=0;
						ypos=0;
						colorf=0;
						if(command[q][0]=='/'&&strncmp(&command[q][7],"triangle ",strlen("triangle "))==0){
							length=strlen("triangle ");
						}
						else if(command[q][0]=='/'&&strncmp(&command[q][7],"square ",strlen("square "))==0){
							length=strlen("square ");
						} 
						else if(command[q][0]=='/'&&strncmp(&command[q][7],"circle ",strlen("circle "))==0){
							length=strlen("circle ");
						}
						
						formula_detect(7+length,q,&scale,0);
						formula_detect(9+length,q,&xpos,0);
						formula_detect(11+length,q,&ypos,0);
						formula_detect(13+length,q,&colorb,0);
						
						output_shape(q,length);
						if(output_shape(q,length))
						Success_text(q);
						exe_check[q]=1;
					}
///////////////////////////////////////////////random
					else if(command[q][0]=='/'&&strncmp(&command[q][1],"random ",strlen("random "))==0){
						Fail_text(q);
						length=0;
						randto=0;
						randfrom=0;
						formula_detect(8+length,q,&randfrom,0);
						formula_detect(10+length,q,&randto,0);
						func_detect(12+length,q);
						func_am[func_pos]=rand()%(randto-randfrom+1)+randfrom;
						if(randfrom<randto)
						Success_text(q);
						exe_check[q]=1;
					}
///////////////////////////////////////////////textlen
					else if(command[q][0]=='/'&&strncmp(&command[q][1],"textlen ",strlen("textlen "))==0){
						Fail_text(q);
						length=0;
						
						if(command[q][9]=='"'){
							b=0;
							while(b<=99){
								intcha[b]=' ';
								text[b]=' ';
								b+=1;
							}

							a=0;//command
							a1=0;//text
							while(command[q][10+a]!='"'&&a<=outputx-3-8){
								func_text_com(10+a,q);
							}
							strlength=a1;	
							length=strlength;
							func_detect(12+a,q);
							func_am[func_pos]=strlength;
						}
						else if(command[q][9]=='['){
							func_detect(9,q);	
							func_am[func_pos]=strlength;
						}
						
						strlength=0;
						Success_text(q);
						exe_check[q]=1;
					}
//////////////////////////////////////////////////int  
					else if(command[q][0]=='/'&&strncmp(&command[q][1],"int \"",strlen("int \""))==0){
						Fail_text(q);
						length=0;
						k=0;//변수명에 띄어쓰기 감지 
						
						a=0;
						while(a<=9999){
							text1[a]=' ';
							a+=1;
						}
						
						text1[0]='[';
						a=1;
							while(command[q][5+a]!='"'&&a<=outputx-3-8){
								if(command[q][5+a]!=' '&&command[q][5+a]!='~'&&command[q][5+a]!='`'&&command[q][5+a]!='!'&&command[q][5+a]!='@'&&command[q][5+a]!='#'&&command[q][5+a]!='$'&&command[q][5+a]!='%'&&command[q][5+a]!='^'&&command[q][5+a]!='&'&&command[q][5+a]!='*'&&command[q][5+a]!='('&&command[q][5+a]!=')'&&command[q][5+a]!='-'&&command[q][5+a]!='+'&&command[q][5+a]!='='&&command[q][5+a]!='{'&&command[q][5+a]!='}'&&command[q][5+a]!='['&&command[q][5+a]!=']'&&command[q][5+a]!='?'&&command[q][5+a]!='<'&&command[q][5+a]!='>'&&command[q][5+a]!=','&&command[q][5+a]!='.'&&command[q][5+a]!=':'&&command[q][5+a]!=';'&&command[q][5+a]!='"'&&command[q][5+a]!='\'')
								text1[a]=command[q][5+a];
								else
								text1[a]='_';
								
								a+=1;
							}
						text1[a]=']';
						
						puts="";
						a=0;
						while(a<=99&&text1[a]!=' '){
							puts+=text1[a];
							a+=1;	
						}
						a=0;
						while(a<=99){//파일 이름 중복 확인  
							if(puts==func_na[a])
							break;
							
							a+=1;
						}

						if(a==100){//중복이 안되면  
							a=0;
							while(a<=99&&text1[a]!=' '){
								func_na[f_amount]+=text1[a];
								length+=1;
							a+=1;	
							}
						 	f_amount+=1;	
						 	Success_text(q);
						}

						if(command[q][6+length]=='='){
							formula_detect(8+length,q,&func_am[f_amount-1],0);
						}		
						exe_check[q]=1;
					}
/////////////////////////////////////vc
					else if(command[q][0]=='/'&&strncmp(&command[q][1],"vc ",strlen("vc "))==0){
						Fail_text(q);
						length=0;
						vc_C=0;
						
						func_detect(4,q);
						b=func_pos;
						length+=func_length;
						if(strncmp(&command[q][5+length],"+= ",strlen("+= "))==0){
							formula_detect(8+length,q,&vc_C,0);
							func_am[b]+=vc_C;
						}
						else if(strncmp(&command[q][5+length],"-= ",strlen("-= "))==0){
							formula_detect(8+length,q,&vc_C,0);
							func_am[b]-=vc_C;
						}
						else if(strncmp(&command[q][5+length],"*= ",strlen("*= "))==0){
							formula_detect(8+length,q,&vc_C,0);
							func_am[b]*=vc_C;
						}
						else if(strncmp(&command[q][5+length],"/= ",strlen("/= "))==0){
							formula_detect(8+length,q,&vc_C,0);
							func_am[b]/=vc_C;
						}
						else if(strncmp(&command[q][5+length],"= ",strlen("= "))==0){
							formula_detect(7+length,q,&vc_C,0);
							func_am[b]=vc_C;
						}
						Success_text(q);
						exe_check[q]=1;
					}					
////////////////////////////////////////for
					else if(command[q][0]=='?'&&strncmp(&command[q][1],"for",strlen("for"))==0){
					Fail_text(q);
					length=0;
					condition=0;
					if(command[q][4]=='('){
							if(command[q][5]!=')')
							condition_detect(5,q,&condition);
						if(command[q][6+length]==')'&&command[q][7+length]==' '){//예비  
							
							if(command[q][8+length]!='i'){//반복 횟수 감지 
								if(exe_check[q]==1){
									a=0;
									b=0;
									while(a<=enterline){
									if(q==det_func_y[a]){
									b=a;
									a=enterline+1;
									break;	
									}
									a+=1;	
									}
									formula_detect(8+length,q,&det_rep[b],0);//반복 횟수 
								}
									else if(exe_check[q]==0)
								formula_detect(8+length,q,&det_rep[det_amount],0);
							}
							else if(exe_check[q]==0&&command[q][8+length]=='i')
								det_rep[det_amount]=100;
	
	//////////////// 만약 i면 무한 반복 
							if(command[q][9+length]==' '&&command[q][10+length]=='{'&&exe_check[q]==0){
							
								det_func_y[det_amount]=q;
								a=q;
								b=0;
								while(a<=enterline){
								if(command[a][0]=='?'&&(strncmp(&command[a][1],"for",strlen("for"))==0||strncmp(&command[a][1],"if",strlen("if"))==0||strncmp(&command[a][1],"unless",strlen("unless"))==0||strncmp(&command[a][1],"test",strlen("test"))==0))
									b+=1;
									else if(command[a][0]=='}')
										b-=1;
										if(b==0){
										det_y[det_amount]=a;
										break;
										}
										a+=1;
									}
								det_amount+=1;	 
								Success_text(q);
							}	
							else
							det_rep[det_amount]=0;
							
							if(condition==0){//조건문 } 이동 
								if(exe_check[q]==1){
									a=0;
									b=0;
									while(a<=enterline){
									if(q==det_func_y[a]){
									b=a;
									a=enterline+1;
									break;	
									}
									a+=1;	
									}
									q=det_y[b];
								}
								else if(exe_check[q]==0)
									q=det_y[det_amount-1];		
							} 
							
						}
					}
					
					exe_check[q]=1;
					}
////////////////////////////////////test 
					else if(command[q][0]=='?'&&strncmp(&command[q][1],"test",strlen("test"))==0){
						Fail_text(q);
						condition=0;//거부 
						
						if(kbhit()){
						test_cha=_getch();
						}
							
						if((command[q][5]=='('&&command[q][6]=='\''&&command[q][8]=='\''&&command[q][9]==')'&&command[q][11]=='{')||(command[q][5]=='('&&command[q][6]=='k'&&command[q][7]=='e'&&command[q][8]=='y'&&command[q][9]==')'&&command[q][11]=='{')){ 
							if(exe_check[q]==1){
								a=0;
								b=0;
								while(a<=enterline){
								if(q==det_func_y[a]){
									b=a;
									a=enterline+1;
									break;	
								}
								a+=1;	
								}
								det_func_y[b]=q;
							}
							else if(exe_check[q]==0)
								det_func_y[det_amount]=q;
							
						if(exe_check[q]==0){
							a=q;
							b=0;
							while(a<=enterline){
							if(command[a][0]=='?'&&(strncmp(&command[a][1],"for",strlen("for"))==0||strncmp(&command[a][1],"if",strlen("if"))==0||strncmp(&command[a][1],"unless",strlen("unless"))==0||strncmp(&command[a][1],"test",strlen("test"))==0))
								b+=1;
								else if(command[a][0]=='}')
									b-=1;
									if(b==0){
									det_y[det_amount]=a;
									break;
									}
									a+=1;
								}
							det_amount+=1;	  							
						}

						
							
							if(test_cha==command[q][7]&&(command[q][6]!='k'&&command[q][7]!='e'&&command[q][8]!='y')){
							test_cha=' ';
							condition=1;//허용  
							}
							else if(command[q][6]=='k'&&command[q][7]=='e'&&command[q][8]=='y'){
							if(test_cha!='\\'&&test_cha!=' ')//'\'는 쓸 수 없기에 모든 키 감지용  
							condition=1;//허용  
							}
							
							if(condition==0){
								Success_text(q);
								exe_check[q]=1;
								if(exe_check[q]==1){
								a=0;
								b=0;
								while(a<=enterline){
								if(q==det_func_y[a]){
								b=a;
								a=enterline+1;
								break;	
								}
								a+=1;	
								}
								q=det_y[b];
								}
								else if(exe_check[q]==0)
								q=det_y[det_amount-1];	
							}
						}
						exe_check[q]=1;
					}
/////////////////////////////////////////if
					else if(command[q][0]=='?'&&(strncmp(&command[q][1],"if",strlen("if"))==0||strncmp(&command[q][1],"unless",strlen("unless"))==0)){
						condition=0;
						if(strncmp(&command[q][1],"if",strlen("if"))==0)
						length=0;
						else if(strncmp(&command[q][1],"unless",strlen("unless"))==0)
						length=4;
						if(command[q][3+length]=='('){
							if(command[q][4+length]!=' ')
							condition_detect(4+length,q,&condition);
////////////////////////////						조건 감지  
						if(command[q][5+length]==')'&&command[q][6+length]==' '&&command[q][7+length]=='{'){
							if(exe_check[q]==1){
							a=0;
							b=0;
							while(a<=enterline){
							if(q==det_func_y[a]){
							b=a;
							a=enterline+1;
							break;	
							}
							a+=1;	
							}
							det_func_y[b]=q;
							}
							else if(exe_check[q]==0)
							det_func_y[det_amount]=q;
							
							if(exe_check[q]==0){
								a=q;
								b=0;
								while(a<=enterline){
								if(command[a][0]=='?'&&(strncmp(&command[a][1],"for",strlen("for"))==0||strncmp(&command[a][1],"if",strlen("if"))==0||strncmp(&command[a][1],"unless",strlen("unless"))==0||strncmp(&command[a][1],"test",strlen("test"))==0))
									b+=1;
									else if(command[a][0]=='}')
										b-=1;
										if(b==0){
										det_y[det_amount]=a;
										break;
										}
										a+=1;
									}
								det_amount+=1;	  							
							}
	
							if((condition==0&&strncmp(&command[q][1],"if",strlen("if"))==0)||(condition!=0&&strncmp(&command[q][1],"unless",strlen("unless"))==0)){//조건문 } 이동  
							if(exe_check[q]==1){
							a=0;
							b=0;
							while(a<=enterline){
							if(q==det_func_y[a]){
							b=a;
							a=enterline+1;
							break;	
							}
							a+=1;	
							}
							q=det_y[b];
							}
							else if(exe_check[q]==0)
							q=det_y[det_amount-1];	
							}
							
							}
						}
					}
//////////////////////////////////////////}
					else if(command[q][0]=='}'){
						a=0;
						while(a<=enterline){
						if(q==det_y[a]){
						b=a;
						a=enterline+1;
						break;	
						}
						a+=1;	
						}
						if(command[det_func_y[b]][0]=='?'&&strncmp(&command[det_func_y[b]][1],"for",strlen("for"))==0){
						a=0;
						c=0;//무한 반복 감지 상수  
						while(a<=outputx-3-4){
						if(command[det_func_y[b]][a]==' '&&command[det_func_y[b]][a+1]=='i'&&command[det_func_y[b]][a+2]==' ')
						c+=1;
						a+=1; 
						}
						if(c==0)
						det_rep[b]-=1;

						if(det_rep[b]!=0)
						q=det_func_y[b]-1;	
						}				
					}
//////////////////////////////////감지완료 						
						q+=1;
				}
			}
		switch_array[switch_y][switch_x]=1;
		}
////////////////////////////////////////////////////////쓰기 모드 
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////

		else if(kbhit()&&switch_num==0){ 
		
		but=_getch();	
		if (GetAsyncKeyState(VK_UP) & 0x8000) { //위

        }
        else if (GetAsyncKeyState(VK_DOWN) & 0x8000) { //아래

        }
        else if (GetAsyncKeyState(VK_LEFT) & 0x8000) { //왼  

        }
        else if (GetAsyncKeyState(VK_RIGHT) & 0x8000) { //오  

        }
		else if(but!=0x08&&but!=0x09&&but!=0x0D&&but!='\\'&&but!='|'){
			if(j!=inputy-2||i!=outputx-3-1)
			wordlength+=1;///////////////문자수  
			if(i==outputx-3-2&&j!=inputy-2){
			wordline+=1;///////////////문자줄  	
			enterline+=1;
			wordlength+=1;
			}
			 
			
				
				if(i<=outputx-3-3){
				command[j][i]=but;	
				i+=1;	
				}
				else if(i==outputx-3-2&&j!=inputy-2){
				k=0;
			a=0;
			while(a<=outputx-3-1){
			if(command[inputy-2][a]!=' '&&command[inputy-2][a]!='\\')
			k+=1;//감지 상수  
			a+=1;
			}
			////////////
			if(k==0){
				Write(2+i,3+j-com_height,BLACK,WHITE," ");	
				command[j][i]='\\';	
				if(j==com_height+34){
				com_height+=1;	
				line_change_color(com_height);
				}
			
					Write(2+i,3+j-com_height,BLACK,WHITE," ");
					command[j][i]='\\';	
					a=0; 
					b=inputy-2;
					while(b>=j+1){
						while(a<=outputx-3-1){
							command[b+1][a]=command[b][a];
							a+=1;
						}	
						a=0;
						b-=1;
					}
					i=0;
					j+=1;
					line_change_color(j+1);		
				command[j][i]=but;	
				i+=1;	
			}
		////////////
			}
	//////////////////////////////// 색깔  				
					textcolor(BLACK,WHITE);
					if(command[j][0]=='?'||command[j][0]=='/'){
						textcolor(LIGHTRED,WHITE);
						if(command[j][i-1]=='0'||command[j][i-1]=='1'||command[j][i-1]=='2'||command[j][i-1]=='3'||command[j][i-1]=='4'||command[j][i-1]=='5'||command[j][i-1]=='6'||command[j][i-1]=='7'||command[j][i-1]=='8'||command[j][i-1]=='9'||command[j][i-1]=='['||command[j][i-1]==']')
							textcolor(LIGHTMAGENTA,WHITE);
						else if(command[j][i-1]=='~'||command[j][i-1]=='('||command[j][i-1]==')'||command[j][i-1]=='{'||command[j][i-1]=='}'||command[j][i-1]=='"'||command[j][i-1]=='\'')
							textcolor(BROWN,WHITE);
						else if(i-1!=0&&(command[j][i-1]=='+'||command[j][i-1]=='-'||command[j][i-1]=='*'||command[j][i-1]=='/'||command[j][i-1]=='&'||command[j][i-1]=='#'||command[j][i-1]=='='||command[j][i-1]=='%'||command[j][i-1]=='^'||command[j][i-1]=='<'||command[j][i-1]=='>'||command[j][i-1]=='!'))
							textcolor(LIGHTGREEN,WHITE);
						else if(command[j][i-1]=='\\')
							textcolor(WHITE,WHITE);
				a=0;
				k=0;//"감지 상수  
				while(a<=outputx-3&&i-1>=a){
					if(command[j][i-a]=='\''){
						k+=1;//"감지 상수
					}
					a+=1;
				}
				if((command[j][0]=='?'||command[j][0]=='/')&&k%2==1&&command[j][i-1]!=']') 
				textcolor(BROWN,WHITE);
				
				a=0;
				k=0;//"감지 상수  
				while(a<=outputx-3&&i>=a){
					if(command[j][i-a]=='"'){
						k+=1;//"감지 상수
					}
					a+=1;
				}
				if((command[j][0]=='?'||command[j][0]=='/')&&k%2==1&&command[j][i-1]!=']') 
				textcolor(BROWN,WHITE);
				
				k=0;
				a=0;//"감지 상수 
				b=0; //"감지 상수 
				while(k<=outputx-3&&i-1>=k){
					if(command[j][i-k]=='['){
						a+=1;//"감지 상수
					}
					else if(command[j][i-k]==']'){
						b+=1;//"감지 상수
					}
					k+=1;
				}
				if(a%2!=b%2)				
				textcolor(LIGHTMAGENTA,WHITE);
					}
					else if(command[j][0]=='}')
					textcolor(BROWN,WHITE);
/////////////////////////////////////////////////////////////////////////////////////////// 색깔  	
				Gotoxy(2+i-1,3+j-com_height);
				cout<<command[j][i-1];  	
				
			}
////////////////////////////////////////////////////	
			else if(but==0x08&&i<=outputx-3-1){    //backspace 감지 
				Write(2+i,3+j-com_height,BLACK,WHITE," ");//커서 깜빡이 없애기  
				if(i!=0)
				wordlength-=1;///////////////문자수 	
				if(i==0&&j!=0){
				wordline-=1;///////////////문자줄	
				enterline-=1;
				wordlength-=1;
				}
				
				
				
				if(i>0){
					i-=1;
					Write(2+i,3+j-com_height,BLACK,WHITE," ");
				}
				else if(i==0){
					if(j==com_height&&j!=0){
					com_height-=1;	
					line_change_color(com_height);
					}
				b=j;
				while(b<=com_height+34){
				Write(2,3+b-com_height,BLACK,WHITE,"                                                              ");
				b+=1;
				}
				a=0;
				b=j;
				while(b<=inputy-2){
					while(a<=outputx-3-1){
						command[b][a]=command[b+1][a];
						a+=1;
					}	
					a=0;
					b+=1;
				}
				a=0;
				while(a<=outputx-3-2){
					command[inputy-2][a]=' ';
					a+=1;	
				}
					if(j>=1)//커서 이동  
					j-=1;
					i1=0;
					while(i1<=outputx-3-1){
						if(command[j][i1]=='\\'){
						i=i1;	
						break;
						}		
						i1+=1;
					}
					line_change_color(j);
				}
				////////////	
				command[j][i]=' ';	
			}	
			else if(but==0x0D&&i<=outputx-3-1&&j<=com_height+34&&j!=inputy-2){   //0x0D enter//////////////////////////////////////////////////
			if(j!=inputy-2){
			wordline+=1;///////////////문자줄
			enterline+=1;	
			wordlength+=1;
			}
			
			
			
			k=0;
			a=0;
			while(a<=outputx-3-1){
				if(command[inputy-2][a]!=' '&&command[inputy-2][a]!='\\')
				k+=1;//감지 상수  
				a+=1;
			}
			////////////
			if(k==0){
				if(j==com_height+34){
				com_height+=1;	
				line_change_color(com_height);
				}
			
					Write(2+i,3+j-com_height,BLACK,WHITE," ");
					command[j][i]='\\';	
					a=0;
					b=inputy-2;
					while(b>=j+1){
						while(a<=outputx-3-1){
							command[b+1][a]=command[b][a];
							a+=1;
						}	
						a=0;
						b-=1;
					}
					a=0;
					while(a<=outputx-3-2){
						command[j+1][a]=' ';
						Write(2+a,4+j-com_height,BLACK,WHITE," ");
						a+=1;	
				}
					i=0;
					j+=1;
					line_change_color(j+1);		
			}
////////////////////////////////////////////////				
			}
			else if(but=='|'&&j>=com_height&&j!=0){//////////////////////////////////////////////////
			if(j==com_height){
			com_height-=1;	
			line_change_color(com_height);
			}
			Write(2+i,3+j-com_height,BLACK,WHITE," ");
			command[j][i]='\\';	
					i1=0;
					while(i1<=outputx-3-1){
						if(command[j-1][i1]=='\\'){
						i=i1;	
						break;
						}		
						i1+=1;
					}
					if(i1==outputx-3)
					i=0;
					j-=1; 			
			}
			else if(but=='\\'&&j<=com_height+34&&j!=inputy-2&&enterline>j){//////////////////////////////////////////////////
			if(j==com_height+34){
			com_height+=1;	
			line_change_color(com_height);
			}
			Write(2+i,3+j-com_height,BLACK,WHITE," ");
			command[j][i]='\\';	
					i1=0;
					while(i1<=outputx-3-1){
						if(command[j+1][i1]=='\\'){
						i=i1;	
						break;
						}		
						i1+=1;
					}
					if(i1==outputx-3)
					i=0;
					j+=1;   
			}
			////////////////////////////////////////////////////////////////////////
			else if(but==0x09){//tab 
			switch_num=1;
			Write(2+i,3+j-com_height,BLACK,WHITE," ");//커서 깜빡이 없애기 
			}
//////////////////////////////////////////////////////////////////////////////////			
		j1=1;
		while(j1<=35){
			if(j1+com_height<=enterline+1){
			Gotoxy(0,j1+3-1);
			if((j1+com_height)%2==1)
			textcolor(LIGHTGRAY,BLACK);
			else if((j1+com_height)%2==0)
			textcolor(WHITE,DARKGRAY);
			
			if(j1+com_height<=9)
			cout<<"0"<<j1+com_height;   
			else
			cout<<j1+com_height;		
			}
			else
			Write(0,j1+3-1,LIGHTGRAY,LIGHTGRAY,"  ");
			  

			j1+=1;
		}
////////////////////////////////////////////////////////////////////////////////////////
			if(wordline<0)//////////////////////초기화  
			wordline=0;
			if(wordlength<0)
			wordlength=0;
			
			}
		if(switch_num==0){
		if(i<=outputx-3-1&&p>=30&&p<50){//단위시간상수 p 
		Gotoxy(2+i,3+j-com_height);
		textcolor(cursor_color,WHITE);
		cout<<cursor_shape[cursor_shape_pos];
		}
		else if(i<=outputx-3-1&&p>=60){//단위시간상수 p 
		Write(2+i,3+j-com_height,WHITE,WHITE," ");
		p=0;	//단위시간상수 p 
		}
		Sleep(5);
		p+=1;//단위시간상수 p 	
		}
	}

}	
