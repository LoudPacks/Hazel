#pragma once

#include "Hazel/Core.h"
#include "Hazel/Layer.h"

#include <vector>

namespace Hazel
{
	class LayerStack
	{
	public:
		LayerStack() = default;
		~LayerStack();

		void PushLayer(Layer* layer);
		void PopLayer(Layer* layer);

		void PushOverlay(Layer* overlay);
		void PopOverlay(Layer* overlay);

		std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
		std::vector<Layer*>::iterator end() { return m_Layers.end(); }
		std::vector<Layer*>::reverse_iterator rbegin() { return m_Layers.rbegin(); }
		std::vector<Layer*>::reverse_iterator rend() { return m_Layers.rend(); }

		std::vector<Layer*>::const_iterator begin() const { return m_Layers.cbegin(); }
		std::vector<Layer*>::const_iterator end() const { return m_Layers.cend(); }
		std::vector<Layer*>::const_reverse_iterator rbegin() const { return m_Layers.crbegin(); }
		std::vector<Layer*>::const_reverse_iterator rend() const { return m_Layers.crend(); }

	private:
		std::vector<Layer*> m_Layers;
		unsigned int m_LayerInsertIndex = 0;
	};
}