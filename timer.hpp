/* 
 * File:   timer.hpp
 * Author: garys
 *
 * Created on September 23, 2013, 7:43 AM
 */

#ifndef TIMER_HPP
#define	TIMER_HPP

class clock{
    int start_ticks;
    int pause_ticks;
    bool paused, started;
public:
    clock(){
        start_ticks = 0;
        pause_ticks = 0;
        paused = false;
        started = false;
    }
    
    void start(){
        started = true;
        
        paused = false;
        
        start_ticks = SDL_GetTicks();
    }
    
    void stop(){
        started = false;
        paused = false;
    }
    
    void pause(){
        if (started == true && paused == true){
            paused = true;
            pause_ticks = SDL_GetTicks() - start_ticks;
                   
        }
    }
    
    void unpause(){
        if (paused == true){
            paused = false;
            start_ticks = SDL_GetTicks() - pause_ticks;
            pause_ticks = 0;
        }
    }
    
    short get_ticks(){
        if (started = true){
            if (paused == true){
                return pause_ticks;
            }
            else { return SDL_GetTicks() - start_ticks;}
        }
        
        return 0;
    }
    
    bool is_started(){
        return started;
    }
    
    bool is_paused(){
        return paused;
    }
};

#endif	/* TIMER_HPP */

