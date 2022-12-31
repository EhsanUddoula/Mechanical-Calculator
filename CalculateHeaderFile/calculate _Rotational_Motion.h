#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>
#include<stdio.h>
#include<iostream>
#include<string>
#include<cmath>

using namespace std;

struct Crotation{
    TTF_Font* sfont=NULL;

    bool initial(){
        bool suc=true;
        if(TTF_Init()<0){
            printf("Did not succeed\n");
            suc=false;
        }
        //SDL_StartTextInput();
        return suc;
    }

    void stop(){
        TTF_CloseFont(sfont);
        sfont=NULL;
        TTF_Quit();
    }
}crot;


void CalROTATIONAL_MOTION(SDL_Window* window, SDL_Renderer* render, SDL_Texture* img[],SDL_Rect img_rect[],string &st1,string &st2,string &st3,int &mouse_x,int &mouse_y){

        if(!crot.initial()){
        printf("Did not Initial\n");
        return;
    }

    double radius,rNum,rTime,T,f,w,v;
    string ss1,ss2,ss3,ss4,ss5;

    /*  radius = radius of sphere
    	rNum = number of rotations
		rTime = times for rNUM rotations
		T = Time period
    	f = Frequency
    	w = Angular velocity
    	v = Linear velocity */

    radius=stod(st1);
    rNum=stod(st2);
    rTime=stod(st3);

    //formula
    T=rTime*60.0/rNum;
    f=1.0/T;
    w=2.0*M_PI/T;
    v=w*radius*1.0;

    ss1=to_string(T);
    ss2=to_string(f);
    ss3=to_string(v);
    ss4=to_string(w);

    ss1+=" s";
    ss2+=" Hz";
    ss3+=" m/s";
    ss4+=" rad/s";

    //OUtput surface
    crot.sfont= TTF_OpenFont("Ubuntu/Ubuntu-Bold.ttf",26);
    SDL_Surface* surface=NULL;
    SDL_Texture* tex=NULL;
    SDL_SetRenderDrawColor(render,255,255,255,255);
    SDL_RenderClear(render);
    if(!render)printf("NOT RENDERED %s\n",SDL_GetError());
    SDL_Color color={255,255,255};
    int run=1;
    SDL_Event e;
    SDL_Rect srect[20];
    SDL_FRect rect[3];

    //for Rotation
    //starting point(x,y)=(x1,y1)=(500,500)
    //center (x,y) = (h,k)=(600,500)

    int r,speed;
    //radius condition
    if(radius==0)
        r=0;
    if(radius>0 && radius<=5)
        r=20;
    if(radius>5 && radius<=10)
        r=50;
    if(radius>10 && radius<=20)
        r=80;
    if(radius>20 && radius<=30)
        r=100;
    if(radius>30 && radius<=60)
        r=130;
    if(radius>60 && radius<=90)
        r=160;
    if(radius>90 && radius<=120)
        r=190;
    if(radius>120 && radius<=200)
        r=210;
    if(radius>200 && radius<=400)
        r=230;
    if(radius>400 && radius<=800)
        r=250;
    if(radius>800 && radius<=1000)
        r=280;
    if(radius>1000)
        r=300;

    //speed condition
    if(f<0)
        speed=3;
    if(f>0 && f<=1)
        speed=6;
    if(f>1 && f<=3)
        speed=10;
    if(f>3 )
        speed=15;


    srect[18]={300,600,50,50};//sphere

    int flag=1,k=500;
    float p,h;
    h=300+r;
    int x1=srect[18].x;
    int y1=srect[18].y;


    while(run){
        SDL_SetRenderDrawColor(render,0,20,55,0);
        SDL_RenderClear(render);

        //back button
        srect[12]={0,0,100,50};
        SDL_SetRenderDrawColor(render,140,200,30,140);
        SDL_RenderFillRect(render,&srect[12]);
        surface = TTF_RenderText_Solid(crot.sfont, " BACK ", color);
        tex = SDL_CreateTextureFromSurface(render, surface);
        srect[13]={10,6,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &srect[13]);

        //Time Period
        surface= TTF_RenderText_Solid(crot.sfont,"Time Period (T): ",color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        srect[0]={30,100,250,30};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&srect[0]);
        srect[1]={300,100,300,40};
        SDL_SetRenderDrawColor(render,255,0,127,255);
        SDL_RenderFillRect(render,&srect[1]);
        surface = TTF_RenderText_Solid(crot.sfont, ss1.c_str(), color);
        tex = SDL_CreateTextureFromSurface(render, surface);
        srect[2]={300,100,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &srect[2]);

        //Frequency
        surface= TTF_RenderText_Solid(crot.sfont,"Frequency (f): ",color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        srect[3]={30,150,250,30};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&srect[3]);
        srect[4]={300,150,300,40};
        SDL_SetRenderDrawColor(render,255,0,127,255);
        SDL_RenderFillRect(render,&srect[4]);
        surface = TTF_RenderText_Solid(crot.sfont, ss2.c_str(), color);
        tex = SDL_CreateTextureFromSurface(render, surface);
        srect[5]={300,150,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &srect[5]);

        //Linear Velocity
        surface= TTF_RenderText_Solid(crot.sfont,"Linear Velocity (v): ",color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        srect[6]={30,200,250,30};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&srect[6]);
        srect[7]={300,200,300,40};
        SDL_SetRenderDrawColor(render,255,0,127,255);
        SDL_RenderFillRect(render,&srect[7]);
        surface = TTF_RenderText_Solid(crot.sfont, ss3.c_str(), color);
        tex = SDL_CreateTextureFromSurface(render, surface);
        srect[8]={300,200,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &srect[8]);

        //angular velocity
        surface= TTF_RenderText_Solid(crot.sfont,"Angular Velocity (w): ",color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        srect[9]={30,250,250,30};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&srect[9]);
        srect[10]={300,250,300,40};
        SDL_SetRenderDrawColor(render,255,0,127,255);
        SDL_RenderFillRect(render,&srect[10]);
        surface = TTF_RenderText_Solid(crot.sfont, ss4.c_str(), color);
        tex = SDL_CreateTextureFromSurface(render, surface);
        srect[11]={300,250,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &srect[11]);

        //mouse event
        while(SDL_PollEvent(&e)){
            switch(e.type){
            	case SDL_QUIT:
            		run=0;
            		break;
                case SDL_MOUSEMOTION:
                    mouse_x=e.motion.x;
                    mouse_y=e.motion.y;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    case SDL_BUTTON_LEFT:
                        if((mouse_x>0&&mouse_x<100)&&(mouse_y>0&&mouse_y<50))
                        run=0;
                    break;
            }
        }


        //Animation- sphere's rotation

        SDL_RenderCopy(render,img[6],NULL,&srect[18]);
        //starting point(x,y)=(x1,y1)=(500,500)
        //center (x,y) = (h,k)=(600,500)

        //center point and circular ring load
        SDL_RenderCopyF(render,img[4],NULL,&rect[0]);
        float R;
        R=r+r/2+r/4.0;
        rect[0]={(h+25-R/2.0),(k+25-R/2.0),R,R}; //25= sphere's height/width's(50) half

        SDL_RenderCopyF(render,img[5],NULL,&rect[1]);
        rect[1]={h-10.0+25,k-10+25.0,20,20.0};

        //conditions of rotation
        if(flag==1 && srect[18].x>=x1 && srect[18].x<=x1+r+r){
            srect[18].x=srect[18].x+speed;
            p=srect[18].x-h;
            srect[18].y=sqrt((r*r)-(p*p))+k;

            if(srect[18].x>=x1+r+r)
                flag=0;
        }
        else if(flag==0){
            srect[18].x=srect[18].x-speed;
            p=srect[18].x-h;
            srect[18].y=-sqrt((r*r)-(p*p))+k;

            if(srect[18].x<=x1)
                flag=1;
        }
        SDL_RenderPresent(render);
        SDL_Delay(10);
    }

    crot.stop();
}



