#include "imgui.h"

namespace ImGui
{
    inline void SetNextWindowMaximized()
    {
        ImGui::SetNextWindowPos({0, 0});
        ImGui::SetNextWindowSize(ImGui::GetIO().DisplaySize);
    }

    //
    //
    inline bool InputInt2(const char* label, int* x0, int* x1, ImGuiInputTextFlags flags = 0)
    {
        int xs[]{*x0, *x1};
        bool result = InputInt2(label, xs, flags);

        *x0 = xs[0];
        *x1 = xs[1];
        return result;
    }
    inline bool InputInt3(const char* label, int* x0, int* x1, int* x2,
                          ImGuiInputTextFlags flags = 0)
    {
        int xs[]{*x0, *x1, *x2};
        bool result = InputInt3(label, xs, flags);

        *x0 = xs[0];
        *x1 = xs[1];
        *x2 = xs[3];
        return result;
    }
    inline bool InputInt4(const char* label, int* x0, int* x1, int* x2, int* x3,
                          ImGuiInputTextFlags flags = 0)
    {
        int xs[]{*x0, *x1, *x2, *x3};
        bool result = InputInt4(label, xs, flags);

        *x0 = xs[0];
        *x1 = xs[1];
        *x2 = xs[2];
        *x3 = xs[3];
        return result;
    }

    inline bool InputFloat2(const char* label, float* x0, float* x1, ImGuiInputTextFlags flags = 0)
    {
        float xs[]{*x0, *x1};
        bool result = InputFloat2(label, xs, flags);

        *x0 = xs[0];
        *x1 = xs[1];
        return result;
    }
    inline bool InputFloat3(const char* label, float* x0, float* x1, float* x2,
                            ImGuiInputTextFlags flags = 0)
    {
        float xs[]{*x0, *x1, *x2};
        bool result = InputFloat3(label, xs, flags);

        *x0 = xs[0];
        *x1 = xs[1];
        *x2 = xs[3];
        return result;
    }
    inline bool InputFloat4(const char* label, float* x0, float* x1, float* x2, float* x3,
                            ImGuiInputTextFlags flags = 0)
    {
        float xs[]{*x0, *x1, *x2, *x3};
        bool result = InputFloat4(label, xs, flags);

        *x0 = xs[0];
        *x1 = xs[1];
        *x2 = xs[2];
        *x3 = xs[3];
        return result;
    }
} // namespace ImGui
