#pragma once
#include <iostream>
using namespace std;
#define MAX 3	//나중에 for문에 넣기 위한 값


class mat3 //mat3라는 3x3행렬을 class로 만들었음
{
private:


public:
	float m[3][3];	//3x3행렬
	mat3(float a = 0, float b = 0, float c = 0, float d = 0, float e = 0, float f = 0, float g = 0, float h = 0, float i = 0);
	//행렬의 값들을 나중에 넣어주기 위한 함수 이다.

	mat3 identity();	//mat3의 값을 단위행렬로 초기화 시켜주는 함수
	mat3 transpose();	//mat3의 값을 전치행렬로 바꿔주는 함수
	void nain();		//값을 출력하기 위한 함수
	mat3 operator*(const mat3& a);//나중에 곱하기를 하기위한 함수
	mat3 operator/(const mat3& a);//나중에 나누기를 하기위한 함수
	mat3 operator+(const mat3& a);//나중에 더하기를 하기위한 함수
	mat3 operator-(const mat3& a);//나중에 빼기를 하기위한 함수

};

mat3::mat3(float a, float b, float c, float d, float e, float f, float g, float h, float i)

{

	//mat3의 행렬을 초기화 시켜준다.

	m[0][0] = a;

	m[0][1] = b;

	m[0][2] = c;

	m[1][0] = d;

	m[1][1] = e;

	m[1][2] = f;

	m[2][0] = g;

	m[2][1] = h;

	m[2][2] = i;

}

class vec3 : public mat3//vec3 class를 만들어 vector을 만들기 위한 함수
{
private:

public:
	float v[3][1];	//3x1행렬로 만듬
	float x, y, z;
	vec3 transpose();//vec3의 값을 전치행렬로 바꿔주는 함수
	void nain();//값을 출력하기 위한 함수
	vec3 operator*(const vec3& a);//나중에 곱하기를 하기위한 함수
	float v_col = sizeof(v[0]) / sizeof(float);//Vector의 배열의 크기를 정확하게 알기 위해 쓰이는 코드로 나중에 행렬 곱을 할때 필요하다.
	float v_row = sizeof(v) / sizeof(v[0]);//Vector의 배열의 크기를 정확하게 알기 위해 쓰이는 코드로 나중에 행렬 곱을 할때 필요하다.

	vec3()
	{
		x = v[0][0] = 0;
		y = v[1][0] = 0;
		z = v[2][0] = 1;
	}//값을 입력받지 않았을때의 원점

	vec3(float x, float y, float z)
	{
		x = v[0][0] = x;
		y = v[1][0] = y;
		z = v[2][0] = z;
	}//값을 입력받아서 원점을 설정
};

class vec4//vec4 class를 만들어 vector을 만들기 위한 함수
{
private:

public:
	float v[4][1];//4x1행렬로 만듬
	vec4(float x = 0, float y = 0, float z = 0, float w = 0);//벡터의 값들을 나중에 넣어주기 위한 함수 이다.

	vec4 transpose();//vec4의 값을 전치행렬로 바꿔주는 함수
	void nain();//값을 출력하기 위한 함수
	vec4 operator*(const vec4& a);//나중에 곱하기를 하기위한 함수
	float v_col = sizeof(v[0]) / sizeof(float);//Vector의 배열의 크기를 정확하게 알기 위해 쓰이는 코드로 나중에 행렬 곱을 할때 필요하다.
	float v_row = sizeof(v) / sizeof(v[0]);//Vector의 배열의 크기를 정확하게 알기 위해 쓰이는 코드로 나중에 행렬 곱을 할때 필요하다.

};

vec4::vec4(float x, float y, float z, float w)

{
	//vec4의 행렬을 초기화 시켜준다

	v[0][0] = z;

	v[0][1] = y;

	v[0][2] = z;

	v[0][3] = w;


}


class mat4//mat4라는 4x4행렬을 class로 만들었음
{
private:


public:
	float m[3][3]; //4x4행렬
	mat4(float a = 0, float b = 0, float c = 0, float d = 0, float e = 0, float f = 0, float g = 0, float h = 0, float i = 0, float j = 0,
		float k = 0, float l = 0, float n = 0, float o = 0, float p = 0, float q = 0);
	//mat4의 값들을 나중에 넣어주기 위한 함수 이다.

	mat4 identity();//mat4의 값을 단위행렬로 초기화 시켜주는 함수
	mat4 transpose();//mat4의 값을 전치행렬로 바꿔주는 함수
	void nain();//값을 출력하기 위한 함수
	mat4 operator*(const mat4& a);//나중에 곱하기를 하기위한 함수
	mat4 operator/(const mat4& a);//나중에 나누기를 하기위한 함수
	mat4 operator+(const mat4& a);//나중에 더하기를 하기위한 함수
	mat4 operator-(const mat4& a);//나중에 빼기를 하기위한 함수


};

mat4::mat4(float a, float b, float c, float d, float e, float f, float g, float h, float i, float j,
	float k, float l, float n, float o, float p, float q)

{

	//mat4의 행렬을 초기화 시켜준다

	m[0][0] = a; m[0][1] = b; m[0][2] = c; m[0][3] = d; m[1][0] = e; m[1][1] = f; m[1][2] = g;

	m[1][3] = h; m[2][0] = i; m[2][1] = j; m[2][2] = k; m[2][3] = l; m[3][0] = n; m[3][1] = o;

	m[3][2] = p; m[3][3] = q;

}




mat3 mat3::identity() //mat3의 값을 단위행렬로 초기화 시켜주는 함수

{
	float c[3][3] = {//단위 행렬을 초기화하기 위한 행렬
		{1,0,0},
		{0,1,0},
		{0,0,1}
	};

	for (int i = 0; i < MAX; i++)

		for (int j = 0; j < MAX; j++)

			m[i][j] = c[i][j];//m행렬의 값을 단위행렬c의 값으로 덮어서 초기화 시킨다.

	return *this;

}

mat4 mat4::identity()//mat4의 값을 단위행렬로 초기화 시켜주는 함수

{
	float c[3][3] = {//단위 행렬을 초기화하기 위한 행렬
		{1,0,0},
		{0,1,0},
		{0,0,1}
	};

	//행렬 복사

	for (int i = 0; i < MAX; i++)

		for (int j = 0; j < MAX; j++)

			m[i][j] = c[i][j];//m행렬의 값을 단위행렬c의 값으로 덮어서 초기화 시킨다.

	return *this;

}


mat3 mat3::transpose()//mat3의 값을 전치 시켜주는 함수이다.

{

	mat3 copy; //새로운 Matrix 생성

	 //행렬 복사

	for (int i = 0; i < MAX; i++)

		for (int j = 0; j < MAX; j++)

			copy.m[i][j] = m[i][j];	//m의 행렬을 다른 행렬에다가 복사 시킨다.

	//전치

	for (int i = 0; i < MAX; i++)

		for (int j = 0; j < MAX; j++)

			m[j][i] = copy.m[i][j];	//복사된 행렬을 다시 m의 값으로 넣는데 j,i의 위치를 바꿔서 전치를 이르키게 해준다.

	return *this;

}

mat4 mat4::transpose()//mat4의 값을 전치 시켜주는 함수이다.

{

	mat4 copy; //새로운 Matrix 생성

	 //행렬 복사

	for (int i = 0; i < MAX; i++)

		for (int j = 0; j < MAX; j++)

			copy.m[i][j] = m[i][j];//m의 행렬을 다른 행렬에다가 복사 시킨다.

	//전치

	for (int i = 0; i < MAX; i++)

		for (int j = 0; j < MAX; j++)

			m[j][i] = copy.m[i][j];//복사된 행렬을 다시 m의 값으로 넣는데 j,i의 위치를 바꿔서 전치를 이르키게 해준다.

	return *this;

}

vec3 vec3::transpose()//vec3의 값을 전치 시켜주는 함수이다.

{
	vec3 copy; //새로운 vector 생성


	 //행렬 복사

	for (int i = 0; i < copy.v_row; i++) {//Vector의 행렬의 크기를 알아야 해서 vec3에 있는 v_row의 값을 넣는다.
		for (int j = 0; j < copy.v_col; j++) {
			copy.v[i][j] = v[i][j];//v의 행렬을 다른 행렬에다가 복사 시킨다.
		}
	}

	//전치

	for (int i = 0; i < copy.v_row; i++) {
		for (int j = 0; j < copy.v_col; j++) {
			v[j][i] = copy.v[i][j];//복사된 행렬을 다시 v의 값으로 넣는데 j,i의 위치를 바꿔서 전치를 이르키게 해준다.
		}
		return *this;
	}

}

vec4 vec4::transpose()//vec4의 값을 전치 시켜주는 함수이다.

{
	vec4 copy; //새로운 vector 생성


	 //행렬 복사

	for (int i = 0; i < copy.v_row; i++) {//Vector의 행렬의 크기를 알아야 해서 vec4에 있는 v_row의 값을 넣는다.
		for (int j = 0; j < copy.v_col; j++) {
			copy.v[i][j] = v[i][j];//v의 행렬을 다른 행렬에다가 복사 시킨다.
		}
	}

	//전치

	for (int i = 0; i < copy.v_row; i++) {
		for (int j = 0; j < copy.v_col; j++) {
			v[j][i] = copy.v[i][j];//복사된 행렬을 다시 v의 값으로 넣는데 j,i의 위치를 바꿔서 전치를 이르키게 해준다.
		}
		return *this;
	}

}



mat3 mat3::operator*(const mat3& a)//곱셈을 하기 위한 함수

{

	mat3 b; //새로운 Matrix 생성

	for (int i = 0; i < MAX; i++)

		for (int j = 0; j < MAX; j++)

			b.m[i][j] = m[i][j] * a.m[i][j]; //곱셈

	return b;

}

mat4 mat4::operator*(const mat4& a)//곱셈을 하기 위한 함수

{

	mat4 b; //새로운 Matrix 생성

	for (int i = 0; i < MAX; i++)

		for (int j = 0; j < MAX; j++)

			b.m[i][j] = m[i][j] * a.m[i][j]; //곱셈

	return b;

}

vec3 operator*(const vec3 a, const mat3 b)//곱셈을 하기 위한 함수

{
	mat3 m = b;
	vec3 c; //새로운 Matrix 생성

	float x = a.x;//vec3의 있는 x의 값을 변수의 x값에 넣는다.
	float y = a.y;//vec3의 있는 y의 값을 변수의 y값에 넣는다.
	float z = a.z;//vec3의 있는 z의 값을 변수의 z값에 넣는다.
	m = m.transpose();
	c.x = (x * m.m[0][0]) + (y * m.m[0][1]) + (z * m.m[0][2]);//vector와 matrix의 곱셈을 하기위한 공식
	c.y = (x * m.m[1][0]) + (y * m.m[1][1]) + (z * m.m[1][2]);
	c.z = (x * m.m[2][0]) + (y * m.m[2][1]) + (z * m.m[2][2]);


	return c;

}

vec4 vec4::operator*(const vec4& a)//곱셈을 하기 위한 함수

{

	vec4 c; //새로운 Matrix 생성

	for (int i = 0; i < MAX; i++)

		for (int j = 0; j < 1; j++)

			c.v[i][j] = v[i][j] * a.v[i][j]; //곱셈

	return c;

}

mat3 mat3::operator/(const mat3& a)//나눗셈을 하기 위한 함수

{

	mat3 b; //새로운 Matrix 생성

	for (int i = 0; i < MAX; i++)

		for (int j = 0; j < MAX; j++)

			b.m[i][j] = m[i][j] / a.m[i][j]; //나눗셈

	return b;

}

mat4 mat4::operator/(const mat4& a)//나눗셈을 하기 위한 함수

{

	mat4 b; //새로운 Matrix 생성

	for (int i = 0; i < MAX; i++)

		for (int j = 0; j < MAX; j++)

			b.m[i][j] = m[i][j] / a.m[i][j]; //나눗셈

	return b;

}


mat3 mat3::operator+(const mat3& a)//더하기를 하기 위한 함수
{

	mat3 b; //새로운 Matrix 생성
	vec3 c;

	for (int i = 0; i < c.v_row; i++)

		for (int j = 0; j < c.v_col; j++)

			b.m[i][j] = m[i][j] + c.v[i][j];

	return b;
}

mat3 mat3::operator-(const mat3& a)//빼기를 하기 위한 함수
{
	mat3 b; //새로운 Matrix 생성
	vec3 c;

	for (int i = 0; i < c.v_row; i++)

		for (int j = 0; j < c.v_col; j++)

			b.m[i][j] = m[i][j] - c.v[i][j];

	return b;
}



void mat3::nain()
{
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			cout << m[i][j]; //mat3의 m의 행렬 값을 출력
			if (j < 2) cout << " ";	//띄어쓰기를 위한 코드
		}
		cout << endl;
	}
}

void mat4::nain()
{
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			cout << m[i][j]; //mat4의 m의 행렬 값을 출력
			if (j < 2) cout << " ";	//띄어쓰기를 위한 코드
		}
		cout << endl;
	}
}

void vec3::nain()
{
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < 1; j++) {
			cout << v[i][j]; //vec3의 v의 행렬 값을 출력
			if (j < 2) cout << " ";	//띄어쓰기를 위한 코드
		}
		cout << endl;
	}
}

void vec4::nain()
{
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < 1; j++) {
			cout << v[i][j]; //vec4의 v의 행렬 값을 출력
			if (j < 2) cout << " ";	//띄어쓰기를 위한 코드
		}
		cout << endl;
	}
}


