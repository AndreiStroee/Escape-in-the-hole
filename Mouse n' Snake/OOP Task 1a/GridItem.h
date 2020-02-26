#pragma once
class GridItem {
protected:
	char symbol;
public:
	GridItem();
	GridItem(char symbol);
	char get_symbol() const;
};