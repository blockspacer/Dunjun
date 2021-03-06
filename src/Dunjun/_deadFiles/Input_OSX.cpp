
#include <Dunjun/Config.hpp>
#ifdef DUNJUN_SYSTEM_OSX
#include <Dunjun/Input.hpp>

namespace Dunjun
{
	namespace Input
	{
		// 
		GLOBAL f64 g_scrollX = 0;
		GLOBAL f64 g_scrollY = 0;

		void scrollCallback(GLFWwindow* window, f64 offsetX, f64 offsetY)
		{
			g_scrollX = offsetX;
			g_scrollY = offsetY;
		}

		void setUp() // set up gamepads
		{
			for (int i = 0; i < Gamepad_MaxCount; i++) // cycle through and check if they're present
			{
				//memset(&g_gamepadStates[i], 0, sizeof(XINPUT_STATE));
				if (isGamepadPresent((GamepadId)i))
					setGamepadVibration((GamepadId)i, 0, 0); // if isPresent set vibration to 0
			}
			setStickyKeys(true); // sticky assumes the button is held until it is checked again
			setStickyMouseButtons(true);
		}

		void cleanup()
		{
			for (int i = 0; i < Gamepad_MaxCount; i++)
			{
				if (isGamepadPresent((GamepadId)i))
					setGamepadVibration((GamepadId)i, 0, 0); // make sure vibration is set to 0 when disconnecting
			}
		}

		//void setInputMode(InputMode mode, int value)
		//{
		//	int m = 0;
		//	if (mode == InputMode::Cursor)
		//		m = GLFW_CURSOR;
		//	if (mode == InputMode::StickyKeys)
		//		m = GLFW_STICKY_KEYS;
		//	if (mode == InputMode::StickyMouseButtons)
		//		m = GLFW_STICKY_MOUSE_BUTTONS;
		//
		//	glfwSetInputMode(Window::getHandle(), m, value);
		//}

		/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
		)				.
		)					INPUT MODES
		)
		)				.
		)					.
		)
		)				.
		%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/

		void setCursorMode(CursorMode mode)
		{
			if (mode == CursorMode::Normal)
				glfwSetInputMode(Window::getHandle(), GLFW_CURSOR, GLFW_CURSOR_NORMAL);
			if (mode == CursorMode::Hidden)
				glfwSetInputMode(Window::getHandle(), GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
			if (mode == CursorMode::Disabled)
				glfwSetInputMode(Window::getHandle(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		}

		void setStickyKeys(bool stickyKeys)
		{
			glfwSetInputMode(Window::getHandle(), GLFW_STICKY_KEYS, stickyKeys);
		}

		void setStickyMouseButtons(bool stickyButtons)
		{
			glfwSetInputMode(Window::getHandle(), GLFW_STICKY_MOUSE_BUTTONS, stickyButtons);
		}

		/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
		)				.
		)					KEYBOARD
		)
		)				.
		)					.
		)
		)				.
		%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/

		// get keyboard key pressed
		bool isKeyPressed(Key key)
		{
			int code = 0;

			// check keyboard key
			switch (key)
			{
			default: code = 0;							break;
			case Key::A: code = GLFW_KEY_A;					break;
			case Key::B: code = GLFW_KEY_B;					break;
			case Key::C: code = GLFW_KEY_C;					break;
			case Key::D: code = GLFW_KEY_D;					break;
			case Key::E: code = GLFW_KEY_E;					break;
			case Key::F: code = GLFW_KEY_F;					break;
			case Key::G: code = GLFW_KEY_G;					break;
			case Key::H: code = GLFW_KEY_H;					break;
			case Key::I: code = GLFW_KEY_I;					break;
			case Key::J: code = GLFW_KEY_J;					break;
			case Key::K: code = GLFW_KEY_K;					break;
			case Key::L: code = GLFW_KEY_L;					break;
			case Key::M: code = GLFW_KEY_M;					break;
			case Key::N: code = GLFW_KEY_N;					break;
			case Key::O: code = GLFW_KEY_O;					break;
			case Key::P: code = GLFW_KEY_P;					break;
			case Key::Q: code = GLFW_KEY_Q;					break;
			case Key::R: code = GLFW_KEY_R;					break;
			case Key::S: code = GLFW_KEY_S;					break;
			case Key::T: code = GLFW_KEY_T;					break;
			case Key::U: code = GLFW_KEY_U;					break;
			case Key::V: code = GLFW_KEY_V;					break;
			case Key::W: code = GLFW_KEY_W;					break;
			case Key::X: code = GLFW_KEY_X;					break;
			case Key::Y: code = GLFW_KEY_Y;					break;
			case Key::Z: code = GLFW_KEY_Z;					break;
			case Key::Num0: code = GLFW_KEY_0;					break;
			case Key::Num1: code = GLFW_KEY_1;					break;
			case Key::Num2: code = GLFW_KEY_2;					break;
			case Key::Num3: code = GLFW_KEY_3;					break;
			case Key::Num4: code = GLFW_KEY_4;					break;
			case Key::Num5: code = GLFW_KEY_5;					break;
			case Key::Num6: code = GLFW_KEY_6;					break;
			case Key::Num7: code = GLFW_KEY_7;					break;
			case Key::Num8: code = GLFW_KEY_8;					break;
			case Key::Num9: code = GLFW_KEY_9;					break;
			case Key::Escape: code = GLFW_KEY_ESCAPE;				break;
			case Key::LControl: code = GLFW_KEY_LEFT_CONTROL;		break;
			case Key::LShift: code = GLFW_KEY_LEFT_SHIFT;			break;
			case Key::LAlt: code = GLFW_KEY_LEFT_ALT;			break;
			case Key::LSystem: code = GLFW_KEY_LEFT_SUPER;			break;
			case Key::RControl: code = GLFW_KEY_RIGHT_CONTROL;		break;
			case Key::RShift: code = GLFW_KEY_RIGHT_SHIFT;		break;
			case Key::RAlt: code = GLFW_KEY_RIGHT_ALT;			break;
			case Key::RSystem: code = GLFW_KEY_RIGHT_SUPER;		break;
			case Key::Menu: code = GLFW_KEY_MENU;				break;
			case Key::LBracket: code = GLFW_KEY_LEFT_BRACKET;		break;
			case Key::RBracket: code = GLFW_KEY_RIGHT_BRACKET;		break;
			case Key::SemiColon: code = GLFW_KEY_SEMICOLON;			break;
			case Key::Comma: code = GLFW_KEY_COMMA;				break;
			case Key::Period: code = GLFW_KEY_PERIOD;				break;
			case Key::Apostrophe: code = GLFW_KEY_APOSTROPHE;			break;
			case Key::Slash: code = GLFW_KEY_SLASH;				break;
			case Key::BackSlash: code = GLFW_KEY_BACKSLASH;			break;
			case Key::Equal: code = GLFW_KEY_EQUAL;				break;
			case Key::Minus: code = GLFW_KEY_MINUS;				break;
			case Key::Space: code = GLFW_KEY_SPACE;				break;
			case Key::Return: code = GLFW_KEY_ENTER;				break;
			case Key::Backspace: code = GLFW_KEY_BACKSPACE;			break;
			case Key::Tab: code = GLFW_KEY_TAB;				break;
			case Key::GraveAccent: code = GLFW_KEY_GRAVE_ACCENT;		break;
			case Key::World1: code = GLFW_KEY_WORLD_1;			break;
			case Key::World2: code = GLFW_KEY_WORLD_2;			break;
			case Key::PageUp: code = GLFW_KEY_PAGE_UP;			break;
			case Key::PageDown: code = GLFW_KEY_PAGE_DOWN;			break;
			case Key::End: code = GLFW_KEY_END;				break;
			case Key::Home: code = GLFW_KEY_HOME;				break;
			case Key::Insert: code = GLFW_KEY_INSERT;				break;
			case Key::Delete: code = GLFW_KEY_DELETE;				break;
			case Key::Add: code = GLFW_KEY_KP_ADD;				break;
			case Key::Subtract: code = GLFW_KEY_KP_SUBTRACT;		break;
			case Key::Multiply: code = GLFW_KEY_KP_MULTIPLY;		break;
			case Key::Divide: code = GLFW_KEY_KP_DIVIDE;			break;
			case Key::Left: code = GLFW_KEY_LEFT;				break;
			case Key::Right: code = GLFW_KEY_RIGHT;				break;
			case Key::Up: code = GLFW_KEY_UP;					break;
			case Key::Down: code = GLFW_KEY_DOWN;				break;
			case Key::Numpad0: code = GLFW_KEY_KP_0;				break;
			case Key::Numpad1: code = GLFW_KEY_KP_1;				break;
			case Key::Numpad2: code = GLFW_KEY_KP_2;				break;
			case Key::Numpad3: code = GLFW_KEY_KP_3;				break;
			case Key::Numpad4: code = GLFW_KEY_KP_4;				break;
			case Key::Numpad5: code = GLFW_KEY_KP_5;				break;
			case Key::Numpad6: code = GLFW_KEY_KP_6;				break;
			case Key::Numpad7: code = GLFW_KEY_KP_7;				break;
			case Key::Numpad8: code = GLFW_KEY_KP_8;				break;
			case Key::Numpad9: code = GLFW_KEY_KP_9;				break;
			case Key::NumpadEnter: code = GLFW_KEY_KP_ENTER;			break;
			case Key::F1: code = GLFW_KEY_F1;					break;
			case Key::F2: code = GLFW_KEY_F2;					break;
			case Key::F3: code = GLFW_KEY_F3;					break;
			case Key::F4: code = GLFW_KEY_F4;					break;
			case Key::F5: code = GLFW_KEY_F5;					break;
			case Key::F6: code = GLFW_KEY_F6;					break;
			case Key::F7: code = GLFW_KEY_F7;					break;
			case Key::F8: code = GLFW_KEY_F8;					break;
			case Key::F9: code = GLFW_KEY_F9;					break;
			case Key::F10: code = GLFW_KEY_F10;				break;
			case Key::F11: code = GLFW_KEY_F11;				break;
			case Key::F12: code = GLFW_KEY_F12;				break;
			case Key::F13: code = GLFW_KEY_F13;				break;
			case Key::F14: code = GLFW_KEY_F14;				break;
			case Key::F15: code = GLFW_KEY_F15;				break;
			case Key::Pause: code = GLFW_KEY_PAUSE;				break;

			}

			if (code == 0)
				return false;

			return static_cast<bool>(glfwGetKey(Window::getHandle(), code));
		}

		/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
		)				.
		)					MOUSE
		)
		)				.
		)					.
		)
		)				.
		%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/

		Vector2 getCursorPosition()
		{
			f64 x, y;
			glfwGetCursorPos(Window::getHandle(), &x, &y);

			return Vector2(x, y);
		}
		void setCursorPosition(const Vector2& pos)
		{
			glfwSetCursorPos(Window::getHandle(),
				static_cast<f64>(pos.x),
				static_cast<f64>(pos.y));
		}

		bool isMouseButtonPressed(MouseButton button)
		{
			return static_cast<bool>(glfwGetMouseButton(Window::getHandle(), (int)button));
		}

		// get scroll wheel movement
		//Vector2 getScrollOffset()
		//{
		//	return Vector2(g_scrollX, g_scrollY);
		//}

		/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
		)				.
		)					TIME
		)
		)				.
		)					.
		)
		)				.
		%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/

		//void setTime(Time time)
		//{
		//	glfwSetTime(time);
		//}

		/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
		)				.
		)					GAMEPAD
		)
		)				.
		)					.
		)
		)				.
		%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/

		void updateGamepads()
		{
			for (size_t i = 0; i < Gamepad_MaxCount; i++)
			{
				isGamepadPresent((GamepadId)i);
			}
		}

		bool isGamepadPresent(GamepadId gamepadId)
		{
				return glfwJoystickPresent(GLFW_JOYSTICK_1 + (int)gamepadId);

		}

		GamepadAxes getGamepadAxes(GamepadId gamepadId)
		{
			GamepadAxes axes;

			int count = 0;
			const f32* glfwAxes = glfwGetJoystickAxes(GLFW_JOYSTICK_1 + (int)gamepadId, &count);

			if(count <= 0)
			{
			axes.leftTrigger = 0.0f; // convert to correct size
			axes.rightTrigger = 0.0f;

			axes.leftThumbStick = Vector2(glfwAxes[0], glfwAxes[1]);
			axes.rightThumbStick = Vector2(glfwAxes[2], glfwAxes[3]);
			}

			return axes;
		}

		GamepadButtons getGamepadButtons(GamepadId gamepadId)
		{
			GamepadButtons buttons((size_t)XboxButton::Count);

			int count = 0;
			const u8* glfwButtons = glfwGetJoystickButtons(GLFW_JOYSTICK_1 + (int)gamepadId, &count);

			buttons[(int)XboxButton::DpadUp] = false;
			buttons[(int)XboxButton::DpadDown] = false;
			buttons[(int)XboxButton::DpadLeft] = false;
			buttons[(int)XboxButton::DpadRight] = false;

			buttons[(int)XboxButton::Start] = glfwButtons[9];
			buttons[(int)XboxButton::Back] = glfwButtons[8];

			buttons[(int)XboxButton::LeftThumb] = glfwButtons[10];
			buttons[(int)XboxButton::RightThumb] = glfwButtons[11];

			buttons[(int)XboxButton::LeftShoulder] = glfwButtons[6];
			buttons[(int)XboxButton::RightShoulder] = glfwButtons[7];

			buttons[(int)XboxButton::A] = glfwButtons[2];
			buttons[(int)XboxButton::B] = glfwButtons[1];
			buttons[(int)XboxButton::X] = glfwButtons[3];
			buttons[(int)XboxButton::Y] = glfwButtons[0];

			return buttons;
		}

		b8 isGamepadButtonPressed(GamepadId gamepadId, XboxButton button)
		{
			return getGamepadButtons(gamepadId)[(size_t)button];
		}

		std::string getGamepadName(GamepadId gamepadId)
		{
			return glfwGetJoystickName(gamepadId);
		}

		void setGamepadVibration(GamepadId gamepadId, f32 leftMotor, f32 rightMotor)
		{
			// TODO
		}

		std::string getClipboardString()
		{
			return glfwGetClipboardString(Window::getHandle());
		}

		void setClipboardString(const std::string& str)
		{
			glfwSetClipboardString(Window::getHandle(), str.c_str());
		}

	} // end Input
} // end Dunjun
#endif
