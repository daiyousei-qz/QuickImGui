#include "application.h"
#include "backend.h"

class MyApp : public Application
{
private:
    DynamicTexture::Ptr tex;
    std::vector<uint32_t> canvas;

public:
    void Initialize() override
    {
        tex = AllocateTexture(200, 200);

        canvas.resize(200 * 200);
        std::fill(canvas.begin(), canvas.end(), 0xff00ff00u);
        tex->UpdateRgba(canvas.data());
    }

    void Update() override
    {
        ImGuiIO& io = ImGui::GetIO();

        ImGui::Begin("laji");
        ImGui::Image(tex->Id(), {200, 200});
        ImGui::End();
    }
};

int main()
{
    MyApp app;
    RunApplication(app);
}