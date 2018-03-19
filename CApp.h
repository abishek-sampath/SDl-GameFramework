#ifndef CAPP_H_INCLUDED
#define CAPP_H_INCLUDED

#include <SDL.h>
#include <iostream>
#include <unordered_map>

#include "CEvent.h"
#include "CAnimation.h"
#include "CEntity.h"
#include "GArea.h"
#include "GCamera.h"

#include "ResourceManager.h"
#include "TextureUtils.h"
#include "Definitions.h"


class CApp : public CEvent {
private:
    bool running;
    SDL_Window* window;
    SDL_Renderer* renderer;

    CEntity*    Entity1 = NULL;
    CEntity*    Entity2 = NULL;

private:
    ResourceManager* resourceManager;
    std::unordered_map<int, std::vector<SDL_Rect>> texRectsMap;

public:
    CApp();
    int OnExecute();

public:
    bool OnInit();
    void OnEvent(SDL_Event* event);
    void OnLoop();
    void OnRender();
    void OnCleanup();

public:
    void OnKeyDown(SDL_Keycode &sym, Uint16 &mod);
    void OnExit();
};

#endif // CAPP_H_INCLUDED
