#pragma once
using namespace std;
#define MAX 3	//���߿� for���� �ֱ� ���� ��

class mat3 //mat3��� 3x3����� class�� �������
{
private:


public:
	int m[3][3];	//3x3���
	mat3(int a = 0, int b = 0, int c = 0, int d = 0, int e = 0, int f = 0, int g = 0, int h = 0, int i = 0);
	//����� ������ ���߿� �־��ֱ� ���� �Լ� �̴�.

	mat3 identity();	//mat3�� ���� ������ķ� �ʱ�ȭ �����ִ� �Լ�
	mat3 transpose();	//mat3�� ���� ��ġ��ķ� �ٲ��ִ� �Լ�
	void nain();		//���� ����ϱ� ���� �Լ�
	mat3 operator*(const mat3& a);//���߿� ���ϱ⸦ �ϱ����� �Լ�
	mat3 operator/(const mat3& a);//���߿� �����⸦ �ϱ����� �Լ�
	mat3 operator+(const mat3& a);//���߿� ���ϱ⸦ �ϱ����� �Լ�
	mat3 operator-(const mat3& a);//���߿� ���⸦ �ϱ����� �Լ�

};

mat3::mat3(int a, int b, int c, int d, int e, int f, int g, int h, int i)

{

	//mat3�� ����� �ʱ�ȭ �����ش�.

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

class vec3 : public mat3//vec3 class�� ����� vector�� ����� ���� �Լ�
{
private:

public:
	int v[3][1];	//3x1��ķ� ����
	vec3(int a = 0, int b = 0, int c = 0);//������ ������ ���߿� �־��ֱ� ���� �Լ� �̴�.

	vec3 transpose();//vec3�� ���� ��ġ��ķ� �ٲ��ִ� �Լ�
	void nain();//���� ����ϱ� ���� �Լ�
	vec3 operator*(const vec3& a);//���߿� ���ϱ⸦ �ϱ����� �Լ�
	float v_col = sizeof(v[0]) / sizeof(float);//Vector�� �迭�� ũ�⸦ ��Ȯ�ϰ� �˱� ���� ���̴� �ڵ�� ���߿� ��� ���� �Ҷ� �ʿ��ϴ�.
	float v_row = sizeof(v) / sizeof(v[0]);//Vector�� �迭�� ũ�⸦ ��Ȯ�ϰ� �˱� ���� ���̴� �ڵ�� ���߿� ��� ���� �Ҷ� �ʿ��ϴ�.


};

vec3::vec3(int a, int b, int c)

{
	//vec3�� ����� �ʱ�ȭ �����ش�.

	v[0][0] = a;

	v[0][1] = b;

	v[0][2] = c;


}

class vec4//vec4 class�� ����� vector�� ����� ���� �Լ�
{
private:

public:
	int v[4][1];//4x1��ķ� ����
	vec4(int a = 0, int b = 0, int c = 0, int d = 0);//������ ������ ���߿� �־��ֱ� ���� �Լ� �̴�.

	vec4 transpose();//vec4�� ���� ��ġ��ķ� �ٲ��ִ� �Լ�
	void nain();//���� ����ϱ� ���� �Լ�
	vec4 operator*(const vec4& a);//���߿� ���ϱ⸦ �ϱ����� �Լ�
	float v_col = sizeof(v[0]) / sizeof(float);//Vector�� �迭�� ũ�⸦ ��Ȯ�ϰ� �˱� ���� ���̴� �ڵ�� ���߿� ��� ���� �Ҷ� �ʿ��ϴ�.
	float v_row = sizeof(v) / sizeof(v[0]);//Vector�� �迭�� ũ�⸦ ��Ȯ�ϰ� �˱� ���� ���̴� �ڵ�� ���߿� ��� ���� �Ҷ� �ʿ��ϴ�.

};

vec4::vec4(int a, int b, int c, int d)

{
	//vec4�� ����� �ʱ�ȭ �����ش�

	v[0][0] = a;

	v[0][1] = b;

	v[0][2] = c;

	v[0][3] = d;


}


class mat4//mat4��� 4x4����� class�� �������
{
private:


public:
	int m[3][3]; //4x4���
	mat4(int a = 0, int b = 0, int c = 0, int d = 0, int e = 0, int f = 0, int g = 0, int h = 0, int i = 0, int j = 0,
		int k = 0, int l = 0, int n = 0, int o = 0, int p = 0, int q = 0);
	//mat4�� ������ ���߿� �־��ֱ� ���� �Լ� �̴�.

	mat4 identity();//mat4�� ���� ������ķ� �ʱ�ȭ �����ִ� �Լ�
	mat4 transpose();//mat4�� ���� ��ġ��ķ� �ٲ��ִ� �Լ�
	void nain();//���� ����ϱ� ���� �Լ�
	mat4 operator*(const mat4& a);//���߿� ���ϱ⸦ �ϱ����� �Լ�
	mat4 operator/(const mat4& a);//���߿� �����⸦ �ϱ����� �Լ�
	mat4 operator+(const mat4& a);//���߿� ���ϱ⸦ �ϱ����� �Լ�
	mat4 operator-(const mat4& a);//���߿� ���⸦ �ϱ����� �Լ�


};

mat4::mat4(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j,
	int k, int l, int n, int o, int p, int q)

{

	//mat4�� ����� �ʱ�ȭ �����ش�

	m[0][0] = a;

	m[0][1] = b;

	m[0][2] = c;

	m[0][3] = d;

	m[1][0] = e;

	m[1][1] = f;

	m[1][2] = g;

	m[1][3] = h;

	m[2][0] = i;

	m[2][1] = j;

	m[2][2] = k;

	m[2][3] = l;

	m[3][0] = n;

	m[3][1] = o;

	m[3][2] = p;

	m[3][3] = q;

}




mat3 mat3::identity() //mat3�� ���� ������ķ� �ʱ�ȭ �����ִ� �Լ�

{
	float c[3][3] = {//���� ����� �ʱ�ȭ�ϱ� ���� ���
		{1,0,0},
		{0,1,0},
		{0,0,1}
	};

	for (int i = 0; i < MAX; i++)

		for (int j = 0; j < MAX; j++)

			m[i][j] = c[i][j];//m����� ���� �������c�� ������ ��� �ʱ�ȭ ��Ų��.

	return *this;

}

mat4 mat4::identity()//mat4�� ���� ������ķ� �ʱ�ȭ �����ִ� �Լ�

{
	float c[3][3] = {//���� ����� �ʱ�ȭ�ϱ� ���� ���
		{1,0,0},
		{0,1,0},
		{0,0,1}
	};

	//��� ����

	for (int i = 0; i < MAX; i++)

		for (int j = 0; j < MAX; j++)

			m[i][j] = c[i][j];//m����� ���� �������c�� ������ ��� �ʱ�ȭ ��Ų��.

	return *this;

}


mat3 mat3::transpose()//mat3�� ���� ��ġ �����ִ� �Լ��̴�.

{

	mat3 copy; //���ο� Matrix ����

	 //��� ����

	for (int i = 0; i < MAX; i++)

		for (int j = 0; j < MAX; j++)

			copy.m[i][j] = m[i][j];	//m�� ����� �ٸ� ��Ŀ��ٰ� ���� ��Ų��.

	//��ġ

	for (int i = 0; i < MAX; i++)

		for (int j = 0; j < MAX; j++)

			m[j][i] = copy.m[i][j];	//����� ����� �ٽ� m�� ������ �ִµ� j,i�� ��ġ�� �ٲ㼭 ��ġ�� �̸�Ű�� ���ش�.

	return *this;

}

mat4 mat4::transpose()//mat4�� ���� ��ġ �����ִ� �Լ��̴�.

{

	mat4 copy; //���ο� Matrix ����

	 //��� ����

	for (int i = 0; i < MAX; i++)

		for (int j = 0; j < MAX; j++)

			copy.m[i][j] = m[i][j];//m�� ����� �ٸ� ��Ŀ��ٰ� ���� ��Ų��.

	//��ġ

	for (int i = 0; i < MAX; i++)

		for (int j = 0; j < MAX; j++)

			m[j][i] = copy.m[i][j];//����� ����� �ٽ� m�� ������ �ִµ� j,i�� ��ġ�� �ٲ㼭 ��ġ�� �̸�Ű�� ���ش�.

	return *this;

}

vec3 vec3::transpose()//vec3�� ���� ��ġ �����ִ� �Լ��̴�.

{
	vec3 copy; //���ο� vector ����


	 //��� ����

	for (int i = 0; i < copy.v_row; i++) {//Vector�� ����� ũ�⸦ �˾ƾ� �ؼ� vec3�� �ִ� v_row�� ���� �ִ´�.
		for (int j = 0; j < copy.v_col; j++) {
			copy.v[i][j] = v[i][j];//v�� ����� �ٸ� ��Ŀ��ٰ� ���� ��Ų��.
		}
	}

	//��ġ

	for (int i = 0; i < copy.v_row; i++) {
		for (int j = 0; j < copy.v_col; j++) {
			v[j][i] = copy.v[i][j];//����� ����� �ٽ� v�� ������ �ִµ� j,i�� ��ġ�� �ٲ㼭 ��ġ�� �̸�Ű�� ���ش�.
		}
		return *this;
	}

}

vec4 vec4::transpose()//vec4�� ���� ��ġ �����ִ� �Լ��̴�.

{
	vec4 copy; //���ο� vector ����


	 //��� ����

	for (int i = 0; i < copy.v_row; i++) {//Vector�� ����� ũ�⸦ �˾ƾ� �ؼ� vec4�� �ִ� v_row�� ���� �ִ´�.
		for (int j = 0; j < copy.v_col; j++) {
			copy.v[i][j] = v[i][j];//v�� ����� �ٸ� ��Ŀ��ٰ� ���� ��Ų��.
		}
	}

	//��ġ

	for (int i = 0; i < copy.v_row; i++) {
		for (int j = 0; j < copy.v_col; j++) {
			v[j][i] = copy.v[i][j];//����� ����� �ٽ� v�� ������ �ִµ� j,i�� ��ġ�� �ٲ㼭 ��ġ�� �̸�Ű�� ���ش�.
		}
		return *this;
	}

}



mat3 mat3::operator*(const mat3& a)//������ �ϱ� ���� �Լ�

{

	mat3 b; //���ο� Matrix ����

	for (int i = 0; i < MAX; i++)

		for (int j = 0; j < MAX; j++)

			b.m[i][j] = m[i][j] * a.m[i][j]; //����

	return b;

}

mat4 mat4::operator*(const mat4& a)//������ �ϱ� ���� �Լ�

{

	mat4 b; //���ο� Matrix ����

	for (int i = 0; i < MAX; i++)

		for (int j = 0; j < MAX; j++)

			b.m[i][j] = m[i][j] * a.m[i][j]; //����

	return b;

}

vec3 vec3::operator*(const vec3& a)//������ �ϱ� ���� �Լ�

{

	vec3 c; //���ο� Matrix ����

	for (int i = 0; i < MAX; i++)

		for (int j = 0; j < 1; j++)

			c.v[i][j] = v[i][j] * a.v[i][j]; //����

	return c;

}

vec4 vec4::operator*(const vec4& a)//������ �ϱ� ���� �Լ�

{

	vec4 c; //���ο� Matrix ����

	for (int i = 0; i < MAX; i++)

		for (int j = 0; j < 1; j++)

			c.v[i][j] = v[i][j] * a.v[i][j]; //����

	return c;

}

mat3 mat3::operator/(const mat3& a)//�������� �ϱ� ���� �Լ�

{

	mat3 b; //���ο� Matrix ����

	for (int i = 0; i < MAX; i++)

		for (int j = 0; j < MAX; j++)

			b.m[i][j] = m[i][j] / a.m[i][j]; //������

	return b;

}

mat4 mat4::operator/(const mat4& a)//�������� �ϱ� ���� �Լ�

{

	mat4 b; //���ο� Matrix ����

	for (int i = 0; i < MAX; i++)

		for (int j = 0; j < MAX; j++)

			b.m[i][j] = m[i][j] / a.m[i][j]; //������

	return b;

}


mat3 mat3::operator+(const mat3& a)//���ϱ⸦ �ϱ� ���� �Լ�
{

	mat3 b; //���ο� Matrix ����
	vec3 c;

	for (int i = 0; i < c.v_row; i++)

		for (int j = 0; j < c.v_col; j++)

			b.m[i][j] = m[i][j] + c.v[i][j];

	return b;
}

mat3 mat3::operator-(const mat3& a)//���⸦ �ϱ� ���� �Լ�
{
	mat3 b; //���ο� Matrix ����
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
			cout << m[i][j]; //mat3�� m�� ��� ���� ���
			if (j < 2) cout << " ";	//���⸦ ���� �ڵ�
		}
		cout << endl;
	}
}

void mat4::nain()
{
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			cout << m[i][j]; //mat4�� m�� ��� ���� ���
			if (j < 2) cout << " ";	//���⸦ ���� �ڵ�
		}
		cout << endl;
	}
}

void vec3::nain()
{
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < 1; j++) {
			cout << v[i][j]; //vec3�� v�� ��� ���� ���
			if (j < 2) cout << " ";	//���⸦ ���� �ڵ�
		}
		cout << endl;
	}
}

void vec4::nain()
{
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < 1; j++) {
			cout << v[i][j]; //vec4�� v�� ��� ���� ���
			if (j < 2) cout << " ";	//���⸦ ���� �ڵ�
		}
		cout << endl;
	}
}



