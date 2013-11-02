/* 
 * File:   button.hpp
 * Author: garys
 *
 * Created on May 21, 2012, 6:11 PM
 */

#ifndef BUTTON_HPP
#define	BUTTON_HPP

#include "gameengine.h"

class clicker{
    short w, h;
    short labelx, labely;
    short labelsize;
    bool selected;
    std::string label;
    SDL_Color textcolor;
    SDL_Rect image;
public:
    short x, y;
    clicker(){
	x = -100;
	y = -100;
	w = -90;
	h = -90;
	labelsize = 10;
	label = "";
    }
    
    void place_button(int a, int b){
	x = a;
	y = b;
    }
    
    void size_button(int a, int b){
	w = x + a;
	h = y + b;
    }
    
    void label_button(std::string a, int b, int red, int green, int blue){
	textcolor.b = blue;
	textcolor.g = green;
	textcolor.r = red;
	label = a;
	labelsize = b;
    }
    
    void place_label(int a, int b){
        labelx = a;
        labely = b;
    }
    
    void button_image(int a, int b, int width, int height){
	image.x = a;
	image.y = b;
	image.w = width;
	image.h = height;
    }
    
    void draw_button_image(SDL_Surface* screen, SDL_Surface* buttons){
	engine::Draw_Pics(screen, buttons, x, y, &image);
        engine::Draw_Text(screen, textcolor, label, labelsize, labelx, labely);
    }
    
    void draw_button(SDL_Surface* a, int red, int green, int blue){
	boxRGBA(a, x, y, w, h, red, green, blue, 255);
	engine::Draw_Text(a, textcolor, label, labelsize, labelx, labely);
    }
    
    bool select_button(engine::pointer z){
	if (z.x > x && z.x < w && z.y > y && z.y < h){
            selected = true;
	    return true;
	}
	else selected = false;
        return false;
    }
    
    bool select_button(int a, int b){
	if (a > x && a < w && b > y && b < h){
	    return true;
	}
	else return false;
    }
    
    bool button_hover(engine::pointer z){
	if (z.x > x && z.x < w && z.y > y && z.y < h){
	    return true;
	}
	else return false;
    }
    short getx(){
        return x;
    }
    short gety(){
        return y;
    }
};

#endif	/* BUTTON_HPP */

