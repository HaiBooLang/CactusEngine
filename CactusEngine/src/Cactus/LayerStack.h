#pragma once

#include "Cactus/Core.h"
#include "Layer.h"

namespace Cactus {

	/**
	 * LayerStack类是一种数据结构，用于管理游戏引擎中层（Layer）的堆栈。
	 * 它提供了成员函数，用于向堆栈中添加和删除层，并提供了迭代器，用于遍历堆栈中的层。
	 * 该类用于管理层的更新和渲染顺序，是游戏引擎架构的重要组成部分。
	 */
	class CACTUS_API LayerStack
	{
	public:
		LayerStack();
		~LayerStack();

		// 接受一个指向Layer对象的指针，并将其添加到层堆栈的顶部。
		void PushLayer(Layer* layer);

		// 接受一个指向Layer对象的指针，并将其添加到层堆栈的顶部，但在使用PushLayer()添加的任何层之上。
		void PushOverlay(Layer* overlay);

		// 接受一个指向Layer对象的指针，并将其从层堆栈中删除。
		void PopLayer(Layer* layer);

		// 接受一个指向Layer对象的指针，并将其从层堆栈中删除。
		void PopOverlay(Layer* overlay);

		std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
		std::vector<Layer*>::iterator end() { return m_Layers.end(); }
	private:
		// 存储堆栈中的层的指针
		std::vector<Layer*> m_Layers;

		// 迭代器，指向下一个应插入的层在vector中的位置。
		std::vector<Layer*>::iterator m_LayerInsert;
	};

}