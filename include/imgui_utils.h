#include "imgui.h"

namespace ImGui
{
    void SetNextWindowMaximized()
    {
        ImGui::SetNextWindowPos({0, 0});
        ImGui::SetNextWindowSize(ImGui::GetIO().DisplaySize);
    }
} // namespace ImGui