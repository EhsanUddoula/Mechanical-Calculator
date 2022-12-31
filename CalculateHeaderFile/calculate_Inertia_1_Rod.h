#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>
#include<stdio.h>
#include<iostream>
#include<string>
#include<cmath>

using namespace std;

struct CRod{
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
}crod;
//7.1
void Cal_Inertia_1_Rod(SDL_Window* window, SDL_Renderer* render, SDL_Texture* img[],SDL_Rect img_rect[],string &st1,string &st2,string &st3,int &mouse_x,int &mouse_y){

    if(!crod.initial()){
        printf("Did not Initial\n");
        return;
    }

    double m, l, Ic, Ie;
    string ss1,ss2;
    /*  m = mass of rod
        l = length of rod
        Ic = inertia about the center axis
        Ie = inertia about the end axis  */

    m=stod(st2);
    l=stod(st3);

    //formula
    Ic=m*l*l/12;
    Ie=m*l*l/3;

    ss1=to_string(Ic);
    ss2=to_string(Ie);

    ss1+="  kgm2";
    ss2+="  kgm2";

    //Output Surface
    crod.sfont= TTF_OpenFont("Ubuntu/Ubuntu-Bold.ttf",26);
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
        surface= TTF_RenderText_Solid(crod.sfont,"I- Inertia about the Center axis :",color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        srect[0]={30,100,265,30};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&srect[0]);
        srect[1]={300,100,300,40};
        SDL_SetRenderDrawColor(render,255,0,127,255);
        SDL_RenderFillRect(render,&srect[1]);
        surface = TTF_RenderText_Solid(crod.sfont, ss1.c_str(), color1);
        tex = SDL_CreateTextureFromSurface(render, surface);
        srect[2]={310,100,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &srect[2]);
        }

        //for end
        else if(st1=="2"){
        surface= TTF_RenderText_Solid(crod.sfont,"I- Inertia about the End axis :",color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        srect[0]={30,100,265,30};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&srect[0]);
        srect[1]={300,100,300,40};
        SDL_SetRenderDrawColor(render,255,0,127,255);
        SDL_RenderFillRect(render,&srect[1]);
        surface = TTF_RenderText_Solid(crod.sfont, ss1.c_str(), color1);
        tex = SDL_CreateTextureFromSurface(render, surface);
        srect[2]={310,100,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &srect[2]);
        }

        //back button
        srect[3]={0,0,100,50};
        SDL_SetRenderDrawColor(render,140,200,30,140);
        SDL_RenderFillRect(render,&srect[3]);
        surface = TTF_RenderText_Solid(crod.sfont, " BACK ", color);
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
            if(x%16==0||x%16==1||x%16==2||x%16==3){
            srect[5]={380,200,500,500};
            SDL_RenderCopy(render,img[34],NULL,&srect[5]);
            }
            //img2
            else if(x%16==4||x%16==5||x%16==6||x%16==7){
            srect[6]={380,200,500,500};
            SDL_RenderCopy(render,img[35],NULL,&srect[6]);
            }
            //img3
            else if(x%16==8||x%16==9||x%16==10||x%16==11){
            srect[7]={380,200,500,500};
            SDL_RenderCopy(render,img[36],NULL,&srect[7]);
            }
            //img4
            else if(x%16==12||x%16==13||x%16==14||x%16==15){
            srect[8]={380,200,500,500};
            SDL_RenderCopy(render,img[37],NULL,&srect[8]);
            }
        }

        //end
        else if(st1=="2"){
            //img1
            if(x%24==0||x%24==1||x%24==2||x%24==3){
            srect[5]={230,200,800,500};
            SDL_RenderCopy(render,img[38],NULL,&srect[5]);
            }
            //img2
            else if(x%24==4||x%24==5||x%24==6||x%24==7){
            srect[6]={230,200,800,500};
            SDL_RenderCopy(render,img[39],NULL,&srect[6]);
            }
            //img3
            else if(x%24==8||x%24==9||x%24==10||x%24==11){
            srect[7]={230,200,800,500};
            SDL_RenderCopy(render,img[40],NULL,&srect[7]);
            }
            //img4
            else if(x%24==12||x%24==13||x%24==14||x%24==15){
            srect[8]={230,200,800,500};
            SDL_RenderCopy(render,img[41],NULL,&srect[8]);
            }
            //img5
            else if(x%24==16||x%24==17||x%24==18||x%24==19){
            srect[9]={230,200,800,500};
            SDL_RenderCopy(render,img[42],NULL,&srect[9]);
            }
            //img6
            else if(x%24==20||x%24==21||x%24==22||x%24==23){
            srect[10]={230,200,800,500};
            SDL_RenderCopy(render,img[43],NULL,&srect[10]);
            }
        }

        x++;


        SDL_RenderPresent(render);
        SDL_Delay(10);
    }

    crod.stop();
}





