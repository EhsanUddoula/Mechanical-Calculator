#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>
#include<stdio.h>
#include<iostream>
#include<string>
#include<cmath>

using namespace std;

struct Cdepth{
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
}cdep;
//3

void Cal_Depth_Measurement(SDL_Window* window, SDL_Renderer* render, SDL_Texture* img[],SDL_Rect img_rect[],string &st1,string &st2,string &st3,string &st4,string &st5,int &mouse_x,int &mouse_y){
        if(!cdep.initial()){
        printf("Did not Initial\n");
        return;
    }

	double n,p,d,g,h;
	string ss1,ss2,ss3;

     /* n = how many times the bubble by Volume/Radius/Area
		p = Pressure above the surface
		d = density
		g = gravitational force
		h = height/ Depth of the container */

    n=stod(st1);
    p=stod(st2);
    d=stod(st3);
    g=stod(st4);

    if(st5=="V"){				//by Volume
        h=p*(n-1)/(d*g);
        ss1=to_string(h);
        ss1+=" m";
    }
    if(st5=="R"){				//by Radius
        h=p*(n*n*n-1)/(d*g);
        ss1=to_string(h);
        ss1+=" m";
    }
    if(st5=="A"){				//by Area
        h=p*(n*sqrt(n)-1)/(d*g);
        ss1=to_string(h);
        ss1+=" m";
    }

	//Output surface
    cdep.sfont= TTF_OpenFont("Ubuntu/Ubuntu-Bold.ttf",26);
    SDL_Surface* surface=NULL;
    SDL_Texture *tex=NULL;
    SDL_Rect srect[20];
    SDL_FRect rect;
    SDL_SetRenderDrawColor(render,255,255,255,255);
    SDL_RenderClear(render);
    if(!render)printf("NOT RENDERED %s\n",SDL_GetError());
    SDL_Color color={255,255,255};
    int run=1;
    SDL_Event e;
    float depth=730.0,r=50.0;


    while(run){
        SDL_SetRenderDrawColor(render,0,20,55,0);
        SDL_RenderClear(render);

        ////back button
        srect[0]={0,0,100,50};
        SDL_SetRenderDrawColor(render,140,200,30,140);
        SDL_RenderFillRect(render,&srect[0]);
        surface = TTF_RenderText_Solid(cdep.sfont, " BACK ", color);
        tex = SDL_CreateTextureFromSurface(render, surface);
        srect[1]={10,6,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &srect[1]);

        //Depth
        surface= TTF_RenderText_Solid(cdep.sfont,"The depth of the container:",color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        srect[2]={30,100,250,30};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&srect[2]);
        srect[3]={300,100,300,40};
        SDL_SetRenderDrawColor(render,255,0,127,255);
        SDL_RenderFillRect(render,&srect[3]);
        surface = TTF_RenderText_Solid(cdep.sfont, ss1.c_str(), color);
        tex = SDL_CreateTextureFromSurface(render, surface);
        srect[4]={300,100,surface->w,surface->h};
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


        //animation-bubble's ascending

        //image1
        srect[5]={180,250,900,500};
        SDL_RenderCopy(render,img[14],NULL,&srect[5]);

        //image2
        rect={630.0-r/2.0,depth-r/2.0,r,r*1.0};
        SDL_RenderCopyF(render,tex,NULL,&rect);

		//condition of movement
        if(depth>250.0){
            depth=depth-3.0;
            r=r+0.5;
            }


        SDL_RenderPresent(render);
        SDL_Delay(10);
    }

    cdep.stop();
}


