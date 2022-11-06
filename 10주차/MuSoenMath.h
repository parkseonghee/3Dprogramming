#pragma once
using namespace std;

class vec3	// vec3라는 클래스를 만들어 Vector하고 동차좌표를 넣는다.
{
public:

	float v[3][1] =		//Vector의 값을 배열로 정렬 3x1 행렬
	{
		{2},    //x
		{2},	//y
		{1}		//1
	};

	float v_col = sizeof(v[0]) / sizeof(float);		//Vector의 배열의 크기를 정확하게 알기 위해 쓰이는 코드로 나중에 행렬 곱을 할때 필요하다.
	float v_row = sizeof(v) / sizeof(v[0]);			//Vector의 배열의 크기를 정확하게 알기 위해 쓰이는 코드로 나중에 행렬 곱을 할때 필요하다.

	float p[3][3] = { 0 };	//나중애 구한 결과값을 p의 배열에 담기 위해 쓰인다. 3x3행렬


private:

};



class mat3 //mat3라는 클래스를 만들어 Translate, Scale, Rotata의 행렬 값을 정의하고 값을 집어 넣는다.
{
public:

	float translate[3][3] =	//translate의 값을 3x3행렬로 정의하고 값을 집어넣었다.
	{
		{1,0,1},
		{0,1,3},
		{0,0,1}
	};


	float scale[3][3] = //scale의 값을 3x3행렬로 정의하고 값을 집어넣었다.
	{
		{1,0,0},
		{0,1,0},
		{0,0,1}
	};


	double PI = 3.1415926;	//π의 값을 정의했다.
	float cos = 0.15425144988;	//cos30의 값을 정의하기 위해 값을 넣었다.
	float sin = 0.5;		//sin 30의 값을 정의하기 위해 값을 넣었다.

	float rotate[3][3] = //rotate의 값을 3x3행렬로 정의하고 값을 집어넣었다.
	{
		{cos,-sin,0},
		{sin,cos,0},
		{0,0,1}
	};


private:

};




void nain()
{
	float C[3][3] = { 0 };	//나중에 행렬들의 곱을 담기 위한 변수로 3x3 행렬이다.
	float A[3][3] = { 0 };	//나중에 행렬들의 곱을 담기 위한 변수로 3x3 행렬이다.

	mat3 Translate, Rotate, Scale; //math3 클래스 안에 있는 translate, rotate, scale을 가져오기 위해 변수를 만든다.
	vec3 V, P;	//vec3 클래스 안에 있는 Vector, p의 값을 가져오기 위해 변수를 만든다.


	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				C[i][j] += Scale.scale[i][k] * Translate.translate[k][j];	//scale의 행렬과 translate의 행렬을 
																			//곱한 값을 C행렬 값에 넣는다.
			}
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				A[i][j] += Rotate.rotate[i][k] * C[k][j];//rotate의 행렬과 아깐전에 scale과translate를 곱한 값인 
														 //C의 행렬과 곱해 A행렬에 값을 넣는다.
			}
		}
	}

	for (int i = 0; i < V.v_row; i++) {		//Vector의 행렬의 크기를 알아야 해서 vec3에 있는 v_row의 값을 넣는다.
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < V.v_col; k++) {
				P.p[i][j] += V.v[i][k] * A[k][j];	//vec3에 있는 Vector의 행렬과 아까전에 rotate*scale*translate의 값을 곱해 
													//vec3에 있는 p의 행렬값에 넣는다.
			}
		}
	}
	cout << "vec3 p의 값은\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			//cout << C[i][j];
			cout << P.p[i][j];
			if (j < 2) cout << " ";	//띄어쓰기를 위한 코드
		}
		cout << endl;
	}



}