#pragma once
class CONTAINER;
class PLAY_BACK;
class PLAY_BACKs {
public:
	PLAY_BACKs(CONTAINER* c);
	~PLAY_BACKs();
	void init(CONTAINER* c);
	void updata();
	void draw();
private:

	int Num = 0;
	PLAY_BACK* Back = 0;
};
