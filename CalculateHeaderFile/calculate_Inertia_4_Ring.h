#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>
#include<stdio.h>
#include<iostream>
#include<string>
#include<cmath>

using namespace std;

struct Cring{
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
}crin;

//7.4
void Cal_Inertia_4_Ring(SDL_Window* window, SDL_Renderer* render, SDL_Texture* img[],SDL_Rect img_rect[],string &st1,string &st2,string &st3,int &mouse_x,int &mouse_y){

    if(!crin.initial()){
        printf("Did not Initial\n");
        return;
    }

    double m, r, Ic, Id, It;
    string ss1,ss2,ss3;

    /*  m = mass of ring
        r = radius of ring
        Ic = inertia about the center axis
        Id = inertia about the diameter axis
        It = inertia about the tangent axis (perpendicular)*/

    m=stod(st2);
    r=stod(st3);

    //formula
    Ic=m*r*r;
    Id=m*r*r/2;
    It=3*m*r*r/2;;

    ss1=to_string(Ic);
    ss2=to_string(Id);
    ss3=to_string(It);

    ss1+="  kgm2";
    ss2+="  kgm2";
    ss3+="  kgm2";

    //Output Surface
    crin.sfont= TTF_OpenFont("Ubuntu/Ubuntu-Bold.ttf",26);
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
        surface= TTF_RenderText_Solid(crin.sfont,"I-Inertia about the Center axis:",color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        srect[0]={30,100,265,30};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&srect[0]);
        srect[1]={300,100,300,40};
        SDL_SetRenderDrawColor(render,255,0,127,255);
        SDL_RenderFillRect(render,&srect[1]);
        surface = TTF_RenderText_Solid(crin.sfont, ss1.c_str(), color1);
        tex = SDL_CreateTextureFromSurface(render, surface);
        srect[2]={310,100,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &srect[2]);
        }

        //for diameter
        else if(st1=="2"){
        surface= TTF_RenderText_Solid(crin.sfont,"I-Inertia about the Diameter axis:",color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        srect[0]={30,100,265,30};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&srect[0]);
        srect[1]={300,100,300,40};
        SDL_SetRenderDrawColor(render,255,0,127,255);
        SDL_RenderFillRect(render,&srect[1]);
        surface = TTF_RenderText_Solid(crin.sfont, ss1.c_str(), color1);
        tex = SDL_CreateTextureFromSurface(render, surface);
        srect[2]={310,100,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &srect[2]);
        }

        //for tangent
        else if(st1=="3"){
        surface= TTF_RenderText_Solid(crin.sfont,"I-Inertia about the Tangent axis:",color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        srect[0]={30,100,265,30};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&srect[0]);
        srect[1]={300,100,300,40};
        SDL_SetRenderDrawColor(render,255,0,127,255);
        SDL_RenderFillRect(render,&srect[1]);
        surface = TTF_RenderText_Solid(crin.sfont, ss1.c_str(), color1);
        tex = SDL_CreateTextureFromSurface(render, surface);
        srect[2]={310,100,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &srect[2]);
        }

        //back button
        srect[3]={0,0,100,50};
        SDL_SetRenderDrawColor(render,140,200,30,140);
        SDL_RenderFillRect(render,&srect[3]);
        surface = TTF_RenderText_Solid(crin.sfont, " BACK ", color);
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
            if(x%12==0||x%12==1||x%12==2||x%12==3||x%12==4||x%12==5){
            srect[5]={380,200,500,500};
            SDL_RenderCopy(render,img[72],NULL,&srect[5]);
            }
            //img2
            else if(x%12==6||x%12==7||x%12==8||x%12==9||x%12==10||x%12==11){
            srect[6]={380,200,500,500};
            SDL_RenderCopy(render,img[73],NULL,&srect[6]);
            }
        }

        //diameter
        else if(st1=="2"){
            //img1
            if(x%48==0||x%48==1||x%48==2||x%48==3||x%48==4||x%48==5){
            srect[5]={380,200,500,500};
            SDL_RenderCopy(render,img[74],NULL,&srect[5]);
            }
            //img2
            else if(x%48==6||x%48==7||x%48==8||x%48==9||x%48==10||x%48==11){
            srect[6]={380,200,500,500};
            SDL_RenderCopy(render,img[75],NULL,&srect[6]);
            }
            //img3
            else if(x%48==12||x%48==13||x%48==14||x%48==15||x%48==16||x%48==17){
            srect[7]={380,200,500,500};
            SDL_RenderCopy(render,img[76],NULL,&srect[7]);
            }
            //img4
            else if(x%48==18||x%48==19||x%48==20||x%48==21||x%48==22||x%48==23){
            srect[8]={380,200,500,500};
            SDL_RenderCopy(render,img[77],NULL,&srect[8]);
            }
            //img5
            else if(x%48==24||x%48==25||x%48==26||x%48==27||x%48==28||x%48==29){
            srect[9]={380,200,500,500};
            SDL_RenderCopy(render,img[78],NULL,&srect[9]);
            }
            //img6
            else if(x%48==30||x%48==31||x%48==32||x%48==33||x%48==34||x%48==35){
            srect[10]={380,200,500,500};
            SDL_RenderCopy(render,img[79],NULL,&srect[10]);
            }
            //img7
            else if(x%48==36||x%48==37||x%48==38||x%48==39||x%48==40||x%48==41){
            srect[11]={380,200,500,500};
            SDL_RenderCopy(render,img[80],NULL,&srect[11]);
            }
            //img8
            else if(x%48==42||x%48==43||x%48==44||x%48==45||x%48==46||x%48==47){
            srect[12]={380,200,500,500};
            SDL_RenderCopy(render,img[81],NULL,&srect[12]);
            }
        }

        //tangent
        else if(st1=="3"){
            //img1
            if(x%32==0||x%32==1||x%32==2||x%32==3||x%32==4||x%32==5||x%32==6||x%32==7){
            srect[5]={380,200,500,500};
            SDL_RenderCopy(render,img[82],NULL,&srect[5]);
            }
            //img2
            else if(x%32==8||x%32==9||x%32==10||x%32==11||x%32==12||x%32==13||x%32==14||x%32==15){
            srect[6]={380,200,500,500};
            SDL_RenderCopy(render,img[83],NULL,&srect[6]);
            }
            //img3
            else if(x%32==16||x%32==17||x%32==18||x%32==19||x%32==20||x%32==21||x%32==22||x%32==23){
            srect[7]={380,200,500,500};
            SDL_RenderCopy(render,img[84],NULL,&srect[7]);
            }
            //img4
            else if(x%32==24||x%32==25||x%32==26||x%32==27||x%32==28||x%32==29||x%32==30||x%32==31){
            srect[8]={380,200,500,500};
            SDL_RenderCopy(render,img[85],NULL,&srect[8]);
            }
        }

        x++;


        SDL_RenderPresent(render);
        SDL_Delay(10);
    }

    crin.stop();
}


