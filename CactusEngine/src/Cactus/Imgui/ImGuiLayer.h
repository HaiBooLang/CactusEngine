#pragma once

#include "Cactus/Layer.h"
#include "Cactus/Events/KeyEvent.h"
#include "Cactus/Events/MouseEvent.h"
#include "Cactus/Events/ApplicationEvent.h"

namespace Cactus {

	class CACTUS_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		// 在ImGuiLayer被添加到应用程序中时调用，用于初始化ImGui库和创建ImGui上下文。
		void OnAttach();

		// 在ImGuiLayer被从应用程序中移除时调用，用于清理ImGui库和销毁ImGui上下文。
		void OnDetach();

		// 在每一帧更新时调用，用于更新ImGui图形用户界面。
		void OnUpdate();
		
		// 在应用程序接收到事件时调用，用于处理ImGui图形用户界面相关的事件。
		void OnEvent(Event& event);
	private:
		// 处理与ImGui图形用户界面相关的事件。
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
		bool OnMouseMovedEvent(MouseMovedEvent& e);
		bool OnMouseScrolledEvent(MouseScrolledEvent& e);
		bool OnKeyPressedEvent(KeyPressedEvent& e);
		bool OnKeyReleasedEvent(KeyReleasedEvent& e);
		bool OnKeyTypedEvent(KeyTypedEvent& e);
		bool OnWindowResizeEvent(WindowResizeEvent& e);
	private:
		// 从ImGuiLayer被添加到应用程序中开始，经过的时间（以秒为单位）。
		float m_Time = 0.0f;
	};

}