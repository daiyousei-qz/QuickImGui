#include "quick_imgui.h"

class MyApp : public Application
{
    DynamicTexture::Ptr tex;

public:
    virtual void Initialize() override
    {
        tex = AllocateTexture(100, 100);
        tex->Update([](void* p, int row_pitch) { memset(p, 0xff3c3c3c, 100 * row_pitch); });
    }
    virtual void Update() override
    {
        {
            ImGui::SetNextWindowMaximized();

            ImScoped::StyleVar sv_0{ImGuiStyleVar_WindowRounding, 0.f};
            auto window_flags = ImGuiWindowFlags_NoMove |
                                ImGuiWindowFlags_NoDecoration | // ImGuiWindowFlags_NoBackground |
                                ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_MenuBar;
            if (ImScoped::Window globe{"Globe", nullptr, window_flags})
            {
                ImGui::Columns(2);

                if (ImScoped::Child child{"C0", {}, true})
                {
                    ImGui::Text("From C0");
                    ImGui::Image(tex->Id(), {200, 200});
                }
                ImGui::NextColumn();

                if (ImScoped::Child child{"C1", {}, true})
                {
                    ImGui::Text("From C1");
                    static float color[3];
                    if (ImGui::ColorEdit3("color", color))
                    {
                        auto r = static_cast<int>(color[0] * 255);
                        auto g = static_cast<int>(color[1] * 255);
                        auto b = static_cast<int>(color[2] * 255);

                        auto pixel = (0xffu << 24) | (b << 16) | (g << 8) | r;

                        tex->Update([=](void* p, int row_pitch) {
                            std::fill_n(reinterpret_cast<int*>(p), 100 * row_pitch / 4, pixel);
                        });
                    }
                }
                ImGui::NextColumn();

                ImGui::Columns(1);
                ImGui::Separator();
            }
        }

        // ImGui::ShowDemoWindow();
    }
};

int main()
{
    MyApp app;
    return RunApplication(app);
}