#include <chrono>
#include <thread>
#include <string>
#include <iostream>
#include <GLFW/glfw3.h>
#include "MusoenMath.h"//라이브러리
#define PI 3.141592//pi의 값을 지정해준다.


#pragma comment(lib, "OpenGL32")

using namespace std;

chrono::system_clock::time_point startRenderTimePoint;
chrono::duration<double> renderDuration;

GLFWwindow* window;
bool isFirstFrame = true;


struct Vertex
{
    vec3 pos;//MusoenMath의 라이브러리에 있는 vec3의 클래스의 값을 가져온다.
    float r, g, b, a;
};

struct Transform
{
    mat3 translate, rotation, scale;//MusoenMath의 라이브러리에 있는 mat3의 클래스의 값을 가져온다.
};


Vertex star[5];             // static mesh
Vertex transformedStar[5];  //화면에 그릴 오망성
Vertex circle[360];             // static mesh 
Vertex transformedCircle[360];  // 화면에 그려질 원

Transform transform;  //world 행렬이 될 transform

//<문제>////////전역변수 쓰는곳////////////////////////////////////////////////////////////

float radians = 0;//rotate의 값을 넣기 위한 변수이다.
float moving = 0; //translate의 이동을 위한 변수이다.
float turn = 0; //rotate의 회전을 위한 변수이다.
float bigger = 1.0f; //scale의 크기를 측정하기 위한 변수이다.
float pluss = 0.01f; //scale의 크기를 키우거나 줄이기 위한 변수이다.

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


    //object생성부
     /// Star(오망성) 생성
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

    // 원 생성
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


    //트랜스폼 초기화 (기본형 제공)
    transform.translate = mat3(//translate의 초기화
        1, 0, 0,
        0, 1, 0,
        0, 0, 1
    );

    transform.rotation = mat3(//rotation의 초기화
        cos(radians * PI / 180), -sin(radians * PI / 180), 0,
        sin(radians * PI / 180), cos(radians * PI / 180), 0,
        0, 0, 1
    );

    transform.scale = mat3(//scale의 초기화
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
        //1. translate 를 프레임당 오른쪽으로 0.001씩 누적시켜서 물체를 이동해보세요.

        moving += 0.001;//오른쪽으로 0.001씩 계속해서 이동하기 위해 0.001을 moving이라는 변수에다가 계속 넣어준다.

        transform.translate = mat3(//해당 translate의 행렬에 맞게 맞는 자리에다가 moving이라는 변수를 넣어준다.
            1, 0, 0,
            0, 1, 0,
            moving, 0, 1
        );

        //2. Rotation 을 프레임당 1도씩 누적시켜서 물체를 회전시켜보세요.
        turn += 1;//1도씩 회전을 하기 위해 turn이라는 변수에다가 1의 값을 계속 더해준다.

        transform.rotation = mat3(//해당 rotation의 행렬에 맞게 cos,sin의 값을 배치해 준다.
            cos(turn * PI / 180), -sin(turn * PI / 180), 0,
            sin(turn * PI / 180), cos(turn * PI / 180), 0,
            0, 0, 1
        );


        //3. Scale은 초당 0.01씩 최대 1.3배까지 늘어났다가 0.7배까지 줄어들도록 만드시오 (반복)
        //   (1.3배 이상이 되면 줄어들고 0.7배 이하가 되면 다시 늘어나게 만드시오)
        bigger += pluss;    //bigger이라는 변수의 값(1)에다가 pluss라는 변수의 값(0.001)을 계속 더해준다.

        if (bigger >= 1.3) //bigger의 값의 크기가 1.3이상이 되면 실행한다.
        {
            pluss -= 0.01;  //0.01씩 계속 빼준다.
        }
        else if (bigger <= 0.7)//bigger의 값의 크기가 0.7이하가 되면 실행한다.
        {
            pluss += 0.01;//0.01씩 계속 더해준다.
        }

        transform.scale = mat3(//해당 Sclae행렬에 맞게 bigger의 변수를 배치해준다.
            bigger, 0, 0,
            0, bigger, 0,
            0, 0, 1
        );

        for (int i = 0; i < 360; i++)
        {
            transformedCircle[i].pos = circle[i].pos * transform.scale * transform.rotation * transform.translate;
            //vec3 p = v * Translate * Rotate * Scale;로 Circle의 최종값을 알기 위해 
            //circle의 vcetor값과 나머지 이동,회전,행렬을 곱해준다.
        }

        for (int i = 0; i < 5; i++)
        {
            transformedStar[i].pos = star[i].pos * transform.scale * transform.rotation * transform.translate;
            //vec3 p = v * Translate * Rotate * Scale;로 Star의 최종값을 알기 위해 
            //star의 vcetor값과 나머지 이동,회전,행렬을 곱해준다.
        }


        //색 초기화
        glClearColor(.0f, 0.0f, 0.0f, 0.1f);
        glClear(GL_COLOR_BUFFER_BIT);

        //선두께
        glLineWidth(7.0f);
        //오망성 그리기
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

        //원그리기
        glBegin(GL_LINE_STRIP);
        for (int theta = 0; theta < 360; theta++)
        {
            glColor4f(transformedCircle[theta].r, transformedCircle[theta].g, transformedCircle[theta].b, transformedCircle[theta].a);
            glVertex3f(transformedCircle[theta].pos.x, transformedCircle[theta].pos.y, 0.0f);
        }

        glTranslatef(-0.001, 0, 0);

        glEnd();

        //화면 스왑
        glfwSwapBuffers(window);
        glfwPollEvents();

        //렌더시간 측정
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