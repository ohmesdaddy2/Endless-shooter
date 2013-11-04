/* 
 * File:   bullets.hpp
 * Author: garys
 *
 * Created on October 24, 2013, 11:45 AM
 */

#ifndef BULLETS_HPP
#define	BULLETS_HPP

#include "gameengine.h"

class bullet{
public:
    short x, y, w;
    bool fired;

    bullet(){
        fired = false;
        w = 5;
    }
    void reset(){
        fired = false;
    }
    
    void set_size(short a){
        w = a;
    }
    
    void fly(){
        y = y - 10;
        //x = x + xSpeed;
    }
    
    void place(short a, short b){
        x = a;
        y = b;
    }
    
    void render(SDL_Surface* screen){
        filledCircleRGBA(screen, x, y, w, 255, 255, 0, 255);
    }
};


#endif	/* BULLETS_HPP */

