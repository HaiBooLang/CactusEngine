#pragma once

#include "Cactus/Core.h"
#include "Cactus/Events/Event.h"

namespace Cactus {

	class CACTUS_API Layer
	{
	public:
		// 构造函数，用于设置层的名称。
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		// 将层添加到应用程序时调用，用于初始化层所需的任何资源。
		virtual void OnAttach() {}

		// 将层从应用程序中删除时调用，用于清理层分配的任何资源。
		virtual void OnDetach() {}

		// 每帧调用一次，用于更新层的状态。
		virtual void OnUpdate() {}

		// 在应用程序中发生事件时调用，用于处理特定于层的事件。
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const { return m_DebugName; }
	protected:
		std::string m_DebugName;
	};

}
