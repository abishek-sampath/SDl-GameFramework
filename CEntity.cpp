#include "CEntity.h"
#include "TextureUtils.h"


std::vector<CEntity*> CEntity::entityList;

CEntity::CEntity(SDL_Renderer* renderer, ResourceManager* resourceManager)
{
    this->renderer = renderer;
    this->resourceManager = resourceManager;

    X = Y = 0.0f;
    width = height = 0;
    animState = 0;
}


CEntity::~CEntity()
{

}


bool CEntity::OnLoad(const char* file, int width, int height, int maxFrames)
{
    if((texture = resourceManager->loadImg(file, renderer)) == NULL) {
        return false;
    }

    this->width = width;
    this->height = height;
    Anim_Control.maxFrames = maxFrames;

    return true;
}


void CEntity::OnLoop()
{
    Anim_Control.OnAnimate();
}


void CEntity::OnRender()
{
    if(texture == NULL) {
        return;
    }
    TextureUtils::OnDraw(texture, renderer,
           X, Y,
           0, 0,
           width, height);
}


void CEntity::OnRender(bool isVertical)
{
    if(texture == NULL)
    {
        return;
    }
    if(isVertical)
        TextureUtils::OnDraw(texture, renderer,
                             X, Y,
                             animState * width, Anim_Control.GetCurrentFrame() * width,
                             width, height);
    else
        TextureUtils::OnDraw(texture, renderer,
                             X, Y,
                             Anim_Control.GetCurrentFrame() * width, animState * width,
                             width, height);
}


void CEntity::OnRender(std::vector<SDL_Rect> &textureRects)
{
    if(texture == NULL)
    {
        return;
    }
    if(Anim_Control.GetCurrentFrame() < textureRects.size())
    {
        SDL_Rect textureRect = textureRects[Anim_Control.GetCurrentFrame()];
        TextureUtils::OnDraw(texture, renderer,
                             X, Y,
                             width, height,
                             &textureRect);
    }
    else
    {
        TextureUtils::OnDraw(texture, renderer,
                             X, Y,
                             0, 0,
                             width, height);
    }
}


void CEntity::OnCleanup()
{
    texture = NULL;
    renderer = NULL;
    resourceManager = NULL;
}
