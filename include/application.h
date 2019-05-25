#pragma once
#include "imgui.h"
#include <string>

struct AppWindowInfo
{
    int version = 0;

    std::string name  = "Application";
    std::string title = "Application";
    int pos_x         = 100;
    int pos_y         = 100;
    int width         = 1280;
    int height        = 800;

    ImVec4 bg_color = {.3, .4, .5, 1};
};

class Application
{
public:
    Application() = default;

    virtual void Initialize() = 0;
    virtual void Update()     = 0;

    const auto& Info() const
    {
        return info_;
    }

    void SetTitle(std::string title)
    {
        info_.title = title;
    }

	void SetBackgroundColor(ImVec4 color)
	{
		info_.bg_color = color;
	}

private:
    AppWindowInfo info_;
};

