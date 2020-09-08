#pragma once
#include "application.h"
#include "imgui.h"
#include <string>
#include <tuple>
#include <memory>

class PlatformWindow
{
public:
    virtual void SetTitle(const std::string& title) = 0;

    virtual void SetSize(int width, int height) = 0;
    virtual std::pair<int, int> GetSize()       = 0;

    virtual void SetPosition(int x, int y)    = 0;
    virtual std::pair<int, int> GetPosition() = 0;
};

class PlatformTexture
{
public:
    using Ptr = std::unique_ptr<PlatformTexture>;

    PlatformTexture()          = default;
    virtual ~PlatformTexture() = default;

    // size of buffer is width_ * height_ * 4, i.e. RGBA
    virtual void UpdateRgba(const void* p) = 0;

    // size of buffer is width_ * height_ * 4, i.e. RGBA
    // virtual void Update(std::function<void(void* p, int row_pitch)> f) = 0;

    ImTextureID Id() const
    {
        return id_;
    }
    int Width() const
    {
        return width_;
    }
    int Height() const
    {
        return height_;
    }

protected:
    void Clear()
    {
        id_     = nullptr;
        width_  = 0;
        height_ = 0;
    }

    ImTextureID id_ = nullptr;
    int width_      = 0;
    int height_     = 0;
};

PlatformWindow& GetCurrentWindow();

std::unique_ptr<PlatformTexture> AllocateTexture(int width, int height);

int RunApplication(Application& app, AppWindowConfig window_config = {});
