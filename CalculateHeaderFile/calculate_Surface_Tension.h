#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>
#include<stdio.h>
#include<iostream>
#include<string>
#include<cmath>

using namespace std;

struct CSurTen{
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
}cst;
//4
void Cal_Surface_Tension(SDL_Window* window, SDL_Renderer* render, SDL_Texture* img[],SDL_Rect img_rect[],string &st1,string &st2,string &st3,string &st4,int &mouse_x,int &mouse_y){

    if(!cst.initial()){
        printf("Did not Initial\n");
        return;
    }

    double n,r,R,T,w,p;
    string ss1,ss2,ss3;

    /*  n = number of small bubbles
    	r = radius of small bubbles
    	R = Radius of large bubble
    	T = Surface Tension of bubbles
   		w = work done by the bubbles
    	p = pressure (extra) inside the large bubble */

    n=stod(st1);
    r=stod(st2);
    R=stod(st3);
    T=stod(st4);

    //formula
    w=4*3.14*T*(n*r*r-R*R);
    p=4*T/R;

    ss1=to_string(w);
    ss2=to_string(p);

    ss1+=" j";
    ss2+=" Pa";

	//Output surface
    cst.sfont= TTF_OpenFont("Ubuntu/Ubuntu-Bold.ttf",26);
    SDL_Surface* surface=NULL;
    SDL_Texture* tex=NULL;
    SDL_SetRenderDrawColor(render,255,255,255,255);
    SDL_RenderClear(render);
    if(!render)printf("NOT RENDERED %s\n",SDL_GetError());
    SDL_Color color={255,255,255};
    SDL_Rect srect[20];
    SDL_FRect rect[2];
    int run=1;
    SDL_Event e;
    float R2=50.0,x1=500.0,x2; //x2=700


    while(run){
        SDL_SetRenderDrawColor(render,0,20,55,0);
        SDL_RenderClear(render);

        //Work
        surface= TTF_RenderText_Solid(cst.sfont,"W- Work done by the bubbles:",color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        srect[0]={30,100,260,30};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&srect[0]);
        srect[1]={300,100,300,40};
        SDL_SetRenderDrawColor(render,255,0,127,255);
        SDL_RenderFillRect(render,&srect[1]);
        surface = TTF_RenderText_Solid(cst.sfont, ss1.c_str(), color);
        tex = SDL_CreateTextureFromSurface(render, surface);
        srect[2]={300,100,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &srect[2]);

        //Pressure
        surface= TTF_RenderText_Solid(cst.sfont,"P- extra pressure inside the bubble:",color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        srect[3]={30,150,260,30};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&srect[3]);
        srect[4]={300,150,300,40};
        SDL_SetRenderDrawColor(render,255,0,127,255);
        SDL_RenderFillRect(render,&srect[4]);
        surface = TTF_RenderText_Solid(cst.sfont, ss2.c_str(), color);
        tex = SDL_CreateTextureFromSurface(render, surface);
        srect[5]={300,150,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &srect[5]);

        //back button
        srect[6]={0,0,100,50};
        SDL_SetRenderDrawColor(render,140,200,30,140);
        SDL_RenderFillRect(render,&srect[6]);
        surface = TTF_RenderText_Solid(cst.sfont, " BACK ", color);
        tex = SDL_CreateTextureFromSurface(render, surface);
        srect[7]={10,6,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &srect[7]);


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


		//animation-bubble's accumulating

        //image1
        rect[0]={x1-25.0,490.0-25.0,50.0,50.0}; //R1=50
        SDL_RenderCopyF(render,img[15],NULL,&rect[0]);

        //image2
        x2=700.0-R2/2.0;
        rect[1]={x2,490.0-R2/2.0,R2,R2};
        SDL_RenderCopyF(render,img[15],NULL,&rect[1]);

		//conditions of movement
        if((x1<(x2+25.0))&&(R2<=300.0)){
            x1=x1+4.0;
        }
        else{
            x1=500.0;
        }
        if((R2<=300.0)&&(x1>=(x2+25.0))){
            R2=R2+25.0;
        }


        SDL_RenderPresent(render);
        SDL_Delay(10);
    }

    cst.stop();
}



