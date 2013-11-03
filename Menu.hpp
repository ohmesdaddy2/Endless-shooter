/* 
 * File:   Menu.hpp
 * Author: garys
 *
 * Created on October 26, 2013, 2:31 PM
 */

#ifndef MENU_HPP
#define	MENU_HPP

#include "button.hpp"
#include "gameengine.h"

class Main{
    clicker button[4];
    
public:
    Main(){
        button[0].label_button("Start Game", 20, 255, 255, 0);
        button[1].label_button("Options", 20, 255, 255, 0);
        button[2].label_button("Quit", 20, 255, 255, 0);
        //std::cout<<"buttons labeled\n";
        button[0].place_button(250, 220);
        button[1].place_button(250, 295);
        button[2].place_button(250, 370);
        //std::cout<<"buttons placed\n";
        for (short i = 0; i < 3; i++){
            button[i].size_button(250, 50);
        }
        //std::cout<<"buttons sized\n";
        button[0].place_label(325, 232);
        button[1].place_label(345, 305);
        button[2].place_label(360, 385);
        //std::cout<<"labels placed\n";
    }
    
    short select(engine::pointer z){
        if (button[0].select_button(z) == true){
            return 1;
        }
        else if (button[1].select_button(z)){
            return 2;
        }
        else if (button[2].select_button(z)){
            return 3;
        }
        else return 0;
    }
    
    void render(SDL_Surface* screen){
        for(short i = 0; i < 3; i++){
            button[i].draw_button(screen, 128, 64, 0);
        }
    }
    
};

/*class levels{
    clicker button[3];
    
    levels(){
        button[0].label_button("Easy", 20, 255, 255, 0);
        button[1].label_button("Medium", 20, 255, 255, 0);
        button[2].label_button("Hard", 20, 255, 255, 0);
        button[0].place_button(375, 360);
        button[1].place_button(375, 420);
        button[2].place_button(375, 480);
        
        for (short i = 0; i < 4; i++){
            button[i].size_button(50, 30);
        }
        
        button[0].place_label(380, 362);
        button[1].place_label(380, 422);
        button[2].place_label(380, 482);
    }
    
    short select(engine::pointer z){
        for(short i = 0; i < 3; i++){
            if (button[i].select_button(z) == true){
                return i;
                break;
            }
        }
    }
    
    void render(SDL_Surface* screen){
        for(short i = 0; i < 3; i++){
            button[i].draw_button(screen, 128, 64, 0);
        }
    }
};*/

/*class saves{
    int screenh, screenw;
    boost::ptr_vector< clicker > button;
    std::vector<std::string> name;
    SDL_Color wordcolor;
public:

    saves(){
        std::ifstream settings("config");
        if (settings != NULL){
            settings >> screenw;
            settings >> screenh;
        }
        button.resize(1);
	button[0].place_button(80, 470);
	button[0].size_button(400, 40);
	button[0].label_button("Back", 20, 0, 255, 255);
	button[0].place_label(85, 495);
	SDL_EnableUNICODE( SDL_ENABLE );
        wordcolor.r = 255;
        wordcolor.g = 255;
        wordcolor.b = 0;
        }
    
    int Select_slot(engine::pointer z){
        DIR *saves = opendir("./saves");
	std::string filename;
	int savenum = 0;
	if(saves){ 
	    struct dirent *ent; 
	    while((ent = readdir(saves)) != NULL){ 
		filename = ent->d_name;
                 if (button[0].select_button(z) == true){
                     return 8;
                     }
		if (filename.length() > 2){
		    savenum++;
		    button.resize(savenum);
		    name.resize(savenum);
		    if (button.size() > 1){
			button[savenum - 1].place_button(button[savenum-2].x, button[savenum-2].y + 40);
			button[savenum - 1].size_button(180, 30);
			button[savenum - 1].label_button(filename, 20, 255, 255, 255);
			button[savenum - 1].place_label(button[savenum -1].x + 5, button[savenum -1].y + 5);
			name[savenum-1] = filename;
		    }
		}
	    }   
	}
	else {std::cout << "Error opening directory\n"; }
    }
    
    void save_game(){
	
    }
    
    std::string select_project(engine::pointer z){
	for(int i = 0; i < button.size(); i++){
	    if (button[i].select_button(z) == true){
		return name[i];
	    }
	}
    }
    
    void Draw_saves(SDL_Surface* a){
	boxRGBA(a, 65, 115, 515, 535, 0, 0, 0, 255);
        for (int i = 0; i < button.size(); i++){
            button[i].draw_button(a, 128, 64, 24);
        }
    }
    
};*/

class settings{
    clicker button[4];
public:
    settings(){
        button[0].label_button("Audio", 25, 255, 255, 0);
        button[1].label_button("Video", 20, 255, 255, 0);
        button[2].label_button("Back", 20, 255, 255, 0);
        button[0].place_button(375, 360);
        button[1].place_button(375, 420);
        button[2].place_button(375, 460);
        
        for (short i = 0; i < 4; i++){
            button[i].size_button(50, 30);
        }
        button[0].place_label(380, 362);
        button[1].place_label(380, 422);
        button[2].place_label(380, 462);
    }
    
    short select(engine::pointer z){
        if (button[0].select_button(z) == true){
            std::cout<<"Needs finishing up first\n";
            
        }
        else if (button[1].select_button(z)== true){
            return 2;
        }
        else if (button[2].select_button(z) == true){
            return 3;
        }
        else return 0;
    }
    
    void render(SDL_Surface* screen){
        for(short i = 0; i < 3; i++){
            button[i].draw_button(screen, 128, 64, 0);
        }
    }
};

class visual{
    clicker button[9];
public:
    visual(){
        button[0].label_button("800 x 600", 20, 255, 255, 0);
        button[1].label_button("1024 x 768", 20, 255, 255, 0);
        button[2].label_button("1280 x 960", 20, 255, 255, 0);
        button[3].label_button("1280 x 1024", 20, 255, 255, 0);
        button[4].label_button("1440 x 960", 20, 255, 255, 0);
        button[5].label_button("1680 x 1050", 20, 255, 255, 0);
        button[6].label_button("2048 x 1152", 20, 255, 255, 0);
        button[7].label_button("Apply", 20, 255, 255, 0);
        button[8].label_button("Back", 20, 255, 255, 0);
        
        button[0].place_button(250, 300);
        button[1].place_button(250, 350);
        button[2].place_button(250, 400);
        button[3].place_button(250, 450);
        button[4].place_button(400, 300);
        button[5].place_button(400, 350);
        button[6].place_button(400, 400);
        button[7].place_button(400, 450);
        button[8].place_button(450, 450);
        
        for(short i = 0; i < 7; i++){
            button[i].size_button(100, 30);
        }
        button[7].size_button(50, 30);
        button[8].size_button(50, 30);
        
        button[0].place_label(252, 305);
        button[1].place_label(252, 355);
        button[2].place_label(252, 405);
        button[3].place_label(252, 455);
        button[4].place_label(402, 305);
        button[5].place_label(402, 355);
        button[6].place_label(402, 405);
        button[7].place_label(400, 455);
        button[8].place_label(455, 455);
    }
    
    short select(engine::pointer z){
        for(short i = 0; i < 9; i++){
            if (button[i].select_button(z) == true){
                return i;
                break;
            }
        }
    }
    
    void render(SDL_Surface* screen){
        for (short i = 0; i < 9; i++){
            button[i].draw_button(screen, 128, 64, 0);
        }
    }
};
#endif	/* MENU_HPP */

