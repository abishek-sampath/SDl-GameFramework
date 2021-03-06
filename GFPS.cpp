#include "GFPS.h"

GFPS GFPS::FPSControl;

GFPS::GFPS()
{
    oldTime     = 0;
    lastTime    = 0;
    speedFactor = 0;
    frames      = 0;
    numFrames   = 0;
}


void GFPS::OnLoop()
{
    if(oldTime + 1000 < SDL_GetTicks()) {
        oldTime = SDL_GetTicks();
        numFrames = frames;
        frames = 0;
    }

    speedFactor = ((SDL_GetTicks() - lastTime) / 1000.0f) * 32.0f;
    lastTime    = SDL_GetTicks();
    frames++;
}


int GFPS::GetFPS()
{
    return numFrames;
}


float GFPS::GetSpeedFactor()
{
    return speedFactor;
}
