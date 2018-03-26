#include "CApp.h"

void CApp::OnCleanup()
{
//    for(auto&& textRects : texRectsMap) {
//        textRects.second.clear();
//    }

    GArea::AreaControl.OnCleanup();

    // cleanup resource manager
    resourceManager->clearResource();

    // cleanup entities
    for(unsigned int i=0; i < GEntity::EntityList.size(); i++) {
        if(!GEntity::EntityList[i])
            continue;
        GEntity::EntityList[i]->OnCleanup();
        delete(GEntity::EntityList[i]);
    }
    GEntity::EntityList.clear();

    // cleanup SDL resources
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    renderer = NULL;
    window = NULL;

    SDL_Quit();
}
