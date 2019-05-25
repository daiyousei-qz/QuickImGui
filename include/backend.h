#include "application.h"
#include <functional>
#include <memory>

class DynamicTexture
{
public:
	using Ptr = std::unique_ptr<DynamicTexture>;

    DynamicTexture()         = default;
    virtual ~DynamicTexture() = default;

	// size of buffer is width_ * height_ * 4, i.e. RGBA
    virtual void Update(std::function<void(void* p, int row_pitch)> f) = 0;

	auto Id() const { return id_; }
	auto Width() const { return width_; }
	auto Height() const { return height_; }

protected:
	ImTextureID id_;
	int width_;
	int height_;
};

int RunApplication(Application& app);

DynamicTexture::Ptr AllocateTexture(int width, int height);

