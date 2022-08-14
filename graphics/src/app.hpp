#pragma once
#define msvcopengl
#include <common.hpp>

class app{
	app(const std::string& name);
	static app& instance {return }

	void loop();

private:
	static app* instance;


};

