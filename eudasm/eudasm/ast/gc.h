#pragma once

class GCEnabled {
private:

public:
	GCEnabled();
	
private:
	~GCEnabled(); // no delete allowed.
	bool _marked;
};

class GCEnabledPtr {
public:
	GCEnabledPtr(GCEnabled* parent, GCEnabled* target);
	~GCEnabledPtr();

	const GCEnabledPtr& operator=(GCEnabledPtr target);
	const GCEnabledPtr& operator=(GCEnabled* target);
};
