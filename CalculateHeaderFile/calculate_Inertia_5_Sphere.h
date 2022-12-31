#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>
#include<stdio.h>
#include<iostream>
#include<string>
#include<cmath>

using namespace std;

struct Csphere{
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
}csp;
//7.5
void Cal_Inertia_5_Sphere(SDL_Window* window, SDL_Renderer* render, SDL_Texture* img[],SDL_Rect img_rect[],string &st1,string &st2,string &st3,int &mouse_x,int &mouse_y){

    if(!csp.initial()){
        printf("Did not Initial\n");
        return;
    }

    double m, r, Ic, It;
    string ss1,ss2;
    /*  m = mass of sphere
        r = radius of sphere
        Ic = inertia about the center axis
        It = inertia about the tangent axis */

    m=stod(st2);
    r=stod(st3);

    //formula
    Ic=2*m*r*r/5;
    It=7*m*r*r/5;

    ss1=to_string(Ic);
    ss2=to_string(It);

    ss1+="  kgm2";
    ss2+="  kgm2";

    //Output Surface
    csp.sfont= TTF_OpenFont("Ubuntu/Ubuntu-Bold.ttf",26);
    SDL_Surface* surface=NULL;
    SDL_Texture* tex=NULL;
    SDL_SetRenderDrawColor(render,255,255,255,255);
    SDL_RenderClear(render);
    if(!render)printf("NOT RENDERED %s\n",SDL_GetError());
    SDL_Color color={255,255,255};
    SDL_Color color1={0,0,0};
    SDL_Rect srect[20];
    int run=1;
    SDL_Event e;
    int x=0;


    while(run){
        SDL_SetRenderDrawColor(render,0,20,55,0);
        SDL_RenderClear(render);

        //for center
        if(st1=="1"){
        surface= TTF_RenderText_Solid(csp.sfont,"I- Inertia about the Center axis :",color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        srect[0]={30,100,265,30};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&srect[0]);
        srect[1]={300,100,300,40};
        SDL_SetRenderDrawColor(render,255,0,127,255);
        SDL_RenderFillRect(render,&srect[1]);
        surface = TTF_RenderText_Solid(csp.sfont, ss1.c_str(), color1);
        tex = SDL_CreateTextureFromSurface(render, surface);
        srect[2]={310,100,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &srect[2]);
        }

        //for tangent
        else if(st1=="2"){
        surface= TTF_RenderText_Solid(csp.sfont,"I- Inertia about the Tangent axis :",color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        srect[0]={30,100,265,30};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&srect[0]);
        srect[1]={300,100,300,40};
        SDL_SetRenderDrawColor(render,255,0,127,255);
        SDL_RenderFillRect(render,&srect[1]);
        surface = TTF_RenderText_Solid(csp.sfont, ss1.c_str(), color1);
        tex = SDL_CreateTextureFromSurface(render, surface);
        srect[2]={310,100,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &srect[2]);
        }

        //back button
        srect[3]={0,0,100,50};
        SDL_SetRenderDrawColor(render,140,200,30,140);
        SDL_RenderFillRect(render,&srect[3]);
        surface = TTF_RenderText_Solid(csp.sfont, " BACK ", color);
        tex = SDL_CreateTextureFromSurface(render, surface);
        srect[4]={10,6,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &srect[4]);


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


        //Animation - circulation

        //center
        if(st1=="1"){
            //img1
            if(x%8==0||x%8==1||x%8==2||x%8==3){
            srect[5]={380,200,500,500};
            SDL_RenderCopy(render,img[89],NULL,&srect[5]);
            }
            //img2
            else if(x%8==4||x%8==5||x%8==6||x%8==7){
            srect[6]={380,200,500,500};
            SDL_RenderCopy(render,img[90],NULL,&srect[6]);
            }
        }

        //tangent
        else if(st1=="2"){
            //img1
            if(x%32==0||x%32==1||x%32==2||x%32==3||x%32==4||x%32==5||x%32==6||x%32==7){
            srect[5]={380,200,500,500};
            SDL_RenderCopy(render,img[91],NULL,&srect[5]);
            }
            //img2
            else if(x%32==8||x%32==9||x%32==10||x%32==11||x%32==12||x%32==13||x%32==14||x%32==15){
            srect[6]={380,200,500,500};
            SDL_RenderCopy(render,img[92],NULL,&srect[6]);
            }
            //img3
            else if(x%32==16||x%32==17||x%32==18||x%32==19||x%32==20||x%32==21||x%32==22||x%32==23){
            srect[7]={380,200,500,500};
            SDL_RenderCopy(render,img[93],NULL,&srect[7]);
            }
            //img4
            else if(x%32==24||x%32==25||x%32==26||x%32==27||x%32==28||x%32==29||x%32==30||x%32==31){
            srect[8]={380,200,500,500};
            SDL_RenderCopy(render,img[94],NULL,&srect[8]);
            }
        }

        x++;


        SDL_RenderPresent(render);
        SDL_Delay(10);
    }

    csp.stop();
}




