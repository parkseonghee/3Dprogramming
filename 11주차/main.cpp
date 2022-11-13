#include <iostream>
#include "matrix.h"

int main()
{

    mat3 matrix1(1, 2, 3, 4, 5, 6, 7, 8, 9); //mat3의 matrix1의 3x3행렬의 값을 지정한다.

    mat3 matrix2(1, 1, 1, 1, 1, 1, 1, 1, 1);//mat3의 matrix2의 3x3행렬의 값을 지정한다.

    mat3 sansu(2, 2, 2, 2, 2, 2, 2, 2, 2);//mat3의 sansu를 매트릭스에 곱하기 위해 만든다.

    mat3 matrix3;//답을 저장하기 위해 만든 것

    vec3 vector1(1, 2, 3);//vec3의 3x1의 vector의 값을 지정한다.

    vec3 vector2(3, 2, 1);//vec3의 3x1의 vector의 값을 지정한다.

    vec3 vector3;//답을 저장하기 위해 만든 것

    cout << "----------------" << endl;

    cout << "Matrix Multi" << endl;//매트릭스의 곱셈

    cout << "----------------" << endl;

    matrix3 = matrix1 * matrix2;//곱셉

    //matrix3.identity(); //이것을 넣으면 matrix3의 값이 단위행렬로 바뀐다.

    matrix3.nain();//값을 출력한다.

    cout << "----------------" << endl;

    cout << "Multiply Transpose Matrix" << endl;//전치 매트릭스 곱셈

    cout << "----------------" << endl;

    matrix3 = matrix1 * matrix2;//곱셈

    matrix3.transpose();//matrix3의 값을 전치 시켜준다.

    matrix3.nain();//값을 출력한다.

    cout << "----------------" << endl;

    cout << " Multiply Vector" << endl;//벡터의 곱

    cout << "----------------" << endl;

    vector3 = vector1 * vector2;//벡터의 곱셈

    vector3.nain();//값을 출력한다.

    cout << "----------------" << endl;

    cout << "Multiply Transpose Vector " << endl;//전치 벡터 곱셈

    cout << "----------------" << endl;

    vector3 = vector1 * vector2;//벡테의 곱

    vector3.transpose();//vector3의 값을 전치 시켜준다.

    vector3.nain();//값을 출력한다.

    cout << "----------------" << endl;

    cout << "행렬/벡터간 덧셈" << endl;//행렬과 벡터의 덧셈

    cout << "----------------" << endl;

    matrix3 = matrix1 + vector1;//덧셈

    matrix3.nain();//값을 출력한다.

    cout << "----------------" << endl;

    cout << "행렬/벡터간 뺄셈" << endl;//행렬과 벡터의 뺄셈

    cout << "----------------" << endl;

    matrix3 = matrix1 - vector1;//뺄셈

    matrix3.nain();//값을 출력한다.

    cout << "----------------" << endl;

    cout << "상수 곱셈" << endl;//상수와 매트릭스의 곱셈

    cout << "----------------" << endl;

    matrix3 = matrix1 * sansu;//매트릭스에다가 상수의 값을 곱해준다.

    matrix3.nain();//값을 출력한다.

    cout << "----------------" << endl;

    cout << "상수 나눗셈" << endl;//상수와 나누기의 곱셈

    cout << "----------------" << endl;

    matrix3 = matrix1 / sansu;//매트릭스에다가 상수의 값을 나눠준다.

    matrix3.nain();//값을 출력한다.

    return 0;

    system("pause");


}