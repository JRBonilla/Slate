#include "Label.h"

namespace ph { namespace renderer {

	using namespace math;

	Label::Label(const std::string& text, float x, float y, Font* font, const Vec4& color)
		: Renderable2D(), m_Text(text), m_Font(font) {
		SetPosition(Vec3(x, y, 0.0f));

		// Convert Vec4 to hexadecimal format
		int r = color.x * 255.0f;
		int g = color.y * 255.0f;
		int b = color.z * 255.0f;
		int a = color.w * 255.0f;
		m_Color = a << 24 |	b << 16 | g << 8 | r;
	}

	void Label::Submit(Renderer2D* renderer) const {
		renderer->DrawString(m_Text, m_Position, *m_Font, m_Color);
	}

}}