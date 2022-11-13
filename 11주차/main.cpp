#include <iostream>
#include "matrix.h"

int main()
{

    mat3 matrix1(1, 2, 3, 4, 5, 6, 7, 8, 9); //mat3�� matrix1�� 3x3����� ���� �����Ѵ�.

    mat3 matrix2(1, 1, 1, 1, 1, 1, 1, 1, 1);//mat3�� matrix2�� 3x3����� ���� �����Ѵ�.

    mat3 sansu(2, 2, 2, 2, 2, 2, 2, 2, 2);//mat3�� sansu�� ��Ʈ������ ���ϱ� ���� �����.

    mat3 matrix3;//���� �����ϱ� ���� ���� ��

    vec3 vector1(1, 2, 3);//vec3�� 3x1�� vector�� ���� �����Ѵ�.

    vec3 vector2(3, 2, 1);//vec3�� 3x1�� vector�� ���� �����Ѵ�.

    vec3 vector3;//���� �����ϱ� ���� ���� ��

    cout << "----------------" << endl;

    cout << "Matrix Multi" << endl;//��Ʈ������ ����

    cout << "----------------" << endl;

    matrix3 = matrix1 * matrix2;//����

    //matrix3.identity(); //�̰��� ������ matrix3�� ���� ������ķ� �ٲ��.

    matrix3.nain();//���� ����Ѵ�.

    cout << "----------------" << endl;

    cout << "Multiply Transpose Matrix" << endl;//��ġ ��Ʈ���� ����

    cout << "----------------" << endl;

    matrix3 = matrix1 * matrix2;//����

    matrix3.transpose();//matrix3�� ���� ��ġ �����ش�.

    matrix3.nain();//���� ����Ѵ�.

    cout << "----------------" << endl;

    cout << " Multiply Vector" << endl;//������ ��

    cout << "----------------" << endl;

    vector3 = vector1 * vector2;//������ ����

    vector3.nain();//���� ����Ѵ�.

    cout << "----------------" << endl;

    cout << "Multiply Transpose Vector " << endl;//��ġ ���� ����

    cout << "----------------" << endl;

    vector3 = vector1 * vector2;//������ ��

    vector3.transpose();//vector3�� ���� ��ġ �����ش�.

    vector3.nain();//���� ����Ѵ�.

    cout << "----------------" << endl;

    cout << "���/���Ͱ� ����" << endl;//��İ� ������ ����

    cout << "----------------" << endl;

    matrix3 = matrix1 + vector1;//����

    matrix3.nain();//���� ����Ѵ�.

    cout << "----------------" << endl;

    cout << "���/���Ͱ� ����" << endl;//��İ� ������ ����

    cout << "----------------" << endl;

    matrix3 = matrix1 - vector1;//����

    matrix3.nain();//���� ����Ѵ�.

    cout << "----------------" << endl;

    cout << "��� ����" << endl;//����� ��Ʈ������ ����

    cout << "----------------" << endl;

    matrix3 = matrix1 * sansu;//��Ʈ�������ٰ� ����� ���� �����ش�.

    matrix3.nain();//���� ����Ѵ�.

    cout << "----------------" << endl;

    cout << "��� ������" << endl;//����� �������� ����

    cout << "----------------" << endl;

    matrix3 = matrix1 / sansu;//��Ʈ�������ٰ� ����� ���� �����ش�.

    matrix3.nain();//���� ����Ѵ�.

    return 0;

    system("pause");


}