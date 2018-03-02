#pragma once
using namespace std;

class Text {
public:
	Text();
	Text(char* str);
	Text(char ch);
	Text(const Text &obj);

	int size();
	void clear();
	void operator+= (Text text2);
	void operator= (Text text2);
	bool operator> (Text text2);
	bool operator< (Text text2);
	friend ostream& operator<< (ostream& os, Text& text);
	~Text();


private:
	std::vector<WordWithMark> words;
	char sep;
};

std::ostream& operator<< (std::ostream& os, const Text& text);