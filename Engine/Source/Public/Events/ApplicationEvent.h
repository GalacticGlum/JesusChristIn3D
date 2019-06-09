/**
 * Author: Shon Verch
 * File Name: ApplicationEvent.h
 * Project Name: JesusChristIn3D
 * Creation Date: 06/09/2019
 * Modified Date: 06/09/2019
 * Description: Application events.
 */

#pragma once

#include <sstream>
#include <Events/Event.h>

/**
 * @class WindowResizeEvent ApplicationEvent.h
 * @brief Raised whenever the window is resized.
 */
class WindowResizeEvent : public Event
{
public:
	/**
	 * Initialize a new WindowResizeEvent given a @p width and @p height.
	 */
	WindowResizeEvent(const uint32_t width, const uint32_t height) : m_Width(width), m_Height(height)
	{
	}

	/**
	 * @brief Get the width.
	 */
	uint32_t GetWidth() const { return m_Width; }

	/**
	 * @brief Get the height.
	 */
	uint32_t GetHeight() const { return m_Height; }

	/**
	 * @brief Convert this WindowResizeEvent to its string representation.
	 */
	std::string ToString() const override
	{
		std::stringstream stream;
		stream << "WindowResizeEvent: " << m_Width << ", " << m_Height;
		return stream.str();
	}

	EVENT_CLASS_TYPE(WindowResize)
	EVENT_CLASS_CATEGORY(EventCategoryApplication)
private:
	uint32_t m_Width;
	uint32_t m_Height;
};

class WindowCloseEvent : public Event
{
public:
	WindowCloseEvent() = default;

	EVENT_CLASS_TYPE(WindowClose)
	EVENT_CLASS_CATEGORY(EventCategoryApplication)
};

class AppTickEvent : public Event
{
public:
	AppTickEvent() = default;

	EVENT_CLASS_TYPE(AppTick)
	EVENT_CLASS_CATEGORY(EventCategoryApplication)
};

class AppUpdateEvent : public Event
{
public:
	AppUpdateEvent() = default;

	EVENT_CLASS_TYPE(AppUpdate)
	EVENT_CLASS_CATEGORY(EventCategoryApplication)
};

class AppRenderEvent : public Event
{
public:
	AppRenderEvent() = default;

	EVENT_CLASS_TYPE(AppRender)
	EVENT_CLASS_CATEGORY(EventCategoryApplication)
};