#pragma once
using namespace std;

class vec3	// vec3��� Ŭ������ ����� Vector�ϰ� ������ǥ�� �ִ´�.
{
public:

	float v[3][1] =		//Vector�� ���� �迭�� ���� 3x1 ���
	{
		{2},    //x
		{2},	//y
		{1}		//1
	};

	float v_col = sizeof(v[0]) / sizeof(float);		//Vector�� �迭�� ũ�⸦ ��Ȯ�ϰ� �˱� ���� ���̴� �ڵ�� ���߿� ��� ���� �Ҷ� �ʿ��ϴ�.
	float v_row = sizeof(v) / sizeof(v[0]);			//Vector�� �迭�� ũ�⸦ ��Ȯ�ϰ� �˱� ���� ���̴� �ڵ�� ���߿� ��� ���� �Ҷ� �ʿ��ϴ�.

	float p[3][3] = { 0 };	//���߾� ���� ������� p�� �迭�� ��� ���� ���δ�. 3x3���


private:

};



class mat3 //mat3��� Ŭ������ ����� Translate, Scale, Rotata�� ��� ���� �����ϰ� ���� ���� �ִ´�.
{
public:

	float translate[3][3] =	//translate�� ���� 3x3��ķ� �����ϰ� ���� ����־���.
	{
		{1,0,1},
		{0,1,3},
		{0,0,1}
	};


	float scale[3][3] = //scale�� ���� 3x3��ķ� �����ϰ� ���� ����־���.
	{
		{1,0,0},
		{0,1,0},
		{0,0,1}
	};


	double PI = 3.1415926;	//���� ���� �����ߴ�.
	float cos = 0.15425144988;	//cos30�� ���� �����ϱ� ���� ���� �־���.
	float sin = 0.5;		//sin 30�� ���� �����ϱ� ���� ���� �־���.

	float rotate[3][3] = //rotate�� ���� 3x3��ķ� �����ϰ� ���� ����־���.
	{
		{cos,-sin,0},
		{sin,cos,0},
		{0,0,1}
	};


private:

};




void nain()
{
	float C[3][3] = { 0 };	//���߿� ��ĵ��� ���� ��� ���� ������ 3x3 ����̴�.
	float A[3][3] = { 0 };	//���߿� ��ĵ��� ���� ��� ���� ������ 3x3 ����̴�.

	mat3 Translate, Rotate, Scale; //math3 Ŭ���� �ȿ� �ִ� translate, rotate, scale�� �������� ���� ������ �����.
	vec3 V, P;	//vec3 Ŭ���� �ȿ� �ִ� Vector, p�� ���� �������� ���� ������ �����.


	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				C[i][j] += Scale.scale[i][k] * Translate.translate[k][j];	//scale�� ��İ� translate�� ����� 
																			//���� ���� C��� ���� �ִ´�.
			}
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				A[i][j] += Rotate.rotate[i][k] * C[k][j];//rotate�� ��İ� �Ʊ����� scale��translate�� ���� ���� 
														 //C�� ��İ� ���� A��Ŀ� ���� �ִ´�.
			}
		}
	}

	for (int i = 0; i < V.v_row; i++) {		//Vector�� ����� ũ�⸦ �˾ƾ� �ؼ� vec3�� �ִ� v_row�� ���� �ִ´�.
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < V.v_col; k++) {
				P.p[i][j] += V.v[i][k] * A[k][j];	//vec3�� �ִ� Vector�� ��İ� �Ʊ����� rotate*scale*translate�� ���� ���� 
													//vec3�� �ִ� p�� ��İ��� �ִ´�.
			}
		}
	}
	cout << "vec3 p�� ����\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			//cout << C[i][j];
			cout << P.p[i][j];
			if (j < 2) cout << " ";	//���⸦ ���� �ڵ�
		}
		cout << endl;
	}



}