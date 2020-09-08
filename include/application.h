#pragma once
#include "imgui.h"
#include <string>

struct AppWindowConfig
{
    std::string name  = "Application";
    std::string title = "Application";
    int pos_x         = 100;
    int pos_y         = 100;
    int width         = 1280;
    int height        = 800;
};

struct AppRenderingConfig
{
    ImVec4 bg_color = {.3f, .4f, .5f, 1.f};
};

class Application
{
public:
    Application() = default;

    virtual void Initialize() = 0;
    virtual void Update()     = 0;

    const auto& RenderingConfig() const
    {
        return render_;
    }

    void SetBackgroundColor(ImVec4 color)
    {
        render_.bg_color = color;
    }

private:
    AppRenderingConfig render_;
};
