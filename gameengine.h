/*
 *  gameengine.h
 *  Author: gary ohmes
 *  
 */
#ifndef _game_engine_
#define _game_engine_

//my complier got stupider somehow... this is why the /../../ is here...
#ifdef USE_SDL
        #include "/../../usr/include/SDL/SDL.h"
        #include "/../../usr/include/SDL/SDL_image.h"
        #include "/../../usr/include/SDL/SDL_ttf.h"
        #include "SDL/SDL_gfxPrimitives.h"

#endif
#include <fstream>
#include <sstream>
#include <iostream>
#include <istream>
#include <string>
#include <time.h>
#include <vector>
#include <dirent.h>
#include <boost/ptr_container/ptr_vector.hpp>
//sqllite stuff...
//#include "/../../usr/include/sqlite3.h"
//for random # generatior...
#include <stdlib.h>
#include <time.h>

//SDL defines... in case they are 'missing' (thanks bs headers)
/*#ifdef USE_SDL
namespace SDL{
    class SDLRect{
    public:
        int h; //the height of the rectangle
        int w; //the width of the rectangle
        int x; //the X coordinate (left position)
        int y; //the Y coordinate (top position)
    };
}
#endif*/

namespace sqlite{
    /*Create and close a blank sqllite database*/
    //moved to Database.h
}

namespace engine{

    /* 
     * Split a string
     * @Author MultiCoder
     *//*
    std::vector<std::vector<std::string> > split(std::string input, char delim){
      //std::string temp(s1.size());
      int i;
      int cnt = std::count(input.begin(), input.end(), delim);
      std::vector<std::vector<std::string> > out(cnt);
      int found = 0;
      std::string temp=input;
      std::string ex="";
      //out[0] = input.substr(find);
      while (i = 0, i<cnt, i++){
          //std::cout<<"Before:"<<temp;
          found = temp.find(input);
          ex = temp.substr(found);
          //out[i] = ex;
          temp.erase(0,found);
          //std::cout<<"After:"<<temp;
      }
      /*for(i=0; input.at(i)!=delim; i++){
        temp.at(i)=s1.at(i);
      }
      for(; i<s1.size(); i++){
        s2.at(i)=s1.at(i);
      }
      s1=temp;*/
    //}
    /* 
     * Split a string
     * @Author <google>
     */
    /*void split(std::string &s1, std::string &s2, char delim){
      std::string temp(s1.size());
      int i;
      for(i=0; s1.at(i)!=delim; i++){
        temp.at(i)=s1.at(i);
      }
      for(; i<s1.size(); i++){
        s2.at(i)=s1.at(i);
      }
      s1=temp;
    }*/
    /*
     * Covert int to string
     * (and back)
     * @Author multicoder
     * 
     */
    /*****************************/
    /* Author: multicoder        */
    /* Date: before Mar 2013     */
    /* Status: perfect [outdated]*/
    /*****************************/
    std::string EnterToBR(std::string test){
        std::string temp = "";
        std::string Tchar;
        int Ichar;
        int cnt = 0;
        //now loop through all of the characters in the string...
        for (int i=0;i<test.length();i++){ //loop through each of the characters and change it one by one...
            Tchar = test.substr(i,1); //may be better to get the ascii value of the char... (it was)
            Ichar = Tchar[0]; //get the integer value of
            if (Ichar==10){
                temp += "<br/>";
            }
            else{
                //std::cout<<"Ichar is["<<Ichar<<"]\n";
                Tchar = Ichar;
                temp += Tchar;
            }
        }
        return temp;
    }
    /************************************/
    /* Author: multicoder               */
    /* Date: before Mar 2013            */
    /* Status: perfect, used by FixHTML */
    /************************************/
    std::string Replace2(std::string test,std::string item, std::string rep){
        std::string temp = "";
        std::string Tchar, Xchar="";
        int Ichar;
        int cnt = 0;
        //now loop through all of the characters in the string...
        for (int i=0;i<test.length();i++){ //loop through each of the characters and change it one by one...
            Tchar = test.substr(i,item.length()); //may be better to get the ascii value of the char... (it was)
            Xchar = test.substr(i,1);
            if (Tchar==item){
                //don't add it to the string...
                Tchar = rep;
                temp += Tchar;
                //skip forward the length of the item...
                i += item.length()-1;
            }
            else{
                //std::cout<<"Ichar is["<<Ichar<<"]\n";
                temp += Xchar;
            }
        }
        return temp;
    }
    /************************************/
    /* Author: multicoder               */
    /* Date: before Mar 2013            */
    /* Status: new */
    /************************************/
    bool HasChar(std::string test,std::string item){
        std::string Tchar;
        //now loop through all of the characters in the string...
        for (int i=0;i<test.length();i++){ //loop through each of the characters and change it one by one...
            Tchar = test.substr(i,item.length()); //may be better to get the ascii value of the char... (it was)
            if (Tchar==item){
                //don't add it to the string...
                return true;
            }
            else{
                //std::cout<<"Ichar is["<<Ichar<<"]\n";
            }
        }
        return false;
    }
    /****************************/
    /* Author: multicoder       */
    /* Date: before Mar 2013    */
    /* Status: works         */
    /****************************/
    std::string Replace(std::string test,std::string item, std::string rep){
        std::string temp = "";
        std::string Tchar;
        int Ichar;
        int cnt = 0;
        //now loop through all of the characters in the string...
        for (int i=0;i<test.length();i++){ //loop through each of the characters and change it one by one...
            Tchar = test.substr(i,1); //may be better to get the ascii value of the char... (it was)
            if (Tchar==item){
                //don't add it to the string...
                Tchar = rep;
                temp += Tchar;
            }
            else{
                //std::cout<<"Ichar is["<<Ichar<<"]\n";
                temp += Tchar;
            }
        }
        return temp;
    }
    /****************************************************************/
    /* Author: multicoder                                           */
    /* Date: Mar 31 2013                                            */
    /* Status: new                                                  */
    /* Purpose: Convert %29 and so on back to standard characters...*/
    /****************************************************************/
    //Uses replace2
    std::string FixHTML(std::string test){
        //std::string temp;
        test = Replace2(test,"%28","(");
        test = Replace2(test,"%29",")");
        test = Replace2(test,"%26","&");
        test = Replace2(test,"+"," ");
        return test;
    }
    /****************************/
    /* Author: multicoder       */
    /* Date: before Mar 2013    */
    /* Status: untested         */
    /****************************/
    std::string EraseChar(std::string test,std::string item){
        std::string temp = "";
        std::string Tchar;
        int Ichar;
        int cnt = 0;
        //now loop through all of the characters in the string...
        for (int i=0;i<test.length();i++){ //loop through each of the characters and change it one by one...
            Tchar = test.substr(i,1); //may be better to get the ascii value of the char... (it was)
            if (Tchar==item){
                //don't add it to the string...
            }
            else{
                //std::cout<<"Ichar is["<<Ichar<<"]\n";
                temp += Tchar;
            }
        }
        return temp;
    }
    /****************************/
    /* Author: multicoder       */
    /* Date: before Mar 2013    */
    /* Status: perfect          */
    /****************************/
    std::string ToLower(std::string test){//TESTED WORKS
        std::string temp = "";
        std::string Tchar;
        int Ichar;
        int cnt = 0;
        //now loop through all of the characters in the string...
        for (int i=0;i<test.length();i++){ //loop through each of the characters and change it one by one...
            Tchar = test.substr(i,1); //may be better to get the ascii value of the char... (it was)
            Ichar = Tchar[0]; //get the integer value of
            if ((Ichar>65) && (Ichar<90)){
                Ichar = Ichar + 32;
            }
            Tchar = Ichar;
            temp += Tchar;
        }
        return temp;
    }
    std::string FloatToString(float i){
        std::stringstream out;
        out << i;
        return out.str();
    }
    std::string IntToString(int i){
        std::stringstream out;
        out << i;
        return out.str();
    }
    int StringToInt(std::string test){/*ONLY WORKS WITH SINGLE CHAR RESULTS...*/
        //return atoi(i.c_str());
        int temp = -1;
        int part = -1;
        std::string Tchar;
        int Ichar;
        int cnt = 0;
        //now loop through all of the characters in the string...
        for (int i=0;i<test.length();i++){ //loop through each of the characters and change it one by one...
            Tchar = test.substr(i,1); //may be better to get the ascii value of the char... (it was)
            Ichar = Tchar[0]; //get the integer value of
            if (Ichar == 48){part = 0;}
            else if (Ichar == 49){part = 1;}
            else if (Ichar == 50){part = 2;}
            else if (Ichar == 51){part = 3;}
            else if (Ichar == 52){part = 4;}
            else if (Ichar == 53){part = 5;}
            else if (Ichar == 54){part = 6;}
            else if (Ichar == 55){part = 7;}
            else if (Ichar == 56){part = 8;}
            else if (Ichar == 57){part = 9;}
            else {part=-1;}
            if (part!=-1){
                if (temp!=-1){//multiply the first number by ten to stack the # correctly
                    temp = temp * 10;
                    temp += part;
                }
                else{
                    temp = 0;
                    temp += part;
                    part = -1;
                }
            }
            //std::cout<<"Part is:"<<part<<"\n";
        }
        //std::cout<<"Final value is:"<<temp<<"\n";
        return temp;
    }
    /**
     * Random # generators
     * @Author multicoder
     * @return A random #
     */
    int Rnum(){     
        return rand();
    }
    int Rnum(int max){
        return (rand() % (max - 1 + 1)) + 1;
    }
    int Rnum(int min, int max){
        return (rand() % (max - min + 1)) + min;
    }
    
    #ifdef USE_SDL
    /*
     * Image Loading function
     * @Author gary ohmes
     */
    SDL_Surface *load_image( std::string filename ){
        std::cout<<"\nLoading image: "<<filename<<"\n";
        std::ifstream fin( filename.c_str() );
        if( fin.fail() )
        {
            std::cout<<"Error loading file: "<<filename<<"\n";
            //File not found
            //close it anyway to save ram...
            fin.close();
        }
        else
        {
            //close the test file...
            std::cout<<"\nThe image exists: "<<filename;
            fin.close();
            std::cout<<"\nClosed file: "<<filename;
            //try to 
            SDL_Surface* loadedImage = NULL;
            SDL_Surface* optimizedImage = NULL;
            std::cout<<"\nSDL_Surfaces created...: \n"<<filename;
            loadedImage = IMG_Load( filename.c_str() );
            std::cout<<"\nRan IMG_Load: \n"<<filename;
            if( loadedImage != NULL ){
                std::cout<<"\nLoadedImage is not null...: \n"<<filename;
                    //try{
                    optimizedImage = SDL_DisplayFormat(loadedImage);
                    std::cout<<"\noptimized image setup...: \n"<<filename;
                    SDL_FreeSurface(loadedImage);
                    std::cout<<"Surface freed";
                    if(optimizedImage != NULL){
                        std::cout<<"Optimized Image is not NULL";
                        Uint32 colorkey = SDL_MapRGB(optimizedImage->format, 0, 0, 0);
                        SDL_SetColorKey(optimizedImage, SDL_SRCCOLORKEY, colorkey);
                    }
                    else{
                        std::cout<<"\nError loading optimized image: "<<filename<<"\n";
                    }
                //}
                //catch(int e){
                //    std::cout<<"\nError has occured: "<<e;
                //}
            }
            return optimizedImage;
        }
    }

    //Drawing functions
    void Draw_Pics(SDL_Surface* a, SDL_Surface* b, int x, int y, SDL_Rect* c = NULL){
            SDL_Rect dest;
            dest.x = x;
            dest.y = y;
            SDL_BlitSurface(b, c, a, &dest);
            }

    void Draw_Clip(SDL_Surface* a, SDL_Surface* b, SDL_Rect c[3], int x, int y, int w, int h){
            SDL_Rect dest;
            dest.x = x;
            dest.y = y;
            dest.w = w;
            dest.h = h;
            SDL_BlitSurface(b, c, a, &dest);
    }

    bool keystroke(bool a[323],SDL_Event event){
            if( event.type == SDL_KEYDOWN ){
                    a[event.key.keysym.sym] = true;
                    return true;
                    }
            else if( event.type == SDL_KEYUP ){
                    a[event.key.keysym.sym] = false;
                    }
            return false;
    }
    
    void Draw_Text(SDL_Surface* a, SDL_Color wordcolor, std::string input, int size, int x, int y){
            TTF_Font *font = TTF_OpenFont( "data-latin.ttf", size);
            if (font == NULL){
                std::cout<<"Duh font is stoopid\n";
            }
            std::stringstream stuff;
            stuff << input;
            SDL_Surface* Message = TTF_RenderText_Solid( font, stuff.str().c_str(), wordcolor );
            engine::Draw_Pics(a, Message, x, y);
            SDL_FreeSurface(Message);
            TTF_CloseFont(font);
    }
    void Draw_Numbers(SDL_Surface* a, SDL_Color wordcolor, int score, int size, int x, int y){
            TTF_Font *font = TTF_OpenFont( "FreeMono.ttf", size);
            std::string input;
            std::stringstream stuff;
            stuff << score;
            SDL_Surface* Message = TTF_RenderText_Solid( font, stuff.str().c_str(), wordcolor );
            engine::Draw_Pics(a, Message, x, y);
            SDL_FreeSurface(Message);
            TTF_CloseFont(font);
    }
	class pointer{
public:
    int x;
    int y;
    bool clicking;

    pointer(){
	    x = 0;
	    y = 0;
	    clicking = false;
	    }

    int mouseinput(SDL_Event click){
	    if (click.type == SDL_MOUSEBUTTONDOWN){
		    if (click.button.button == SDL_BUTTON_LEFT){
			    x = click.button.x;
			    y = click.button.y;
			    clicking = true;
			    return 1;
			    }
		    else if (click.button.button == SDL_BUTTON_RIGHT){
			    clicking = true;
			    return 2;
			    }
		    }
	    else if (click.type == SDL_MOUSEBUTTONUP){
		    if (click.button.button == SDL_BUTTON_LEFT){
			    x = 0;
			    y = 0;
			    clicking = false;
                            return 4;
			    }
		    if (click.button.button == SDL_BUTTON_RIGHT){
			    clicking = false;
                            return 5;
			    }
		    }
	    else if (click.type == SDL_MOUSEMOTION){
		    x = click.button.x;
		    y = click.button.y;
		    return 3;
		    }
	return 0;
	}
    };
	
	class clock{
		
		bool started;
		bool paused;
		
		int starttime;
		int currenttime;
		int pausetime;
		int endtime;
        public:
		clock(){
			started = false;
			paused = false;
			starttime = 0;
			currenttime = 0;
			pausetime = 0;
			endtime = 120000;
			}
		
		void start_clock(){
			started = true;
			starttime = SDL_GetTicks();
			}
		
		void pause_clock(){
			if(started == true && paused == false){
				paused = true;
				}
			}
		
		void reset_clock(){
                    currenttime = 0;
                        }
                
                int get_ticks(){
                    currenttime = SDL_GetTicks();
                    return currenttime;
                }
                
                bool is_started(){
                    return started;
                }
                
                bool is_paused(){
                    return paused;
                }
		
		};
	
        #endif //USE_SDL end if....
}
#endif //game engine define....
