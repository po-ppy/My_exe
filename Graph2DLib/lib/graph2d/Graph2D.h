//Graph2D����ͼ�ο�V1.0
//���ߣ����پ�����骣��̳ң�κ�٣���ҫ��
//2015��3��
/*Graph2D�ο�Borland C++��graphics�⣬ͨ�����ֿռ�(namespace)��װOpenGL�е�ͼ�γ�ʼ����
����ͼԪ���ơ����̺���꽻���Ⱥ�����Ϊ�û��ṩһ�����׵Ŀ���������ӿڣ�ͼԪ���ƺ�����
��������Ϯ��ͳgraphics���������Graph2D����ͼ�γ�ʼ�����������á�����ͼԪ���ơ����崴
�����ı���ʾ��ͼ���������ʾ��������꽻���ȹ���ģ�顣
����ϵͳ���ö�ά�ѿ�����������ϵ������X��ָ���ҷ���Y��ָ���Ϸ�*/
#include <GL/glut.h>
#include <cstdio>
#include <cmath>

#ifndef GRAPH_2D_H
#define GRAPH_2D_H

#if !defined(PI)
#define PI 3.1415926535897932384626433832795
#endif

#if !defined(DEG_TO_RAD)
#define DEG_TO_RAD       PI/180.0
#endif

#if !defined(GL_BGR_EXT)
#define GL_BGR_EXT       0x80E0
#endif

#if !defined(GL_BGRA_EXT)
#define GL_BGRA_EXT      0x80E1
#endif

#if !defined(GL_CLAMP_TO_EDGE)
#define GL_CLAMP_TO_EDGE 0x812F
#endif

namespace graph
{
    const unsigned long BLACK = 0x0;
    const unsigned long RED = 0xFF0000;
    const unsigned long GREEN = 0x00FF00;
    const unsigned long BLUE = 0x0000FF;
    const unsigned long GREY = 0x808080;
    const unsigned long PURPLE = 0x800080;
    const unsigned long WHITE = 0xFFFFFF;
    const unsigned long CYAN = 0x00FFFF;
    const unsigned long MAGENTA = 0xFF00FF;
    const unsigned long YELLOW = 0xFFFF00;
    const unsigned long ORANGE = 0xFFA500;
    const unsigned long BROWN = 0xA52A2A;

    const int LEFT_BUTTON_DOWN = 1001;
    const int LEFT_BUTTON_UP = 1002;
    const int RIGHT_BUTTON_DOWN = 1003;
    const int RIGHT_BUTTON_UP = 1004;
    const int MIDDLE_BUTTON_DOWN = 1005;
    const int MIDDLE_BUTTON_UP = 1006;
    const int KEY_LEFT = GLUT_KEY_LEFT;
    const int KEY_RIGHT = GLUT_KEY_RIGHT;
    const int KEY_UP = GLUT_KEY_UP;
    const int KEY_DOWN = GLUT_KEY_DOWN;

    const int BOLD = FW_BOLD;

    static const int MAX_NUM_TEXS = 512;
    static const int MAX_NUM_FONTS = 32;
    static const double ANGLE_STEP = PI/180.0;

    static int m_fps = 40;
    static int m_preTime;

    static bool m_bInitGraphDone = false;
    static bool m_bFullScreen = false;
    static bool m_bBindImage = false;
    static bool m_bHelpEnabled = false;
    static bool m_bShowCoordinate = false;

    static int m_numTexs = 0;
    struct ImageData
    {
        void *pImage;
        int width;
        int height;
        GLint component;
        GLenum format;
        GLuint texID;
    };
    static struct ImageData m_texture[MAX_NUM_TEXS];
    static double m_texPosU[2] = {0.0, 1.0};
    static double m_texPosV[2] = {0.0, 1.0};

    static int m_winXPos = 100;
    static int m_winYPos = 100;
    static int m_winWidth = 1024;
    static int m_winHeight = 768;
    static double m_bgColor[3] = {1.0, 1.0, 1.0};
    static double m_color[3] = {0.0, 0.0, 0.0};

    static char m_strWinTitle[] = "Simple Graph Window";

    struct FontData
    {
        GLint fontList;
        int width;
        int height;
        HFONT hFont;
    };
    static struct FontData m_font[MAX_NUM_FONTS];
    static int m_numFonts = 0;
    static int m_nFontID = -1;
    static int m_nHelpFontID = -1;

    static void (*inDisplay)(void);
    static void (*inKeyboard)(unsigned char key);
    static void (*inMousePress)(int message, int x, int y);
    static void (*inMouseMove)(int x, int y);
    static void (*inSpecialKeyboard)(int key);
    static void displayCK();
    static void specialKeyboardCK(int key, int x, int y);
    static void keyboardCK(unsigned char key, int x, int y);
    static void mousePressCK(int button, int state, int x, int y);
    static void mouseMoveCK(int x, int y);

    static void idleCK(void);
    static void reshapeCK(int w, int h);

    static void scanLineFilling(int numPoints,double polyX[], double polyY[]);
    static GLbyte *loadBMP(const char *fileName, int &width, int &height,
                           GLint &component, GLenum &format, bool bGrey);

    //һ��ͼ�γ�ʼ��
    /*ͼ��ϵͳ��ʼ�����������ڹ���ͼ�δ��ڣ�Ƕ��ص�����
    �����뷵��ֵ����������5������ָ�룬�ֱ��Ӧͼ�δ��ڻ�������º���display��������Ӧ����keyboard��
    ��갴����Ӧ����mousePress������ƶ���Ӧ����mouseMove�ͼ����������Ӧ����specialKeyboard������
    ˵������ͼ�κ����еĵ�1����������ȱʡ������4����������ȱʡ����������û�����Ҫ����һ������ͼ����ʾ����µ�display������*/
    void initGraph(void (*display)(),
                   void (*keyboard)(unsigned char key)=NULL,
                   void (*mousePress)(int message, int x, int y)=NULL,
                   void (*mouseMove)(int x, int y)=NULL,
                   void (*specialKeyboard)(int key)=NULL);

    //������������
    /*���ô��ڱ�����ɫ
    �����뷵��ֵ���������غ����������ô��ڱ�����ɫ�����е�һ�������ж�Ӧ�Ĳ���Ϊ��������ɫ������ȡֵ��ΧΪ[0, 255]��
    �ڶ���������Ӧ��������һ��16���ƺ��ʾ�������ɫRED��Ӧ0XFF0000��
    �������Ƶĺ껹����BLACK��GREEN��BLUE��GREY��PURPLE��WHITE��CYAN��MAGENTA��YELLOW��ORANGE��BROWN��
    ˵����һ����initGraphǰ���á�*/
    void setBkColor(unsigned char red, unsigned char green, unsigned char blue);
    void setBkColor(unsigned long color);
    /*���ô��ڱ���
    �����뷵��ֵ��Ĭ�ϴ��ڱ���Ϊ��Simple Graph Window����ͨ��strTitle�ַ�����ָ���µĴ��ڱ��⡣
    ˵����һ����initGraphǰ���á�*/
    void setWinTitle(char strTitle[]);
    /*���ô��ڴ�С
    �����뷵��ֵ��Ĭ�ϴ��ڴ�СΪ1024*768��ͨ��width��height�ֱ������´��ڵĿ����߶ȡ�
    ˵����һ����initGraphǰ���á�*/
    void setWinSize(int width, int height);
    /*��ȡ���ڿ����߶�
    �����뷵��ֵ�����ص�ǰ���ڿ�ȡ�
    ˵�����޵������ơ�*/
    int getWinWidth();
    int getWinHeight();
    /*�ñ�����ɫ����
    �����뷵��ֵ���ޡ�
    ˵������display�����е��ú�ǰ����Ƶ�����ͼ�ν��������*/
    void clearWindow();
    /*����ȫ��ģʽ
    �����뷵��ֵ���ޡ�
    ˵��������ȫ��ģʽ��һ����initGraphǰ���á�*/
    void setFullScreen();
    /*�˳�ȫ�����л�������ģʽ
    �����뷵��ֵ���ޡ�
    ˵�����˳�ȫ��ģʽ��һ����keyboard�ص������е��á�*/
    void exitFullScreen();

    //��������ͼԪ����
    /*�����߿�
    �����뷵��ֵ�����õ�ǰ����Ϊ���ߡ�
    ˵������display�е���*/
    void setLineWidth(int width);
    /*��������Ϊ����
    �����뷵��ֵ���ޡ�
    ˵������display�е��á�*/
    void setDottedLines();
    /*��������Ϊʵ��
    �����뷵��ֵ���ޡ�
    ˵�������õ�ǰ����Ϊʵ�ߣ�Ĭ������Ϊʵ�ߣ��ú�����display�е��á�*/
    void setSolidLines();
    /*����ͼԪ��ɫ
    �����뷵��ֵ����setBkColor���ƣ��������غ�����������ͼԪ������ɫ�����е�1�������ж�Ӧ��3������Ϊ������3ɫ������ȡֵ��ΧΪ[0, 255]����2��������Ӧ��������һ��24λ��16��������ʾ����0XFFFF00��ӦΪ��ɫ��
    ˵�����ú��������õ㡢�ߡ�������״���ı��Լ���ͼ��Ļ��ɫ����display�е��á�*/
    void setColor(unsigned char red, unsigned char green, unsigned char blue);
    void setColor(unsigned long color);
    /*��ʾ���ص�
    �����뷵��ֵ��������(x, y)����ʾһ�����ص㡣
    ˵������display�е��á�*/
    void putPixel(double x, double y);
    /*�����߶�
    �����뷵��ֵ��startX��startY��Ӧ�߶���㣬endX��endY��Ӧ�߶��յ㡣
    ˵������display�е��á�*/
    void line(double startX, double startY, double endX, double endY);
    /*���ƴ���ͷ�߶�
    �����뷵��ֵ��startX��startY��Ӧ�߶���㣬endX��endY��Ӧ�߶��յ㣬s1λ��ͷ��ȣ�s2Ϊ��ͷ���ȡ�
    ˵������display�е��á�*/
    void arrowLine(double startX, double startY, double endX, double endY, double s1=5.0, double s2=10.0);
    /*���ƾ����߿�
    �����뷵��ֵ��x0��y0��Ӧ�������½����꣬x1��y1��Ӧ���Ͻ����ꡣ
    ˵������display�е��á�*/
    void rectangle(double x0, double y0, double x1, double y1);
    /*����������
    �����뷵��ֵ��x0��y0��Ӧ�������½����꣬x1��y1��Ӧ���Ͻ����ꡣ
    ˵������display�е��á�*/
    void fillRectangle(double x0, double y0, double x1, double y1);
    /*����������
    �����뷵��ֵ��(x0, y0)��(x1, y1)��(x2, y2)�ֱ��Ӧ�����ε������������ꡣ
    ˵������display�е��á�*/
    void triangle(double x0, double y0, double x1, double y1, double x2, double y2);
    /*�������������
    �����뷵��ֵ��(x0, y0)��(x1, y1)��(x2, y2)�ֱ��Ӧ�����ε������������ꡣ
    ˵������display�е��á�*/
    void fillTriangle(double x0, double y0, double x1, double y1, double x2, double y2);
    /*����Բ
    �����뷵��ֵ��xcr��ycrΪԲ�����꣬radiusΪ�뾶��
    ˵������display�е��á�*/
    void circle(double xctr, double yctr, double radius);
    /*�������Բ
    �����뷵��ֵ��xctr��yctrΪԲ�����꣬radiusΪ�뾶��
    ˵������display�е��á�*/
    void fillCircle(double xctr, double yctr, double radius);
    /*������Բ
    �����뷵��ֵ��xctr��yctrΪ��ԲԲ�����꣬xRadiusΪx������뾶��yRadiusΪy������뾶��
    ˵������display�е��á�*/
    void ellipse(double xctr, double yctr, double xRadius, double yRadius);
    /*���������Բ
    �����뷵��ֵ��xctr��yctrΪ��ԲԲ�����꣬xRadiusΪx������뾶��yRadiusΪy������뾶��
    ˵������display�е��á�*/
    void fillEllipse(double xctr, double yctr, double xRadius, double yRadius);
    /*������Բ��
    �����뷵��ֵ��xctr��yctrΪԲ�����꣬xRadiusΪx������뾶��yRadiusΪy������뾶��ratioΪ��Բ�뾶����Բ�뾶�ı�����
    ˵������display�е��á�*/
    void donut(double xctr, double yctr, double xRadius, double yRadius, double ratio);
    /*���������Բ��
    �����뷵��ֵ��xctr��yctrΪԲ�����꣬xRadiusΪx������뾶��yRadiusΪy������뾶��ratioΪ��Բ�뾶����Բ�뾶�ı�����
    ˵������display�е��á�*/
    void fillDonut(double xctr, double yctr, double xRadius, double yRadius, double ratio);
    /*����Բ��
    �����뷵��ֵ��cx��cyΪԲ�����꣬radiusΪ�뾶��startAngle��endAngle��ӦԲ������ʼ�Ƕȡ�
    ˵������display�е��á�*/
    void arc(double xctr, double yctr, double radius, double startAngle, double endAngle);
    /*��������
    �����뷵��ֵ��cx��cyΪԲ�����꣬radiusΪ�뾶��startAngle��endAngle��ӦԲ������ʼ�Ƕȡ�
    ˵������display�е��á�*/
    void sector(double xctr, double yctr, double radius,double startAngle, double endAngle);
    /*���ƶ����
    �����뷵��ֵ��numPointsΪ����ζ�������x[]��y[]�����ڴ洢����ζ���x�����y��������顣
    ˵������display�е��á�*/
    void polygon(int numPoints, double x[], double y[]);
    /*�����������
    �����뷵��ֵ��numPointsΪ����ζ�������x[]��y[]�����ڴ洢����ζ���x�����y��������飬
    Ĭ�������bConvexΪ�棬������͹����Σ���Ϊ������Σ���bConvex��Ϊ�٣�����ɨ�����㷨��䡣
    ˵������display�е��ã����ڰ�����ε���䣬�ݲ�֧��ͼ�����ܡ�*/
    void fillPolygon(int numPoints, double x[], double y[], bool bConvex=true);

    //�ġ��ı���������ʾ
    /*�����ֺ�������
    �����뷵��ֵ��pixHeightΪ����߶ȣ���λΪ���أ���Ĭ�ϸ߶�Ϊ24��
    styleΪ���壬Ĭ��Ϊ��Arial����Ҳ����Ϊ��Times New Roman���������塱�������塱�ȣ�
    weightΪ����ֶȣ�Ĭ��Ϊ�����ֶȣ�Ҳ����Ϊ�Ӵ֣���Ӧ��ΪBOLD����
    bItalicΪ��бģʽ��Ĭ��Ϊ��б�塣���������ش��������Ǻţ�������ʧ���򷵻�-1��
    ˵������initGraphǰ���ã��ݲ�֧�ֺ�����ʾ��*/
    int createFont(int pixHeight=24, const char style[]="Arial",
                   int weight=FW_NORMAL, bool bItalic=false);
    /*ʹ��ָ������
    �����뷵��ֵ��fontID��ӦcreateFont�д������ص������Ǻš�
    ˵������display�е��á�*/
    void useFont(int fontID);
    /*��ȡָ������߶�
    �����뷵��ֵ������fontID��Ӧ����߶ȡ�
    ˵������display�е��á�*/
    int getFontHeight(int fontID);
    /*��ȡָ��������
    �����뷵��ֵ������fontID��Ӧ�����ȡ�
    ˵������display�е��á�*/
    int getFontWidth(int fontID);
    /*��ʾ�ı�
    �����뷵��ֵ������Ļ����(x, y)����ʾ�ַ���strText��
    ˵������display�е��ã�����Ԥ�ȵ���createFont��useFont��������ʹ��Ĭ�ϡ�Arial��24�����塣*/
    void putText(int x, int y, const char strText[]);

    //�塢ͼ�����������
    /*����ͼ��
    �����뷵��ֵ������fileName��Ӧ��BMP���ɫͼ���ļ���bGrey��Ϊ��ֵ���򽫶���ͼ��ת��Ϊ�Ҷ�ͼ�񣬷���Ϊԭͼ��
    �ú������ض�ȡͼ��ı�Ǻţ���ͼ���ȡʧ�ܣ�����-1��
    ˵������initGraphǰ���ã��ݲ�֧�����ɫBMP��ʽ����ͼ���ļ��Ķ�д��*/
    int loadImage(const char *fileName, bool bGrey=false);
    /*��ʾָ��ͼ��
    �����뷵��ֵ������Ļ��������ʾ��Ǻ�ΪimageID��ͼ��
    startU��startV��endU��endV�ֱ�ָ����ͼ���н�ȡ����������ͼ������½Ǻ����Ͻ����꣬
    ���귶Χ����Ϊ[0, 1]��Ĭ���������ʾ����ͼ��
    ˵������display�е��á�*/
    void showImage(int imageID, double startU=0.0, double startV=0.0, double endU=1.0, double endV=1.0);
    /*��ָ��ͼ��������ͼԪ
    �����뷵��ֵ��ʹ�ñ�Ǻ�ΪimageID��ͼ��������ͼ�����bBlendΪ�棬
    ��ͼ����setColorָ����ɫ��Ϻ���������ͼԪ��������Ρ�Բ��͹����εȣ���
    ĬȻ�����ͼ�����趨��ɫ��ϣ�startU��startV��endU��endV�ֱ�ָ����ͼ���н�ȡ����������ͼ������½Ǻ����Ͻ����꣬
    ���귶Χ����Ϊ[0, 1]��Ĭ������»�ȡ��������ͼ��
    ˵������display�е��á�*/
    void bindImage(int imageID, bool bBlend=false,
                                double startU=0.0, double startV=0.0, double endU=1.0, double endV=1.0);
    // ��������
    /*����֡����
    �����뷵��ֵ��������Ļ����Ƶ��ΪframePerSec��ĬȻ֡����Ϊÿ��40֡��
    ˵������initGraphǰ���ã����ͼ����ƹ��ڸ��ӣ���ʹ���ø�֡����Ҳ�޷���߻�������ٶȡ�*/
    void setFPS(int fps);
    /*��ȡ֡����
    �����뷵��ֵ�����ص�ǰ֡���ʡ�
    ˵������display�е��á�*/
    int getFPS();
    /*��ʾ������Ϣ
    �����뷵��ֵ���ޡ�
    ˵������initGraphǰ���ã���F1�������ظð�����Ϣ��*/
    void showHelp();
    /*��ʾ����ϵ
    �����뷵��ֵ���ޡ�
    ˵������display�е��ã���ʾ��ǰ����ϵ��Ĭ������²���ʾ����F2�������øú�����*/
    void showCoordinate();
    /*������Ļͼ�����ļ�
    �����뷵��ֵ��ʵ��ץ�����ܣ�������Ļͼ��BMPͼ���ļ�fileName��fileName��׺��Ϊbmp��
    ˵������keyboard�ص�������ʹ�á�*/
    bool saveScreenImage(char *fileName);
}
#endif
