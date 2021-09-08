#pragma once

#include "input.hpp"

namespace Core::Input
{
	class KeyButton : public Input
	{
	private:
		bool m_isPressed = false;
		bool m_isReleased = false;
		bool m_wasDown = false;
		bool m_isDown = false;

	public:
		int m_keyID;

		KeyButton(int keyID);

		void compute(GLFWwindow* window) override;

		bool isButtonPressed() const;
		bool isButtonReleased() const;
		bool isButtonDown() const;
	};
}