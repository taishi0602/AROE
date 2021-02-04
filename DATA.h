#pragma once
#include<string>
class DATA {
	//de-ta chi
	float Value = 0;
	//de-ta mei
	std::string Name;

public:
	//setta-
	void setValue(float value);
	void setName(const char* name);
	//getta-
	float value();
	std::string name();
};