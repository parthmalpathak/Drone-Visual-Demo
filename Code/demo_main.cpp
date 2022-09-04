#include <string>
#include <stdio.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

#include "yssimplesound.h"
#include "fssimplewindow.h"
#include "yspng.h"
#include "yspngenc.h"
#include "ysglfontdata.h"

const double Pi = 3.1415927;
const double G = 9.81;

//METRIC CONVERSION
float Source(double p)
{
    double m;
    m = p * 10;
    return m;

}
//DRAWING SOLID BACKGROUND
void DrawBackground()
{
    glColor3ub(0, 0, 90);

    glBegin(GL_QUADS);
    glVertex2i(0, 0);
    glVertex2i(800, 0);
    glVertex2i(800,600);
    glVertex2i(0, 600);
    glEnd();
}

void DrawBackground1()
{
    glColor3ub(0, 0, 90);

    glBegin(GL_QUADS);
    glVertex2i(0, 0);
    glVertex2i(800, 0);
    glVertex2i(800, 600);
    glVertex2i(0, 600);
    glEnd();
}



// DRAWING CIRCLES FOR PERSPECTIVE VIEW EFFECTS
void Circles(double a, double b, double c, int ri, int g, int bi)

{
    double x = Source(a);
    double y = Source(b);
    double r = Source(c);
    int i;
    int lineAmount = 300;


    GLfloat twicePi = 2.0f * Pi;
    glColor3ub(ri, g, bi);
    glBegin(GL_LINE_LOOP);
    for (i = 0; i <= lineAmount;i++) {
        glVertex2f(
            x + (r * cos(i * twicePi / lineAmount)),
            y + (r * sin(i * twicePi / lineAmount))
        );
    }
    glEnd();
}

void Circles2(double a, double b, double c, int ri, int g, int bi)

{
    double x = Source(a);
    double y = Source(b);
    double r = Source(c);
    glColor3ub(ri, g, bi);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 64; ++i)
    {
        const double pi = 3.14159;
        double a = (double)i * pi / 32.0;
        double c = cos(a);
        double s = sin(a);

        glVertex2d(x + c * r, y + s * r);
    }
    glEnd();
}



//DRAWING PLANET 1
void Planet1(double a, double b, double c, int ri, int g, int bi)
{
    glColor3ub(ri, g, bi);
    glBegin(GL_TRIANGLE_FAN);

    double x = Source(a);
    double y = Source(b);
    double r = Source(c);
    for (int i = 0; i < 64; ++i)
    {
        double a = (double)i * Pi / 32.0;
        double c = cos(a);
        double s = sin(a);
        glVertex2d(x + c * r, y + s * r);
    }
    glEnd();

}

// DRAWING PLANET 2-------------------------------------------------------------------------------------
void Planet2(double a, double b, double c, int ri, int g, int bi)
{
    glColor3ub(ri, g, bi);
    glBegin(GL_TRIANGLE_FAN);

    double x = Source(a);
    double y = Source(b);
    double r = Source(c);
    for (int i = 0; i < 64; ++i)
    {
        double a = (double)i * Pi / 32.0;
        double c = cos(a);
        double s = sin(a);
        glVertex2d(x + c * r, y + s * r);
    }
    glEnd();

}

//DRAWING PLANET 3--------------------------------------------------------------------------------------
void Planet3(double a, double b, double c, int ri, int g, int bi)
{
    glColor3ub(ri, g, bi);
    glBegin(GL_TRIANGLE_FAN);

    double x = Source(a);
    double y = Source(b);
    double r = Source(c);
    for (int i = 0; i < 64; ++i)
    {
        double a = (double)i * Pi / 32.0;
        double c = cos(a);
        double s = sin(a);
        glVertex2d(x + c * r, y + s * r);
    }
    glEnd();

}

//DRAWING PLANET 4--------------------------------------------------------------------------------------
void Planet4(double a, double b, double c, int ri, int g, int bi)
{
    glColor3ub(ri, g, bi);
    glBegin(GL_TRIANGLE_FAN);

    double x = Source(a);
    double y = Source(b);
    double r = Source(c);
    for (int i = 0; i < 64; ++i)
    {
        double a = (double)i * Pi / 32.0;
        double c = cos(a);
        double s = sin(a);
        glVertex2d(x + c * r, y + s * r);
    }
    glEnd();

}
//DRAWING PLANET 5--------------------------------------------------------------------------------------
void Planet5(double a, double b, double c, int ri, int g, int bi)
{
    glColor3ub(ri, g, bi);
    glBegin(GL_TRIANGLE_FAN);

    double x = Source(a);
    double y = Source(b);
    double r = Source(c);
    for (int i = 0; i < 64; ++i)
    {
        double a = (double)i * Pi / 32.0;
        double c = cos(a);
        double s = sin(a);
        glVertex2d(x + c * r, y + s * r);
    }
    glEnd();

}

//DRAWING PLANET 6----------------------------------------------------------------------------------------
void Planet6(double a, double b, double c, int ri, int g, int bi)
{
    glColor3ub(ri, g, bi);
    glBegin(GL_TRIANGLE_FAN);

    double x = Source(a);
    double y = Source(b);
    double r = Source(c);
    for (int i = 0; i < 64; ++i)
    {
        double a = (double)i * Pi / 32.0;
        double c = cos(a);
        double s = sin(a);
        glVertex2d(x + c * r, y + s * r);
    }
    glEnd();

}


//DRAWING OBSTACLE----------------------------------------------------------------------------------------
void Obstacle(double a, double b, double c, double d)
{
    double x = Source(a);
    double y = Source(b);
    double w = Source(c);
    double h = Source(d);

    glColor3ub(128 , 128, 128);
    glBegin(GL_POLYGON);
    
    glVertex2i(x - 8 * w, y);

    glVertex2i(x - 2 * w, y - 12 * h);

    glVertex2i(x + 2 * w, y - 12* h);

    glVertex2i(x + 8 * w, y);

    glVertex2i(x + 8 * w, y + 8 * h);

    glVertex2i(x - 8 * w, y + 8 * h);
    glEnd();
    
}


//DRAWING RUNWAY FOR TAKEOFF EFFECT---------------------------------------------------------------------------
void Runway(double run_x1, double run_y1, double run_x2, double run_y2)
{
    double x1 = Source(run_x1);
    double y1 = Source(run_y1);
    double x2 = Source(run_x2);
    double y2 = Source(run_y2);

    glColor3ub(132, 115, 90);

    glBegin(GL_QUADS);
    glVertex2i(0, y1);
    glVertex2i(800, y1);
    glVertex2i(800, y1 + 300);
    glVertex2i(0, y1 + 300);
    glEnd();

    glColor3ub(255, 255, 0);
    glBegin(GL_QUADS);
    glVertex2i(x1, y1);
    glVertex2i(x1 - 200 ,y1 + 300);
    glVertex2i(x1 - 180, y1 + 300);
    glVertex2i(x1 + 20, y1);
    glEnd();

    glColor3ub(255, 255, 0);
    glBegin(GL_QUADS);
    glVertex2i(x2, y2);
    glVertex2i(x2 + 200, y2 + 300);
    glVertex2i(x2 + 180, y2 + 300);
    glVertex2i(x2 - 20, y2);
    glEnd();
}


//DRAWING FLIGHT-----------------------------------------------------------------------------------
void Flight(double a, double b, double c, double d)
{ 
    double x = Source(a);
    double y = Source(b);
    double w = Source(c);
    double h = Source(d);

    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2i(x, y);
    glVertex2i(x + 4*w, y + 4*h);
    glVertex2i(x + w, y + 15*h);
    glVertex2i(x - w, y + 15*h);
    glVertex2i(x - 4*w, y + 4*h);
    glEnd();

    glColor3ub(255, 0,0);
    glBegin(GL_QUADS);
    glVertex2i(x - w, y + 15*h);
    glVertex2i(x + w, y + 15*h);
    glVertex2i(x + 3*w, y + 16*h);
    glVertex2i(x - 3*w, y + 16*h);
    glEnd();

    glColor3ub(255, 0,0);
    glBegin(GL_QUADS);
    glVertex2i(x + 4*w, y + 4*h);
    glVertex2i(x + 14*w, y + 8*h);
    glVertex2i(x + 12.5*w, y + 9*h);
    glVertex2i(x + 2.4*w, y + 8*h);
    glEnd();

    glColor3ub(255, 0,0);
    glBegin(GL_QUADS);
    glVertex2i(x - 4*w, y + 4*h);
    glVertex2i(x - 14*w, y + 8*h);
    glVertex2i(x - 12.5*w, y + 9*h);
    glVertex2i(x - 2.4*w, y + 8*h);
    glEnd();
}





//MAIN FUNCTION-----------------------------------------------------------------------------------------------
int main(void)
{
    int window_W = 800;
    int window_H = 600;

    double circle_x = 40, circle_y = 30, circle_r = 0,  circle_state = 0;

    double circle_x_1 = 40, circle_y_1 = 30, circle_r_1 = 0, circle_r_2 = 0, circle_r_3 = 0, circle_state_1 = 0;

    double flight_x = 40, flight_y = 60, flight_w = 0.5, flight_h = 0.5, flight_state = 1;

    double run_x1 = 20, run_y1 = 30, run_x2 = 60, run_y2 = 30, run_state = 1;

    double star_state = 1;

    double Planet1_x = 40, Planet1_y = 20, Planet1_r = 0, Planet1_state = 1;

    double Planet2_x = 40, Planet2_y = 20, Planet2_r = 0, Planet2_state = 1;

    double Planet3_x = 40, Planet3_y = 20, Planet3_r = 0, Planet3_state = 1;

    double Planet4_x = 40, Planet4_y = 30, Planet4_r = 0, Planet4_state = 1;

    double Planet5_x = 40, Planet5_y = 30, Planet5_r = 0, Planet5_state = 1;

    double Planet6_x = 40, Planet6_y = 30, Planet6_r = 0, Planet6_state = 1;

    double Obstacle_x = 40, Obstacle_y = 20, Obstacle_w = 0.5, Obstacle_h = 0.5, Obstacle_state = 1;


    int counter = 0;

    YsSoundPlayer player;
    FsChangeToProgramDir();

    YsSoundPlayer::SoundData wav1;
    YsSoundPlayer::SoundData wav2;
    YsSoundPlayer::SoundData wav3;
    YsSoundPlayer::SoundData wav4;

    char fName1[256] = "263962__a-mcarthur__flyby4.wav";
    char fName2[256] = "587221__younoise__rings-of-saturn-ambient.wav";
    char fName3[256] = "235968__tommccann__explosion-01.wav";
    char fName4[256] = "520557__aj-heels__wehaveliftoff.wav";

    if (YSOK != wav1.LoadWav(fName1))
    {
        printf("Error!  Cannot load flyby.wav!\n");
    }

    if (YSOK != wav2.LoadWav(fName2))
    {
        printf("Error!  Cannot load saturn.wav!\n");
    }

    if (YSOK != wav3.LoadWav(fName3))
    {
        printf("Error!  Cannot load explosion.wav!\n");
    }

    if (YSOK != wav4.LoadWav(fName4))
    {
        printf("Error!  Cannot load flyby.wav!\n");
    }


    srand(time(NULL));

    //LOAD PNG SPACE IMAGE
    YsRawPngDecoder png;
    if (YSOK == png.Decode("democpp_image.png"))
    {
        png.Flip();
        printf("%d x %d\n", png.wid, png.hei);
    }
    else
    {
        printf("Could not read the image.\n");
    }



    FsOpenWindow(32, 32, window_W, window_H, 1);

    player.Start();
    player.PlayBackground(wav2);
    

    //FOR LOOP-----------------------------------------------------------------------------------------------------------
    for (;;)
    {

        FsPollDevice();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        auto key = FsInkey();
        if (FSKEY_ESC == key)
        {
            break;
        }


        //RENDERING------------------------------------------------------------------------------------------------------

        if (0 != flight_state)
        {
            flight_w -= 0.0025;
            flight_h -= 0.0025;
            flight_y -= 0.25;
            if (flight_y == 30)
            {
                flight_state = 0;
            }
        }

        

        if (0 != run_state)
        {
            run_y1 += 0.15;
            run_y2 += 0.15;

            if (run_y1 == 60 && run_y2 == 60 )
            {
                run_state = 0;
            }
        }

        if (run_state == 0)
        {
            circle_state = 1;
        }

        if (counter > 9000)
        {
            if (Planet4_state == 1)
            {
                Planet4_r += 0.04;
                Planet4_y -= 0.2;
                if (Planet4_y == 0)
                {
                    Planet4_state = 0;
                }
            }
        }

        if (counter > 7000)
        {
            player.PlayBackground(wav1);
        }

        if (counter > 22000)
        {
            player.Stop(wav1);
        }

        if (counter > 21200)
        { 
            player.PlayBackground(wav4);
        }

        if (counter > 35600)
        {
            player.Stop(wav4);
            player.PlayBackground(wav3);
        }

        if (counter > 7000)
        {
            if (Planet1_state == 1)
            {
                Planet1_r += 0.04;
                Planet1_y += 0.2;
                if (Planet1_x == 80)
                {
                    Planet1_state = 0;
                }
            }
        }

        if (counter > 11000)
        {
            if (Planet5_state == 1)
            {
                Planet5_r += 0.04;
                Planet5_x -= 0.2;
                if (Planet5_x == 0)
                {
                    Planet5_state = 0;
                }
            }
        }

        if (counter > 14000)
        {
            if (Obstacle_state == 1)
            {
                Obstacle_y += 0.25;
                Obstacle_w += 0.0025;
                Obstacle_h += 0.0025;
                if (Obstacle_y == 70)
                {
                    Obstacle_state = 0;
                }
            }
        }

        if (counter > 17000)
        {
            if (Planet6_state == 1)
            {
                Planet6_r += 0.04;
                Planet6_x += 0.2;
                if (Planet6_x == 80)
                {
                    Planet6_state = 0;
                }
            }
        }

        if (counter > 20000)
        {
            if (Planet2_state == 1)
            {
                Planet2_r += 0.04;
                Planet2_y += 0.2;
                if (Planet2_x == 80)
                {
                    Planet2_state = 0;
                }
            }
        }


        if (counter > 35000)
        {
            if (Planet3_state == 1)
            {
                Planet3_r += 0.04;
                Planet3_y += 0.2;
                if (Planet3_x == 80)
                {
                    Planet3_state = 0;
                }
            }
        }

        if (counter >= 7000 && counter <= 8000)
        {
            flight_x += 0.25;
            if (flight_x == 60)
            {
                flight_x = 60;
            }
        }

        if (counter > 11000 && counter <= 12000)
        {
            flight_x -= 0.25;
            if (flight_x == 40)
            {
                flight_x = 40;
            }
        }


        if (counter > 14000 && counter < 15000)
        {
            flight_x += 0.25;
            if (flight_x == 60)
            {
                flight_x = 60;
            }
        }

        if (counter > 16000 && counter <= 17000)
        {
            flight_x -= 0.25;
            if (flight_x == 40)
            {
                flight_x = 40;
            }
        }


        if (counter >= 20000 && counter <= 21000)
        {
            flight_x -= 0.25;
            if (flight_x == 20)
            {
                flight_x = 20;
            }
        }

        if (counter > 23000 && counter <= 24000)
        {
            flight_x += 0.25;
            if (flight_x == 40)
            {
                flight_x = 40;
            }
        }




        if (counter >= 30000 && counter <30100)
        {
            flight_x += 0.25;
            if (flight_x == 50 )
            {
                flight_x = 50;
            }
        }
        if (counter >= 30100 && counter < 30200)
        {
            flight_x -= 0.25;
            if (flight_x == 40)
            {
                flight_x = 40;
            }
        }
        if (counter >= 30200 && counter < 30300)
        {
            flight_x -= 0.25;
            if (flight_x == 30)
            {
                flight_x = 30;
            }
        }
        if (counter >= 30300 && counter < 30400)
        {
            flight_x += 0.25;
            if (flight_x == 40)
            {
                flight_x = 40;
            }
        }
        //1

        if (counter >= 30400 && counter < 30500)
        {
            flight_x += 0.25;
            if (flight_x == 50)
            {
                flight_x = 50;
            }
        }
        if (counter >= 30500 && counter < 30600)
        {
            flight_x -= 0.25;
            if (flight_x == 40)
            {
                flight_x = 40;
            }
        }
        if (counter >= 30600 && counter < 30700)
        {
            flight_x -= 0.25;
            if (flight_x == 30)
            {
                flight_x = 30;
            }
        }
        if (counter >= 30700 && counter < 30800)
        {
            flight_x += 0.25;
            if (flight_x == 40)
            {
                flight_x = 40;
            }
        }

        //2

        if (counter >= 30800 && counter < 30900)
        {
            flight_x += 0.25;
            if (flight_x == 50)
            {
                flight_x = 50;
            }
        }
        if (counter >= 30900 && counter < 31000)
        {
            flight_x -= 0.25;
            if (flight_x == 40)
            {
                flight_x = 40;
            }
        }
        if (counter >= 31000 && counter < 31100)
        {
            flight_x -= 0.25;
            if (flight_x == 30)
            {
                flight_x = 30;
            }
        }
        if (counter >= 31100 && counter < 31200)
        {
            flight_x += 0.25;
            if (flight_x == 40)
            {
                flight_x = 40;
            }
        }

        //3
        if (counter >= 31200 && counter < 31300)
        {
            flight_x += 0.25;
            if (flight_x == 50)
            {
                flight_x = 50;
            }
        }
        if (counter >= 31300 && counter < 31400)
        {
            flight_x -= 0.25;
            if (flight_x == 40)
            {
                flight_x = 40;
            }
        }
        if (counter >= 31400 && counter < 31500)
        {
            flight_x -= 0.25;
            if (flight_x == 30)
            {
                flight_x = 30;
            }
        }
        if (counter >= 31500 && counter < 31600)
        {
            flight_x += 0.25;
            if (flight_x == 40)
            {
                flight_x = 40;
            }
        }

        //4
        if (counter >= 31600 && counter < 31700)
        {
            flight_x += 0.25;
            if (flight_x == 50)
            {
                flight_x = 50;
            }
        }
        if (counter >= 31700 && counter < 31800)
        {
            flight_x -= 0.25;
            if (flight_x == 40)
            {
                flight_x = 40;
            }
        }
        if (counter >= 31800 && counter < 31900)
        {
            flight_x -= 0.25;
            if (flight_x == 30)
            {
                flight_x = 30;
            }
        }
        if (counter >= 31900 && counter < 32000)
        {
            flight_x += 0.25;
            if (flight_x == 40)
            {
                flight_x = 40;
            }
        }


        // 3200 - 3400
        if (counter >= 32000 && counter < 32100)
        {
            flight_x += 0.25;
            if (flight_x == 50)
            {
                flight_x = 50;
            }
        }
        if (counter >= 32100 && counter < 32200)
        {
            flight_x -= 0.25;
            if (flight_x == 40)
            {
                flight_x = 40;
            }
        }
        if (counter >= 32200 && counter < 32300)
        {
            flight_x -= 0.25;
            if (flight_x == 30)
            {
                flight_x = 30;
            }
        }
        if (counter >= 32300 && counter < 32400)
        {
            flight_x += 0.25;
            if (flight_x == 40)
            {
                flight_x = 40;
            }
        }
        //1

        if (counter >= 32400 && counter < 32500)
        {
            flight_x += 0.25;
            if (flight_x == 50)
            {
                flight_x = 50;
            }
        }
        if (counter >= 32500 && counter < 32600)
        {
            flight_x -= 0.25;
            if (flight_x == 40)
            {
                flight_x = 40;
            }
        }
        if (counter >= 32600 && counter < 32700)
        {
            flight_x -= 0.25;
            if (flight_x == 30)
            {
                flight_x = 30;
            }
        }
        if (counter >= 32700 && counter < 32800)
        {
            flight_x += 0.25;
            if (flight_x == 40)
            {
                flight_x = 40;
            }
        }

        //2

        if (counter >= 32800 && counter < 32900)
        {
            flight_x += 0.25;
            if (flight_x == 50)
            {
                flight_x = 50;
            }
        }
        if (counter >= 32900 && counter < 33000)
        {
            flight_x -= 0.25;
            if (flight_x == 40)
            {
                flight_x = 40;
            }
        }
        if (counter >= 33000 && counter < 33100)
        {
            flight_x -= 0.25;
            if (flight_x == 30)
            {
                flight_x = 30;
            }
        }
        if (counter >= 33100 && counter < 33200)
        {
            flight_x += 0.25;
            if (flight_x == 40)
            {
                flight_x = 40;
            }
        }

        //3
        if (counter >= 33200 && counter < 33300)
        {
            flight_x += 0.25;
            if (flight_x == 50)
            {
                flight_x = 50;
            }
        }
        if (counter >= 33300 && counter < 33400)
        {
            flight_x -= 0.25;
            if (flight_x == 40)
            {
                flight_x = 40;
            }
        }
        if (counter >= 33400 && counter < 33500)
        {
            flight_x -= 0.25;
            if (flight_x == 30)
            {
                flight_x = 30;
            }
        }
        if (counter >= 33500 && counter < 33600)
        {
            flight_x += 0.25;
            if (flight_x == 40)
            {
                flight_x = 40;
            }
        }

        //4
        if (counter >= 33600 && counter < 33700)
        {
            flight_x += 0.25;
            if (flight_x == 50)
            {
                flight_x = 50;
            }
        }
        if (counter >= 33700 && counter < 33800)
        {
            flight_x -= 0.25;
            if (flight_x == 40)
            {
                flight_x = 40;
            }
        }
        if (counter >= 33800 && counter < 33900)
        {
            flight_x -= 0.25;
            if (flight_x == 30)
            {
                flight_x = 30;
            }
        }
        if (counter >= 33900 && counter < 34000)
        {
            flight_x += 0.25;
            if (flight_x == 40)
            {
                flight_x = 40;
            }
        }

        //34000 to 35000
        if (counter >= 34000 && counter < 34100)
        {
            flight_x += 0.25;
            if (flight_x == 50)
            {
                flight_x = 50;
            }
        }
        if (counter >= 34100 && counter < 34200)
        {
            flight_x -= 0.25;
            if (flight_x == 40)
            {
                flight_x = 40;
            }
        }
        if (counter >= 34200 && counter < 34300)
        {
            flight_x -= 0.25;
            if (flight_x == 30)
            {
                flight_x = 30;
            }
        }
        if (counter >= 34300 && counter < 34400)
        {
            flight_x += 0.25;
            if (flight_x == 40)
            {
                flight_x = 40;
            }
        }

        //4
        if (counter >= 34400 && counter < 34500)
        {
            flight_x += 0.25;
            if (flight_x == 50)
            {
                flight_x = 50;
            }
        }
        if (counter >= 34500 && counter < 34600)
        {
            flight_x -= 0.25;
            if (flight_x == 40)
            {
                flight_x = 40;
            }
        }
        if (counter >= 34600 && counter < 34700)
        {
            flight_x -= 0.25;
            if (flight_x == 30)
            {
                flight_x = 30;
            }
        }
        if (counter >= 34700 && counter < 34800)
        {
            flight_x += 0.25;
            if (flight_x == 40)
            {
                flight_x = 40;
            }
        }

        if (counter >= 34800 && counter < 34900)
        {
            flight_x += 0.25;
            if (flight_x == 50)
            {
                flight_x = 50;
            }
        }
        if (counter >= 34900 && counter < 35000)
        {
            flight_x -= 0.25;
            if (flight_x == 40)
            {
                flight_x = 40;
            }
        }

        if (counter > 35650)
        {
            circle_r_1 += 0.5;
            circle_r_2 += 0.5;
            circle_r_3 += 0.5;
        }
 



        //DRAWING-----------------------------------------------------------------------------------------------------------
        if (counter <= 2000)
        {
            DrawBackground1();
        }

        if (counter > 2000)
            DrawBackground();

        glRasterPos2i(0, 599);
        glDrawPixels(png.wid, png.hei, GL_RGBA, GL_UNSIGNED_BYTE, png.rgba);


        if (counter >= 2100 && counter <= 24000)
        {

            Circles(circle_x, circle_y, 38, 255, 255, 255);

            Circles(circle_x, circle_y, 25, 255, 255, 255);

            Circles(circle_x, circle_y, 22, 255, 255, 255);            

            Circles(circle_x, circle_y, 18, 255, 255, 255);

            Circles(circle_x, circle_y, 16, 255,255,255);

            Circles(circle_x, circle_y, 14, 255,255,255);

            Circles(circle_x, circle_y, 12 , 255,255,255);

            Circles(circle_x, circle_y, 11, 255, 255, 255);
        }

        


        if (counter >= 500 && counter < 1900)
            if (run_state != 0)
            {
                Runway(run_x1, run_y1, run_x2, run_y2);
            }

        if (counter <= 500)
        {
            glColor3ub(132, 115, 90);

            glBegin(GL_QUADS);
            glVertex2i(0, 300);
            glVertex2i(800, 300);
            glVertex2i(800, 300 + 300);
            glVertex2i(0, 300 + 300);
            glEnd();

            glColor3ub(255, 255, 0);
            glBegin(GL_QUADS);
            glVertex2i(200, 300);
            glVertex2i(200 - 200, 300 + 300);
            glVertex2i(200 - 180, 300 + 300);
            glVertex2i(200 + 20, 300);
            glEnd();

            glColor3ub(255, 255, 0);
            glBegin(GL_QUADS);
            glVertex2i(600, 300);
            glVertex2i(600 + 200, 300 + 300);
            glVertex2i(600 + 180, 300 + 300);
            glVertex2i(600 - 20, 300);
            glEnd();

        }

        if (counter <= 1600)
        {
            glColor3f(1, 1, 0);
            glRasterPos2i(50, 150);
            YsGlDrawFontBitmap10x14("OUR DRONE WILL BEGIN SPACE EXPLORATION FROM ITS MOTHER - SPACESHIP NOW!");

            glColor3f(1, 0, 0);
            glRasterPos2i(250, 250);
            YsGlDrawFontBitmap16x20("BRACE YOURSELF! ");
        }

        if (counter > 24100 && counter <= 35650)
        {
            Circles(circle_x, circle_y, 40, 255, 255, 255);

            Circles(circle_x, circle_y, 27, 255, 255, 255);

            Circles(circle_x, circle_y, 24, 255, 255, 255);

            Circles(circle_x, circle_y, 20, 255, 255, 255);

            Circles(circle_x, circle_y, 18, 255, 255, 255);

            Circles(circle_x, circle_y, 16, 255, 255, 255);

            Circles(circle_x, circle_y, 14, 255, 255, 255);

            Circles(circle_x, circle_y, 12.5, 255, 255, 255);

            Circles(circle_x, circle_y, 11, 255, 255, 255);
        }

        if (counter >= 24000 && counter <= 35650)
        {
            if (star_state == 1)
            {
                int r = rand() % 256;
                int g = rand() % 256;
                int b = rand() % 256;
                int x1 = 400;
                int y1 = 300;
                int x2 = rand() % 800;
                int y2 = rand() % 600;
                glLineWidth(10);
                glColor3ub(r, g, b);
                glBegin(GL_LINES);
                glVertex2i(x1, y1);
                glVertex2i(x2, y2);
                glEnd();

            }
        }

        if (counter >= 7000)
        {
            if (Planet1_state == 1)
            {
                Planet1(Planet1_x, Planet1_y, Planet1_r, 59, 93, 56);
            }
        }

        if (counter >= 9000)
        {
            if (Planet4_state == 1)
            {
                Planet1(Planet4_x, Planet4_y, Planet4_r, 146, 126, 119);
            }
        }


        if (counter >= 11000)
        {
            if (Planet5_state == 1)
            {
                Planet1(Planet5_x, Planet5_y, Planet5_r, 255, 157, 111);
            }
        }


        if (counter > 14000)
        {
            if (Obstacle_state == 1)
            {
                Obstacle(Obstacle_x, Obstacle_y, Obstacle_w, Obstacle_h);
            }
        }

        if (counter >= 17000)
        {
            if (Planet6_state == 1)
            {
                Planet1(Planet6_x, Planet6_y, Planet6_r, 153, 133, 122);
            }
        }

        if (counter >= 20000)
        {
            if (Planet2_state == 1)
            {
                Planet1(Planet2_x, Planet2_y, Planet2_r, 148, 91, 71);
            }
        }

        if (counter >= 34900 && counter < 35650)
        {
            if (Planet3_state == 1)
            {
                Planet1(Planet3_x, Planet3_y, Planet3_r, 140, 177, 222);
            }
        }


        if (counter >= 35650 && counter < 37500)
        {
            glColor3ub(255, 0, 0);
            glBegin(GL_POLYGON);
            for (int i = 0; i < 64; ++i)
            {
                const double pi = 3.14159;
                double a = (double)i * pi / 32.0;
                double c = cos(a);
                double s = sin(a);

                glVertex2d(400 + c * circle_r_1, 300 + s * circle_r_1);
            }
            glEnd();
        }

        if (counter >= 36000 && counter <= 38000)
        {
            glColor3ub(255,255,0);
            glBegin(GL_POLYGON);
            for (int i = 0; i < 64; ++i)
            {
                const double pi = 3.14159;
                double a = (double)i * pi / 32.0;
                double c = cos(a);
                double s = sin(a);

                glVertex2d(400 + c * circle_r_2, 300 + s * circle_r_2);
            }
            glEnd();
        }

        if (counter >= 36500 && counter <= 39500)
        {
            glColor3ub(255, 165, 0);
            glBegin(GL_POLYGON);
            for (int i = 0; i < 64; ++i)
            {
                const double pi = 3.14159;
                double a = (double)i * pi / 32.0;
                double c = cos(a);
                double s = sin(a);

                glVertex2d(400 + c * circle_r_3, 300 + s * circle_r_3);
            }
            glEnd();
        }


        if (counter > 22000 && counter < 23000)
        {

            glColor3ub(0,0,0);
            glBegin(GL_QUADS);
            glVertex2i(200, 100);
            glVertex2i(600, 100);
            glVertex2i(600, 150);
            glVertex2i(200, 150);
            glEnd();


            glColor3f(1, 1, 0);
            glRasterPos2i(300, 125);
            YsGlDrawFontBitmap8x8("IT IS TIME TO GO FASTERR");
        }

        if (counter > 7500 && counter < 9500)
        {
            glColor3ub(0,0,0);
            glBegin(GL_QUADS);
            glVertex2i(100, 100);
            glVertex2i(700, 100);
            glVertex2i(700, 150);
            glVertex2i(100, 150);
            glEnd();


            glColor3f(1, 1, 0);
            glRasterPos2i(190, 125);
            YsGlDrawFontBitmap8x12("THAT WAS SUPER CLOSE, WE WILL HAVE TO STAY ALERT!");

        }

        if (counter > 32000 && counter < 34000)
        {
            glColor3ub(0, 0, 0);
            glBegin(GL_QUADS);
            glVertex2i(100, 100);
            glVertex2i(700, 100);
            glVertex2i(700, 150);
            glVertex2i(100, 150);
            glEnd();


            glColor3f(1, 1, 0);
            glRasterPos2i(190, 125);
            YsGlDrawFontBitmap8x12("THIS SPEED IS UNCONTROLLABLE! WE MIGHT CRASH!!");

        }
        
        if (counter < 35650)
            Flight(flight_x, flight_y, flight_w, flight_h);

        if (counter > 37500 && counter < 40000)
        {
            glColor3ub(0, 0, 0);
            glBegin(GL_QUADS);
            glVertex2i(100, 100);
            glVertex2i(700, 100);
            glVertex2i(700, 150);
            glVertex2i(100, 150);
            glEnd();


            glColor3f(1, 1, 0);
            glRasterPos2i(190, 125);
            YsGlDrawFontBitmap8x12("PERHAPS GOING THIS FAST WAS NOT A GOOD IDEA");

        }

        if (counter > 40000 && counter < 43000)
        {
            glColor3f(1, 1, 1);
            glRasterPos2i(50 , 300);
            YsGlDrawFontBitmap16x20("THANK YOU FOR BEING A PART OF THIS JOURNEY!");

        }

        if (counter == 43500)
        {
            break;
        }


        FsSwapBuffers();
        glFlush();
        FsSleep(10);
        counter += 10;

    }

    player.End();

    return 0;
}



