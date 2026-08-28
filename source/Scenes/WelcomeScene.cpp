#include "WelcomeScene.hpp"

#include <DrawFunctions/DrawText.hpp>
#include <LetoAPI_V1/LetoAPI_V1.h>

static const RGBColor colors[]
{
    PurpleColor,
    IndigoColor,
    DeepOrangeColor,
    BlueColor,
    DarkGrayColor
};
static const uint32_t colors_cnt = sizeof(colors) / sizeof(colors[0]);

static unsigned cur_color;

WelcomeScene::WelcomeScene(ISceneManager* game) : IScene{game}
{
}

bool WelcomeScene::ProcessInput(const AppEvent& event)
{
    if (IsSystemPrevEvent(event))
    {
        cur_color--;
        return true;
    }
    if (IsSystemNextEvent(event))
    {
        cur_color--;
        return true;
    }
    return false;
}

void WelcomeScene::Draw(IScreen& screen)
{
    static const LetoFont_V1* font = leto_api_v1->Font->GetFont(7, 7, 1);
    static int p = 0, k = 1;

    if      (p > 100)   k = -1;
    else if (p < 10)    k = +1;
    
    p += k;

    static bool inv = false;
    if (p % 20 == 0) inv = !inv;

    // TODO: Убрать все FromHandle
    DrawFunctions::DrawText(screen, { p, p }, "WELCOME", WhiteColor, colors[cur_color % colors_cnt], inv, IFont::FromHandle(font));
}
