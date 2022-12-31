#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>
#include<stdio.h>
#include<iostream>
#include<string>
#include<cmath>

using namespace std;

struct Cwave{
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
}cwv;
//6
void Cal_Wave_Melody(SDL_Window* window, SDL_Renderer* render, SDL_Texture* img[],SDL_Rect img_rect[],string &st1,string &st2,string &st3,int &mouse_x,int &mouse_y){

    if(!cwv.initial()){
        printf("Did not Initial\n");
        return;
    }

    double l,m,M,T,f,v,g;
    string ss1,ss2,ss3;
    /*  l=length of wire
        m = mass of weight
        M = mass of wire
        T = Tension
        f = frequency
        v = velocity of the wave
        g = gravitational acceleration  */

    l=stod(st1)/100;   // cm > m
    m=stod(st2)/1000;  // g > kg
    M=stod(st3)/1000;  // g > kg
    g=9.8;

    //formula
    T=m*g;
    f=sqrt(m*g*l/M)/(2*l);
    v=sqrt(m*g*l/M);

    ss1=to_string(T);
    ss2=to_string(f);
    ss3=to_string(v);

    ss1+="  N";
    ss2+="  Hz";
    ss3+="  m/s";

    //Output Surface
    cwv.sfont= TTF_OpenFont("Ubuntu/Ubuntu-Bold.ttf",26);
    SDL_Surface* surface=NULL;
    SDL_Texture* tex=NULL;
    SDL_Rect srect[20];
    SDL_SetRenderDrawColor(render,255,255,255,255);
    SDL_RenderClear(render);
    if(!render)printf("NOT RENDERED %s\n",SDL_GetError());
    SDL_Color color={255,255,255};
    SDL_Color color1={0,0,0};
    int run=1;
    SDL_Event e;
    int x=0;


    while(run){
        SDL_SetRenderDrawColor(render,0,20,55,0);
        SDL_RenderClear(render);

        //Tension
        surface= TTF_RenderText_Solid(cwv.sfont,"T- Tension on the wire :",color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        srect[0]={30,100,260,30};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&srect[0]);
        srect[1]={300,100,300,40};
        SDL_SetRenderDrawColor(render,255,0,127,255);
        SDL_RenderFillRect(render,&srect[1]);
        surface = TTF_RenderText_Solid(cwv.sfont, ss1.c_str(), color1);
        tex = SDL_CreateTextureFromSurface(render, surface);
        srect[2]={310,100,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &srect[2]);

        //Frequency
        surface= TTF_RenderText_Solid(cwv.sfont,"f- Frequency of the wave :",color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        srect[3]={30,150,260,30};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&srect[3]);
        srect[4]={300,150,300,40};
        SDL_SetRenderDrawColor(render,255,0,127,255);
        SDL_RenderFillRect(render,&srect[4]);
        surface = TTF_RenderText_Solid(cwv.sfont, ss2.c_str(), color1);
        tex = SDL_CreateTextureFromSurface(render, surface);
        srect[5]={310,150,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &srect[5]);

        //Velocity
        surface= TTF_RenderText_Solid(cwv.sfont,"v- Velocity :",color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        srect[6]={30,200,120,30};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&srect[6]);
        srect[7]={300,200,300,40};
        SDL_SetRenderDrawColor(render,255,0,127,255);
        SDL_RenderFillRect(render,&srect[7]);
        surface = TTF_RenderText_Solid(cwv.sfont, ss3.c_str(), color1);
        tex = SDL_CreateTextureFromSurface(render, surface);
        srect[8]={310,200,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &srect[8]);

        //back button
        srect[9]={0,0,100,50};
        SDL_SetRenderDrawColor(render,140,200,30,140);
        SDL_RenderFillRect(render,&srect[9]);
        surface = TTF_RenderText_Solid(cwv.sfont, " BACK ", color);
        tex = SDL_CreateTextureFromSurface(render, surface);
        srect[10]={10,6,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &srect[10]);


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


        //Animation-wave movement

        //wave
        if(x%24==0||x%24==1||x%24==2||x%24==3||x%24==4||x%24==5){
        srect[13]={100,300,900,500};
        SDL_RenderCopy(render,img[25],NULL,&srect[13]);
        }

        else if(x%24==6||x%24==7||x%24==8||x%24==9||x%24==10||x%24==11){
        srect[14]={100,300,900,500};
        SDL_RenderCopy(render,img[26],NULL,&srect[14]);
        }

        else if(x%24==12||x%24==13||x%24==14||x%24==15||x%24==16||x%24==17){
        srect[15]={100,300,900,500};
        SDL_RenderCopy(render,img[27],NULL,&srect[15]);
        }

        else if(x%24==18||x%24==19||x%24==20||x%24==21||x%24==22||x%24==23){
        srect[16]={100,300,900,500};
        SDL_RenderCopy(render,img[28],NULL,&srect[16]);
        }

        //Tunic fork
        if(x%12==0||x%12==1||x%12==2||x%12==3||x%12==4||x%12==5){
        srect[11]={210,470,150,150};
        SDL_RenderCopy(render,img[29],NULL,&srect[11]);
        }
        else{
        srect[12]={210,470,150,150};
        SDL_RenderCopy(render,img[30],NULL,&srect[12]);
        }

        x++;


        SDL_RenderPresent(render);
        SDL_Delay(10);
    }

    cwv.stop();
}




