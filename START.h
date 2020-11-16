#pragma once
class CONTAINER;
class START1_1;
class START {
public:
	START();
    ~START();
	void proc(int* state);
private:
	CONTAINER* C = 0;
	START1_1* Start = 0;
};