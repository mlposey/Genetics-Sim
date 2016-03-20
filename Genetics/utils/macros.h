// Creates a custom std::runtime_error exception
#define MAKE_EXCEPTION(NAME) \
	class NAME : public std::runtime_error { \
	public: \
	NAME(const string &msg) : std::runtime_error(msg.c_str()) {} };

// Turns the class into a singleton retrievable by ::getInstance()
#define SINGLETON(CLASSNAME) \
	public: \
	static CLASSNAME *getInstance() { \
	static CLASSNAME *instance = new CLASSNAME(); \
	return instance; } \
	private: \
	CLASSNAME() {}