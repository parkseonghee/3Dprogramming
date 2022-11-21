#include <chrono>
#include <thread>
#include <string>
#include <iostream>
#include <GLFW/glfw3.h>
#include "MusoenMath.h"//���̺귯��
#define PI 3.141592//pi�� ���� �������ش�.


#pragma comment(lib, "OpenGL32")

using namespace std;

chrono::system_clock::time_point startRenderTimePoint;
chrono::duration<double> renderDuration;

GLFWwindow* window;
bool isFirstFrame = true;


struct Vertex
{
    vec3 pos;//MusoenMath�� ���̺귯���� �ִ� vec3�� Ŭ������ ���� �����´�.
    float r, g, b, a;
};

struct Transform
{
    mat3 translate, rotation, scale;//MusoenMath�� ���̺귯���� �ִ� mat3�� Ŭ������ ���� �����´�.
};


Vertex star[5];             // static mesh
Vertex transformedStar[5];  //ȭ�鿡 �׸� ������
Vertex circle[360];             // static mesh 
Vertex transformedCircle[360];  // ȭ�鿡 �׷��� ��

Transform transform;  //world ����� �� transform

//<����>////////�������� ���°�////////////////////////////////////////////////////////////

float radians = 0;//rotate�� ���� �ֱ� ���� �����̴�.
float moving = 0; //translate�� �̵��� ���� �����̴�.
float turn = 0; //rotate�� ȸ���� ���� �����̴�.
float bigger = 1.0f; //scale�� ũ�⸦ �����ϱ� ���� �����̴�.
float pluss = 0.01f; //scale�� ũ�⸦ Ű��ų� ���̱� ���� �����̴�.

 //////////////////////////////////////////////////////////////////////////////////////////

void Init();
void Update();
void Release();

static void error_callback(int error, const char* description);
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

int main(void);


void Init()
{
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(720, 720, "Simple example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);


    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glfwSwapInterval(1);

    startRenderTimePoint = chrono::system_clock::now();


    //object������
     /// Star(������) ����
    int i = 0;
    for (float theta = 0; theta < 360; theta += 72)
    {

        star[i].pos.x = -sin(theta * PI / 180) * 0.5f;
        star[i].pos.y = cos(theta * PI / 180) * 0.5f;
        star[i].pos.z = 1.0f;

        star[i].r = 0.3f;
        star[i].g = 0.0f;
        star[i].b = theta / 360.0f;
        star[i].a = 0.7f;


        transformedStar[i] = star[i];

        i++;
    }

    // �� ����
    for (int theta = 0; theta < 360; theta++)
    {
        circle[theta].pos.x = -sin((float)theta * PI / 180) * 0.5;
        circle[theta].pos.y = cos((float)theta * PI / 180) * 0.5;
        circle[theta].pos.z = 1.0f;

        circle[theta].r = 0.3f;
        circle[theta].g = 0.0f;
        circle[theta].b = theta / 360.0f;
        circle[theta].a = 0.7f;

        transformedCircle[theta] = circle[theta];
    }


    //Ʈ������ �ʱ�ȭ (�⺻�� ����)
    transform.translate = mat3(//translate�� �ʱ�ȭ
        1, 0, 0,
        0, 1, 0,
        0, 0, 1
    );

    transform.rotation = mat3(//rotation�� �ʱ�ȭ
        cos(radians * PI / 180), -sin(radians * PI / 180), 0,
        sin(radians * PI / 180), cos(radians * PI / 180), 0,
        0, 0, 1
    );

    transform.scale = mat3(//scale�� �ʱ�ȭ
        1, 0, 0,
        0, 1, 0,
        0, 0, 1
    );
}

void Release()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}
void Update()
{
    while (!glfwWindowShouldClose(window))
    {
        //1. translate �� �����Ӵ� ���������� 0.001�� �������Ѽ� ��ü�� �̵��غ�����.

        moving += 0.001;//���������� 0.001�� ����ؼ� �̵��ϱ� ���� 0.001�� moving�̶�� �������ٰ� ��� �־��ش�.

        transform.translate = mat3(//�ش� translate�� ��Ŀ� �°� �´� �ڸ����ٰ� moving�̶�� ������ �־��ش�.
            1, 0, 0,
            0, 1, 0,
            moving, 0, 1
        );

        //2. Rotation �� �����Ӵ� 1���� �������Ѽ� ��ü�� ȸ�����Ѻ�����.
        turn += 1;//1���� ȸ���� �ϱ� ���� turn�̶�� �������ٰ� 1�� ���� ��� �����ش�.

        transform.rotation = mat3(//�ش� rotation�� ��Ŀ� �°� cos,sin�� ���� ��ġ�� �ش�.
            cos(turn * PI / 180), -sin(turn * PI / 180), 0,
            sin(turn * PI / 180), cos(turn * PI / 180), 0,
            0, 0, 1
        );


        //3. Scale�� �ʴ� 0.01�� �ִ� 1.3����� �þ�ٰ� 0.7����� �پ�鵵�� ����ÿ� (�ݺ�)
        //   (1.3�� �̻��� �Ǹ� �پ��� 0.7�� ���ϰ� �Ǹ� �ٽ� �þ�� ����ÿ�)
        bigger += pluss;    //bigger�̶�� ������ ��(1)���ٰ� pluss��� ������ ��(0.001)�� ��� �����ش�.

        if (bigger >= 1.3) //bigger�� ���� ũ�Ⱑ 1.3�̻��� �Ǹ� �����Ѵ�.
        {
            pluss -= 0.01;  //0.01�� ��� ���ش�.
        }
        else if (bigger <= 0.7)//bigger�� ���� ũ�Ⱑ 0.7���ϰ� �Ǹ� �����Ѵ�.
        {
            pluss += 0.01;//0.01�� ��� �����ش�.
        }

        transform.scale = mat3(//�ش� Sclae��Ŀ� �°� bigger�� ������ ��ġ���ش�.
            bigger, 0, 0,
            0, bigger, 0,
            0, 0, 1
        );

        for (int i = 0; i < 360; i++)
        {
            transformedCircle[i].pos = circle[i].pos * transform.scale * transform.rotation * transform.translate;
            //vec3 p = v * Translate * Rotate * Scale;�� Circle�� �������� �˱� ���� 
            //circle�� vcetor���� ������ �̵�,ȸ��,����� �����ش�.
        }

        for (int i = 0; i < 5; i++)
        {
            transformedStar[i].pos = star[i].pos * transform.scale * transform.rotation * transform.translate;
            //vec3 p = v * Translate * Rotate * Scale;�� Star�� �������� �˱� ���� 
            //star�� vcetor���� ������ �̵�,ȸ��,����� �����ش�.
        }


        //�� �ʱ�ȭ
        glClearColor(.0f, 0.0f, 0.0f, 0.1f);
        glClear(GL_COLOR_BUFFER_BIT);

        //���β�
        glLineWidth(7.0f);
        //������ �׸���
        glBegin(GL_LINE_STRIP);

        int a = 0;
        glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
        glVertex3f(transformedStar[a].pos.x, transformedStar[a].pos.y, 0.0f);
        a = 3;
        glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
        glVertex3f(transformedStar[a].pos.x, transformedStar[a].pos.y, 0.0f);
        a = 1;
        glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
        glVertex3f(transformedStar[a].pos.x, transformedStar[a].pos.y, 0.0f);
        a = 4;
        glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
        glVertex3f(transformedStar[a].pos.x, transformedStar[a].pos.y, 0.0f);
        a = 2;
        glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
        glVertex3f(transformedStar[a].pos.x, transformedStar[a].pos.y, 0.0f);

        a = 0;
        glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
        glVertex3f(transformedStar[a].pos.x, transformedStar[a].pos.y, 0.0f);

        glEnd();

        //���׸���
        glBegin(GL_LINE_STRIP);
        for (int theta = 0; theta < 360; theta++)
        {
            glColor4f(transformedCircle[theta].r, transformedCircle[theta].g, transformedCircle[theta].b, transformedCircle[theta].a);
            glVertex3f(transformedCircle[theta].pos.x, transformedCircle[theta].pos.y, 0.0f);
        }

        glTranslatef(-0.001, 0, 0);

        glEnd();

        //ȭ�� ����
        glfwSwapBuffers(window);
        glfwPollEvents();

        //�����ð� ����
        renderDuration = chrono::system_clock::now() - startRenderTimePoint;
        startRenderTimePoint = chrono::system_clock::now();

        float fps = 1.0 / renderDuration.count();
        if (isFirstFrame == true)
        {
            isFirstFrame = false;
            continue;
        }
        if (renderDuration.count() < (1.0f / 60.0f))
            this_thread::sleep_for(chrono::milliseconds((int)(((1.0f / 60.0f) - renderDuration.count()) * 1000)));
        string fps_s = "FPS : " + to_string(fps);
        cout << fps_s << endl;

    }
}

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

int main(void)
{
    Init();
    Update();
    Release();

    exit(EXIT_SUCCESS);
}