#pragma once

class Debug
{
public:
	static bool isEnabled() { return enabled; }
	static void setEnabled(bool enabled) { Debug::enabled = enabled; }
private:
	static bool enabled;
};