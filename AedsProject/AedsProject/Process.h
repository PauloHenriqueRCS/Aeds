#pragma once
struct Process {
	Process * next;
	int id;
	int timeStamp;
	void init(int id, int timeStamp);
};
