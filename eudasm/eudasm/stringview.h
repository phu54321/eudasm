#pragma once

#include <string.h>
#include <string>

// simple string view class
class string_view {
public:
	string_view() : _start(nullptr), _end(nullptr) {}
	string_view(const std::string& str) : _start(str.data()), _end(str.data() + str.size()) {}
	string_view(const char* str) : _start(str), _end(str + strlen(str)) {}
	string_view(const char* start, const char* end) : _start(start), _end(end) {}
	~string_view() {}
	
	const char* pbegin() const { return _start; }
	const char* pend() const { return _end; }
	const char* data() const { return _start; }

	size_t size() const { return _end - _start; }

	char operator[](size_t index) { return _start[index]; }

	void assign(const char* start, const char* end) {
		_start = start; _end = end;
	}

	bool operator==(const string_view& rhs) {
		return rhs.size() == size() && memcmp(rhs.pbegin(), pbegin(), size()) == 0;
	}

private:
	const char *_start, *_end;
};


